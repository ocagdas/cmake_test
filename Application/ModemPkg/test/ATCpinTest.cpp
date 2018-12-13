/*
 * ATCmeeTests.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATCpin.h"
#include "ATCommand.h"


TEST(ATCpinTests, ATCpin_UnitTest1)
{
	//all functions should be good
    std::vector<std::string> parameter_list = {"1234"};
    ATCpin foo = ATCpin(parameter_list);
    EXPECT_EQ("AT+CPIN?",foo.GenerateReadCommand());
    EXPECT_EQ("AT+CPIN=?",foo.GenerateTestCommand());
    EXPECT_EQ("AT+CPIN=\"1234\"",foo.GenerateWriteCommand());
    EXPECT_EQ(120, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATCPIN, foo.GetCommandType());
}

TEST(ATCpinTests, ATCpin_UnitTest2)
{
	//passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"-1"};
    ATCpin foo = ATCpin(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCpinTests, ATCpin_UnitTest3)
{
    //passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"1234", "4567"};
    ATCpin foo = ATCpin(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST(ATCpinTests, ATCpin_UnitTest4)
{
	//passing an incorrect string that will not convert to an integer and should create an exception
    std::vector<std::string> parameter_list = {"dd"};
    ATCpin foo = ATCpin(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo.GenerateWriteCommand());
}

TEST(ATCpinTests, ATCpin_UnitTest5)
{
    std::vector<std::string> parameter_list = {"0000"};
    ATCpin foo = ATCpin(parameter_list);
    std::vector<std::string> response_list = {"+CPIN","READY"};
    ATResponse expected_response = ATResponse(ATResponseType::ATCPIN, response_list);
    std::string response = "+CPIN: READY";
    ATResponse actual_response = foo.ParseCommand(response);
    expected_response.PrintResponseData();
    actual_response.PrintResponseData();
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    EXPECT_EQ(expected_response.GetResponseData()[0], actual_response.GetResponseData()[0]);
    EXPECT_EQ(expected_response.GetResponseData()[1], actual_response.GetResponseData()[1]);
}

TEST(ATCpinTests, ATCpin_UnitTest6)
{
    //passing a parameter outside the range of the GenerateWriteCommand function
    std::vector<std::string> parameter_list = {"0000"};
    ATCpin foo = ATCpin(parameter_list);
    EXPECT_EQ("AT+CPIN=\"0000\"",foo.GenerateWriteCommand());
}

