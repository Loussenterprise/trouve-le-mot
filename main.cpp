#include "mainwindow.h"
#include <QPushButton>
#include <QScreen>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(QGuiApplication::screens().at(0)->geometry().center() - w.frameGeometry().center());
    w.show();

    QPushButton b("hello world");
    b.resize(200, 100);
    b.setFont(QFont("Times", 18, QFont::Bold));
    b.adjustSize();
    b.move(QGuiApplication::screens().at(0)->geometry().center() - b.frameGeometry().center());
    //QObject::connect(&b, SIGNAL(clicked()), &a, SLOT(quit()));
//    b.show();

    return a.exec();
}

