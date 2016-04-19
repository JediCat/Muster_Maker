#include "invocation.h"

int findInvocation(QString name)
{
    int i;
    for(i = 0; i < numInvoc; i++)
    {
        if(invocList[i].name == name)
        {
            return i;
        }
    }

    return -1;
}
