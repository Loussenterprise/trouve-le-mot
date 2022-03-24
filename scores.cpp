#include "scores.h"
#include "ui_scores.h"
#include <dbmanager.h>


ResultModel::ResultModel(QObject *parent) : QAbstractTableModel(parent)
{
}
scores::scores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scores)
{
    ui->setupUi(this);

    DbManager dbm("db.sqlite");
    QList<QList<QString>> list = dbm.getResults();
    ResultModel* rm = new ResultModel(this);
    rm->populateData(DbManager("db.sqlite").getResults());
    ui->tableView->setModel(rm);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}

scores::~scores()
{
    delete ui;
}

void ResultModel::populateData(const QList<QList<QString>> &list)
{
    names.clear();
    names = list.at(0);
    scores.clear();
    scores = list.at(1);
}

int ResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return names.length();
}

int ResultModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant ResultModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return names[index.row()];
    } else if (index.column() == 1) {
        return scores[index.row()];
    }
    return QVariant();
}

QVariant ResultModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Name");
        } else if (section == 1) {
            return QString("Score");
        }
    }
    return QVariant();
}

ResultModel::~ResultModel(){}
