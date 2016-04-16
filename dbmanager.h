#ifndef DBMANAGER
#define DBMANAGER

#include<vector>
#include<QSqlDatabase>
#include "unit.h"
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSql>
#include "ubiquity.h"

class DbManager
{
public:
    DbManager(const QString& path);
    void selectUnits(std::vector<Unit*>& unitVector, const int KINDRED_CODE);
    Ubiquity *fetchUbi(int ubiID2);
    std::vector<ubiChange> fetchUbiChange(int commID);

private:
    QSqlDatabase m_db;
};

extern DbManager db;

#endif // DBMANAGER

