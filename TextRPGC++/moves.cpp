#include "moves.h"
#include <iostream>

Move::Move() {
    name = "DoNothing";
    damage = 0;
}

Move::Move(string nameIn, int damageIn, string tagIn, int effectIn) {
    name = nameIn;
    damage = damageIn;
    tag = tagIn;
    effect = effectIn;
}

Move::~Move() {}

void Move::applyEffect(int newEffect) {}

void Move::applyDamage(int n) {
    damage += n;
}

void Move::printInfo() {
    cout << "=== Move Information! ===" << endl;
    cout << " Name: " << name << endl;
    cout << " Damage: " << damage << endl;
    cout << " Effect: " << effect << endl;
    cout << "=========================" << endl;
}

// main function ========================================================

/*
int main() {
    Move myMove("Splinter", 1);
    Splinter mySplinter;

    myMove.printInfo();
    mySplinter.printInfo();

    return 0;
}
*/