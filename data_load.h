#ifndef DATA_LOAD_H
#define DATA_LOAD_H
#include <QFile>
#include <QObject>
 #include <QStringList>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <gl.h>
#include <glu.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <unistd.h>
#define PI 3.14159265
#define G 9.80665
#define WindowSize 10

class data_load
{
public:
    data_load();
    ~data_load();
    int index;
    int sizeofData,LsizeofData,RsizeofData;
    int Load(QString filename,bool left);
    void processLine(QString line,bool left);
    void acceleration2Displacement(bool left);


    QList <float> LtimeBuffer;
    QList <float> RtimeBuffer;

    QList <float> LaccXBuffer;
    QList <float> LaccYBuffer;
    QList <float> LaccZBuffer;
    QList <float> RaccXBuffer;
    QList <float> RaccYBuffer;
    QList <float> RaccZBuffer;

    QList <float> LdisXBuffer;
    QList <float> LdisYBuffer;
    QList <float> LdisZBuffer;
    QList <float> RdisXBuffer;
    QList <float> RdisYBuffer;
    QList <float> RdisZBuffer;

    QList <float> LangleBuffer;
    QList <float> LrotXBuffer;
    QList <float> LrotYBuffer;
    QList <float> LrotZBuffer;
    QList <float> RangleBuffer;
    QList <float> RrotXBuffer;
    QList <float> RrotYBuffer;
    QList <float> RrotZBuffer;

    float angleDegree,rotX,rotY,rotZ,SamplingRate;
    int lineCounter;

private:

};

#endif // DATA_LOAD_H
