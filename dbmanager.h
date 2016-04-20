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
#include "invocation.h"

class DbManager
{
public:
    DbManager(const QString& path);
    DbManager();
    void close();
    void fetchUnits(int realmID);
    Ubiquity *fetchUbi(int ubiID2);
    std::vector<ubiChange> fetchUbiChange(int commID);
    void fetchCommandOptions(QCheckBox* champ, QCheckBox* banner, QCheckBox* horn, int unitID, bool hostCommand, int cost[]);
    void fetchInvocations();
    void fetchRealms();

private:
    QSqlDatabase m_db;
};

extern DbManager db;

#endif // DBMANAGER

