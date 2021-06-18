#include "selection.h"

Selection::Selection() {}

Selection::Selection(int* statsIn) {
	for (int i = 0; i < 4; i++)
		stats[i] = statsIn[i];
}

Selection::~Selection() {}

Race Selection::race_select() {
	string races[4] = { "Lizard      (very strong, a bit sluggish)",  // str [12, 10, 8]
						"Automaton   (very formidable, a bit weak)",  // magic [8, 12, 10]
						"Monster-A   (very fast, a bit fragile)" };  // defense [10, 8, 12]
	
	Class_ result;

	while (true) {

	}
}

/*
* 
* strength  magic
*  defense  speed
* 
*/