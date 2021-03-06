#ifndef UBIQUITY_H
#define UBIQUITY_H

#include <QString>

class Ubiquity
{
public:
    Ubiquity();
    Ubiquity(int mnsty2,
                int cmmn2,
                int uncmmn2,
                int rare2,
                int mythic2,
                bool unique2);
    ~Ubiquity();

    int mnsty;
    int cmmn;
    int uncmmn;
    int rare;
    int mythic;
    int unique;
};

struct ubiChange
{
    QString targetName;
    Ubiquity* newUbi;
};

#endif // UBIQUITY_H
