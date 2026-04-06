#include "Automata.h"

int main() {
    Automata coffeMachine;

    showMenu(coffeMachine.getMenu());

    coffeMachine.on();
    coffeMachine.off();
    coffeMachine.on();

    coffeMachine.coin(5);
    coffeMachine.coin(5);
    coffeMachine.choice(1);
    coffeMachine.check();

    coffeMachine.coin(5);
    coffeMachine.choice(2);
    coffeMachine.cancel();

    coffeMachine.coin(10);
    coffeMachine.choice(0);
    coffeMachine.check();

    return 0;
}
