#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    int levelIndex; //内部成员属性 记录选择的关卡

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    int gameArray[4][4]; //二维数组 维护每个关卡具体数据

    MyCoin * coinBtn[4][4];

    //是否胜利的标志
    bool isWin=false;
signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
