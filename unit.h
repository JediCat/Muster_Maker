#ifndef UNIT_H
#define UNIT_H

#include<QString>
#include<vector>
#include "constants.h"



class Ubiquity;

class Unit
{
public:
    Unit();
    Unit(int unitID2,
          QString name2,
          bool comm2,
          bool gen2,
          int costPer2,
          int minSize2,
          int maxSize2,
          int invocSlots2,
          int ubiID2,
          int auth2,
          Ubiquity* ubi2);

    int unitID;
    QString name;
    bool comm;
    bool gen;
    int costPer;
    int minSize;
    int maxSize;
    int invocSlots;
    int ubiID;
    int auth;
    Ubiquity* ubi;
    Ubiquity* oldUbi;
    bool ubiChanged;

};

extern std::vector<Unit*> hostUnits;

Unit* findUnit(QString name);

#endif // UNIT_H
