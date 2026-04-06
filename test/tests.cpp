// Copyright 2026 Shkelev Egor

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata testMachine;
    testMachine.on();
    STATES result = testMachine.getState();
    EXPECT_EQ(WAIT, result);
}
