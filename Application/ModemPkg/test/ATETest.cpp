/*
 * ATKstTest.cpp
 *
 *  Created on: 18 Sep 2018
 *      Author: tunstall
 */


#include <iostream>
#include "gtest/gtest.h"
#include "ATE.h"
#include "ATCommand.h"

TEST (ATEtests,ATETestValidParam)
{
    std::vector<std::string> parameter_list0 = {"0"};
    std::vector<std::string> parameter_list1 = {"1"};
    ATE foo = ATE(parameter_list0);
    ATE foo2 = ATE(parameter_list1);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateReadCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateTestCommand());
    EXPECT_EQ("ATE0",foo.GenerateWriteCommand());
    EXPECT_EQ("ATE1",foo2.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATE, foo.GetCommandType());
}

TEST (ATEtests, ATETestInvalidParam) //parameter too large test
{
    std::vector<std::string> parameter_list = {"2"};
    ATE foo = ATE(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateReadCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST (ATEtests, ATETestEmptyParam) //empty parameter list
{
    std::vector<std::string> parameter_list = {};
    ATE foo = ATE(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateReadCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateTestCommand());
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

