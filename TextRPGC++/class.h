#ifndef CLASS_H
#define CLASS_H

#include <string>
using namespace std;

class Class_ {
protected:
    string name;
    string appearance;
    int stats[4];    // {strength, magic, defense, speed}

public:
    Class_();
    Class_(string nameIn, string appearanceIn, int *statsIn);
    ~Class_();

    void queryLooks();
    string getName();
    int *getStats();
};

// Weapons Master Class ==============================================
class Master : public Class_ {
public:
    Master(int *statsList)
        : Class_("Weapons Master",
            "Many scars signify you have quite a lot of battle experience. What you lack in magic you "
            "make up for in battle knowledge and a mastery of most weapons.",
            statsList) {
        statsList[0] += 2;  // +str
    }
};

// Monk-ey Class ==============================================
class MonkEY : public Class_ {
public:
    MonkEY(int *statsList)
        : Class_("Monk-ey",
            "You are a battle monk initiate from beyond the Great Eastern Sea. Your defensive style " 
            "can emulate various primate species around the island you trained at. Bananas are your favorite food, coincidentally.",
            statsList) {
        statsList[2] += 2;  // +def
    }
};

// Sorcerer/Sorceress Class ===========================================
class Sorceress : public Class_ {
public:
    Sorceress(int *statsList)
        : Class_("Sorceress",
            "Dragons have granted you enormous raw magical talent. But because of this, "
            "you were unable to hone this power at an academy, and have little control as of yet.",
            statsList) {
        statsList[1] += 2;  // +mag
    }

};

#endif