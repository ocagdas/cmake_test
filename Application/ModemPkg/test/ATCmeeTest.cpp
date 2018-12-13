/*
 * ATCmeeTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCmee.h"
#include "ATCommand.h"


TEST(ATCmeeTests, ATCmee_UnitTest1)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"2"};
    ATCmee foo = ATCmee(parameter_list);
    EXPECT_EQ("AT+CMEE?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+CMEE=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CMEE=2",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCMEE, foo.GetCommandType());
}

TEST(ATCmeeTests, ATCmee_UnitTest2)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"3"};
    ATCmee foo = ATCmee(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCmeeTests, ATCmee_UnitTest3)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list = {"dd"};
    ATCmee foo = ATCmee(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo.GenerateWriteCommand());
}

TEST(ATCmeeTests, ATCmee_UnitTest4)
{
    std::vector<std::string> parameter_list = {"2"};

    ATCmee foo = ATCmee(parameter_list);
    std::vector<std::string> response_list = {"+CMEE","2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCMEE, response_list);
    std::string response = "+CMEE: 2";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

