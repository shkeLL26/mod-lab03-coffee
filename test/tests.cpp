// Copyright 2026 Shkelev Egor

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata testMachine;
    testMachine.on();
    STATES result = testMachine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task2, test1) {
    Automata testMachine;
    testMachine.off();
    STATES result = testMachine.getState();
    EXPECT_EQ(OFF, result);
}

TEST(task3, test1) {
    Automata testMachine;
    testMachine.on();
    testMachine.coin(-10);
    testMachine.choice(1);
    STATES result = testMachine.getState();
    EXPECT_EQ(CHECK, result);
}

TEST(task3, test2) {
    Automata testMachine;
    testMachine.on();
    testMachine.coin(20);
    testMachine.choice(2);
    STATES result = testMachine.getState();
    EXPECT_EQ(CHECK, result);
}

TEST(task3, test3) {
    Automata testMachine;
    testMachine.on();
    testMachine.coin(2);
    testMachine.choice(7);
    STATES result = testMachine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task4, test1) {
    Automata testMachine;
    testMachine.on();
    testMachine.coin(20);
    testMachine.choice(2);
    testMachine.check();
    STATES result = testMachine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task4, test2) {
    Automata testMachine;
    testMachine.on();
    testMachine.coin(1);
    testMachine.choice(2);
    testMachine.check();
    STATES result = testMachine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task4, test3) {
	Automata testMachine;
	testMachine.on();
	testMachine.coin(100);
	testMachine.choice(0);
	testMachine.check();
	STATES result = testMachine.getState();
	EXPECT_EQ(WAIT, result);
}

TEST(task4, test4) {
	Automata testMachine;
	testMachine.on();
	testMachine.coin(100);
	testMachine.choice(-2);
	testMachine.check();
	STATES result = testMachine.getState();
	EXPECT_EQ(WAIT, result);
}

TEST(task5, test1) {
	Automata testMachine;
	testMachine.on();
	testMachine.coin(100);
	coffeMachine.choice(3);
	testMachine.cancel();
	STATES result = testMachine.getState();
	EXPECT_EQ(WAIT, result);
}
