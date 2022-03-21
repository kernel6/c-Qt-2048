#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPushButton>
#include<QKeyEvent>
#include<ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

void paintEvent(QPaintEvent*);
void keyPressEvent(QKeyEvent*event);
void press_up();
void press_down();
void press_left();
void press_right();

bool is_merge();
int is_empty();
bool is_2048();

void countScore();//统计分数
void creatRandBlock();//创建新的随机位置的随机数方块

bool is_same();//当空方块为0时，看有没有上下左右相邻且相等的方块。



protected slots:
    void gameStarSolt();//槽函数


private:
    Ui::Widget *ui;
    int score = 0;
   //QPainter p;
    int block[4][4];
    QPushButton*starBtn;


    //空方块结构体坐标
    struct nullBlock{
        int posX;
        int posY;
    };
    //结构体数组，存放为0的方块
   struct nullBlock nullBolckArray[15];

};
#endif // WIDGET_H
