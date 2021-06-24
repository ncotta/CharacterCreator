#include "selection.h"

Selection::Selection() {
	for (int i = 0; i < 4; i++)
		stats[i] = 0;
} 

Selection::Selection(int* statsIn) {
	for (int i = 0; i < 4; i++)
		stats[i] = statsIn[i];
}

Selection::~Selection() {}

Race Selection::race_select() {
	/*
	*             strength  magic  defense  speed
	* Lizard      14        6      10       10
	* Automaton   8         16     8        8
	* MonsterA    8         12     12       8
	*/
	string races[3] = { "Lizard      (physically powerful, little magical ability)",
						"Automaton   (physically weak, very strong lunar magic)",  
						"Monster-A   (good defense and sun magic, well-rounded)"};  
	
	int choice;
	Race result;

	while (true) {
		cout << "Pick a race!" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "[" << i + 1 << "] " << races[i] << endl;
			// Sleep(0.25);
		}

		if ( (cin >> choice) && (choice <= 3) ) {
			break;
		}
		else {
			cout << "Invalid input!" << endl;
			cin.clear();
		}
	}

	switch (choice) {
		case 1:  // Lizard
			stats[0] = 14;
			stats[1] = 6;
			stats[2] = 10;
			stats[3] = 10;

			result = Lizard(stats);
			break;
		case 2:  // Automaton
			stats[0] = 8;
			stats[1] = 16;
			stats[2] = 8;
			stats[3] = 8;

			result = Automaton(stats);
			break;
		case 3:  // MonsterA
			stats[0] = 8;
			stats[1] = 12;
			stats[2] = 12;
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
	string classes[4] = {"Brute         (+str)",
						 "MonkEY        (+def)",
						 "Witch Doctor  (+mag)"};

	int choice;
	Class_ result;

	while (true) {
		cout << "Pick a class!" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "[" << i + 1 << "] " << classes[i] << endl;
			// Sleep(0.25);
		}

		if ((cin >> choice) && (choice <= 3)) {
			break;
		}
		else {
			cout << "Invalid input!" << endl;
			cin.clear();
		}
	}

	switch (choice) {
		case 1:  // Brute
			result = Brute(stats);
			break;
		case 2:  // MonkEY
			result = MonkEY(stats);
			break;
		case 3:  // Witch Doctor (change name)
			result = WitchDoctor(stats);
			break;
		default:
			result = Class_();
	}

	return result;

}

/*
* int main() {
*	Selection mySelection;
*	mySelection.race_select();
*	mySelection.class_select();
*/
