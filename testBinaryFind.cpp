#include "testBinaryFind.h"
#include "binaryFind.h"

namespace testBinaryFind {

/// \brief Checks that binaryFind() works correctly for specified arguments
/// \param where Array of integers where to find value.
/// \param what Value to find.
/// \return true if binaryFind() worked correctly, false if not
/// \note This function writes diagnostics to verbose_cout.
bool checkFind( IntVec& where, int what )
{
    //
    int i = binaryFind( where, what );
    if( i == -1 )
    {
        foreach (int x, where)
        {
            if( x == what )
            {
                verbose_cout << "Value " << what << " was not found but it's here at index " << i << endl;
                return false;
            }
        }
    }
    else
    {
        if( !( i >= 0   &&   i < where.size() ) )
        {
            verbose_cout << "Index " << i << " returned by binaryFind() is out of range" << endl;
            return false;
        }
        if( where[i] != what )
        {
            verbose_cout << "Value at index " << i << " returned by binaryFind() is not equal to " << what << endl;
            return false;
        }
    }
    verbose_cout << "Index of " << what << ": " << i << endl;
    return true;
}

void run()
{
    verbose_cout << "testBinaryFind::run() - starting" << endl;
    IntVec v = makeSortedRandomIntVec( 50 );
    verbose_cout << v;
    verbose_cout << "====" << endl;
    bool result =
        checkFind( v, 42 )  &&
        checkFind( v, 0 )   &&
        checkFind( v, 65 )  &&
        checkFind( v, -20 )  &&
        checkFind( v, 156 )  &&
        checkFind( v, 97 );
    verbose_cout << "testBinaryFind::run() - finished" << endl;
    REPORT_TEST_RESULT( testBinaryFind, result );
}

} // namespace testBinaryFind
