#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(QSize(320,480));
    w.setWindowTitle("2048");
    w.show();
    return a.exec();
}
