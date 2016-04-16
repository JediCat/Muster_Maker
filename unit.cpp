#include "unit.h"

Unit::Unit()
{


}

Unit::Unit(int unitID2, QString name2, bool comm2, bool gen2, int costPer2, int minSize2, int maxSize2, int invocSlots2, int ubiID2, int auth2, Ubiquity *ubi2)
{
    unitID = unitID2;
    name = name2;
    comm = comm2;
    gen = gen2;
    costPer = costPer2;
    minSize = minSize2;
    maxSize = maxSize2;
    invocSlots = invocSlots2;
    ubiID = ubiID2;
    auth = auth2;
    ubi = ubi2;
}
