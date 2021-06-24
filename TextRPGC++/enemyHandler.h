#ifndef HANDLER_H
#define HANDLER_H

#include "selection.h"
#include <iostream>
using namespace std;

class randEnemy {
protected:
	int stats[4];
	Race* races[3];
	Class_* classes[3];

	// Name generation
	string prefixLizard[3];
	string prefixAutomaton[3];
	string prefixMonsterA[3];

	// Moves lists (put in moves.h?)
	vector<Move> lizardMoves;
	vector<Move> automatonMoves;
	vector<Move> monsteraMoves;

public:
	randEnemy();
	~randEnemy();

	Race randomRace();
	Class_ randomClass();

	string randomName(Race raceIn);
	vector<Move> randomMoves(Race raceIn);

};

#endif