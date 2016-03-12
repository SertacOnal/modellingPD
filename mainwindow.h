#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "base.h"
#include <QMenuBar>
#include <QMenu>
#include <QtWidgets>
#include <QTextEdit>
#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data_load.h"
#include "lcdnumber.h"
#include "qmediaplayer.h"
#include <QMediaPlayer>
#include <QtMultimedia>
#include <qvideowidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void openFileRight();
    void openVideo();
    void Play();
    void Pause();
    void ForwardRelease();
    void ReverseRelease();
    void timelineChange();
    void deactivateControls();
    void activateControls();
    void gotoSec();
    void initialize();
    void uiSetup();
    void radio0Selected();
    void radio1Selected();
    void radio2Selected();
    void radio3Selected();
    void closeEvent(QCloseEvent *event);
    void handleRotation();
    void restRotation();
    void Animate();
private:
    Ui::MainWindow *ui;
    QString fileName;
    QString fileNameVideo;
    data_load dl;
    LCDNumber *number;
    QSlider *timeline;
    QSlider *initRotation;

    int index;
    base* b_right;

    bool resumeStatus;
    int lastIndex;
    bool userInterupt;
    int rightDelay,leftDelay;
    int speedMultiplier;
    QWidget * wdg ;
    QTimer* animationTimer;
    QPushButton *loadRightBtn;
 QPushButton *loadVideo;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QPushButton *forwardBtn;
    QPushButton *reverseBtn;
    QPushButton *restoreRotation;
    QLabel *rotText;
    QLabel *rotValue;
    QLabel *rightText;

    QLabel *rightDelayLabel;
    QLineEdit *RDelayAmount;
    QRadioButton *radio0;
    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;

    QBoxLayout  * mainContainer;
    QBoxLayout * animation_lay;
    QVBoxLayout * rightHand_lay;
    QBoxLayout * leftHand_lay;
    QHBoxLayout * buttons_lay;
    QHBoxLayout * slider_lay;
    QHBoxLayout * rightControl;
    QBoxLayout * bottom_lay;
    QHBoxLayout * speed_lay;
    QBoxLayout * selection_lay;
    QVBoxLayout * rotation_lay;
    QGroupBox * rotGroupBox;
    QGroupBox *groupBox;
    QGroupBox *leftBox;
    QGroupBox *rightBox;
    QVBoxLayout *left1;
    QVBoxLayout *right1;

    //QVideoWidget *videoWidget;
    QMediaPlayer *player;
 //   QVideoWidget *vidWidget;
 //   QWidget *videoContainer;
    //QMediaPlaylist *playlist;
    QVideoWidget *vw;
    QHBoxLayout *vb;

};

#endif // MAINWINDOW_H
