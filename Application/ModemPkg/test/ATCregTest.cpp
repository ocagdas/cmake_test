/*
 * ATCregTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCreg.h"
#include "ATCommand.h"


TEST(ATCregTests, ATCreg_ReadWriteTestSuccess)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"2"};
    ATCreg foo = ATCreg(parameter_list);
    EXPECT_EQ("AT+CREG?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+CREG=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CREG=2",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCREG, foo.GetCommandType());
}

TEST(ATCregTests, ATCreg_ParameterOutOfRange)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"3"};
    ATCreg foo = ATCreg(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCregTests, ATCreg_MissingAndBadCommand)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list;
    ATCreg foo = ATCreg(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
    parameter_list = {"dd"};
    ATCreg foo2 = ATCreg(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo2.GenerateWriteCommand());
}

// Simple URC reporting
TEST(ATCregTests, ATCreg_SimpleURCReporting)
{
    std::vector<std::string> parameter_list = {"1"};

    ATCreg foo = ATCreg(parameter_list);
    std::vector<std::string> response_list = {"+CREG", "1", "5"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCREG, response_list);
    std::string response = "+CREG: 1,5";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

// Successful connection message.
TEST(ATCregTests, ATCreg_LongURCReporting)
{
    std::vector<std::string> parameter_list = {"2"};

    ATCreg foo = ATCreg(parameter_list);
    std::vector<std::string> response_list = {"+CREG", "2", "5", "0065", "00960BA1", "6"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCREG, response_list);
    std::string response = "+CREG: 2,5,\"0065\",\"00960BA1\",6";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
    EXPECT_EQ(expected_response.GetResponseData()[2], actual_response.GetResponseData()[2]);
    EXPECT_EQ(expected_response.GetResponseData()[3], actual_response.GetResponseData()[3]);
    EXPECT_EQ(expected_response.GetResponseData()[4], actual_response.GetResponseData()[4]);
    EXPECT_EQ(expected_response.GetResponseData()[5], actual_response.GetResponseData()[5]);
}

