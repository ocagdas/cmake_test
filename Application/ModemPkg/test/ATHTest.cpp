/*
 * ATKvgtTest.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATH.h"
#include "ATCommand.h"

// Working command call.
TEST(ATHTests, ATHUnitTest1)
{
    std::vector<std::string> parameter_list;
    ATH foo = ATH(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateReadCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateTestCommand());
    EXPECT_EQ("ATH",foo.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATH, foo.GetCommandType());
}

// Unnecessary extra parameter.
TEST(ATHTests, ATHUnitTest2)
{
    std::vector<std::string> parameter_list = {"2"};
    ATH foo = ATH(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateReadCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}


TEST(ATHTests, ATHUnitTest4)
{
    std::vector<std::string> parameter_list = {""};
    ATH foo = ATH(parameter_list);
    std::vector<std::string> response_list = {""};
    ATResponse expected_response = ATResponse(ATResponseType::NONE, response_list);
    std::string response = "";
    ATResponse actual_response = foo.ParseCommand(response);
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    actual_response.PrintResponseData();
}


