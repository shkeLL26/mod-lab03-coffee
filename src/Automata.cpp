// Copyright 2026 Shkelev Egor

#include "Automata.h"
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

Automata::Automata() {
    cash = 0;
    menu = {
        { "Americana", 10 },
        { "Latte", 20 },
        { "Chocolate", 30 },
        { "Tea", 40 }
    };
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "\nAutomata is waiting...\n";
        return;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        cout << "\nAutomata turned OFF";
        return;
    }
}

void Automata::coin(double tenge) {
    cash += abs(tenge);
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cout << "\nAutomata gained: " << abs(tenge)
             << ". Balance: " << cash;
        return;
    }
}

vector<Product> Automata::getMenu() {
    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(unsigned int option) {
    if (option > 3) {
        cout << "\nThere isn`t such product in menu";
        cancel();
    }
    if (state == ACCEPT) {
        state = CHECK;
        cout << "\nYou chose " << menu[option-1].itemName;
        currentPrice = menu[option-1].price;
        return;
    }
}

void Automata::check() {
    if (currentPrice <= cash) {
        cout << "\nStarting cooking...";
        cook();
    } else {
        cout << "\nYou don`t have enough tenge, dude";
        cancel();
    }
}

void Automata::cancel() {
    cash = 0;
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cout << "\nCancellation\nAutomata is waiting...\n";
        return;
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        this_thread::sleep_for(4s);
        finish();
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        cout << "\nReady\nAutomata is waiting...\n";
        return;
    }
}

void showMenu(vector<Product> menu) {
    for (int i = 0; i < menu.size(); i++) {
        cout << '\n' << i + 1 << ". " << menu[i].itemName
             << " Price:" << menu[i].price;
    }
    cout << '\n';
}
