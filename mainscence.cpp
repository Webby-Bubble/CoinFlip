#include "mainscence.h"
#include "ui_mainscence.h"
#include <QPainter>
#include<QDebug>
#include"mypushbutton.h"
#include<QTimer>
#include<QSound> //多媒体模块下的音效头文件
MainScence::MainScence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScence)
{
    ui->setupUi(this);
    //配置主场景

    //设置固定大小
    setFixedSize(320,588);
    //设置图标（标题 ）
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //准备开始按钮的音效
    QSound *startSound =new QSound(":/res/TapButtonSound.wav",this);
//    startSound->setLoops(-1); //设置循环 如果是-1则无限循环
//    startSound->play();

    //开始按钮
    MyPushButton*startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景
    chooseScence = new ChooseLevelScene;




    //监听返回按钮的信号
    connect(chooseScence,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScence->geometry());
        chooseScence->hide(); //将选择关卡场景隐藏
        this->show(); //重新显示关卡主场景

    });
    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了开始";
        //播放开始音效资源
        startSound->play();

        //做一个弹起的特效
        startBtn->zoom1();
        startBtn->zoom2();

        //进入选择关卡场景中
        //延时进入选择关卡场景中
        QTimer::singleShot(500,this,[=](){
            //设置chooseScene场景的位置
            chooseScence->setGeometry(this->geometry());
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScence->show();
            //进入到选择关卡场景中

        });

    });
}
void MainScence::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/mainBg1.png");
    //painter.drawPixmap(0,0,pix); 下面是拉伸
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画一个背景上的图标
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);


}

MainScence::~MainScence()
{
    delete ui;
}
