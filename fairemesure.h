#ifndef FAIREMESURE_H
#define FAIREMESURE_H
#include "instrument.h"

class FaireMesure
{
    instrument::frequence Frequence;
    instrument::multimetre Multimetre;
    instrument::oscilloscope Oscilloscope;
public:
    FaireMesure();
    ~FaireMesure();
    int freq1;

    QString gain;
    //QString aff;
   void mesurer();
    QString table;
    QString donnee;
};

#endif // FAIREMESURE_H
