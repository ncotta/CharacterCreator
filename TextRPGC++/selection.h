#ifndef SELECT_H
#define SELECT_H

#include "race.h"
#include "class.h"
using namespace std;

class Selection {
private:
	int stats[4];

public:
	Selection();
	Selection(int* statsIn);
	~Selection();

	Race race_select();
	Class_ class_select();
};


#endif