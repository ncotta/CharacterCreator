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

    for (int i = 0; i < 3; i++)
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

void Race::queryLooks() {
    cout << "You appear to be..." << appearance << endl;
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