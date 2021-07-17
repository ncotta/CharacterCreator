#ifndef RACE_H
#define RACE_H


#include "moves.h"
#include <vector>
#include <iostream>


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

    void queryLooks();
    string getName();
    void printMoves();
    vector<Move> getMoves();
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

// Werebeast Race ============================================
class Werebeast : public Race {
private:
    vector<Move> beastMoves = { Rake(), Fangs(), Slam(), Regenerate() };
public:
    Werebeast(int *statsList)
        : Race("Werebeast",
            "a powerful looking creature. You appear human but with beastly characteristics.",
            statsList,
            beastMoves) {}
};

// Automaton Race ==========================================
class Automaton : public Race {
private:
    // vector<Move> automatonMoves = { Fire(), Repair(), Error() };
    vector<Move> automatonMoves = { Rake(), Fangs(), Slam(), Regenerate() };
public:
    Automaton(int *statsList)
        : Race("Automaton",
            "an early automaton. When Helios created you, their process was not as refined as it is now.",
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
            "a savage and wild sentient plant. A life deity has granted you both knowledge and power.",
            statsList,
            monsteraMoves) {}
};

// Tutorial Enemy Race ===================================
class Creature : public Race {
private:
    vector<Move> creatureMoves = { Moan() };
public:
    Creature(int *statsList)
        : Race("Creature",
            "Only a creature touched by a Prophet would be affected so",
            statsList,
            creatureMoves) {}
};

#endif