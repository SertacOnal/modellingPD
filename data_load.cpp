#include "data_load.h"

float windowBufferX,windowBufferY,windowBufferZ;
data_load::data_load()
{


}
int data_load::Load(QString filename,bool left)
{
    lineCounter=0;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))   // If obj file is open, continue
    {
        while(!file.atEnd())   	// Start reading file data
        {
            QString line = file.readLine();
            processLine(line,left);
            lineCounter++;
        }
        file.close();  		// Close OBJ file
        // After Read Convert Acc Data to Displacement
        RsizeofData=RaccXBuffer.size();
        LsizeofData=LaccXBuffer.size();
        acceleration2Displacement(left);

    }
    else
    {
        std::cout << "Unable to open file";
    }
    return 0;
}
void data_load::processLine(QString line,bool left)
{
    if (left) // Left is True
    {
        SamplingRate=100.0f;
        QStringList values = line.split(",");
        if (lineCounter>1)
        {

            // TimeStamp read

             //   LtimeBuffer.append(values.value(0).toFloat()-2000);


                // Acc Read and convert into m/s^2
                float rawAccX=(39.227 * (values.value(2).toFloat() / 32768));
                float rawAccY=(39.227 * (values.value(3).toFloat() / 32768));
                float rawAccZ=(39.227 * (values.value(4).toFloat() / 32768));
                //Quaternions Read
                float q0= (values.value(11).toFloat()); //w
                float q1= (values.value(12).toFloat()); //x
                float q2= (values.value(13).toFloat()); //y
                float q3= (values.value(14).toFloat()); //z
                // Remove Earth G from acc. and add into buffer
                LaccXBuffer.append(rawAccX -(2 * (q1*q3 - q0*q2))*G);
                LaccYBuffer.append(rawAccY -(2 * (q0*q1 - q2*q3))*G);
                LaccZBuffer.append(rawAccZ -(q0*q0 - q1*q1 - q2*q2 + q3*q3)*G);
                //quaternion2Angle
                float angle_rad = acos(q0) * 2;
                LangleBuffer.append(angle_rad * 180 / PI);
                LrotXBuffer.append(q1 / sin(angle_rad/2));
                LrotYBuffer.append(q2 / sin(angle_rad/2));

        }
    }else // Left is false then it is right
    {SamplingRate=100.0f;
        QStringList values = line.split(",");
        if (lineCounter>1)
        {
            // TimeStamp read
//            if ((lineCounter-2)*10==values.value(0).toInt()-2000)
//            {
                RtimeBuffer.append(values.value(0).toFloat()-2000);
                // Acc Read and convert into m/s^2
                float rawAccX=(39.227 * (values.value(2).toFloat() / 32768));
                float rawAccY=(39.227 * (values.value(3).toFloat() / 32768));
                float rawAccZ=(39.227 * (values.value(4).toFloat() / 32768));
                //Quaternions Read
                float q0= (values.value(11).toFloat()); //w
                float q1= (values.value(12).toFloat()); //x
                float q2= (values.value(13).toFloat()); //y
                float q3= (values.value(14).toFloat()); //z
                // Remove Earth G from acc. and add into buffer
                RaccXBuffer.append(rawAccX -(2 * (q1*q3 - q0*q2))*G);
                RaccYBuffer.append(rawAccY -(2 * (q0*q1 - q2*q3))*G);
                RaccZBuffer.append(rawAccZ -(q0*q0 - q1*q1 - q2*q2 + q3*q3)*G);
                //quaternion2Angle
                float angle_rad = acos(q0) * 2;
                RangleBuffer.append(angle_rad * 180 / PI);
                RrotXBuffer.append(q1 / sin(angle_rad/2));
                RrotYBuffer.append(q2 / sin(angle_rad/2));
                RrotZBuffer.append(q3 / sin(angle_rad/2));
//            }else
//            {
//                RtimeBuffer.append((lineCounter-2)*10);
//                RaccXBuffer.append(RaccXBuffer.last());
//                RaccYBuffer.append(RaccYBuffer.last());
//                RaccZBuffer.append(RaccZBuffer.last());
//                RangleBuffer.append(RangleBuffer.last());
//                RrotXBuffer.append(RrotXBuffer.last());
//                RrotYBuffer.append(RrotYBuffer.last());
//                RrotZBuffer.append(RrotZBuffer.last());
//            }
        }
    }


}
void data_load::acceleration2Displacement(bool left)
{
    // Running Average Low Pass Filter
    if (left) //  left is True
    {
        for(int i=0;i<LsizeofData;i++)
        {
            windowBufferX=0.0f;
            windowBufferY=0.0f;
            windowBufferZ=0.0f;

            if (i >= WindowSize)
            {
                for (int k=i;k>=i-WindowSize;k--)
                {
                    windowBufferX+= LaccXBuffer.at(k) / (float) WindowSize;
                    windowBufferY+= LaccYBuffer.at(k) / (float) WindowSize;
                    windowBufferZ+= LaccZBuffer.at(k) / (float) WindowSize;
                }
                LdisXBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferX);
                LdisYBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferY);
                LdisZBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferZ);
            }else
            {
                for(int k=i;k<=WindowSize;k++)
                {
                    windowBufferX+= LaccXBuffer.at(k) / (float) WindowSize;
                    windowBufferY+= LaccYBuffer.at(k) / (float) WindowSize;
                    windowBufferZ+= LaccZBuffer.at(k) / (float) WindowSize;
                }
                for(int k=i-1;k>=0;k--)
                {
                    windowBufferX+= LaccXBuffer.at(k) / (float) WindowSize;
                    windowBufferY+= LaccYBuffer.at(k) / (float) WindowSize;
                    windowBufferZ+= LaccZBuffer.at(k) / (float) WindowSize;
                }

                LdisXBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferX);
                LdisYBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferY);
                LdisZBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferZ);
            }
        }
    }else // left is false then right
    {
        for(int i=0;i<RsizeofData;i++)
        {
            windowBufferX=0.0f;
            windowBufferY=0.0f;
            windowBufferZ=0.0f;

            if (i >= WindowSize)
            {
                for (int k=i;k>=i-WindowSize;k--)
                {
                    windowBufferX+= RaccXBuffer.at(k) / (float) WindowSize;
                    windowBufferY+= RaccYBuffer.at(k) / (float) WindowSize;
                    windowBufferZ+= RaccZBuffer.at(k) / (float) WindowSize;
                }
                RdisXBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferX);
                RdisYBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferY);
                RdisZBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferZ);
            }else
            {
                for(int k=i;k<=WindowSize;k++)
                {
                    windowBufferX+= RaccXBuffer.at(k) / (float) WindowSize;
                    windowBufferY+= RaccYBuffer.at(k) / (float) WindowSize;
                    windowBufferZ+= RaccZBuffer.at(k) / (float) WindowSize;
                }
                for(int k=i-1;k>=0;k--)
                {
                    windowBufferX+= RaccXBuffer.at(k) / (float) WindowSize;
                    windowBufferY+= RaccYBuffer.at(k) / (float) WindowSize;
                    windowBufferZ+= RaccZBuffer.at(k) / (float) WindowSize;
                }

                RdisXBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferX);
                RdisYBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferY);
                RdisZBuffer.append((1/SamplingRate) * (1/SamplingRate) * windowBufferZ);
            }
        }

    }


    if (LsizeofData>RsizeofData)
    {
        sizeofData=LsizeofData;
    }else
    {
        sizeofData=RsizeofData;
    }



}

data_load::~data_load()
{

}

