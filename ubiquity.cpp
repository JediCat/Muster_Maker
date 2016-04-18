#include "ubiquity.h"

Ubiquity::Ubiquity()
{
    mnsty =0;
    cmmn = 0;
    uncmmn = 0;
    rare = 0;
    mythic = 0;
    unique = 0;
}

Ubiquity::Ubiquity(int mnsty2,
                   int cmmn2,
                   int uncmmn2,
                   int rare2,
                   int mythic2,
                   bool unique2)
{
    mnsty = mnsty2;
    cmmn = cmmn2;
    uncmmn = uncmmn2;
    rare = rare2;
    mythic = mythic2;
    unique = unique2;
}

Ubiquity::~Ubiquity()
{

}
