#include "enemyHandler.h"
#include <iostream>

randEnemy::randEnemy() {
	for (int i = 0; i < (sizeof(stats) / sizeof(stats[0])); i++) {
		stats[i] = rand() % (15 - 6) + 6;
	}

	races[0] = new Werebeast(stats);
	races[1] = new Automaton(stats);
	races[2] = new MonsterA(stats);
	
	classes[0] = new Master(stats);
	classes[1] = new MonkEY(stats);
	classes[2] = new Sorceress(stats);

	// Name generation
	prefixBeast[0] = "Starved";
	prefixBeast[1] = "Rabid";
	prefixBeast[2] = "Depraved";

	prefixAutomaton[0] = "Rusted";
	prefixAutomaton[1] = "Malfunctioning";
	prefixAutomaton[2] = "Defective";

	prefixMonsterA[0] = "Rotted";
	prefixMonsterA[1] = "Blighted";
	prefixMonsterA[2] = "Diseased";

	// Moves lists (put in moves.h?)
	beastMoves.push_back(Rake());
	beastMoves.push_back(Fangs());
	beastMoves.push_back(Slam());
	beastMoves.push_back(Shed());

	automatonMoves.push_back(Fire());
	automatonMoves.push_back(Repair());
	automatonMoves.push_back(Error());

	monsteraMoves.push_back(Thorns());
	monsteraMoves.push_back(Tangle());
	monsteraMoves.push_back(Absorb());
	monsteraMoves.push_back(Poison());
}

randEnemy::~randEnemy() {
	for (int i = 0; i < (sizeof(races) / sizeof(races[0])); i++)
		delete races[i];

	for (int i = 0; i < (sizeof(classes) / sizeof(classes[0])); i++)
		delete classes[i];
}

Race randEnemy::randomRace() {
	int randNum = rand() % (sizeof(races) / sizeof(races[0]));
	return *races[randNum];

}

Class_ randEnemy::randomClass() {
	int randNum = rand() % (sizeof(classes) / sizeof(classes[0]));
	return *classes[randNum];
}

string randEnemy::randomName(Race raceIn) {
	int randNum = rand() % 3;
	string prefix;
	string raceName = raceIn.getName();

	if (raceName == "Werebeast")
		prefix = prefixBeast[randNum];
	else if (raceName == "Automaton")
		prefix = prefixAutomaton[randNum];
	else if (raceName == "Monster-a")
		prefix = prefixMonsterA[randNum];

	return (prefix + " " + raceName);
}

vector<Move> randEnemy::randomMoves(Race raceIn) {
	//int numRaces = sizeof(stats)/sizeof(stats[0]);
	//int start = rand() % numRaces;  // 2  moves[2:
	//int remaining = numRaces - (start + 1);  // 0
	//int end = rand() % remaining + start;  // moves[2:

	vector<Move> result;
	string raceName = raceIn.getName();

	if (raceName == "Werebeast")
		result = beastMoves;
	else if (raceName == "Automaton")
		result = automatonMoves;
	else if (raceName == "Monster-a")
		result = monsteraMoves;

	return result;
}
