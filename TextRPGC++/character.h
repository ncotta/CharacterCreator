#ifndef CHARACTER_H
#define CHARACTER_H

#include "selection.h"
#include "enemyHandler.h"

class Character {
protected:
    string name;
    Race race;
    Class_ class_;
    int stats[4];
    int statsSize;
    vector<Move> moves;
    int hp;
    // vector<Item> inventory;


public:
    Character();
    // Character(string nameIn, Race raceIn, Class_ classIn, 
    // int *statsIn, vector<Move>& movesIn);
    ~Character();

    void printInfo();
};


class Enemy {
protected:
    string name;
    Race race;
    Class_ class_;
    int stats[4];
    int statsSize;
    vector<Move> moves;
    int hp;
    // vector<Item> inventory;


public:
    Enemy();
    ~Enemy();

    void printInfo();
};

#endif