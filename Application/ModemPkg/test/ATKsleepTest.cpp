/*
 * ATCmeeTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATKsleep.h"
#include "ATCommand.h"


TEST(ATKsleepTests, ATKsleep_UnitTest1)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"2"};
    ATKsleep foo = ATKsleep(parameter_list);
    EXPECT_EQ("AT+KSLEEP?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+KSLEEP=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+KSLEEP=2",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATKSLEEP, foo.GetCommandType());
}

TEST(ATKsleepTests, ATKsleep_UnitTest2)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"3"};
    ATKsleep foo = ATKsleep(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATKsleepTests, ATKsleep_UnitTest3)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list = {"dd"};
    ATKsleep foo = ATKsleep(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo.GenerateWriteCommand());
}

TEST(ATKsleepTests, ATKsleep_UnitTest4)
{
    std::vector<std::string> parameter_list = {"2"};

    ATKsleep foo = ATKsleep(parameter_list);
    std::vector<std::string> response_list = {"+KSLEEP","2"};
    ATResponse expected_response = ATResponse(ATResponseType::ATKSLEEP, response_list);
    std::string response = "+KSLEEP: 2";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

