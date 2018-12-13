/*
 * ICellularManager.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: tunstall
 */
#include "gtest/gtest.h"
#include "ICellularManager.h"
#include "CellularManager.h"

class ICellularManagerTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
		//code here will be called immediately after each test
	}

	ICellularManager *foo = new CellularManager();
};

TEST_F(ICellularManagerTests, UnitTest1)
{
	ASSERT_TRUE(foo->foo());
}

TEST_F(ICellularManagerTests, UnitTest2)
{
	EXPECT_EQ(true, foo->foo());
}
