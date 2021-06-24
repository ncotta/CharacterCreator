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
    string getName();
    void printMoves();
    void queryLooks();
};

// Dummy Race ==============================================
class Dummy : public Race {
private:
    vector<Move> dummyMoves = { Splinter(), Glare(), Retaliate() };
public:
    Dummy(int* statsList)
        : Race("Dummy",
            "a training dummy. It fixes you with a sinister glare.",
            statsList,
            dummyMoves) {}
};

// Lizard Race ============================================
class Lizard : public Race {
private:
    vector<Move> lizardMoves = { Rake(), Fangs(), Slam(), Shed() };
public:
    Lizard(int *statsList)
        : Race("Lizard",
            "a hulking lizard with green scales that glisten in the sun. You lick your eyeball and bare your teeth in a menacing way.",
            statsList,
            lizardMoves) {}
};

// Automaton Race ==========================================
class Automaton : public Race {
private:
    vector<Move> automatonMoves = { Fire(), Repair(), Error() };
public:
    Automaton(int *statsList)
        : Race("Automaton",
            "a feeble machine far past it's warranty. You can remember the lost arts of civilization before The Schism.",
            statsList,
            automatonMoves) {}
};

// MonsterA Race ==========================================
class MonsterA : public Race {
private:
    vector<Move> monsteraMoves = { Thorns(), Tangle(), Absorb(), Poison() };
public:
    MonsterA(int *statsList)
        : Race("Monster-a",
            "a plant with beautiful fenestrations. Gaia's Blessing gives you sentience.",
            statsList,
            monsteraMoves) {}
};

// Tutorial Enemy Race ===================================
class Beast : public Race {
private:
    vector<Move> beastMoves = { Moan() };
public:
    Beast(int *statsList)
        : Race("Beast",
            "Only a creature touched by a Prophet would be affected so",
            statsList,
            beastMoves) {}
};

#endif`