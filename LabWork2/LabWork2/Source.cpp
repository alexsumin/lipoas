#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum menuItem { START = 1, ENTER_THE_ARRAY = 1, READ_FROM_FILE = 2, SAVE_RESULT = 1, BACK = 3, QUIT = 2};

struct Answer {
	double sum;
	double firstElement;
	double lastElement;
};

static Answer expectedAnswer1 = { 123, 109, 14 };
static Answer expectedAnswer2 = { 45.45, 45.45, 45.45 };
static Answer expectedAnswer3 = { 1556.35, 243, 1213 };
static Answer expectedAnswer4 = { 0, 0, 0 };
static Answer expectedAnswer5 = { 0.0087, 0.0023, 0.0045 };

static vector<double>testData1 = { 53, 14, -23, -118, 109, 14 };
static vector<double>testData2 = { 0, 2.03, 4.01, -6.12, -8.3, 45.45 };
static vector<double>testData3 = { 243, 432.01, -15.67, 98, 0.01, -756, 342, 1213, -12045, 129, 547.06 };
static vector<double>testData4 = { 0 };
static vector<double> testData5 = { -0.0034, -0.0432, 0.0023, 0.0019, 0.0045, -0.003, 0.001, 0.0012 };

Answer findSum(vector<double> vector) {
	int size = vector.size();
	double maxSum = vector[0];
	int maxStartIndex = 0;
	int maxEndIndex = 0;
	double currentMaxSum = 0;
	int currentEndIndex = -1;
	for (int i = 0; i < size; ++i) {
		currentMaxSum += vector[i];
		if (currentMaxSum > maxSum) {
			maxSum = currentMaxSum;
			maxStartIndex = currentEndIndex + 1;
			maxEndIndex = i;
		}
		if (currentMaxSum < 0) {
			currentMaxSum = 0;
			currentEndIndex = i;
		}
	}

	Answer answer = { maxSum, vector[maxStartIndex], vector[maxEndIndex] };
	return answer;
};

void unitTest1() {
	Answer calculated = findSum(testData1);
	if ((expectedAnswer1.sum == calculated.sum) &&
		(expectedAnswer1.firstElement == calculated.firstElement)
		&& (expectedAnswer1.lastElement == calculated.lastElement))
		cout << "Test passed!" << endl;
	else
		cout << "Test didn't pass!" << endl;
}

void unitTest2() {
	Answer calculated = findSum(testData2);
	if ((expectedAnswer2.sum == calculated.sum) &&
		(expectedAnswer2.firstElement == calculated.firstElement)
		&& (expectedAnswer2.lastElement == calculated.lastElement))
		cout << "Test passed!" << endl;
	else
		cout << "Test didn't pass!" << endl;
}

void unitTest3() {
	Answer calculated = findSum(testData3);
	if ((expectedAnswer3.sum == calculated.sum) &&
		(expectedAnswer3.firstElement == calculated.firstElement)
		&& (expectedAnswer3.lastElement == calculated.lastElement))
		cout << "Test passed!" << endl;
	else
		cout << "Test didn't pass!" << endl;
}

void unitTest4() {
	Answer calculated = findSum(testData4);
	if ((expectedAnswer4.sum == calculated.sum) &&
		(expectedAnswer4.firstElement == calculated.firstElement)
		&& (expectedAnswer4.lastElement == calculated.lastElement))
		cout << "Test passed!" << endl;
	else
		cout << "Test didn't pass!" << endl;
}

void unitTest5() {
	Answer calculated = findSum(testData5);
	if ((expectedAnswer5.sum == calculated.sum) &&
		(expectedAnswer5.firstElement == calculated.firstElement)
		&& (expectedAnswer5.lastElement == calculated.lastElement))
		cout << "Test passed!" << endl;
	else
		cout << "Test didn't pass!" << endl;
}


void showResult(Answer answer) {
	cout << "Sum = " << answer.sum << ", first element = "
		<< answer.firstElement << ", last element = "
		<< answer.lastElement << endl;
	system("pause");
}

void runUnitTests() {
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();
	cout << endl;
}

void hello() {
	cout << "Hello! This simple program implements Kadane's Algorithm " << endl 
		<< "for finding the maximum contiguous subsequence in a one-dimensional sequence."<< endl 
		<< "Author 444 group's student Aleksandr Sumin, github.com/alexsumin" << endl << endl;
}

void showMainMenu() {
	cout << "Main menu" << endl;
	cout << "Choose an option" << endl;
	cout << "[1] Start" << endl;
	cout << "[2] Exit" << endl;
}

void displayStartMenu() {
	cout << "Well, choose an option" << endl;
	cout << "[1] Enter an array" << endl;
	cout << "[2] Read an array from file" << endl;
	cout << "[3] Back" << endl;

}

vector<double> readFromFile() {
	ifstream file;
	string path;
	int size = 0;
	cout << "Enter path to the file" << endl;
	cin >> path;
	file.open(path);
	if (!file.is_open()) {
		throw "File doesn't exist!";
	}

	vector<double>doubles;
	double num;
	
	while (!file.eof()) {
		file >> num;
		if (file.fail()) {
			file.close();
			throw "Something's wrong!";
		}
		doubles.push_back(num);
	}
	file.close();

	for (int i = 0; i < doubles.size(); i++) {
		cout << doubles[i] << " ";
	}
	cout << endl;
	return doubles;
}

template <typename T>
T getValue() {
	T number;
	cin >> number;
	while (cin.fail()) {
		cout << "Please enter a valid value" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
	}
	return number;
}

vector<double> enterArray() {
	int size;
	cout << "Enter size of array (more than 0)" << endl;
	do {
		size = getValue<int>();
	} while (size <= 0);
	vector<double> vector(size);

	cout << "Enter elements of array" << endl;

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". ";
		vector[i] = getValue<double>();
	}
	return vector;
}

void saveToFile(Answer answer) {
	string path;
	bool isWrotten = false;
	do {
		cout << "Enter a path: " << endl;
		cin >> path;
		ifstream fout(path);
		if (fout.is_open()) {
			cout << "\nFile already exists!\n";
			fout.close();
		}
		else {
			ofstream fout(path);
			if (fout.is_open()) {
				fout << "Sum = " << answer.sum;
				fout << ", first element = " << answer.firstElement << ", last element = " << answer.lastElement;
				fout.close();
				isWrotten = true;
				cout << "Succesfull!" << endl;
			}
			else cout << "\nIncorrect path! Try again\n";
		}
	} while (!isWrotten);
}

bool showSaveDialog(Answer answer) {
	int choice = 0;
	bool res = false;
	cout << "Would you like to save results?" << endl;
	cout << "[1] Yes" << endl;
	cout << "[2] No" << endl;
	choice = getValue<int>();
	switch (choice) {
	case(SAVE_RESULT): {
		res = true;
		break;
	}
	default:
		break;
	}
	return res;
}


void start() {
	string result;
	int choice = 0;
	ifstream file;
	bool isRead = false;
	vector<double> vector;

	do {
		cout << endl;
		displayStartMenu();
		choice = getValue<int>();
		switch (choice) {
		case ENTER_THE_ARRAY: {
			vector = enterArray();
			isRead = true;
			break;
		}
		case READ_FROM_FILE: {
			try {
				vector = readFromFile();
				isRead = true;
			}
			catch (char* msg) {
				cout << msg << endl;
				return;
			}
			break;
		}
		case BACK:
			break;
		default:
			cout << "Incorrect choice!" << endl;
			break;
		}
		if (isRead) {
			Answer answer = findSum(vector);
			showResult(answer);
			if (showSaveDialog(answer)) {
				saveToFile(answer);
			}
		}

	} while (choice != BACK);

}

int main() {
	int choice = 0;
	hello();
	runUnitTests();
	do {
		showMainMenu();
		choice = getValue<int>();
		switch (choice) {

		case START:
			start();
			break;
		case QUIT:
			cout << endl << "Goodbye!" << endl;
			break;
		default:
			cout << "Incorrect choice!" << endl;
			system("pause");
		}
		cout << endl;
	} while (choice != QUIT);
	system("pause");
	return 0;
}
