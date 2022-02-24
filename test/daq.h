#ifndef DAQ_H
#define DAQ_H
#include "NIDAQmx.h"
#include <QDebug>

class daq {

public:
    daq();
    ~daq();

    bool enableDAQ = true;
    double analogInputVoltages[8] = {0.0};
    const static int maxSamples = 10;
    int numSamples = 10; // Number of samples per datapoint on all channels
//    double sampleRate = 31000.0; // internal clock speed
    double sampleRate = 25000.0; // internal clock speed
    constexpr static double maxSampleRate = 250000.0/8.0; // this rate is shared among the channels used

    void dataAcquisition( void );
    void dataAcquisition8(double datastream[8]);

    bool isEnabled( void );
    void setupTask( void );
    void setNumSamples( int numSamp );
    void setSampleRate(double sampRate);
    void finishTask( void );

private:
    TaskHandle taskHandle;
    int32      error=0;
    char       errBuff[2048]={'\0'};
    int32 samplesReceived = 0;

    float64 data[8*maxSamples];

    double timeout = 10.0;

};

#endif // DAQ_H
