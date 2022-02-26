#include "daq.h"

daq::daq() {

}

daq::~daq() {

}

bool daq::isEnabled( void ) {
    return DAQ_enabled;
}

bool daq::enable( void ) {
    if (!DAQ_enabled)
    {
        DAQ_enabled = true;
    }
    return DAQ_enabled;
}

bool daq::disable( void ) {
    if (DAQ_enabled)
    {
        DAQ_enabled = false;
    }
    return DAQ_enabled;
}

void daq::setupTask(void)
{
    // Voltage readings are set to max and mins of +-10 V
    // Recommended sampleRate = 10000.0;
    // Recommended numSamples = 10;
    DAQmxCreateTask("MyTask", &taskHandle);
    DAQmxCreateAIVoltageChan(taskHandle, "Dev1/ai0:7", "8_AI_Channels", DAQmx_Val_Cfg_Default, -10, 10, DAQmx_Val_Volts, nullptr);
    DAQmxCfgSampClkTiming(taskHandle, "", sampleRate, DAQmx_Val_Rising, DAQmx_Val_FiniteSamps, numSamples);
}

void daq::finishTask(void)
{
    if( DAQmxFailed(error) )
    {
        DAQmxGetExtendedErrorInfo(errBuff,2048);
    }
    if( taskHandle!=nullptr )
    {
        DAQmxClearTask(taskHandle);
    }
    if( DAQmxFailed(error) )
    {
        printf("DAQmx Error: %s\n",errBuff);
    }
}

void daq::stopTask(void)
{
    DAQmxStopTask(taskHandle);
    DAQmxClearTask(taskHandle);
}


void daq::setNumSamples(int numSamp)
{
    // TODO: check for application start first
    if (numSamp < maxSamples)
    {
        numSamples = numSamp;
    }
    else
    {
        numSamples = maxSamples;
        qInfo() << "Number of samples was set too high. Instead, number of samples was set to the maximum: " << maxSamples;
    }
}

void daq::setSampleRate(double sampRate)
{
    // TODO: check for application start first
    sampleRate = sampRate;
}

void daq::dataAcquisition(double datastream[8])
{
    // Start Code
    DAQmxStartTask(taskHandle);
    // Read Code
    DAQmxReadAnalogF64(taskHandle, numSamples, timeout, DAQmx_Val_GroupByChannel, data, 8*numSamples, &samplesReceived, nullptr);

    if( samplesReceived > 0 )
    {
        //qInfo() << "Acquired " << (int)samplesReceived << " samples.";
        for (int i = 0; i < 8; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < numSamples; j++)
            {
                sum += data[i*numSamples+j];
                //qDebug() << "Datapoint: " << i*numSamples+j << " is " << data[i*numSamples+j];
            }
            // Average over numSamples is the value measured
            datastream[i] = sum/numSamples;
        }
    }
    else
    {
        qInfo() << "No samples were read.";
    }

    // Stop Code
    DAQmxStopTask(taskHandle);

}

double* daq::collect_data( void ) {
    if (DAQ_enabled) {
        dataAcquisition(analogInputVoltages);

        double tempVoltages[6];
        for (int v = 0; v<6; v++)
        {
            tempVoltages[v] = analogInputVoltages[v]-ATINanoVoltageOffsets[v];
        }
        MatrixMultVect6(ATINanoCalibrationMatrix, tempVoltages, ATINanoForceTorque);
        /*for (int v = 0; v<6; v++)
        {
            qDebug() << ATINanoForceTorque[v];
        }*/
        return ATINanoForceTorque;
    }
}

void daq::MatrixMultVect6(const double C[6][6], double D[6], double E[6])
{
    // This function returns the matrix multiplication of C*D=E
    // Where C is a 6x6 matrix and D is a 6x1 vector and thus E is
    // the resulting 6x1 vector.
    // The vector E is a buffer array that is passed by reference and editted
    // to receive the result of the matrix multiplication.

    double num;

    for ( int i = 0; i < 6; i++ )
    {
        num = 0.0;
        for ( int k = 0; k < 6; k++ )
        {
            num = C[i][k]*D[k] + num;
        }
        E[i] = num;
    }
}
