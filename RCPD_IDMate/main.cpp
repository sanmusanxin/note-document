#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString ("RCPD-SP2_IDMate_V1.1***瑞磁科技***SP2 ID匹配"));
    w.setWindowIcon(QIcon(":/new/prefix1/half.png"));
    w.show();
    return a.exec();
}
