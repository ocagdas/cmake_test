/*
 * ATDTest.cpp
 *
 *  Created on: 26 Sep 2018
 *      Author: tunstall
 */


#include <iostream>
#include "gtest/gtest.h"
#include "ATD.h"
#include "ATCommand.h"

TEST (ATDtests,ATDTestValidParam)
{
    std::vector<std::string> parameter_list0 = {"01224999888"};
    std::vector<std::string> parameter_list1 = {"+44123456789"};
    ATD foo = ATD(parameter_list0);
    ATD foo2 = ATD(parameter_list1);
    EXPECT_EQ("ATD?",foo.GenerateReadCommand());
    EXPECT_EQ("ATD=?",foo.GenerateTestCommand());
    EXPECT_EQ("ATD01224999888;",foo.GenerateWriteCommand());
    EXPECT_EQ("ATD+44123456789;",foo2.GenerateWriteCommand());
    EXPECT_EQ(2, static_cast<int>(foo.GetCommandTimeout()));
    EXPECT_EQ(ATCommandTypes::ATD, foo.GetCommandType());
}

TEST (ATDtests, ATDTestTooLongParam) //parameter too large test, maximum 20 digits
{
    std::vector<std::string> parameter_list = {"123456789012345678901"};
    ATD foo = ATD(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST (ATDtests, ATDTestTooManyParam) //too many parameters
{
    std::vector<std::string> parameter_list = {"1234567", "01234"};
    ATD foo = ATD(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST (ATDtests, ATDTestEmptyParam) //empty parameter list
{
    std::vector<std::string> parameter_list = {};
    ATD foo = ATD(parameter_list);
    EXPECT_EQ(ATCommand::INVALID_COMMAND,foo.GenerateWriteCommand());
}

TEST (ATDtests, ATDTestIllegalCharacters) //Phone number with illegal characters
{
    std::vector<std::string> parameter_list = {"123456andrew"};
    ATD foo = ATD(parameter_list);
    EXPECT_EQ(ATCommand::COMMAND_ERROR,foo.GenerateWriteCommand());
}


