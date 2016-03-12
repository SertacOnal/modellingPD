#include "base.h"

base::base(QWidget *parent,bool Isleft) : QOpenGLWidget(parent) {



    xRot=0.0f;
    yRot=0.0f;
    zRot=0.0f;
    xMov=0.0f;
    yMov=0.0f;
    zMov=0.0f;
    rotAngle = 0.0f;
    initRot=0.0f;

    left=Isleft;
    QTimer* scenetimer = new QTimer(this);
    connect(scenetimer, SIGNAL(timeout()), this,
            SLOT(updateAnimation()));
     scenetimer->start(34); // 30 Hz animation
}

// OpenGL related initializations
void base::initializeGL() {
  initializeOpenGLFunctions();



    glClearColor(218,218,218,1);
  //glClearColor(0,0,0,1);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    setAutoFillBackground(false);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_LIGHTING);

    // Create light components
    GLfloat ambientLight[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    GLfloat diffuseLight[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat specularLight[] = { 0.7f, 0.7f, 0.3f, 1.0f };
    GLfloat position[] = { 3.0f, 2.0f, 4.0f, 1.0f };

    // Assign created components to GL_LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

   //glColor4f(3.0f, 3.0f, 3.0f, 2.0f);
   //glColor3dv(239.0,208.0,207.0);
   color[0] = 243.0; color[1] = 160.0; color[2] = 120.0;
//glColor3f(1.0f,0.0f,0.0f);
    //glColor3ub(color);
    glColor3ubv(color);





   if (left)
    {
    objName = ":/Left_Hand.obj";
    }else
    {
    objName = ":/Right_Hand.obj";
    }
    obj.Load(objName);
 //   glDisable(GL_LIGHTING);
 //   glDisable(GL_DEPTH_TEST);
}

// called for each frame
void base::paintGL() {

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


     glLoadIdentity();
    // adjust camera
    glTranslatef(0.0f, 0.0f, -7.0f);
       // glRotatef(180,1,0,0);
       // glRotatef(180,0,0,1);
    glRotatef(180,0,0,1);
    glRotatef(initRot-90,0,1,0);

    // NEW ONE Sensor is below of hand
    glRotatef(rotAngle, xRot,-1*zRot,yRot);

    glTranslatef(xMov,-1*zMov,yMov);




    // OLD ONE Sensor is above of hand
    //glRotatef(rotAngle, -1*xRot, zRot, yRot);
    //glTranslatef(-1*xMov,zMov,yMov);

       obj.Draw();

       glDisable(GL_DEPTH_TEST);
}

void base::updateAnimation() {
    update();
}

void base::setOrientation(float angle, float vX, float vY, float vZ) {
    rotAngle = angle;
    xRot = vX;
    yRot = vY;
    zRot = vZ;
}

void base::setMovement(float vmX, float vmY, float vmZ) {
    // 1000 is to scale m to mm
    xMov = vmX*1000;
    yMov = vmY*1000;
    zMov = vmZ*1000;
}


QSize base::minimumSizeHint() const {
    return QSize(50, 50);
}

// initial size
QSize base::sizeHint() const {
    return QSize(300, 300);
}

void base::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (((float)width)/height), 1, 100);
    glMatrixMode(GL_MODELVIEW);
}


base::~base()
{

}

