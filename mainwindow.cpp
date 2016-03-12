#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PD - Hand Visualization");
    initialize();
    uiSetup();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"Handmodeller",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {


        index=dl.sizeofData;
        qApp->quit();
        event->accept();
    }
}
void MainWindow::uiSetup()
{
    number->setSegmentStyle(QLCDNumber::Flat);
    number->setFixedSize(100, 40);
    rightText->setAlignment(Qt::AlignCenter);
    rightText->setMaximumHeight(30);
    rightDelayLabel->setMaximumSize(QSize(68,20));
    RDelayAmount->setMaximumSize(QSize(30,20));



    vw = new QVideoWidget();



    vb=new QHBoxLayout(wdg);
    vb->insertLayout(0,mainContainer);
    vb->insertLayout(1,leftHand_lay);
    // Animation Container
    mainContainer->insertLayout(0,animation_lay);
    // animation_lay->insertLayout(0,leftHand_lay);
    animation_lay->insertLayout(1,rightHand_lay);

    leftHand_lay->addWidget(vw);



    vw->setMinimumSize(0,0);
    vw->setMaximumSize(0,0);


    rightHand_lay->addWidget(rightText);
    right1->addWidget(b_right);
    rightBox->setLayout(right1);
    rightHand_lay->addWidget(rightBox);
    rightHand_lay->setAlignment(Qt::AlignCenter);
    rightBox->setStyleSheet("padding:-8px;");

    rightHand_lay->insertLayout(2,rightControl);
    rightControl->addWidget(rightDelayLabel);
    rightControl->addWidget(RDelayAmount);
    rightControl->addWidget(loadRightBtn);
    rightControl->addWidget(loadVideo);
    // Slider Container
    mainContainer->insertLayout(2,slider_lay);

    slider_lay->addWidget(timeline);
    slider_lay->addWidget(number);

    // Bottom Container
    mainContainer->insertLayout(4,bottom_lay);

    bottom_lay->insertLayout(0,speed_lay);


    // Rotation Lay
    rotation_lay->addWidget(initRotation);
    rotation_lay->addWidget(restoreRotation);
    rotGroupBox->setLayout(rotation_lay);
    rotGroupBox->setMaximumSize(QSize(170,95));
    rotGroupBox->setMinimumSize(QSize(170,95));
    speed_lay->addWidget(rotGroupBox);
    // Selection of speed
    selection_lay->addWidget(radio0);
    selection_lay->addWidget(radio1);
    selection_lay->addWidget(radio2);
    selection_lay->addWidget(radio3);
    selection_lay->addStretch(1);
    groupBox->setLayout(selection_lay);
    groupBox->setMinimumSize(QSize(200,95));
    groupBox->setMaximumSize(QSize(200,95));
    speed_lay->addWidget(groupBox);

    // Buttons
    bottom_lay->insertLayout(1,buttons_lay);
    buttons_lay->setAlignment(Qt::AlignRight);


    playBtn->setMinimumSize(65,80);
    playBtn->setMaximumSize(65,80);
    pauseBtn->setMinimumSize(65,80);
    pauseBtn->setMaximumSize(65,80);
    reverseBtn->setMinimumSize(65,80);
    reverseBtn->setMaximumSize(65,80);
    forwardBtn->setMinimumSize(65,80);
    forwardBtn->setMaximumSize(65,80);


    buttons_lay->addWidget(playBtn);
    buttons_lay->addWidget(pauseBtn);
    buttons_lay->addWidget(reverseBtn);
    buttons_lay->addWidget(forwardBtn);

    this->setCentralWidget(wdg);

    this->setMinimumSize(QSize(700,600));

}
void MainWindow::initialize()
{

    lastIndex=0;
    dl.LsizeofData=0;
    dl.RsizeofData=0;
    speedMultiplier=1;

    player = new QMediaPlayer;


    timeline =new QSlider(Qt::Horizontal, this);
    // timeline->setTickPosition(QSlider::TicksBelow);
    initRotation=new QSlider(Qt::Horizontal,this);
    initRotation->setTickPosition(QSlider::TicksBelow);
    initRotation->setTickInterval(60);
    initRotation->setRange(-180,180);
    initRotation->setValue(0);
    animationTimer = new QTimer();
    b_right = new base(this,false);

    wdg = new QWidget(this);
    number=new LCDNumber(this,0,0,0);

    restoreRotation=new QPushButton("Restore Rotation");
    mainContainer = new QBoxLayout(QBoxLayout::TopToBottom);
    animation_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    rotation_lay=new QVBoxLayout();
    left1=new QVBoxLayout();
    right1=new QVBoxLayout();
    rightHand_lay = new QVBoxLayout();
    leftHand_lay = new QBoxLayout(QBoxLayout::TopToBottom);

    rightControl=new QHBoxLayout();
    buttons_lay= new QHBoxLayout();
    slider_lay = new QHBoxLayout();
    bottom_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    speed_lay = new QHBoxLayout();
    selection_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    groupBox = new QGroupBox(tr("Speed Slower Multiplier"));
    rotGroupBox = new QGroupBox(tr("Rotation of Hand 0 Degree"));
    leftBox = new QGroupBox();
    rightBox = new QGroupBox();


    radio0 = new QRadioButton(tr("x1"));
    radio0->setAutoExclusive(false);
    radio1 = new QRadioButton(tr("x2"));
    radio1->setAutoExclusive(false);
    radio2 = new QRadioButton(tr("x4"));
    radio2->setAutoExclusive(false);
    radio3 = new QRadioButton(tr("x8"));
    radio3->setAutoExclusive(false);
    radio0->setChecked(true);
    radio1->setChecked(false);
    radio2->setChecked(false);
    radio3->setChecked(false);

    rotText= new QLabel("Rotation of Hand");
    rotValue= new QLabel("0");

    rightText= new QLabel("<p>Hand - <FONT COLOR='#8A0808' FONT SIZE = 3>No Data</p>");

    loadRightBtn = new QPushButton("Load Hand Data");
    rightDelayLabel=new QLabel("Delay (sec)");


    playBtn = new QPushButton("Play");
    pauseBtn = new QPushButton("Pause");
    forwardBtn = new QPushButton(">>");
    reverseBtn = new QPushButton("<<");
    RDelayAmount= new QLineEdit("0");
    loadVideo=new QPushButton("Load Video");



    connect(animationTimer,SIGNAL(timeout()),this,SLOT(Animate()));
    connect(timeline, SIGNAL(valueChanged(int)),this, SLOT(timelineChange()));
    connect(timeline, SIGNAL(sliderReleased()),this, SLOT(gotoSec()));
    connect(timeline, SIGNAL(sliderPressed()),this, SLOT(Pause()));
    connect(loadRightBtn, SIGNAL(released()), this, SLOT(openFileRight()));
    connect(loadVideo,SIGNAL(released()), this, SLOT(openVideo()));
    connect(playBtn, SIGNAL(released()), this, SLOT(Play()));
    connect(pauseBtn, SIGNAL(released()), this, SLOT(Pause()));
    connect(restoreRotation, SIGNAL(pressed()), this, SLOT(restRotation()));
    connect(forwardBtn, SIGNAL(pressed()), this, SLOT(Pause()));
    connect(forwardBtn, SIGNAL(pressed()), this, SLOT(Pause()));
    connect(forwardBtn, SIGNAL(released()), this, SLOT(ForwardRelease()));
    connect(reverseBtn, SIGNAL(released()), this, SLOT(ReverseRelease()));
    connect(radio0,SIGNAL(clicked(bool)),this,SLOT(radio0Selected()));
    connect(radio1,SIGNAL(clicked(bool)),this,SLOT(radio1Selected()));
    connect(radio2,SIGNAL(clicked(bool)),this,SLOT(radio2Selected()));
    connect(radio3,SIGNAL(clicked(bool)),this,SLOT(radio3Selected()));
    connect(initRotation, SIGNAL(valueChanged(int)),this, SLOT(handleRotation()));


    deactivateControls();
}

void MainWindow::deactivateControls()
{
    timeline->setEnabled(0);
    playBtn->setEnabled(0);
    pauseBtn->setEnabled(0);
    forwardBtn->setEnabled(0);
    reverseBtn->setEnabled(0);
    radio0->setEnabled(0);
    radio1->setEnabled(0);
    radio2->setEnabled(0);
    radio3->setEnabled(0);
    RDelayAmount->setEnabled(0);

    initRotation->setEnabled(0);
    restoreRotation->setEnabled(0);

}
void MainWindow::activateControls()
{
    timeline->setEnabled(1);
    playBtn->setEnabled(1);
    pauseBtn->setEnabled(1);
    forwardBtn->setEnabled(1);
    reverseBtn->setEnabled(1);
    radio0->setEnabled(1);
    radio1->setEnabled(1);
    radio2->setEnabled(1);
    radio3->setEnabled(1);
    initRotation->setEnabled(1);
    restoreRotation->setEnabled(1);
}

void MainWindow::handleRotation()
{
    int rott=initRotation->value();
    if (dl.RsizeofData>0)
    {
        b_right->initRot=rott;
    }
    if (dl.LsizeofData>0)
    {
        //b_left->initRot=rott;
    }
    rotGroupBox->setTitle("Rotation of Hand "+QString::number(rott)+" Degree");
}
void MainWindow::restRotation()
{
    initRotation->setValue(0);

    b_right->initRot=0;
    //b_left->initRot=0;
    rotGroupBox->setTitle("Rotation of Hand ("+QString::number(0)+" Degree)");
}

void MainWindow::openFileRight()
{
    QFileDialog openDialog(this, tr("Load File"),
                           "",
                           tr("Files (*.*)"));

    fileName=openDialog.getOpenFileName();
    if (fileName!=NULL)
    {
        dl.Load(fileName,false);
        timeline->setRange(0,dl.sizeofData/dl.SamplingRate);
        rightText->setText("<p>Right Hand - <FONT COLOR='#21610B' FONT SIZE = 3>Ready</p>");
        activateControls();
        RDelayAmount->setEnabled(1);
    }
}
void MainWindow::openVideo()
{
    QFileDialog openDialog(this, tr("Load Video"),
                           "",
                           tr("Files (*.*)"));

    fileNameVideo=openDialog.getOpenFileName();
    if (fileNameVideo!=NULL)
    {
        vw->setMinimumSize(540,540);
        vw->setMaximumSize(540,540);
        this->setMinimumSize(QSize(1240,600));
        player->setMedia(QUrl::fromLocalFile(fileNameVideo));
        player->setVideoOutput(vw);
    }
}
void MainWindow::timelineChange()
{
    int timelineVal=timeline->value();
    if (resumeStatus==false)
    {
        QDateTime time=QDateTime::fromTime_t(timelineVal).toUTC();
        number->timeValue->setHMS(time.time().hour(),time.time().minute(),time.time().second());
        number->display(number->timeValue->toString());
    }
}
void MainWindow::gotoSec()
{
    lastIndex=timeline->value()*dl.SamplingRate;
    Play();
}
void MainWindow::radio0Selected()
{
    Pause();
    radio0->setChecked(true);
    radio1->setChecked(false);
    radio2->setChecked(false);
    radio3->setChecked(false);
    speedMultiplier=1;
    lastIndex=index;
    Play();
}
void MainWindow::radio1Selected()
{
    Pause();
    radio0->setChecked(false);
    radio1->setChecked(true);
    radio2->setChecked(false);
    radio3->setChecked(false);
    speedMultiplier=2;
    lastIndex=index;
    Play();
}
void MainWindow::radio2Selected()
{
    Pause();
    radio0->setChecked(false);
    radio1->setChecked(false);
    radio2->setChecked(true);
    radio3->setChecked(false);
    speedMultiplier=4;
    lastIndex=index;
    Play();
}
void MainWindow::radio3Selected()
{
    Pause();
    radio0->setChecked(false);
    radio1->setChecked(false);
    radio2->setChecked(false);
    radio3->setChecked(true);
    speedMultiplier=8;
    lastIndex=index;
    Play();
}

void MainWindow::Animate()
{
    if(index<dl.sizeofData)
    {
       // if(index*10==dl.RtimeBuffer.at(index))
       // {
            // Mainwindow LED Time increase
            QDateTime time=QDateTime::fromTime_t(index/dl.SamplingRate).toUTC();
            number->timeValue->setHMS(time.time().hour(),time.time().minute(),time.time().second());

            // Dirty Trick

            if((time.time().minute()==1)&&(time.time().second()==10))
            {
                // RDelayAmount->setText("120.0");
            }

            number->display(number->timeValue->toString());
            // Timeline Handle
            timeline->setValue((int) (index/dl.SamplingRate));
            // Consider Delays if any
            rightDelay=(int)((RDelayAmount->text().toFloat())*dl.SamplingRate);
            // Right Hand run
            if ((dl.RsizeofData>0) && (dl.RsizeofData>(index+rightDelay)))
            {
                b_right->setOrientation(dl.RangleBuffer.at(index+rightDelay), dl.RrotXBuffer.at(index+rightDelay), dl.RrotYBuffer.at(index+rightDelay), dl.RrotZBuffer.at(index+rightDelay));
                b_right->setMovement(dl.RdisXBuffer.at(index+rightDelay),dl.RdisYBuffer.at(index+rightDelay),dl.RdisZBuffer.at(index+rightDelay));
            }
          index++;
        //}





    }

}


void MainWindow::Play()
{
    playBtn->setEnabled(0);

    if(fileName!=NULL)
    {
        index=lastIndex;
        resumeStatus=true;
        // 1000 is 1 sec (1 sec=1000msec) and it must recalled every data
        // in our case data is taken 100 per sec.
        animationTimer->start(speedMultiplier*(1000/dl.SamplingRate));


        //videoWidget->show();
        //playlist->setCurrentIndex(1);

        if (fileNameVideo!=NULL)
        {
            if (player->duration()<=0)
            {
                player->play();
                player->setVideoOutput(vw);
            }else
            {
                player->play();
            }

        }
        qApp->processEvents();
    }



}
void MainWindow::Pause()
{
    playBtn->setEnabled(1);
    animationTimer->stop();
    if (fileNameVideo!=NULL)
    {
        player->pause();
    }
    lastIndex=index;
    resumeStatus=false;
}
void MainWindow::ForwardRelease()
{
    Pause();
    lastIndex=lastIndex+dl.SamplingRate;

    Play();
}
void MainWindow::ReverseRelease()
{
    Pause();
    lastIndex=lastIndex-dl.SamplingRate;

    Play();
}

