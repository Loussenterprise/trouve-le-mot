#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_home.h"
#include "scores.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pause->setDisabled(true);
    ui->pause->setVisible(false);
    showHomeWidget();
    QObject::connect(ui->about, SIGNAL(triggered()), this, SLOT(showAboutWidget()));
    QObject::connect(ui->home, SIGNAL(triggered()), this, SLOT(showHomeWidget()));
    QObject::connect(ui->actionNouvelle_partie, SIGNAL(triggered()), this, SLOT(startSeason()));
    QObject::connect(ui->actionComment_jouer, SIGNAL(triggered()), this, SLOT(showHelpWidget()));
    QObject::connect(ui->actionScores, SIGNAL(triggered()), this, SLOT(showScoresWidget()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAboutWidget(){
    QLabel* about = new QLabel() ;
    about->setText("\n\tProjet de Qt __Trouve le mot__\n\tPar\n"
                   "\tLOUSSIN André (GL) 13367920\n"
                   "\tASSOCLE Bernice (SI) 13871720\n"
                   "\tAZONHOUMON Bernice (GL) 3366420\n"
                   "\tTOKOU Aymar Hugues (SI) 13387120\n"
                   "\tOGOUTOLOU Arafat (GL) 13386320\n"
                   "\tADEOGOUN Adéwalé (SI) 13383920");
    setCentralWidget(about);
}

void MainWindow::showHelpWidget(){
    QLabel* help = new QLabel() ;
    help->setText("\n   Bienvenue dans le jeu Trouve le mot.\n"
                  "   Trouve le mot est un jeu dans lequel le joueur doit trouver \n"
                  "   le mot à n lettres à partir d’une combinaison de 10 lettres qui\n"
                  "   lui seront présentés afin d'avoir les points\n"
                  "   Pour un temps inférieur à 10s le score est de 10pts\n"
                  "   Pour un temps inférieur à 20s le score est de 5pts\n"
                  "   Et pour un temps contraire aux précédents le score est de 2 pts\n"
                  "   Une partie est faite d'une série de 10 et \n"
                  "   le score est enregistré avec le nom du joueur");
    setCentralWidget(help);
}

void MainWindow::showScoresWidget(){
    setCentralWidget(new scores());
}
void MainWindow::showHomeWidget(){
    home = new Home;
    QObject::connect(home->ui->start, SIGNAL(clicked()), this, SLOT(startSeason()));
    QObject::connect(home->ui->help, SIGNAL(clicked()), this, SLOT(showHelpWidget()));
    QObject::connect(home->ui->scores, SIGNAL(clicked()), this, SLOT(showScoresWidget()));
    setCentralWidget(home);
}
void MainWindow::startSeason(){
    ep = new Eppisode;
    QObject::connect(ep, SIGNAL(finished()), this, SLOT(showHomeWidget()));
    setCentralWidget(ep);
}

void connector(){

}
