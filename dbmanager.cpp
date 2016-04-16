#include "dbmanager.h"
#include <QStringList>
#include "ubiquity.h"


DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        qDebug() << "Error: Connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection okay";
    }

}

void DbManager::selectUnits(std::vector<Unit *>& unitVector, const int KINDRED_CODE)
{
    QSqlQuery query("SELECT unitID FROM units");
    if(query.exec())
    {

    }
    else
    {
        qDebug() <<  m_db.lastError();
    }

    int numUnits = KINDRED_CODE;
    int* unitID = new int[numUnits];
    int curr = 0;
    while(query.next())
    {
        unitID[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    QString* name = new QString[numUnits];
    query = QSqlQuery("SELECT name FROM units");
    while(query.next())
    {
        name[curr] = query.value(0).toString();
        curr++;
    }
    curr = 0;

    bool* comm = new bool[numUnits];
    query = QSqlQuery("SELECT comm FROM units");
    while(query.next())
    {
        comm[curr] = query.value(0).toBool();
        curr++;
    }
    curr = 0;

    int* costPer = new int[numUnits];
    query = QSqlQuery("SELECT costPer FROM units");
    while(query.next())
    {
        costPer[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    int* minSize = new int[numUnits];
    query = QSqlQuery("SELECT minSize FROM units");
    while(query.next())
    {
        minSize[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    int* maxSize = new int[numUnits];
    query = QSqlQuery("SELECT maxSize FROM units");
    while(query.next())
    {
        maxSize[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    int* invocSlots = new int[numUnits];
    query = QSqlQuery("SELECT invocSlots FROM units");
    while(query.next())
    {
        invocSlots[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    int* ubiID = new int[numUnits];
    query = QSqlQuery("SELECT ubiID FROM units");
    while(query.next())
    {
        ubiID[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    bool* gen = new bool[numUnits];
    query = QSqlQuery("SELECT gen FROM units");
    while(query.next())
    {
        gen[curr] = query.value(0).toBool();
        curr++;
    }
    curr = 0;

    int* auth = new int[numUnits];
    query = QSqlQuery("SELECT auth FROM units");
    while(query.next())
    {
        auth[curr] = query.value(0).toInt();
        curr++;
    }
    curr = 0;

    Ubiquity** ubi = new Ubiquity*[numUnits];
    for(curr = 0; curr < numUnits; curr++)
    {
        ubi[curr] = fetchUbi(ubiID[curr]);
    }

    for(int i = 0; i < numUnits; i++)
    {
        Unit* unit = new Unit(unitID[i], name[i], comm[i], gen[i], costPer[i], minSize[i], maxSize[i], invocSlots[i], ubiID[i], auth[i], ubi[i]);
        unitVector.insert(unitVector.end(), unit);
    }

}

Ubiquity* DbManager::fetchUbi(int ubiID2)
{
    Ubiquity* ubi = new Ubiquity();
    QSqlQuery query;
    query.prepare("SELECT mnsty FROM ubiquity WHERE ubiID = (:ubiID2)");
    query.bindValue(":ubiID2", ubiID2);
    if(query.exec())
    {
        if(query.next())
        {
            ubi->mnsty = query.value(0).toInt();
        }
    }

    query.prepare("SELECT cmmn FROM ubiquity WHERE ubiID = (:ubiID2)");
    query.bindValue(":ubiID2", ubiID2);
    if(query.exec())
    {
        if(query.next())
        {
            ubi->cmmn = query.value(0).toInt();
        }
    }

    query.prepare("SELECT uncmmn FROM ubiquity WHERE ubiID = (:ubiID2)");
    query.bindValue(":ubiID2", ubiID2);
    if(query.exec())
    {
        if(query.next())
        {
            ubi->uncmmn = query.value(0).toInt();
        }
    }

    query.prepare("SELECT rare FROM ubiquity WHERE ubiID = (:ubiID2)");
    query.bindValue(":ubiID2", ubiID2);
    if(query.exec())
    {
        if(query.next())
        {
            ubi->rare = query.value(0).toInt();
        }
    }

    query.prepare("SELECT mythic FROM ubiquity WHERE ubiID = (:ubiID2)");
    query.bindValue(":ubiID2", ubiID2);
    if(query.exec())
    {
        if(query.next())
        {
            ubi->mythic = query.value(0).toInt();
        }
    }

    query.prepare("SELECT uniqueUnit FROM ubiquity WHERE ubiID = (:ubiID2)");
    query.bindValue(":ubiID2", ubiID2);
    if(query.exec())
    {
        if(query.next())
        {
            ubi->unique = query.value(0).toBool();
        }
    }

    return ubi;
}
