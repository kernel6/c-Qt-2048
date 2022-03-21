#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //随机数函数
    srand((unsigned)time(NULL));
    //初始画方块二维数组
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            block[i][j]=0;
        }
    }


    starBtn=new QPushButton(this);
    starBtn->setText("开始游戏");
    starBtn->setGeometry(60,400,200,50);

    connect(starBtn,&QPushButton::clicked,this, [this](){gameStarSolt();});//！！！注意（）和;关系 ，函数调用（）；
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{

     QPainter p(this);

    p.setFont(QFont("仿宋",20,900,false));
    p.drawText(QPoint(20,60),"分数 "+QString::number(score));



    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {

             p.setPen(Qt::transparent);//透明&画透明方框
            if(block[i][j]==0)
            {

                p.setBrush(Qt::gray);
                p.drawRect(40+60*i,120+60*j,55,55);
            }
            else if(block[i][j]==2)
            {
                p.setBrush(QColor(220,200,182,180));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(2),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==4)
            {
                p.setBrush(QColor(209,219,170,180));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(4),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==8)
            {
                p.setBrush(QColor(245,213,163,192));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(8),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==16)
            {
                p.setBrush(QColor(238,151,151,183));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(16),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==32)
            {
                p.setBrush(QColor(243,149,80,152));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(32),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==64)
            {
                p.setBrush(QColor(234,97,38,128));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(64),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==128)
            {
                p.setBrush(QColor(156,250,187,191));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(128),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==256)
            {
                p.setBrush(QColor(116,159,51,99));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(256),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==512)
            {
                p.setBrush(QColor(203,196,253,211));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(512),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==1024)
            {
                p.setBrush(QColor(60,77,234,138));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(1024),QTextOption(Qt::AlignCenter));
            }
            else if(block[i][j]==2048)
            {
                p.setBrush(QColor(Qt::green));
                p.drawRect(40+60*i,120+60*j,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(40+60*i,120+60*j,55,55),QString::number(2048),QTextOption(Qt::AlignCenter));
            }

        }
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        press_up();
        break;
    case Qt::Key_S:
        press_down();
        break;
    case Qt::Key_A:
        press_left();
        break;
    case Qt::Key_D:
        press_right();
        break;
    default:
        break;
    }
    //产生新方块
    if(is_merge()==true)
    {
       creatRandBlock();
    }

    update();//调用绘图事件！！！！
}

void Widget::press_up()
{
    for(int j=1;j<=3;j++)
    {
        for(int cj=j;cj>=1;cj--)
        {
            for(int i=0;i<=3;i++)
            {
                if(block[i][cj-1]==0)
                {
                    block[i][cj-1]=block[i][cj];
                    block[i][cj]=0;
                }
                else if(block[i][cj-1]==block[i][cj])
                {
                    block[i][cj-1]=block[i][cj]*2;

                    block[i][cj]=0;
                }
            }
        }

    }

}

void Widget::press_down()
{
    for(int j=2;j>=0;j--)
    {
        for(int cj=j;cj<=2;cj++)
        {
            for(int i=0;i<=3;i++)
            {
                if(block[i][cj+1]==0)
                {
                    block[i][cj+1]=block[i][cj];
                    block[i][cj]=0;
                }
                else if(block[i][cj+1]==block[i][cj])
                {
                    block[i][cj+1]=block[i][cj]*2;

                    block[i][cj]=0;
                }
            }
        }

    }


}

void Widget::press_left()
{
    for(int j=1;j<=3;j++)
    {
        for(int cj=j;cj>=1;cj--)
        {
            for(int i=0;i<=3;i++)
            {
                if(block[cj-1][i]==0)
                {
                    block[cj-1][i]=block[cj][i];
                    block[cj][i]=0;
                }
                else if(block[cj-1][i]==block[cj][i])
                {
                    block[cj-1][i]=block[cj][i]*2;

                    block[cj][i]=0;
                }
            }
        }

    }

}

void Widget::press_right()
{
    for(int j=2;j>=0;j--)
    {
        for(int cj=j;cj<=2;cj++)
        {
            for(int i=0;i<=3;i++)
            {
                if(block[cj+1][i]==0)
                {
                    block[cj+1][i]=block[cj][i];
                    block[cj][i]=0;
                }
                else if(block[cj+1][i]==block[cj][i])
                {
                    block[cj+1][i]=block[cj][i]*2;

                    block[cj][i]=0;
                }
            }
        }

    }


}

bool Widget::is_merge()
{

    if(is_empty()==0&&is_same()==false)
    {

        QMessageBox::information(this,"提示","很遗憾，游戏失败");
        return false;
    }
    else if(is_2048()==true)
    {
        return  false;

    }
    else
    {
        return true;
    }

}

int Widget::is_empty()
{


    int count=0;
    int a=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==0)
            {
                 count++;


                nullBolckArray[a]={nullBolckArray->posX=i,nullBolckArray->posY=j};
                a++;

            }
        }
    }

    return count;
}

bool Widget::is_2048()
{
    int num_2048=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==2048)
            {
               num_2048++;
                QMessageBox::information(this,"提示","恭喜你，游戏胜利");
            }

        }
    }

    if(num_2048>0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Widget::countScore()
{
    score=0;//赋值为0.重新计算;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            score+=block[j][i];
        }
    }
}

void Widget::creatRandBlock()
{

    int temp1=rand()%3;
    int temp2=rand()%3;
    int num1=temp1==2?4:2;
    int num2=temp2==2?4:2;

    //空方块大于等于2个 每次随机两个方块
    if(is_merge()==true&&is_empty()>1)
    {


        int tempnum1=rand()%is_empty();

        int tempnum2=rand()%is_empty();
        while(tempnum1==tempnum2)
        {
             tempnum2=rand()%is_empty();
        }

        block[nullBolckArray[tempnum1].posX][nullBolckArray[tempnum1].posY]=num1;
        block[nullBolckArray[tempnum2].posX][nullBolckArray[tempnum2].posY]=num2;
        countScore();
    }
    //空方块等于1个 只能随机一个
    else if(is_merge()==true&&is_empty()==1)
    {
        int tempnum1=rand()%is_empty();

        block[nullBolckArray[tempnum1].posX][nullBolckArray[tempnum1].posY]=num1;
        countScore();
    }
}

bool Widget::is_same()
{
    //遍历数组，如果相同的数有0个，return false
    int sameNum=0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(block[i][j]==block[i][j+1])
            {
                sameNum++;
            }      
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==block[i+1][j])
            {
                sameNum++;
            }
        }
    }
    if(sameNum==0)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void Widget::gameStarSolt()
{
    score=0;//每次开始前分数为0；
    srand((unsigned int)time(NULL));
    starBtn->setText("重新开始");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            block[i][j]=0;
        }
    }


        creatRandBlock();
        update();
}
