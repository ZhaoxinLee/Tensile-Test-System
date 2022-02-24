#include "callbacks.h"

void MainWindow::callbacks(void){
    if (DAQ.isEnabled())
    {
        // Read analog inputs from the DAQ by reading values and passing by ref.
        //DAQ.dataAcquisition8(DAQ.analogInputVoltages);
        DAQ.dataAcquisition();
        //Get Forces and torques from values
        double tempVoltages[6];
        for (int v = 0; v<6; v++)
        {
            tempVoltages[v] = DAQ.analogInputVoltages[v]-ATINanoVoltageOffsets[v];
        }

        double A[6][6] = {0.0};
        double J[6] = {0.0};
//        MatrixMultVect6(A, tempVoltages, J);
        //MatrixMultVect6(ATINanoCalibrationMatrix, tempVoltages, ATINanoForceTorque);
        for (int v = 0; v<6; v++)
        {
            DAQ.analogInputVoltages[v] = ATINanoForceTorque[v];
        }
    }
    else{
        qDebug() << "Error running DAQ.\n";
    }
}
