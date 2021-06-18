#ifndef RACE_H
#define RACE_H


#include "moves.h"
#include <vector>

class Race {
protected:
    string name;
    string appearance;
    int stats[4];  // {strength, magic, defense, speed}
    vector<Move> moves;

public:
    Race();
    Race(string nameIn, string appearanceIn,
        int *statsIn, vector<Move>& movesIn);
    ~Race();

    void queryName();
    void queryLooks();
};

// Dummy Race ==============================================
class Dummy : public Race {
public:
    Dummy(int *statsList, vector<Move>& movesList)
        : Race("Dummy",
            "a training dummy. It fixes you with a sinister glare.",
            statsList,
            movesList) {}
};

// Lizard Race ============================================
class Lizard : public Race {
public:
    Lizard(int *statsList, vector<Move>& movesList)
        : Race("Lizard",
            "a hulking lizard with green scales that glisten in the sun. You lick your eyeball and bare your teeth in a menacing way.",
            statsList,
            movesList) {}
};

// Automaton Race ==========================================
class Automaton : public Race {
public:
    Automaton(int *statsList, vector<Move>& movesList)
        : Race("Automaton",
            "a feeble machine far past it's warranty. You can remember the lost arts of civilization before The Schism.",
            statsList,
            movesList) {}
};

// MonsterA Race ==========================================
class MonsterA : public Race {
public:
    MonsterA(int *statsList, vector<Move>& movesList)
        : Race("Monster-a",
            "a plant with beautiful fenestrations. Gaia's Blessing gives you sentience.",
            statsList,
            movesList) {}
};

// Tutorial Enemy Race ===================================
class Beast : public Race {
public:
    Beast(int *statsList, vector<Move>& movesList)
        : Race("Bestial and rabid",
            "Only a creature touched by a Prophet would be affected so",
            statsList,
            movesList) {}
};

#endif