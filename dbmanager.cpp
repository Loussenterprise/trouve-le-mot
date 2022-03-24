#include "dbmanager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


Result::Result(QString name,int score)
{
    this->name=name;
    this->score=score;
}

DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database failed";
   }
   else
   {
       QSqlQuery query("CREATE TABLE IF NOT EXISTS 'result' ("
                       "'name'	VARCHAR(100) NOT NULL,"
                       "'score'	INTEGER NOT NULL"
                       ")"
                  );
       query.exec();
      qDebug() << "Database: connection ok";
   }
}


bool DbManager::addResult(Result r)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO result  VALUES (:name, :score)");
   query.bindValue(":name",r.name);
   query.bindValue(":score",r.score);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addResult error:"
                 << query.lastError();
   }

   return success;
}
QList<QList<QString>> DbManager::getResults(){
    QList<QString> noms;
    QList<QString> scores;

    QSqlQuery query("SELECT * FROM result ORDER BY score DESC LIMIT 10");
    int idName = query.record().indexOf("name");
    int idScore = query.record().indexOf("score");
    while (query.next())
    {
        noms.append(query.value(idName).toString());
        scores.append(query.value(idScore).toString());
    }

    QList<QList<QString>> resultat;
    resultat.append(noms);
    resultat.append(scores);
    return resultat;
};
