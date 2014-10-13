#include "common.h"
#include <QtAlgorithms>
#include <QProcess>
#include <QFile>

QTextStream cout( stdout );
QTextStream cerr( stderr );

static QFile null_dev( QProcess::nullDevice() );

static struct NullDevInit
{
    NullDevInit()
    {
        null_dev.open( QIODevice::WriteOnly );
    }
} nullDevInit;

static QTextStream null_out( &null_dev );

IntVec makeSortedRandomIntVec( int size, int maxVal )
{
    IntVec result( size );
    for (int i=0; i<size; ++i)
        result[i] = rand() % (maxVal + 1);
    qSort( result );
    return result;
}

void reportTestResult( const char *testName, bool passed )
{
    cout << QString("Test %1 %2").arg(testName, (passed? "PASSED": "FAILED")) << endl;
}

bool VerboseCoutHelper::m_verbose = false;

void VerboseCoutHelper::setVerbose( bool verbose )
{
    m_verbose = verbose;
}

bool VerboseCoutHelper::verbose()
{
    return m_verbose;
}

QTextStream& VerboseCoutHelper::verboseCout()
{
    return m_verbose ?   cout :   null_out;
}
