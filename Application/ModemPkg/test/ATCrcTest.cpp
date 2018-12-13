/*
 * ATCrcTest.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCrc.h"
#include "ATCommand.h"


TEST(ATCrcTests, ATCrc_ReadWriteTestSuccess)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"0"};
    std::vector<std::string> parameter_list2 = {"1"};
    ATCrc foo = ATCrc(parameter_list);
    ATCrc foo2 = ATCrc(parameter_list2);
    EXPECT_EQ("AT+CRC?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+CRC=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CRC=0",foo.GenerateWriteCommand());
    EXPECT_EQ("AT+CRC=1",foo2.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCRC, foo.GetCommandType());
}

TEST(ATCrcTests, ATCrc_ParameterOutOfRange)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"3"};
    ATCrc foo = ATCrc(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCrcTests, ATCrc_MissingAndBadCommand)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list;
    ATCrc foo = ATCrc(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
    parameter_list = {"dd"};
    ATCrc foo2 = ATCrc(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo2.GenerateWriteCommand());
}

// Simple reporting
TEST(ATCrcTests, ATCrc_SimpleURCReporting)
{
    std::vector<std::string> parameter_list = {"1"};

    ATCrc foo = ATCrc(parameter_list);
    std::vector<std::string> response_list = {"+CRC", "1"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCRC, response_list);
    std::string response = "+CRC: 1";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}


