#ifndef INVOCATION
#define INVOCATION

#include <QString>
#include <vector>

struct invocation
{
    int invocID;
    QString name;
    int cost;
};

extern std::vector<invocation> invocList;
extern int numInvoc;

int findInvocation(QString name);

#endif // INVOCATION

