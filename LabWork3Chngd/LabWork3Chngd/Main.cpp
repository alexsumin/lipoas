#pragma once
#include "Solver.h"
#include <fstream> 
#include <string>
#include "CoutModified.h"
#include "Tests.h"

using namespace std;
enum input { START = 1, QUIT = 2 };
extern CoutModified coutMod;

void hello() {
	coutMod << "Hello! This simple program solves the problem of " << endl
		<< "finding the longest common substring. Also it displays" << endl
		<< "a length, a starting position and text." << endl
		<< "Author 444 group's student Aleksandr Sumin, github.com/alexsumin" << endl << endl;
}

void showMainMenu() {
	coutMod << "Main menu" << endl;
	coutMod << "Choose an option" << endl;
	coutMod << "[1] Start" << endl;
	coutMod << "[2] Exit" << endl;
}

int main() {
	//system("mode con cols=80 lines=22");
	setlocale(LC_ALL, "Russian");
	runUnitTests();
	int choice = 0;
	hello();
	do {
		showMainMenu();
		choice = getUsersInput();
		switch (choice) {
		case START:
			solveTask();
			break;
		case QUIT:
			coutMod << endl << "Goodbye!" << endl;
			break;
		default:
			coutMod << "Incorrect choice! Try again!" << endl;
			system("pause");
		}
		coutMod << endl;
	} while (choice != QUIT);
	system("pause");
	return 0;

}
