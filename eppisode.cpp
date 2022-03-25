#include "eppisode.h"
#include "ui_eppisode.h"
#include <QRandomGenerator>
#include <QInputDialog>
#include <QDebug>

Eppisode::Eppisode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Eppisode)
{
    this->parent = parent;
    ui->setupUi(this);

    QObject::connect(ui->b_1, SIGNAL(clicked()), this, SLOT(b_1_clicked()));
    QObject::connect(ui->b_2, SIGNAL(clicked()), this, SLOT(b_2_clicked()));
    QObject::connect(ui->b_3, SIGNAL(clicked()), this, SLOT(b_3_clicked()));
    QObject::connect(ui->b_4, SIGNAL(clicked()), this, SLOT(b_4_clicked()));
    QObject::connect(ui->b_5, SIGNAL(clicked()), this, SLOT(b_5_clicked()));
    QObject::connect(ui->b_6, SIGNAL(clicked()), this, SLOT(b_6_clicked()));
    QObject::connect(ui->b_7, SIGNAL(clicked()), this, SLOT(b_7_clicked()));
    QObject::connect(ui->b_8, SIGNAL(clicked()), this, SLOT(b_8_clicked()));
    QObject::connect(ui->b_9, SIGNAL(clicked()), this, SLOT(b_9_clicked()));
    QObject::connect(ui->b_10, SIGNAL(clicked()), this, SLOT(b_10_clicked()));
    QObject::connect(ui->del, SIGNAL(clicked()), this, SLOT(del_clicked()));
    QObject::connect(ui->continuer, SIGNAL(clicked()), this, SLOT(continuer()));
    QObject::connect(ui->passer, SIGNAL(clicked()), this, SLOT(passer()));
    QObject::connect(ui->clear, SIGNAL(clicked()), this, SLOT(clear()));

    init_buts(ui);

    t = new std::thread([](Eppisode* param){
        while (!param->fin) {
            if (param->playing) {
                sleep(1);
                param->time_count++;
                param->ui->time_count->setText(QString().setNum(param->time_count));
            }
            param->total_time++;
        }
    },this);
    t->detach();

}


void Eppisode::init_buts(Ui::Eppisode* ui){
    mot = QString::fromStdString(motList[QRandomGenerator::global()->generate() % 297]);
    qDebug()<<mot;
    tail=mot.length();
    entered=0;
    time_count=0;
    confirmed=0;

    for (int i=0;i<tail ;i++ ) {
        caracters[i] = mot.at(i);
    }
    for (int i=tail;i<10 ;i++ ) {
        caracters[i] = QChar((QRandomGenerator::global()->generate() % 26) + 65);
    }




    for(int position=9; position>=1; position--){

        //hasard reçoit un nombre entier aléatoire entre 0 et position
        int hasard=QRandomGenerator::global()->generate() % position+1;

        //Echange
        QChar sauve=caracters[position];
        caracters[position]=caracters[hasard];
        caracters[hasard]=sauve;

    }


    ui->b_1->setDisabled(false);
    ui->b_2->setDisabled(false);
    ui->b_3->setDisabled(false);
    ui->b_4->setDisabled(false);
    ui->b_5->setDisabled(false);
    ui->b_6->setDisabled(false);
    ui->b_7->setDisabled(false);
    ui->b_8->setDisabled(false);
    ui->b_9->setDisabled(false);
    ui->b_10->setDisabled(false);

    ui->b_1->setText(caracters[0]);
    ui->b_2->setText(caracters[1]);
    ui->b_3->setText(caracters[2]);
    ui->b_4->setText(caracters[3]);
    ui->b_5->setText(caracters[4]);
    ui->b_6->setText(caracters[5]);
    ui->b_7->setText(caracters[6]);
    ui->b_8->setText(caracters[7]);
    ui->b_9->setText(caracters[8]);
    ui->b_10->setText(caracters[9]);


    ui->er->setVisible(false);

    ui->rst->setText(QString().setNum(tail));
    ui->point->setText(QString().setNum(point));
    ui->entree->setText(QString());
    ui->level->setText(QString().setNum(level));
    ui->time_count->setText(QString().setNum(time_count));
    ui->taille->setText(QString().setNum(tail));
    ui->continuer->setDisabled(!checkContinuable());


    playing=true;

}

Eppisode::~Eppisode()
{
    playing=false;
    fin=true;
    qDebug() << "is thread t joinable" <<t->joinable();
    sleep(1);
    qDebug() << "is thread t always joinable" <<t->joinable();
    delete ui;
}


void Eppisode::b_1_clicked(){
    ui->b_1->setDisabled(true);
    addchar(caracters[0],1);
};
void Eppisode::b_2_clicked(){
    ui->b_2->setDisabled(true);
    addchar(caracters[1],2);
};
void Eppisode::b_3_clicked(){
    ui->b_3->setDisabled(true);
    addchar(caracters[2],3);
};
void Eppisode::b_4_clicked(){
    ui->b_4->setDisabled(true);
    addchar(caracters[3],4);
};
void Eppisode::b_5_clicked(){
    ui->b_5->setDisabled(true);
    addchar(caracters[4],5);
};
void Eppisode::b_6_clicked(){
    ui->b_6->setDisabled(true);
    addchar(caracters[5],6);
};
void Eppisode::b_7_clicked(){
    ui->b_7->setDisabled(true);
    addchar(caracters[6],7);
};
void Eppisode::b_8_clicked(){
    ui->b_8->setDisabled(true);
    addchar(caracters[7],8);
};
void Eppisode::b_9_clicked(){
    ui->b_9->setDisabled(true);
    addchar(caracters[8],9);
};
void Eppisode::b_10_clicked(){
    ui->b_10->setDisabled(true);
    addchar(caracters[9],10);
};
void Eppisode::del_clicked(){
    delchar();
};


/**
 * @brief Eppisode::continuer
 *  Continue apres avoir valide le mot
 */
void Eppisode::continuer(){
    if(mot==ui->entree->text()){
        // STOP COUNTDOWN TREAD
        playing=false;

        if(time_count<=10){
            point+=10;
        }else if (time_count<=20) {
            point+=5;
        }else{
            point+=2;
        }

        if(level==10){
            terminer();
        }else{
            level++;
            if(level==10){
                ui->continuer->setText("Terminer");
            }
            if(level>10){
                ui->continuer->setVisible(false);
                ui->passer->setVisible(false);
            }
            confirmed++;
            init_buts(ui);
        }


    }else{
        ui->er->setVisible(true);
        ui->continuer->setDisabled(true);
    }

};

/**
 * @brief Eppisode::terminer
 *  Termine le jeu
 */
void Eppisode::terminer(){
    qDebug() << "terminer";
    ui->continuer->setVisible(false);
    ui->passer->setVisible(false);
    QString t("Vous avez gagné %1 points après %2 s\nVeillez entrer votre nom :");
    bool ok;
    QString name = QInputDialog::getText(this, tr("Sauvegarder votre score"),
                                        QString("Vous avez gagné %1 points après %2 s\n"
                                                "Veillez entrer votre nom pour le sauvegardement:").
                                        arg(point).arg(total_time),
                                        QLineEdit::Normal,
                                        QString(),
                                        &ok);
    if (ok && !name.isEmpty()){
       Result r(name,point);
       DbManager dbm("db.sqlite");
       dbm.addResult(r);
    }
    emit finished();
};
void Eppisode::clear(){
    ui->entree->setText(QString());
    entered=0;
    ui->b_1->setDisabled(false);
    ui->b_2->setDisabled(false);
    ui->b_3->setDisabled(false);
    ui->b_4->setDisabled(false);
    ui->b_5->setDisabled(false);
    ui->b_6->setDisabled(false);
    ui->b_7->setDisabled(false);
    ui->b_8->setDisabled(false);
    ui->b_9->setDisabled(false);
    ui->b_10->setDisabled(false);
    ui->rst->setText(QString().setNum(tail));
};

/**
 * @brief Eppisode::passer
 *  Passe au tour suivant sans valider le mot
 */
void Eppisode::passer(){
    playing=false;
    if(level==10){
        terminer();
    }else{
        level++;
        if(level==10){
            ui->continuer->setText("Terminer");
        }
        init_buts(ui);
    }
};
void Eppisode::addchar(QChar c,int index){
    ui->er->setVisible(false);
    ui->entree->setText(ui->entree->text()+c);
    registereds[entered]=index;
    ++entered;
    ui->rst->setText(QString().setNum(tail-entered));
    ui->continuer->setDisabled(!checkContinuable());
};
QChar Eppisode::delchar(){
    ui->er->setVisible(false);
    QChar c;
    if(ui->entree->text().size() > 0){
        c = ui->entree->text().at(ui->entree->text().size() - 1);
        ui->entree->setText(ui->entree->text().left(ui->entree->text().size()-1));
        int i = registereds[entered-1];
        --entered;
        switch (i) {
            case 1:
                ui->b_1->setDisabled(false);
                break;
            case 2:
                ui->b_2->setDisabled(false);
                break;
            case 3:
                ui->b_3->setDisabled(false);
                break;
            case 4:
                ui->b_4->setDisabled(false);
                break;
            case 5:
                ui->b_5->setDisabled(false);
                break;
            case 6:
                ui->b_6->setDisabled(false);
                break;
            case 7:
                ui->b_7->setDisabled(false);
                break;
            case 8:
                ui->b_8->setDisabled(false);
                break;
            case 9:
                ui->b_9->setDisabled(false);
                break;
            case 10:
                ui->b_10->setDisabled(false);
                break;
        }
        ui->rst->setText(QString().setNum(tail-entered));
    }

    ui->continuer->setDisabled(!checkContinuable());
    return c;
};


bool Eppisode::checkContinuable(){
    return tail-entered == 0;
}

