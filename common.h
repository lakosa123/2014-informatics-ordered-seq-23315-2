#ifndef COMMON_H
#define COMMON_H

/// \file
/// \brief Common stuff for the entire project.

#include <QTextStream>
#include <QVector>
#include <cstdlib>

/// \brief Text stream for standard output
extern QTextStream cout;

/// \brief Text stream for standard error
extern QTextStream cerr;

/// \brief Type for array of integers
typedef QVector<int> IntVec;

/// \brief Outputs array of integers to a text stream
inline QTextStream& operator<<( QTextStream& s, const IntVec& v )
{
    for (int i=0; i<v.size(); ++i)
        s << i << "\t" << v[i] << endl;
    return s;
}

/// \brief Generates a vector of random integers of length size.
/// \param size The size of the array returned.
/// \param maxVal Maximum allowed value of element in the array returned.
/// \return Array of \a size random integer numbers between 0 and \a maxVal,
/// sorted in the ascending order.
IntVec makeSortedRandomIntVec( int size, int maxVal = 100 );

/// \brief Function that prints test result (use macro REPORT_TEST_RESULT instead)
void reportTestResult( const char *testName, bool passed );

/// \brief Macro that prints test result
#define REPORT_TEST_RESULT( testName, passed ) \
    reportTestResult( #testName, passed )

/// \brief Helper class for verbose output stream.
class VerboseCoutHelper
{
public:
    /// \brief Sets current verbosity option.
    static void setVerbose( bool verbose );

    /// \brief Returns current verbosity option.
    static bool verbose();

    /// \brief Returns verbose output stream.
    static QTextStream& verboseCout();
private:
    // Current verbosity option
    static bool m_verbose;
};

/// \brief Mactor returning the verbose output text stream.
///
/// It is the text stream for standard output,
/// if -v command line option is specified, and for /dev/null if not.
#define verbose_cout VerboseCoutHelper::verboseCout()

#endif // COMMON_H
