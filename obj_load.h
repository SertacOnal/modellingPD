#ifndef OBJ_LOAD_H
#define OBJ_LOAD_H

#include <QObject>
#include <QFile>
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

#define KEY_ESCAPE 27
#define KEY_LEFT 65

#define POINTS_PER_VERTEX 3
#define TOTAL_FLOATS_IN_TRIANGLE 9

/************************************************************************
  Window
 ************************************************************************/

class Model_OBJ : public QObject
{
    Q_OBJECT

public:
    Model_OBJ();
    ~Model_OBJ();
    float* calculateNormal(float* coord1,float* coord2,float* coord3 );
    int Load(const char *filename);	// Loads the model
    void Draw();					// Draws the model on the screen
    void Release();				// Release the model

private:
    float* normals;							// Stores the normals
    float* Faces_Triangles;					// Stores the triangles
    float* vertexBuffer;					// Stores the points which make the object
    long TotalConnectedPoints;				// Stores the total number of connected verteces
    long TotalConnectedTriangles;			// Stores the total number of connected triangles

};

#endif //OBJ_LOAD_H
