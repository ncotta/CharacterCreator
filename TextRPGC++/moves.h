#ifndef MOVES_H
#define MOVES_H

#include <string> 
using namespace std;

class Move {
protected:
    string name;
    string tag;
    int damage;
    int effect;

public:
    Move();
    Move(string nameIn, int damageIn, string tagIn = "enemy", int effectIn = 0);
    ~Move();

    void applyEffect(int newEffect);
    void applyDamage(int n);
    void printInfo();
};

// Dummy Moves ==============================================
class Splinter : public Move {
public:
    Splinter() : Move("Splinter", 1) {}
};

class Glare : public Move {
public:
    Glare() : Move("Malevolent Look", 4) {}
};

class Retaliate : public Move {
public:
    Retaliate() : Move("Retaliate", 2) {}
};

// Lizard Moves ==============================================
class Rake : public Move {
public:
    Rake() : Move("Rake", 4) {}
};

class Fangs : public Move {
public:
    Fangs() : Move("Fangs", 3) {}
};

class Slam : public Move {
public:
    Slam() : Move("Tail Slam", 2) {}
};

class Shed : public Move {
public:
    Shed() : Move("Skin Shed", -2, "self") {}
};

// Automaton Moves ==============================================
class Fire : public Move {
public:
    Fire() : Move("Molten Core", 6) {}
};

class Repair : public Move {
public:
    Repair() : Move("Emergency Repair", -2, "self") {}
};

class Error : public Move {
public:
    Error() : Move("Short Circuit", 3, "self") {}
};

// MonsterA Moves ==============================================
class Thorns : public Move {
public:
    Thorns() : Move("Thorns", 3) {}
};

class Tangle : public Move {
public:
    Tangle() : Move("Tangle", 2) {}
};

class Absorb : public Move {
public:
    Absorb() : Move("Absorb", -4, "self") {}
};

class Poison : public Move {
public:
    Poison() : Move("Seep Poison", 3) {}
};

// Misc Moves ==============================================
class Moan : public Move {
public:
    Moan() : Move("Pitiful Moan", 2, "self") {}
};

#endif
