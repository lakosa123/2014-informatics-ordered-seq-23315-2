#include "common.h"
#include "testBinaryFind.h"
#include "testLowerBound.h"
#include "testUpperBound.h"
#include "testMerge.h"
#include "testCountDuplicate.h"
#include "testUnique.h"
#include "testInsertElement.h"
#include "testRemoveElement.h"

void processArgs( int argc, char *argv[] )
{
    bool verbose = false;
    for( int i=1; i<argc; ++i )
    {
        if( argv[i] == QString("-v") )
            verbose = true;
        else
        {
            cerr << "Unknown argument " << argv[i];
            exit( -1 );
        }
    }
    VerboseCoutHelper::setVerbose( verbose );
}

int main( int argc, char *argv[] )
{
    processArgs( argc, argv );
    testBinaryFind::run();
    testLowerBound::run();
    testUpperBound::run();
    testMerge::run();
    testCountDuplicate::run();
    testUnique::run();
    testInsertElement::run();
    testRemoveElement::run();
    return 0;
}
