#include "selection.h"

Selection::Selection() {
	for (int i = 0; i < (sizeof(stats) / sizeof(stats[0])); i++)
		stats[i] = 0;
} 

Selection::Selection(int* statsIn) {
	for (int i = 0; i < (sizeof(stats) / sizeof(stats[0])); i++)
		stats[i] = statsIn[i];
}

Selection::~Selection() {}

Race Selection::race_select() {
	/*
	*             strength  magic  defense  speed
	* Werebeast         12      6       12     10  
	* Automaton          8     14        8     10  
	* Monster-A         12     12        8      8
	*/
	string races[3] = { "Werebeast   (physically powerful, little latent magic)",
						"Automaton   (magically powerful, physically lacking without upgrades)",  
						"Monster-A   (well-rounded, quite slow)"};  
	
	int choice;
	Race result;
	int raceLen = sizeof(races) / sizeof(races[0]);

	while (true) {
		cout << "Pick a race!" << endl;
		for (int i = 0; i < raceLen; i++) {
			cout << "[" << i + 1 << "] " << races[i] << endl;
		}
		cout << ">> ";

		if ((cin >> choice) && (int(choice) <= raceLen)) {
			cout << choice << endl;
			break;
		}
		else {
			cout << "Invalid input!" << endl;
			cin.clear();
		}
	}

	switch (choice) {
		case 1:  // Werebeast
			stats[0] = 12;
			stats[1] = 6;
			stats[2] = 12;
			stats[3] = 10;

			result = Werebeast(stats);
			break;
		case 2:  // Automaton
			cout << "You have selected Automaton (chkpt 1)" << endl;
			stats[0] = 8;
			stats[1] = 14;
			stats[2] = 8;
			stats[3] = 10;

			cout << "You have selected Automaton (chkpt 2)" << endl;

			result = Automaton(stats);
			cout << "You have selected Automaton (chkpt 3)" << endl;
			break;
		case 3:  // MonsterA
			stats[0] = 12;
			stats[1] = 12;
			stats[2] = 8;
			stats[3] = 8;

			result = MonsterA(stats);
			break;
		default:
			result = Race();
			break;
	}

	return result;
}

Class_ Selection::class_select() {
	string classes[3] = {"Weapons Master  (+str)",
						 "Monk-ey         (+def)",
						 "Sorceress       (+mag)"};

	int choice;
	int classLen = sizeof(classes) / sizeof(classes[0]);
	Class_ result;

	while (true) {
		cout << "Pick a class!" << endl;
		for (int i = 0; i < classLen; i++) {
			cout << "[" << i + 1 << "] " << classes[i] << endl;
		}
		cout << ">> ";

		if ( (cin >> choice) && (choice <= classLen) ) {
			break;
		}
		else {
			cout << "Invalid input!" << endl;
			cin.clear();
		}
	}

	switch (choice) {
		case 1:  // Weapons Master
			result = Master(stats);
			break;
		case 2:  // Monk-ey
			result = MonkEY(stats);
			break;
		case 3:  // Sorceress
			result = Sorceress(stats);
			break;
		default:
			result = Class_();
	}

	return result;

}
