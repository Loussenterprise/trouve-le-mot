#ifndef RESULTAT_H
#define RESULTAT_H

#include <QDialog>

namespace Ui {
class Resultat;
}

class Resultat : public QDialog
{
    Q_OBJECT

public:
    explicit Resultat(QWidget *parent = nullptr,int time_count=0,int score=0);
    ~Resultat();

public slots:
    void okClicked();
    void cancelClicked();

private:
    Ui::Resultat *ui;
    bool accepted=false;
};

#endif // RESULTAT_H
