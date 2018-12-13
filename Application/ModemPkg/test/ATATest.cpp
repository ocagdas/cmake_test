/*
 * ATATest.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: tunstall
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ATA.h"
#include "ATCommand.h"

// Working command call.
TEST(ATATests, ATAUnitTest1)
{
    std::vector<std::string> parameter_list;
    ATA foo = ATA(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateReadCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateTestCommand());
    EXPECT_EQ("ATA",foo.GenerateWriteCommand());
    EXPECT_EQ(60, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATA, foo.GetCommandType());
}

// Unnecessary extra parameter.
TEST(ATATests, ATAUnitTest2)
{
    std::vector<std::string> parameter_list = {"2"};
    ATA foo = ATA(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}


TEST(ATATests, ATAUnitTest4)
{
    std::vector<std::string> parameter_list = {""};
    ATA foo = ATA(parameter_list);
    std::vector<std::string> response_list = {""};
    ATResponse expected_response = ATResponse(ATResponseType::NONE, response_list);
    std::string response = "";
    ATResponse actual_response = foo.ParseCommand(response);
    EXPECT_EQ(expected_response.GetATResponseType(), actual_response.GetATResponseType());
    actual_response.PrintResponseData();
}


