#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>

class Result
{
public:
    Result(QString name, int score);
public:
    QString name;
    int score;
};

class DbManager
{
public:
    DbManager(const QString &path);

private:
    QSqlDatabase m_db;

public:
    bool addResult(Result r);
    QList<QList<QString>> getResults();

};


#endif // DBMANAGER_H
