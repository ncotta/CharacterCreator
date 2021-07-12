#include "enemyHandler.h"
#include <iostream>

randEnemy::randEnemy() {
	for (int i = 0; i < 4; i++) {
		stats[i] = rand() % (15 - 6) + 6;
	}

	races[0] = new Lizard(stats);
	races[1] = new Automaton(stats);
	races[2] = new MonsterA(stats);
	
	classes[0] = new Brute(stats);
	classes[1] = new MonkEY(stats);
	classes[2] = new WitchDoctor(stats);

	// Name generation
	prefixLizard[0] = "Spiked";
	prefixLizard[1] = "Starving";
	prefixLizard[2] = "Rabid";

	prefixAutomaton[0] = "Rusted";
	prefixAutomaton[1] = "Malfunctioning";
	prefixAutomaton[2] = "Defective";

	prefixMonsterA[0] = "Rotted";
	prefixMonsterA[1] = "Blighted";
	prefixMonsterA[2] = "Diseased";

	// Moves lists (put in moves.h?)
	lizardMoves.push_back(Rake());
	lizardMoves.push_back(Fangs());
	lizardMoves.push_back(Slam());
	lizardMoves.push_back(Shed());

	automatonMoves.push_back(Fire());
	automatonMoves.push_back(Repair());
	automatonMoves.push_back(Error());

	monsteraMoves.push_back(Thorns());
	monsteraMoves.push_back(Tangle());
	monsteraMoves.push_back(Absorb());
	monsteraMoves.push_back(Poison());
}

randEnemy::~randEnemy() {
	for (int i = 0; i < 3; i++) {
		delete races[i];
		delete classes[i];
	}
}

Race randEnemy::randomRace() {
	int randNum = rand() % 3;
	return *races[randNum];

}

Class_ randEnemy::randomClass() {
	int randNum = rand() % 3;
	return *classes[randNum];
}

string randEnemy::randomName(Race raceIn) {
	int randNum = rand() % 3;
	string prefix;
	string raceName = raceIn.getName();

	if (raceName == "Lizard")
		prefix = prefixLizard[randNum];
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

	if (raceName == "Lizard")
		result = lizardMoves;
	else if (raceName == "Automaton")
		result = automatonMoves;
	else if (raceName == "Monster-a")
		result = monsteraMoves;

	return result;
}
