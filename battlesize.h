#ifndef BATTLESIZE_H
#define BATTLESIZE_H

#include <QString>

struct battleSize
{
    QString name;
    int goldMin;
    int goldMax;
    int mnstyMin;
    int mnstyMax;
    int cmmnMin;
    int cmmnMax;
    int uncmmnMin;
    int uncmmnMax;
    int rareMin;
    int rareMax;
    int mythicMin;
    int mythicMax;
    int uniqueMin;
    int uniqueMax;
};

    const battleSize BATTLESIZE[5] = {
        {"Encounter",   0,      499,    1,  0,  0, 4,   0, 2,   0, 0, 0, 0, 0, 0},
        {"Skirmish",    500,    999,    2,  0,  1, 6,   0, 4,   0, 1, 0, 0, 0, 1},
        {"Battle",      1000,   2499,   3,  0,  2, 8,   1, 6,   0, 2, 0, 1, 0, 1},
        {"War",         2500,   4999,   5,  0,  4, 16,  2, 8,   0, 4, 0, 2, 0, 1},
        {"Cataclysm",   5000,   9999,   10, 0,  6, 20,  4, 16,  1, 6, 0, 4, 0, 2}
    };


/*    battleSize ENCOUNTER =  {"Encounter",   0,      499,    1,  0,  0, 4,   0, 2,   0, 0, 0, 0, 0, 0};
    battleSize SKIRMISH =   {"Skirmish",    500,    999,    2,  0,  1, 6,   0, 4,   0, 1, 0, 0, 0, 1};
    battleSize BATTLE =     {"Battle",      1000,   2499,   3,  0,  2, 8,   1, 6,   0, 2, 0, 1, 0, 1};
    battleSize WAR =        {"War",         2500,   4999,   5,  0,  4, 16,  2, 8,   0, 4, 0, 2, 0, 1};
    battleSize CATACLYSM =  {"Cataclysm",   5000,   9999,   10, 0,  6, 20,  4, 16,  1, 6, 0, 4, 0, 2};*/

#endif // BATTLESIZE_H

