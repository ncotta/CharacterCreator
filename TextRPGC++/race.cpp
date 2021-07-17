#include "race.h"
#include <iostream>

Race::Race() {
    name = "Missingno";
    appearance = "I shouldn't be here!";
    moves = {};
}

Race::Race(string nameIn, string appearanceIn,
        int *statsIn, vector<Move>& movesIn) {
    name = nameIn;
    appearance = appearanceIn;

    for (int i = 0; i < (sizeof(stats) / sizeof(stats[0])); i++)
        stats[i] = statsIn[i];

    moves = movesIn;
}

Race::~Race() {}

void Race::queryName() {
    string suffix[3] = { "clan.", "people.", "race." };
    srand(time(0));
    string res = suffix[rand() % 3];
    cout << "You are one of the " << name << " " << res << endl;
}

string Race::getName() {
    return name;
}

void Race::printMoves() {
    if (moves.size() == 0)
        cout << "SOMETHING WENT WRONG: NO MOVES!!" << endl;

    for (int i = 0; i < moves.size(); i++) {
        moves[i].printInfo();
    }
}

/* int main() {
    Race myRace();
    int myStats[3] = {12, 10, 8};
    vector<Move> myMoves = {Rake(), Fangs(), Slam(), Shed()};
    Lizard myLizard(myStats, myMoves);

    myLizard.queryName();
    myLizard.queryLooks();

    return 0;
}
*/