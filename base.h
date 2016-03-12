    #ifndef BASE_H
#define BASE_H

#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVector>
#include <cmath>
#include <QtGui>
#include <glu.h>
#include <unistd.h>
//
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include "obj_load.h"



class base : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    base(QWidget *parent = 0,bool IsLeft=false);
    ~base();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    float initRot;
public slots:
    void updateAnimation();
   void setOrientation(float angle, float vX, float vY, float vZ);
   void setMovement(float vX, float vY, float vZ);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:
    int frameRate;
    Model_OBJ obj;
    float xRot;
    float yRot;
    float zRot;
    float rotAngle;
    float xMov,yMov,zMov;
    bool left;
    const char* objName;
  GLubyte color[3];

};

#endif // BASE_H
