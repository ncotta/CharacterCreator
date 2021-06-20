#include <iostream>
#include <Windows.h>

#include "selection.h"

int main(int argc, char* argv[]) {

	Selection mySelection;
	mySelection.race_select();
	mySelection.class_select();

	return 0;
}