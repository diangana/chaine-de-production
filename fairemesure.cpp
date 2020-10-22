#include "fairemesure.h"
#include <QSettings>
#include <QtDebug>
FaireMesure::FaireMesure()
{

}
FaireMesure::~FaireMesure()
{

}
void FaireMesure::mesurer()
{
    for(int i=1;i<=6;i++)
    {
        table="mesure";
        donnee="Frequence";

        QString m=QString::number(i);
        QSettings settings("IDD","mesurer");
        int gabarit=settings.value("gabarit").toInt();
        freq1=600000;
            Frequence.changer(QString("freq %1").arg(freq1));



     if(freq1<500000)
     {
         QString a="";
         QString b="";
          Oscilloscope.mesurerOsc(a,b);
         QStringList oscS= Oscilloscope.stringS.split("E");
         double mesureS=oscS[0].toDouble()*pow(10,oscS[1].toDouble());
         QStringList oscE= Oscilloscope.stringE.split("E");
         double mesureE=oscE[0].toDouble()*pow(10,oscE[1].toDouble());
         double mesureO=20*log(mesureS/mesureE);
         gain=QString::number(mesureO);
         qDebug()<<gain;


      }
     else
     {
         QString a="";
         QString b="";
         Oscilloscope.mesurerOsc(a,b);
         Multimetre.mesurerMuli(a);
         QStringList multi= Multimetre.string.split("E");
         double mesureS=multi[0].toDouble()*pow(10,multi[1].toDouble());
         QStringList oscE= Oscilloscope.stringE.split("E");
         double mesureE=oscE[0].toDouble()*pow(10,oscE[1].toDouble());
         double mesureM=20*log(mesureS/mesureE);
         gain=QString::number(mesureM);
          qDebug()<<gain;


     }
    }
}
