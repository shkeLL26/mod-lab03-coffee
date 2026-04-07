// Copyright 2024 Your Name
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using std::string;
using std::vector;
using std::cout;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

struct Product {
    string itemName;
    int price;
};

class Automata {
 private:
    double cash;
    vector<Product> menu;
    STATES state;
    double currentPrice;

    void cook();
    void finish();

 public:
    Automata();

    void on();
    void off();
    void coin(double tenge);
    void choice(unsigned int option);
    void check();
    void cancel();
    vector<Product> getMenu();
    STATES getState();
};

void showMenu(vector<Product> menu);
