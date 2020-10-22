#include "instrument.h"
#include <QtDebug>
instrument::instrument()
{


}
instrument::multimetre::multimetre()
{
}

void instrument::multimetre::mesurerMuli(QString buf)
{
    qDebug() << "Connection to Wafesurfer";
    status = viOpenDefaultRM (& defaultRM);

    if(status!=VI_SUCCESS)
    {
        qDebug() << "Connecting failed";
    }
    //qDebug() << "Setting time out for communication ";

    char IOaddress[]="GPIB0::11::INSTR";

    status = viOpen(defaultRM,IOaddress, VI_NULL, VI_NULL, &vi);
    if (status !=VI_SUCCESS)
    {

        qDebug() << "Connecting " << "failed";
    }

    status = viSetAttribute(vi, VI_ATTR_TMO_VALUE, 2000);
    if (status < VI_SUCCESS)
    {

        qDebug() << "Setting time out failed";
    }
    buf="RWLS\n";
    viPrintf(vi,buf.toLatin1().data());
    //status = viRead(vi,(ViBuf)stringoutput, sizeof(stringoutput), &retCount);
    buf="VAC\n";
    viPrintf(vi,buf.toLatin1().data());
     buf="MEAS1?\n";
    char stringoutput[512];
    viPrintf(vi,buf.toLatin1().data());
    status=viScanf(vi,(char*)"%t",stringoutput);
    QString str(stringoutput);
    string=str;
    if (status < VI_SUCCESS)
    {
       qDebug() <<"Error reading a response from the device\n";
    }
    else
    {
        qDebug() <<"Data read:"<<str;
    }
}
instrument::oscilloscope::oscilloscope()
{

}

void instrument::oscilloscope::mesurerOsc(QString buf, QString buf2)
{
    qDebug() << "Connection to Wafesurfer";
    status = viOpenDefaultRM (& defaultRM);

    if(status!=VI_SUCCESS)
    {
        qDebug() << "Connecting failed";
    }
    //qDebug() << "Setting time out for communication ";

    char IOaddress[]="GPIB0::14::INSTR";
    status = viOpen(defaultRM,IOaddress, VI_NULL, VI_NULL, &vi);
    if (status !=VI_SUCCESS)
    {

        qDebug() << "Connecting " << "failed";
    }

    status = viSetAttribute(vi, VI_ATTR_TMO_VALUE, 2000);
    if (status < VI_SUCCESS)
    {

        qDebug() << "Setting time out failed";
    }
    char stringoutput[12];
    buf="REM\n";
    viPrintf(vi,buf.toLatin1().data());
    status=viScanf(vi,(char*)"%t",stringoutput);
    char stringoutputS[512];
    buf="MEASUrement:MEAS1:VAlue?\n";
    viPrintf(vi,buf.toLatin1().data());
    status=viScanf(vi,(char*)"%t",stringoutputS);
    QString strS(stringoutputS);
    stringS=strS;
    if (status < VI_SUCCESS)
    {
       qDebug() <<"Error reading a response from the device\n";
    }
    else
    {
        qDebug() <<"Data read:"<<strS;
    }
    char stringoutputE[512];
    buf2="MEASUrement:MEAS2:VAlue?\n";
    viPrintf(vi,buf2.toLatin1().data());
    status=viScanf(vi,(char*)"%t",stringoutputE);
    QString strE(stringoutputE);
    stringE=strE;
    if (status < VI_SUCCESS)
    {
       qDebug() <<"Error reading a response from the device\n";
    }
    else
    {
        qDebug() <<"Data read:"<<strE;
    }

    status = viClose(vi);
    if (status != VI_SUCCESS)
    {
        qDebug() << "Disconnecting failed";
    }
    status = viClose(defaultRM);
     qDebug() << "Disconnecting ";
}

instrument::frequence::frequence()
{

}

instrument::frequence::~frequence()
{

}

void instrument::frequence::changer(QString string)
{
    qDebug() << "Connection to Wafesurfer";
    status = viOpenDefaultRM (& defaultRM);

    if(status!=VI_SUCCESS)
    {
        qDebug() << "Connecting failed";
    }
    //qDebug() << "Setting time out for communication ";

    char IOaddress[]="GPIB0::12::INSTR";
    status = viOpen(defaultRM,IOaddress, VI_NULL, VI_NULL, &vi);
    if (status !=VI_SUCCESS)
    {

        qDebug() << "Connecting " << "failed";
    }

    status = viSetAttribute(vi, VI_ATTR_TMO_VALUE, 500);
    if (status < VI_SUCCESS)
    {

        qDebug() << "Setting time out failed";
    }
      char* stringinput;
    stringinput=string.toLatin1().data();
    status = viWrite(vi,(ViBuf)stringinput,strlen(stringinput),&retCount);
    if (status < VI_SUCCESS)
    {
        qDebug() <<"Error writing to the device\n";
    }
    else
    {
        qDebug() <<"Data WRITE:"<<stringinput;
    }

    status = viClose(vi);
    if (status != VI_SUCCESS)
    {
        qDebug() << "Disconnecting failed";
    }
    status = viClose(defaultRM);
     qDebug() << "Disconnecting ";
}
