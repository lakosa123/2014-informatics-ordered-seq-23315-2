#include "binaryFind.h"

int binaryFind( const IntVec &where, int what )
{
    if (where.isEmpty()   ||   what < where.first()   ||   where.last() < what)
        return -1;
    int i1 = 0,   i2 = where.size() - 1;
    forever
    {
        if (what == where[i1])
            return i1;
        if (what == where[i2])
            return i2;
        if (i2 - i1 < 2)
            return -1;
        int i3 = (i1 + i2) >> 1;
        if (what < where[i3])
            i2 = i3;
        else
            i1 = i3;
    }
}
