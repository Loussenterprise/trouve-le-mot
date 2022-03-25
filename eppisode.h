#ifndef EPPISODE_H
#define EPPISODE_H

#include <chrono>
#include <thread>
#include <QWidget>
#include <dbmanager.h>

namespace Ui {
class Eppisode;
}

class Eppisode : public QWidget
{
    Q_OBJECT

public slots:
    void b_1_clicked();
    void b_2_clicked();
    void b_3_clicked();
    void b_4_clicked();
    void b_5_clicked();
    void b_6_clicked();
    void b_7_clicked();
    void b_8_clicked();
    void b_9_clicked();
    void b_10_clicked();
    void del_clicked();
    void continuer();
    void terminer();
    void passer();
    void clear();

signals:
    void finished();

public:
    void levelUp();
    void addchar(QChar c, int index=0);
    QChar delchar();
    void init_buts(Ui::Eppisode* ui);
    bool checkContinuable();


public:
    explicit Eppisode(QWidget *parent = nullptr);
    ~Eppisode();

public:
    Ui::Eppisode *ui;
    QWidget* parent;
    bool playing;
    bool fin=false;
    int point = 0 ;
    int confirmed = 0 ;
    int tail = 10 ;
    int entered = 0 ;
    int level = 1 ;
    int time_count = 0 ;
    int total_time = 0 ;
    QString mot;
    const std::string motList[297]{"ABAISSA", "INFESTERA", "INFIDÈLE", "INFIDÉLITÉ"", ""INFILTRA", "INFILTRAIT", "INFILTRANT", "INFILTRE", "INFILTRÉ", "INFILTRÉE", "INFILTRENT", "INFILTRER", "PRÉFACIEZ", "PRÉFECTURE", "PRÉFÉRA", "PRÉFÉRABLE", "PRÉFÉRAIT", "PRÉFÉRANT", "PRÉFÈRE", "PRÉFÉRÉ", "PRÉFÉRÉE", "PRÉFÉRENCE", "PRÉFÈRENT", "PRÉFÉRER", "PRÉFÉRERA", "PRÉFÉRERAI", "PRÉFÉREREZ", "PRÉFÉREZ", "PRÉFÉRIEZ", "PRÉFET", "PRÉFIGURA", "PRÉFIGURE", "PRÉFIGURÉ", "PRÉFIGURÉE", "PRÉFIGURER", "PRÉFIGUREZ", "PRÉFIXE", "PRÉFIXER", "PRÉFORMER", "PRÉGNANT", "PRÉGNANTE", "PRÉHENSILE", "PRÉHENSION", "PRÉJUDICE", "PRÉJUGE", "PRÉJUGÉ", "PRÉJUGEA", "PRÉJUGEAIT", "PRÉJUGEANT", "PRÉJUGÉE", "PRÉJUGENT", "PRÉJUGER", "PRÉJUGERA", "PRÉJUGERAI", "PRÉJUGEREZ", "PRÉJUGEZ", "PRÉJUGIEZ", "PRÉLASSA", "PRÉLASSAIT", "PRÉLASSANT", "PRÉLASSE", "PRÉLASSÉ", "PRÉLASSÉE", "PRÉLASSENT", "PRÉLASSER", "PRÉLASSERA", "PRÉLASSEZ", "PRÉLASSIEZ", "PRÉLAT", "PRÉLAVAGE", "PRÉLEVA", "PRÉLEVAIT", "PRÉLEVANT", "PRÉLÈVE", "PRÉLEVÉ", "PRÉLEVÉE", "PRÉLÈVENT", "PRÉLEVER", "PRÉLÈVERA", "PRÉLÈVERAI", "PRÉLÈVEREZ", "PRÉLEVEZ", "PRÉLEVIEZ", "PRÉLUDA", "PRÉLUDAIT", "PRÉLUDANT", "PRÉLUDE", "PRÉLUDÉ", "PRÉLUDENT", "PRÉLUDER PRÉMATURÉ", "PRÉMATURÉE", "PRÉMÉDITA", "PRÉMÉDITE", "PRÉMÉDITÉ", "PRÉMÉDITÉE", "PRÉMÉDITER", "PRÉMÉDITEZ", "PREMIER", "PREMIÈRE", "PREMIER-NÉ", "PRÉMISSE", "PRÉMOLAIRE", "PRÉMUNI", "PRÉMUNIE", "PRÉMUNIR", "PRENDRIEZ", "PRENDRONT", "PRENEUR", "PRENEZ", "PRENIEZ", "PRENNE", "PRENNENT", "PRÉNOM", "PRÉNOMMA", "PRÉNOMMAIT", "PRÉNOMMANT", "PRÉNOMME", "PRÉNOMMÉ", "PRÉNOMMÉE", "PRÉNOMMENT", "PRÉNOMMER", "PRÉNOMMERA", "PRÉNUPTIAL", "PRÉOCCUPA", "PRÉOCCUPE", "PRÉOCCUPÉ", "PRÉOCCUPÉE", "PRÉOCCUPER", "PRÉOCCUPEZ", "PRÉPARENT", "PRÉPARER", "PRÉPARERA", "PRÉPARERAI", "PRÉPAREREZ", "PRÉPAREZ", "PRÉPARIEZ", "PRÉPAYER", "PRÉPOSA", "PRÉPOSAIT", "PRÉPOSANT", "PRÉPOSE", "PRÉPOSÉ", "PRÉPOSÉE", "PRÉPOSENT", "PRÉPOSER", "PRÉPOSERA", "PRÉPOSERAI", "PRÉPOSEREZ", "PRÉPOSEZ", "PRÉPOSIEZ", "PRÉPUCE", "PRÉSAGE", "PRÉSAGÉ", "PRÉSAGEA", "PRÉSAGEAIT", "PRÉSAGEANT", "PRÉSAGÉE", "PRÉSAGENT", "PRÉSAGER", "PRÉSAGERA", "PRÉSAGERAI", "PRÉSAGEREZ", "PRÉSAGEZ", "PRÉSAGIEZ", "PRÉ-SALÉ", "PRESBYTE", "PRESBYTÈRE", "PRESBYTIE", "PRESCIENCE", "PRESCRIRA", "PRESCRIRAI", "PRÉSENTÉ", "PRÉSENTÉE", "PRÉSENTENT", "PRÉSENTER", "PRÉSENTERA", "PRÉSENTEZ", "PRÉSENTIEZ", "PRÉSENTOIR", "PRÉSERVA", "PRÉSERVAIT", "PRÉSERVANT", "PRÉSERVE", "PRÉSERVÉ", "PRÉSERVÉE", "PRÉSERVENT", "PRÉSERVER", "PRÉSERVERA", "PRÉSERVEZ", "PRÉSERVIEZ", "PRÉSIDA", "PRÉSIDAIT", "PRÉSIDANT", "PRÉSIDE", "PRÉSIDÉ", "PRÉSIDÉE", "PRÉSIDENCE", "VINDICTE", "VINER", "VINEUSE", "VINEUX", "VINGT", "VINGTAINE", "VINGTIÈME", "VINICOLE", "VINIFIER", "VINRENT", "VINYLE", "VIOLA", "VIOLACÉ", "VIOLACÉE", "VIOLACER", "VIOLAIENT", "VIOLAIT", "VIOLANT", "VIOLATEUR", "VIOLATION", "VIOLATRICE", "VIOLE", "VIOLÉ", "VIOLÉE", "VIOLEMMENT", "VIOLEREZ", "VIOLERIEZ", "VIOLERONT", "VIOLET", "VIOLETER", "VIOLETTE", "VIOLEUR", "VIOLEZ", "VIOLIEZ", "VIOLINE", "VIOLON", "VIOLONER", "VIOLONISTE", "VIPÈRE", "VIRAGE", "VIRAGO", "VIRAIENT", "VOILIER", "VOILURE", "VOIRE", "VOIRIE", "VOISIN", "VOISINA", "VOISINAGE", "VOISINAIT", "VOISINANT", "VOISINE", "VOISINÉ", "VOISINÉE", "VOISINENT", "VOISINER", "VOISINERA", "VOISINERAI", "VOISINEREZ", "VOISINEZ", "VOISINIEZ", "VOITURE", "VOITURER", "VOLAGE", "VOLAIENT", "VOLAILLE", "VOLAILLER", "VOLAILLEUR", "VOLAIT", "VOLANT", "VOLANTE", "VOLATIL", "VOLATILE", "VOLATILISA", "VOLATILISE", "VOLATILISÉ", "VOLCAN", "VOLCANIQUE", "VOLER", "VOLTE-FACE", "VOLTER", "VOLTIGE", "VOULEZ", "VOULOIR", "VOUVOYER", "VOYAGE", "WAGON", "WARRANTER", "YOGOURT", "YOUGOSLAVE", "YOUYOU", "ZÈBRE", "ZÉNITH", "ZESTE", "ZIGOUILLER", "ZIGZAG", "ZIZANIE", "ZODIAQUE", "ZOMBIE", "ZOOLOGIE", "ZOOMER"};
    QChar caracters[10];
    int registereds[10];
    std::thread* t;

};

#endif // EPPISODE_H
