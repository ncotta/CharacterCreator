#include "character.h"

// Character class implementation ===============================================

Character::Character() {
    cout << "What is your name?" << endl << ">> ";
    cin >> name;

    Selection mySelection;
    race = mySelection.race_select();
    class_ = mySelection.class_select();
    hp = 20;

    statsSize = sizeof(stats) / sizeof(stats[0]);
    for (int i = 0; i < statsSize; i++)
        stats[i] = class_.getStats()[i];

    moves = race.getMoves();
}

Character::~Character() {}

void Character::printInfo() {
    int attack = stats[0];
    int magic = stats[1];
    int defense = stats[2];
    int speed = stats[3];

    cout << "======= Character Info =======" << endl;
    cout << "Hello, " << name << endl;
    race.queryLooks();
    class_.queryLooks();
    cout << "You are a " << race.getName() << " and a " << class_.getName() << " to boot!" << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attack << endl;
    cout << "Magic: " << magic << endl;
    cout << "Defense: " << defense << endl;
    cout << "Speed: " << speed << endl;
    cout << "==============================" << endl << endl;
}

// Enemy class implementation ===============================================

Enemy::Enemy() {
    randEnemy myEnemy;
	race = myEnemy.randomRace();
	class_ = myEnemy.randomClass();
    hp = 20;
	name = myEnemy.randomName(race);

    statsSize = sizeof(stats) / sizeof(stats[0]);
    for (int i = 0; i < statsSize; i++)
        stats[i] = class_.getStats()[i];
    
    moves = myEnemy.randomMoves(race);
}

Enemy::~Enemy() {}

void Enemy::printInfo() {
    int attack = stats[0];
    int magic = stats[1];
    int defense = stats[2];
    int speed = stats[3];

    cout << "========= Enemy Info =========" << endl;
    cout << "Name: " << name << endl;
    cout << "Class: " << class_.getName() << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attack << endl;
    cout << "Magic: " << magic << endl;
    cout << "Defense: " << defense << endl;
    cout << "Speed: " << speed << endl;
    cout << "==============================" << endl << endl;
}