#include "resultat.h"
#include "ui_resultat.h"

Resultat::Resultat(QWidget *parent,int time_count,int score) :
    QDialog(parent),
    ui(new Ui::Resultat)
{
//    ui->setupUi(this);
//    ui->score->setText(QString().setNum(score));
//    ui->time_count->setText(QString().setNum(time_count));
}

Resultat::~Resultat()
{
    delete ui;
}



void Resultat::okClicked(){
    accepted=true;
}

void Resultat::cancelClicked(){

}
