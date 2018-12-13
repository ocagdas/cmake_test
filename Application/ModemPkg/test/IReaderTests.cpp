/*
 * FooTests.cpp
 *
 *  Created on: Aug 29, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "IReader.h"
#include "SierraReader.h"

class IReaderTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	IReader *foo = new SierraReader();
};

TEST_F(IReaderTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(IReaderTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
