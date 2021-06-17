#ifndef CLASS_H
#define CLASS_H

#include <string>
using namespace std;

class Class_ {
protected:
    string name;
    string appearance;
    int stats[3];

public:
    Class_();
    Class_(string nameIn, string appearanceIn, int *statsIn);
    ~Class_();

    void queryLooks();
};

// Brute Class ==============================================
class Brute : public Class_ {
public:
    Brute(int *statsList)
        : Class_("Brute",
            "Scars mark you as someone with fighting experience. Your arms are corded with muscles.",
            statsList) {
        statsList[0] += 2;
    }
};

// Monk-ey Class ==============================================
class MonkEY : public Class_ {
public:
    MonkEY(int *statsList)
        : Class_("Monk-ey",
            "As one of the monks from beyond the Great Eastern Sea, your unique fighting style involves feces, unfortunately",
            statsList) {
        statsList[2] += 2;
    }
};

// Witch Doctor Class ==============================================
class WitchDoctor : public Class_ {
public:
    WitchDoctor(int *statsList)
        : Class_("Witch Doctor",
            "Exotic and offputting, you were a slave from the south. No one knows if you're a witch or a doctor.",
            statsList) {
        statsList[1] += 2;
    }

};

#endif