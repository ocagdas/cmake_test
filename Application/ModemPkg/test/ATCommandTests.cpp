/*
 * ATCommandTests.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "ATKvgr.h"
#include "IPULogger.h"

class ATCommandTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}
	ATCommand *foo = new ATKvgr({""});
};

TEST_F(ATCommandTests, UnitTest1)
{
}

TEST_F(ATCommandTests, UnitTest2)
{
}
