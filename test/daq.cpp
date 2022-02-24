#include "daq.h"

daq::daq() {

}

daq::~daq() {

}

bool daq::isEnabled( void ) {
    return enableDAQ;
}

void daq::setupTask(void)
{
    DAQmxCreateTask("MyTask", &taskHandle);
    DAQmxCreateAIVoltageChan(taskHandle, "Dev1/ai0:7", "8_AI_Channels", DAQmx_Val_Cfg_Default, -10, 10, DAQmx_Val_Volts, nullptr);
    DAQmxCfgSampClkTiming(taskHandle, "", sampleRate, DAQmx_Val_Rising, DAQmx_Val_FiniteSamps, numSamples);
}

void daq::finishTask()
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

void daq::dataAcquisition(void)
{

    // Voltage readings are set to max and mins of +-10 V

    // Recommended sampleRate = 10000.0;
    // Recommended numSamples = 10;

    DAQmxCreateTask("MyTask", &taskHandle);
    DAQmxCreateAIVoltageChan(taskHandle, "Dev1/ai0:7", "8_AI_Channels", DAQmx_Val_Cfg_Default, -10, 10, DAQmx_Val_Volts, nullptr);
    DAQmxCfgSampClkTiming(taskHandle, "", sampleRate, DAQmx_Val_Rising, DAQmx_Val_FiniteSamps, numSamples);
    // Start Code
    DAQmxStartTask(taskHandle);
    // Read Code
    // This could be the part that is repeated and cut out the top and bottom code to speed up calcs.
    DAQmxReadAnalogF64(taskHandle, numSamples, timeout, DAQmx_Val_GroupByChannel, data, 8*numSamples, &samplesReceived, nullptr);

    if( samplesReceived > 0 )
    {
        qInfo() << "Acquired " << (int)samplesReceived << " samples.";

        for (int i = 0; i < 8; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < numSamples; j++)
            {
                sum += data[i*numSamples+j];
                //qDebug() << "Datapoint: " << i*numSamples+j << " is " << data[i*numSamples+j];
            }
            // Average over numSamples is the value measured
            analogInputVoltages[i] = sum/numSamples;
            qDebug() << "Datapoint: " << i << " is " << analogInputVoltages[i];
        }
    }
    else
    {
        qInfo() << "No samples were read.";
    }

    if( taskHandle!=nullptr )
    {
        // Stop Code
        DAQmxStopTask(taskHandle);
        DAQmxClearTask(taskHandle);
    }
}
