#ifndef DAQ_H
#define DAQ_H
#include "NIDAQmx.h"
#include <QDebug>
#include <QDateTime>
#include <QObject>

class daq
{

public:
    daq();
    ~daq();

    bool DAQ_enabled = true;
    double analogInputVoltages[8] = {0.0};
    const static int maxSamples = 10;
    int numSamples = 10; // Number of samples per datapoint on all channels
    double sampleRate = 25000.0; // internal clock speed
    constexpr static double maxSampleRate = 250000.0/8.0; // this rate is shared among the channels used

    bool isEnabled( void );
    bool enable( void );
    bool disable( void );
    void setupTask( void );
    void setNumSamples( int numSamp );
    void setSampleRate(double sampRate);
    void dataAcquisition(double datastream[8]);
    void finishTask( void );
    void stopTask( void );
    void MatrixMultVect6(const double C[6][6], double D[6], double E[6]);

    const double ATINanoVoltageOffsets[6] = {-1.3051,	3.7328, 2.0871,	2.2321,	-0.2898, -0.7321};
    const double ATINanoCalibrationMatrix[6][6] =  {{  0.00749,	 0.02250,	 0.01747,	-0.80775,	-0.02452,	 0.81951},
                                                   { -0.03933,	 0.97698,	 0.01759,	-0.43942,	 0.00040,	-0.49738},
                                                   {  0.92086,	 0.03400,	 0.93714,	-0.00522,	 0.97298,	 0.01115},
                                                   { -0.55209,	 5.99193,	 5.23393,	-2.69998,	-5.44013,	-3.14306},
                                                   { -5.88807,	-0.35924,	 2.76672,	 4.91801,	 3.46558,	-4.95869},
                                                   { -0.17835,	 3.57785,	-0.02007,	 3.30164,	-0.08660,	 3.66835}};
    double ATINanoForceTorque[6] = {0.0};

    QDateTime start_recording_time;

    QString FILENAME;
    QString FILE_PATH;
    QString DATA_SAVE_PATH = "../data/";


private:
    TaskHandle taskHandle;
    int32      error=0;
    char       errBuff[2048]={'\0'};
    int32 samplesReceived = 0;

    float64 data[8*maxSamples];

    double timeout = 10.0;

public slots:
    void start_recording( void );
    void stop_recording( void );
    void receive_gantry_positions( QStringList );
    double* collect_data( void );

private slots:
    void write_to_txt ( void );

};

#endif // DAQ_H
