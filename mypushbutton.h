#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explict 防止隐式类型转换
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造函数 参数1 正常显示的图片路径 参数2 按下后显示的图片路径
    MyPushButton(QString normalImg,QString pressImg="");
    //成员属性 保护用户传入的默认显示路径 以及按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1(); //向下跳
    void zoom2(); //向下跳

    //重写按钮 按下 和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
