#ifndef UBIQUITY_H
#define UBIQUITY_H


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

    int mnsty;
    int cmmn;
    int uncmmn;
    int rare;
    int mythic;
    bool unique;
};

#endif // UBIQUITY_H
