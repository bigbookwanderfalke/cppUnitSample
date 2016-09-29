#include "Class1.h"

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include <iostream>
using namespace std;

class ExampleTestCase : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( ExampleTestCase );
	CPPUNIT_TEST( example );
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();

protected:
	void example();
};

CPPUNIT_TEST_SUITE_REGISTRATION( ExampleTestCase );

void ExampleTestCase::setUp()
{
}

void ExampleTestCase::example()
{
	Class1 x;
	CPPUNIT_ASSERT( 1 == x.func(0) );
}

int main(int argc, char **argv)
{
	CPPUNIT_NS::TestResult controller;

	CPPUNIT_NS::TestResultCollector result;
	controller.addListener( &result );        

	CPPUNIT_NS::BriefTestProgressListener progress;
	controller.addListener( &progress );      

	CPPUNIT_NS::TestRunner runner;
	runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
	runner.run( controller );

	CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
	outputter.write(); 

	return result.wasSuccessful() ? 0 : 1;
}

