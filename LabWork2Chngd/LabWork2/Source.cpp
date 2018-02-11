#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
using namespace std::experimental::filesystem;

enum menuItem { START = 1, ENTER_THE_ARRAY = 1, READ_FROM_FILE = 2, SAVE_RESULT = 1, BACK = 3, QUIT = 2};

struct ArrayWithSize {
	int *array;
	int size = 0;
	ArrayWithSize() {
	}
	ArrayWithSize(int s) {
		size = s;
		array = new int[s];
	}
	ArrayWithSize(int *arr, int s) {
		array = arr;
		size = s;
	}
};

static const int SIZE_OF_TESTARRAYS = 8;

static int testArray1[] = { 4, 3, 5, 3, 2, 1, 8, 7 };
static int testArray2[] = { 4, 42, 15, 31, 0, 1, 8, 7 };
static int testArray3[] = { 4, 3, 3, 3, 2, 1, 8, 7 };
static int testArray4[] = { 4, 4, 4, 4, 1, 4, 4, 4 };
static int testArray5[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

static ArrayWithSize testData1 = { testArray1, 8 };
static ArrayWithSize testData2 = { testArray2, 8 };
static ArrayWithSize testData3 = { testArray3, 8 };
static ArrayWithSize testData4 = { testArray4, 8 };
static ArrayWithSize testData5 = { testArray5, 8 };

static int arrayFromAnswer1[] = { 4, 3, 5, 2, 1, 8, 7 };
static int arrayFromAnswer2[] = { 4, 42, 15, 31, 0, 1, 8, 7 };
static int arrayFromAnswer3[] = { 4, 3, 2, 1, 8, 7 };
static int arrayFromAnswer4[] = { 4, 1 };
static int arrayFromAnswer5[] = { 0 };

static ArrayWithSize expectedTestData1 = { arrayFromAnswer1, 7 };
static ArrayWithSize expectedTestData2 = { arrayFromAnswer2, 8 };
static ArrayWithSize expectedTestData3 = { arrayFromAnswer3, 6 };
static ArrayWithSize expectedTestData4 = { arrayFromAnswer4, 2 };
static ArrayWithSize expectedTestData5 = { arrayFromAnswer5, 1 };

ArrayWithSize solveTask(ArrayWithSize forCalc) {
	int size = forCalc.size;
	int *array = forCalc.array;
	int *tempArray = new int[size];

	size_t curIndex = 0;
	bool isFound = false;

	for (size_t i = 0; i < size; i++) {
		isFound = false;
		for (size_t j = 0; j < curIndex; j++) {
			if (tempArray[j] == array[i]) {
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			tempArray[curIndex++] = array[i];		
		}
	}
	int *finalArray = new int[curIndex];

	for (size_t i = 0; i < curIndex; i++)
		finalArray[i] = tempArray[i];
	delete[] tempArray;

	ArrayWithSize answer;
	answer.array = finalArray;
	answer.size = curIndex;
	

	return answer;
}

void unitTest(ArrayWithSize forCalc, ArrayWithSize expected) {
	ArrayWithSize calculated = solveTask(forCalc);
	if (calculated.size != expected.size) {
		cout << "Test didn't pass!" << endl;
		return;
	}
	bool isPass = true;
	for (size_t i = 0; i < calculated.size; i++) {
		if (calculated.array[i] != expected.array[i])
			isPass = false;
	}
	if (isPass) {
		cout << "Test passed!" << endl;
	}
	else {
		cout << "Test didn't pass!" << endl;
	}
}

void runUnitTests() {
	unitTest(testData1, expectedTestData1);
	unitTest(testData2, expectedTestData2);
	unitTest(testData3, expectedTestData3);
	unitTest(testData4, expectedTestData4);
	unitTest(testData5, expectedTestData5);
	cout << endl;
}

void showResult(ArrayWithSize answer) {
	cout << "Array after removing:" << endl;
	for (size_t i = 0; i < answer.size; i++) {
		cout << answer.array[i] << " ";
	}
	cout << endl;
}

void hello() {
	cout << "Hello! This simple program implements algorithm " << endl 
		<<  "to remove duplicate values from an array"<< endl 
		<<  "Author 444 group's student Aleksandr Sumin, github.com/alexsumin" << endl << endl;
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

ArrayWithSize enterArray() {
	int size;
	cout << "Enter size of array (more than 0)" << endl;
	do {
		size = getValue<int>();
	} while (size <= 0);
	ArrayWithSize forCalc(size);

	cout << "Enter elements of array" << endl;

	for (size_t i = 0; i < size; i++) {
		cout << i + 1 << ". ";
		forCalc.array[i] = getValue<int>();
	}
	return forCalc;
}

ArrayWithSize readFromFile() {
	ifstream file;
	string path;
	int size = 0;
	do {
		cout << "Enter path to the file: " << endl;
		cin >> path;
		file.open(path);
		if (!file.is_open()) {
			cout << "File doesn't exist!" << endl;
		}
	} while (!file.is_open());

	int num;
	file >> size;
	if (file.fail()) {
		file.close();
		throw "Something's wrong!";
	}
	ArrayWithSize forCalc(size);
	size_t count = 0;
	while (count < size) {
		file >> num;
		if (file.fail()) {
			file.close();
			throw "Something's wrong!";
		}
		forCalc.array[count++] = num;
	}

	file.close();
	for (int i = 0; i < forCalc.size; i++) {
		cout << forCalc.array[i] << " ";
	}
	cout << endl;
	return forCalc;
}



void saveToFile(ArrayWithSize answer) {
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
				fout << answer.size << " ";
				for (int i = 0; i < answer.size; i++) {
					fout << answer.array[i] << " ";
				}
				fout.close();
				isWrotten = true;
				cout << "Succesfull!" << endl;
			}
			else cout << "\nIncorrect path! Try again\n";
		}
	} while (!isWrotten);
}

bool showSaveDialog() {
	int choice = 0;
	bool result = false;
	cout << "Would you like to save that?" << endl;
	cout << "[1] Yes" << endl;
	cout << "[2] No" << endl;
	choice = getValue<int>();
	switch (choice) {
		case(SAVE_RESULT): {
			result = true;
			break;
		}
		default:
			break;
		}
	return result;
}

void start() {
	string result;
	int choice = 0;
	ifstream file;
	bool isRead = false;
	ArrayWithSize forCalc;
	do {
		cout << endl;
		displayStartMenu();
		choice = getValue<int>();
		switch (choice) {
		case ENTER_THE_ARRAY: {		
			forCalc = enterArray();
			isRead = true;
			if (showSaveDialog())
				saveToFile(forCalc);
			break;
		}
		case READ_FROM_FILE: {
			while (!isRead) {
				try {
					forCalc = readFromFile();
					isRead = true;
				}
				catch (char* msg) {
					cout << msg << endl;
					return;
				}
			}
			break;
		}
		case BACK:
			isRead = false;
			break;
		default:
			cout << "Incorrect choice!" << endl;
			break;
		}
		if (isRead) {
			ArrayWithSize answer = solveTask(forCalc);
			cout << "done!" << endl;
			showResult(answer);
			if (showSaveDialog()) 
				saveToFile(answer);
			isRead = false;
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
