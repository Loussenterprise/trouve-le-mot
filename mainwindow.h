#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <home.h>
#include <QString>
#include <eppisode.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showAboutWidget();
    void showHomeWidget();
    void showHelpWidget();
    void showScoresWidget();
    void startSeason();


private:
    Ui::MainWindow *ui;
    Home* home;
    Eppisode* ep;

};
#endif // MAINWINDOW_H
