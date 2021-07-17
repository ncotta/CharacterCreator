#include "class.h"
#include <iostream>

Class_::Class_() {
    name = "Class-ic Ragu";
    appearance = "I shouldn't be here!";
}

Class_::Class_(string nameIn, string appearanceIn, int *statsIn) {
    name = nameIn;
    appearance = appearanceIn;
    
    for (int i = 0; i < (sizeof(stats) / sizeof(stats[0])); i++)
        stats[i] = statsIn[i];
}

Class_::~Class_() {}

void Class_::queryLooks() {
    cout << appearance << endl;
}

string Class_::getName() {
    return name;
}