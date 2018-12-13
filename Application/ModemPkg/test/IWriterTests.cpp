/*
 * IWriterTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "IWriter.h"
#include "SierraWriter.h"

class IWriterTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	IWriter *foo = new SierraWriter();
};

TEST_F(IWriterTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(IWriterTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
