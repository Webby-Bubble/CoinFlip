#ifndef MAINSCENCE_H
#define MAINSCENCE_H
#include"ChooseLevelScene.h"
#include <QMainWindow>

namespace Ui {
class MainScence;
}

class MainScence : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScence(QWidget *parent = 0);
    ~MainScence();
    //重新paintEvent事件 画背景
    void paintEvent(QPaintEvent *);
    ChooseLevelScene *chooseScence = NULL;
private:
    Ui::MainScence *ui;
};

#endif // MAINSCENCE_H
