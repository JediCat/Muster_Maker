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
#include <QCheckBox>

class DbManager
{
public:
    DbManager(const QString& path);
    DbManager();
    void selectUnits(std::vector<Unit*>& unitVector, const int KINDRED_CODE);
    Ubiquity *fetchUbi(int ubiID2);
    std::vector<ubiChange> fetchUbiChange(int commID);
    void fetchCommandOptions(QCheckBox* champ, QCheckBox* banner, QCheckBox* horn, int unitID, bool hostCommand, int cost[]);

private:
    QSqlDatabase m_db;
};

extern DbManager db;

#endif // DBMANAGER

