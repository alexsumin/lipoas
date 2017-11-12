#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct ForCalculate {
	int size;
	double *array = new double[size];
};

struct Answer{
	double sum;
	int firstBorder;
	int secondBorder;
};

int getInt() {
	int number;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
		if (cin.fail()) {
			cout << "Please enter a valid integer value" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail());
	return number;
}

double getDouble() {
	double number;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
		if (cin.fail()) {
			cout << "Please enter a valid double value" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail());
	return number;
}

/*
ifstream fout(path)
if fout.is_open()
*/

ForCalculate enterArray() {
	cout << "Enter the size of array" << endl;
	int size = getInt();
	double *array = new double[size];

	cout << "Enter all elements of array" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = getDouble();
	}
	cout << "Got it!" << endl;
	ForCalculate forCalc = { size, array };

	return forCalc;
}

ForCalculate readFromFile() {
	//ifstream file;
	int size = 0;
	cout << "Enter the path to file" << endl;
	string path;
	cin >> path;
	ForCalculate forCalc;

	ifstream ifs("C:\\Users\\alex\\Desktop\\d.txt");
	//ifs.open(path, std::ifstream::in);
	//file.open(path);
	/*
	if (file.is_open()) {
		file >> size;
		
		double *array = new double[size];
		for (int i = 0; i < size; i++) {
			file >> array[i];
		}

		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		forCalc = { size, array };
		file.close();
	}
	else {
		cout << "Incorrect path! Try again" << endl;
	}

	*/

	while (!ifs.eof()) {
		size++;
	}
	ifs.close();
	cout << size;
	double arr[2] = { 1, 2 };
	return forCalc = { 0, arr };
	

}


Answer findSum(ForCalculate forCalc) {
	int size = forCalc.size;
	double *array = forCalc.array;
	double ans = array[0];
	int ans_l = 0;
	int ans_r = 0;
	double sum = 0;
	int minus_pos = -1;
	for (int i = 0; i < forCalc.size; ++i) {
		sum += array[i];

		if (sum > ans) {
			ans = sum;
			ans_l = minus_pos + 1;
			ans_r = i;
		}

		if (sum < 0) {
			sum = 0;
			minus_pos = i;
		}
	}

	Answer answer = { ans, ans_l, ans_r };
	return answer;
}

void hello() {
	cout << "Hello here" << endl;
}

void showResult(Answer answer) {
	cout << answer.sum << " " << answer.firstBorder << " " << answer.secondBorder << endl;
	system("pause");
}

void secondInput() {
	int option;
	do {
		cin.clear();
		cout << "Choose an option: " << endl;
		cout << "1. Read from a file" << endl;
		cout << "2. Enter in concole" << endl;
		cout << "3. Run unti-tests" << endl;
		cout << "4. Cancel" << endl;

		cin >> option;

		switch (option) {

		case 1: {
			ForCalculate forCalc = readFromFile();
			Answer answer = findSum(forCalc);
			showResult(answer);
		}
		case 2: {
			ForCalculate forCalc = enterArray();
			Answer answer = findSum(forCalc);
			showResult(answer);
			}
			break;
		case 3:
		case 4:
		default: {

		}
		}
	} while (true);
}


void firstInput() {
	string choice;
	int option;
	
	do {
		cin.clear();
		cout << "Choose an option: " << endl;
		cout << "1. Start" << endl;
		cout << "2. Exit" << endl;
		cin >> option;
		switch (option) {
		case 1:
			secondInput();
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
}




int main() {

	//double A[] = { 3.0, -7.5, 4.2, 1.0, -6.0 };
	
	hello();
	firstInput();
	

	system("pause");


	return 0;
}