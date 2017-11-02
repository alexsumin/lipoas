#include <iostream>      
#include <cmath>
#include <string>

using namespace std;

struct Parabola {
	double a, b, c;
};

struct Interval {
	double leftBorder, rightBorder;
};

struct Answer {
	bool isFind;
	double root;
};

void swap(Interval interval) {
	double temp = interval.leftBorder;
	interval.leftBorder = interval.rightBorder;
	interval.leftBorder = temp;
	cout << "Interval borders changed" << endl;
}

double calcFunc(Parabola parabola, double x) {
	return (parabola.a*x*x + parabola.b*x + parabola.c);
}

Answer binSearch(Parabola parabola, Interval interval, double epsilon) {
	int count = 0;
	double border1 = interval.leftBorder;
	double border2 = interval.rightBorder;
	double center = (border1 + border2)*0.5;
	double calculated;

	do {
		calculated = calcFunc(parabola, center);
		if (calcFunc(parabola, border1)*calcFunc(parabola, center) > 0) {
			border1 = center;
		}
		else {
			border2 = center;
		}
		center = (border2 + border1) * 0.5;
		count++;
	} while (((fabs(border2 - border1) > epsilon) & count < 32));

	Answer answer;
	if (calculated < epsilon) {
		answer.isFind = true;
		answer.root = center;
	}
	else answer.isFind = false;

	return answer;
}


double getDouble() {
	double number;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
		if (cin.fail())
		{
			cout << "Please enter a valid double value" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail());
	return number;
}

double getNotZero() {
	double number;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
		if (cin.fail() || number == 0)
		{
			cout << "Please enter a valid double value (not zero)" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail());
	return number;
}


int getInt() {
	int number;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
		if (cin.fail()) {
			cout << "Please enter a valid int value" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail());
	return number;
}

void hello() {
	cout << "Hello! This simple program represents a binary search for root"
		" of a function likes y=a*x^2+b*x+c. You should define the function's coefficients, the borders of interval "
		"and the precision(epsilon).\n"
		"Author 444 group's student Aleksandr Sumin, github.com/alexsumin" << endl;
	}


bool isChangedSign(double first, double second) {
	if ((first > 0 && second > 0) || (first < 0 && second < 0))
		return false;
	else return true;
}

Parabola setParabola() {
	Parabola parabola;
	cout << "Enter the coefficients a, b, and c: \n";
	parabola.a = getNotZero();
	parabola.b = getDouble();
	parabola.c = getDouble();
	return parabola;
}

Interval setInterval() {
	Interval interval;
	do {
		cout << "Enter the borders for search interval. \n";
		cout << "Enter the left border: " << endl;
		interval.leftBorder = getDouble();
		cout << "Enter the right border: " << endl;
		interval.rightBorder = getDouble();
	} while (interval.leftBorder == interval.rightBorder);

	if (interval.leftBorder > interval.rightBorder)
		swap(interval);
	return  interval;
}

double setEpsilon() {
	double epsilon;
	do {
		cout << "So, enter the epsilon within 0.1 - 0.0001" << endl;
		epsilon = getDouble();
	} while (epsilon > 0.1 | epsilon < 0.0001);
	return epsilon;
}

void showResult(Answer answer) {
	if (answer.isFind == false)
		cout << "Ooups! Couldn't find the root\n";
	else {
		cout << "Root of function is " << answer.root << endl;
	}
	system("pause");
}


int main() {
	string choice;
	int option;
	double epsilon;
	
	hello();
	
	do {
		cin.clear();
		cout << "Choose an option: " << endl;
		cout << "1. Start" << endl;
		cout << "2. Exit" << endl;

		cin >> option;

		switch (option) {

		case 1:
			Parabola parabola = setParabola();
			Interval interval = setInterval();
			if (!isChangedSign(calcFunc(parabola, interval.leftBorder), calcFunc(parabola, interval.rightBorder))) {
				cout << "There isn't root in the interval!" << endl;
				break;
			}
			epsilon = setEpsilon();
		

			Answer answer = binSearch(parabola, interval, epsilon);
			showResult(answer);
			break;

		case 2:
			cout << "Goodbye!";
			system("pause");
			exit(0);

		default:
			cout << "Incorrect input!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

		cout << "Press Y for continue or any key for exit" << endl;
		cin >> choice;

	} while (choice == "y" || choice == "Y");

	system("pause");
	return 0;
}
