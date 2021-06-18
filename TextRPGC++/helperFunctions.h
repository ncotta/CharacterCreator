#ifndef HELP_H
#define HELP_H

#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>

int getChoice(string* inList, T (*f)(T));
void delayPrint(string s, float delay);
void enumPrint(string* inList);


#endif