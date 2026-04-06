// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
	Automata testMachine;
	testMachine.on();
	result = testMachine.getState();
	EXPECT_EQ(WAIT, result);
}
