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
	string prefixLizard[3] = { "Spiked", "Starving", "Rabid" };
	string prefixAutomaton[3] = { "Rusted", "Malfunctioning", "Defective" };
	string prefixMonsterA[3] = { "Rotted", "Blighted", "Diseased" };

	// Moves lists (put in moves.h?)
	vector<Move> lizardMoves = { Rake(), Fangs(), Slam(), Shed() };
	vector<Move> automatonMoves = { Fire(), Repair(), Error() };
	vector<Move> monsteraMoves = { Thorns(), Tangle(), Absorb(), Poison() };
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
	int numRaces = sizeof(stats)/sizeof(stats[0]);
	int start = rand() % numRaces;  // 2  moves[2:
	int remaining = numRaces - (start + 1);  // 0
	int end = rand() % remaining + start;  // moves[2:

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
