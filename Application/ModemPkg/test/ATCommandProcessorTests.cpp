/*
 * ATCommandProcessorTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "ATCommandProcessor.h"

//class ATCommandProcessorTests : public ::testing::Test
//{
//protected:
//	virtual void SetUp()
//	{
//
//	}
//	virtual void TearDown()
//	{
//		//code here will be called immediately after each test
//	}
//
//	ATCommandProcessor foo;
//};

TEST(ATCommandProcessorTests, UnitTest1)
{
	ATCommandProcessor foo;
	ASSERT_TRUE(foo.foo());
}

TEST(ATCommandProcessorTests, UnitTest2)
{
	ATCommandProcessor foo;
	EXPECT_EQ(true, foo.foo());
}
