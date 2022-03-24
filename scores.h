#ifndef SCORES_H
#define SCORES_H

#include <QWidget>
#include <QAbstractTableModel>
#include <QModelIndex>

namespace Ui {
class scores;
}

class scores : public QWidget
{
    Q_OBJECT

public:
    explicit scores(QWidget *parent = nullptr);
    ~scores();

private:
    Ui::scores *ui;
};

class ResultModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ResultModel(QObject *parent = 0);
    ~ResultModel();

    void populateData(const QList<QList<QString>> &List);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> names;
    QList<QString> scores;

};

#endif // SCORES_H
