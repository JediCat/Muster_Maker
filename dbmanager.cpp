#include "dbmanager.h"
#include <QStringList>
#include "ubiquity.h"
#include "constants.h"
#include "unit.h"
#include "newmusterdialog.h"

DbManager::DbManager()
{

}

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
        qDebug() << "Database: connection okay, Path: " << path;
    }

}

void DbManager::fetchUnits(int realmID)
{
    int curr = 0;
    int numUnits;
    QSqlQuery query;
    std::vector<int> unitID;
    query.prepare("SELECT unitID FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            unitID.insert(unitID.end(), query.value(0).toInt());
            curr++;
        }
        numUnits = unitID.size();
        curr = 0;
    }

    QString* name = new QString[numUnits];
    query.prepare("SELECT name FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            name[curr] = query.value(0).toString();
            curr++;
        }
        curr = 0;
    }

    bool* comm = new bool[numUnits];
    query.prepare("SELECT comm FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            comm[curr] = query.value(0).toBool();
            curr++;
        }
        curr = 0;
    }

    int* costPer = new int[numUnits];
    query.prepare("SELECT costPer FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            costPer[curr] = query.value(0).toInt();
            curr++;
        }
        curr = 0;
    }

    int* minSize = new int[numUnits];
    query.prepare("SELECT minSize FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            minSize[curr] = query.value(0).toInt();
            curr++;
        }
        curr = 0;
    }

    int* maxSize = new int[numUnits];
    query.prepare("SELECT maxSize FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            maxSize[curr] = query.value(0).toInt();
            curr++;
        }
        curr = 0;
    }

    int* invocSlots = new int[numUnits];
    query.prepare("SELECT invocSlots FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            invocSlots[curr] = query.value(0).toInt();
            curr++;
        }
        curr = 0;
    }

    int* ubiID = new int[numUnits];
    query.prepare("SELECT ubiID FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            ubiID[curr] = query.value(0).toInt();
            curr++;
        }
        curr = 0;
    }

    bool* gen = new bool[numUnits];
    query.prepare("SELECT gen FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            gen[curr] = query.value(0).toBool();
            curr++;
        }
        curr = 0;
    }

    int* auth = new int[numUnits];
    query.prepare("SELECT auth FROM units WHERE realmID = (:realmID)");
    query.bindValue(":realmID", realmID);
    if(query.exec())
    {
        while(query.next())
        {
            auth[curr] = query.value(0).toInt();
            curr++;
        }
        curr = 0;
    }

    Ubiquity** ubi = new Ubiquity*[numUnits];
    for(curr = 0; curr < numUnits; curr++)
    {
        ubi[curr] = fetchUbi(ubiID[curr]);
    }

    for(int i = 0; i < numUnits; i++)
    {
        Unit* unit = new Unit(unitID[i], name[i], comm[i], gen[i], costPer[i], minSize[i], maxSize[i], invocSlots[i], ubiID[i], auth[i], ubi[i]);
        hostUnits.insert(hostUnits.end(), unit);
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
            ubi->unique = query.value(0).toInt();
        }
    }

    return ubi;
}

std::vector<ubiChange> DbManager::fetchUbiChange(int commID)
{
    std::vector<ubiChange> toReturn;
    QSqlQuery query;

    query.prepare("SELECT newUbi FROM ubiChange WHERE commUnit = (:commID)");
    query.bindValue(":commID", commID);
    if(query.exec())
    {
        while(query.next())
        {
            int ubiID = query.value(0).toInt();
            ubiChange target;
            target.newUbi = fetchUbi(ubiID);
            target.targetName = "";
            toReturn.insert(toReturn.end(), target);
        }
    }

    int i = 0;
    query.prepare("SELECT targetUnit FROM ubiChange WHERE commUnit = (:commID)");
    query.bindValue(":commID", commID);
    if(query.exec())
    {
        while(query.next())
        {

            QSqlQuery query2;
            query2.prepare("SELECT name FROM units WHERE unitID = (:targetUnit)");
            int targetUnit = query.value(0).toInt();
            query2.bindValue(":targetUnit", targetUnit);
            if(query2.exec())
            {
                while(query2.next())
                {
                    toReturn[i].targetName = query2.value(0).toString();
                    i++;
                }
            }
        }
    }

    return toReturn;
}

void DbManager::fetchCommandOptions(QCheckBox *champ, QCheckBox *banner, QCheckBox *horn, int unitID, bool hostCommand, int cost[])
{
    int chCode = (hostCommand) ? HOST_CHAMPION_CODE : CHAMPION_CODE;
    int baCode = (hostCommand) ? HOST_BANNER_CODE : BANNER_CODE;
    int hoCode = (hostCommand) ? HOST_HORN_CODE : HORN_CODE;

    QSqlQuery query;
    query.prepare("SELECT cost FROM unitOptions WHERE optType = (:chCode) AND unitID = (:unitID)");
    query.bindValue(":chCode", chCode);
    query.bindValue(":unitID", unitID);
    if(query.exec())
    {
        if(query.next())
        {
            champ->setEnabled(true);
            cost[0] = query.value(0).toInt();
        }
        else
        {
            cost[0] = 0;
            champ->setEnabled(false);
        }
    }

    query.prepare("SELECT cost FROM unitOptions WHERE optType = (:baCode) AND unitID = (:unitID)");
    query.bindValue(":baCode", baCode);
    query.bindValue(":unitID", unitID);
    if(query.exec())
    {
        if(query.next())
        {
            banner->setEnabled(true);
            cost[1] = query.value(0).toInt();
        }
        else
        {
            cost[1] = 0;
            banner->setEnabled(false);
        }
    }

    query.prepare("SELECT cost FROM unitOptions WHERE optType = (:hoCode) AND unitID = (:unitID)");
    query.bindValue(":hoCode", hoCode);
    query.bindValue(":unitID", unitID);
    if(query.exec())
    {
        if(query.next())
        {
            horn->setEnabled(true);
            cost[2] = query.value(0).toInt();
        }
        else
        {
            cost[2] = 0;
            horn->setEnabled(false);
        }
    }
}

void DbManager::fetchInvocations()
{
    QSqlQuery query;
    query.prepare("SELECT invocID FROM invocations");
    if(query.exec())
    {
        while(query.next())
        {
            invocation temp;
            temp.invocID = query.value(0).toInt();
            invocList.insert(invocList.end(), temp);
            numInvoc++;
        }
    }

    query.prepare("SELECT name FROM invocations");
    if(query.exec())
    {
        int i = 0;
        while(query.next())
        {
            invocList[i].name = query.value(0).toString();
            i++;
        }
    }

    query.prepare("SELECT cost FROM invocations");
    if(query.exec())
    {
        int i = 0;
        while(query.next())
        {
            invocList[i].cost = query.value(0).toInt();
            i++;
        }
    }
}

void DbManager::fetchRealms()
{
    QSqlQuery query;
    query.prepare("SELECT name FROM realms");
    if(query.exec())
    {
        while(query.next())
        {
            realmList.insert(realmList.end(), query.value(0).toString());
        }
    }
}

void DbManager::close()
{
    m_db.close();
}
