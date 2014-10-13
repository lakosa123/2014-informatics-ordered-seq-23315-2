#ifndef BINARYFIND_H
#define BINARYFIND_H

#include "common.h"

/// \brief Finds specified value in the specified array of integers.
/// \param where Array of integers where to find value.
/// \param what Value to find.
/// \return Index of value \a what in the array \a where, if found; -1 if not found.
int binaryFind( const IntVec& where, int what );

#endif // BINARYFIND_H
