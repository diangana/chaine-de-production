#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include "visa.h"
#include <QObject>

class instrument
{
public:
    instrument();

    class multimetre
    {
    public:
        multimetre();
        void mesurerMuli(QString buf);
        QString string;
    private:
        // for VISA-communication
        ViSession defaultRM;        // connection to main VISA drive
        ViSession vi;               // connection to device
         ViStatus status;            // communication status
         ViUInt32 retCount;          // retur count from string I/O
         ViUInt32 writeCount;
          ViSession instr;

    };
    class oscilloscope
    {

    public:
        oscilloscope();
        void mesurerOsc(QString buf, QString buf2);
        QString stringE;
         QString stringS;
    private:
        // for VISA-communication
        ViSession defaultRM;        // connection to main VISA drive
        ViSession vi;               // connection to device
         ViStatus status;            // communication status
         ViUInt32 retCount;          // retur count from string I/O
         ViUInt32 writeCount;
          ViSession instr;

    };
    class frequence
    {

    public:
        frequence();
        ~frequence();
            void changer(QString string);
    private:
        // for VISA-communication
        ViSession defaultRM;        // connection to main VISA drive
        ViSession vi;               // connection to device
         ViStatus status;            // communication status
         ViUInt32 retCount;          // retur count from string I/O
         ViUInt32 writeCount;
          ViSession instr;
    };



};

#endif // INSTRUMENT_H
