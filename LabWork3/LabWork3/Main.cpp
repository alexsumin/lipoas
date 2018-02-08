#include "Calculate.h"
#include "Test.h"
#include <string.h>
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;
enum input { START = 1, QUIT = 2 };

void hello() {
	cout << "Hello! This simple program solves the problem of " << endl
		<< "finding the longest common substring. Also it displays" << endl
		<< "a length, a starting position and text." << endl
		<< "Author 444 group's student Aleksandr Sumin, github.com/alexsumin" << endl << endl;
}

void showMainMenu() {
	cout << "Main menu" << endl;
	cout << "Choose an option" << endl;
	cout << "[1] Start" << endl;
	cout << "[2] Exit" << endl;
}

int main() {
	system("mode con cols=80 lines=22");
	setlocale(LC_ALL, "Russian");
	bool(*tests[])(void) = { test1, test2, test3, test4, test5 };
	bool areAllTestsSuccessful = true;

	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
		if (!tests[i]()) {
			cout << "Test " << i + 1 << " didn't pass!" << endl;
			areAllTestsSuccessful = false;
		}
	if (areAllTestsSuccessful)
		cout << "Tests passed!" << endl;
	
	int choice;
	hello();
	do {
		showMainMenu();
		choice = GetInt();
		switch (choice) {
			case START:
				calculate();
				break;
			case QUIT:
				cout << endl << "Goodbye!" << endl;
			default:
				cout << "Incorrect choice! Try again!" << endl;
				system("pause");
		}
		cout << endl;
	} while (choice != QUIT);
	system("pause");
	return 0;
	
}
