#include <iostream> 
#include <fstream>
#include <string>
#include <experimental\filesystem>
using namespace std::experimental::filesystem;
using namespace std;

enum menuItem { START = 1, OVERRIDE_FILE = 1, ENTER_THE_ARRAY = 1, READ_FROM_FILE = 2, SAVE_RESULT = 1, BACK = 3, QUIT = 2 };

static string SYSTEM_WORDS[] = { "con", "prn", "aux", "nul", "com1", "com2", "com3", "com4", "com5", "com5",
"com6", "com7", "com9", "lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };
struct ArrayWithSize {
	int *array;
	int size;
	ArrayWithSize() {
	}
	ArrayWithSize(int *arr, int s) {
		array = arr;
		size = s;
	}
	~ArrayWithSize() {
		if (array)
			delete[] array;
	}
};

static const int SIZE_OF_TESTARRAYS = 8;
static int* testArray1 = new int[SIZE_OF_TESTARRAYS];
static int* testArray2 = new int[SIZE_OF_TESTARRAYS];
static int* testArray3 = new int[SIZE_OF_TESTARRAYS];
static int* testArray4 = new int[SIZE_OF_TESTARRAYS];
static int* testArray5 = new int[SIZE_OF_TESTARRAYS];
static int* arrayFromAnswer1 = new int[8];
static int* arrayFromAnswer2 = new int[8];
static int* arrayFromAnswer3 = new int[6];
static int* arrayFromAnswer4 = new int[2];
static int* arrayFromAnswer5 = new int[1];
static ArrayWithSize *testData1 = new ArrayWithSize( testArray1, 8 );
static ArrayWithSize *testData2 = new ArrayWithSize(testArray2, 8 );
static ArrayWithSize *testData3 = new ArrayWithSize(testArray3, 8 );
static ArrayWithSize *testData4 = new ArrayWithSize(testArray4, 8 );
static ArrayWithSize *testData5 = new ArrayWithSize(testArray5, 8 );
static ArrayWithSize *expectedTestData1 = new ArrayWithSize(arrayFromAnswer1, 7 );
static ArrayWithSize *expectedTestData2 = new ArrayWithSize(arrayFromAnswer2, 8 );
static ArrayWithSize *expectedTestData3 = new ArrayWithSize(arrayFromAnswer3, 6 );
static ArrayWithSize *expectedTestData4 = new ArrayWithSize(arrayFromAnswer4, 2 );
static ArrayWithSize *expectedTestData5 = new ArrayWithSize(arrayFromAnswer5, 1 );
static ArrayWithSize testsData[5];
static ArrayWithSize expectedTestsData[5];
static int forInitTestArray1[] = { 4, 3, 5, 3, 2, 1, 8, 7 };
static int forInitTestArray2[] = { 4, 42, 15, 31, 0, 1, 8, 7 };
static int forInitTestArray3[] = { 4, 3, 3, 3, 2, 1, 8, 7 };
static int forInitTestArray4[] = { 4, 4, 4, 4, 1, 4, 4, 4 };
static int forInitTestArray5[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
static int forInitTArrayFromAnswer1[] = { 4, 3, 5, 2, 1, 8, 7 };
static int forInitTArrayFromAnswer2[] = { 4, 42, 15, 31, 0, 1, 8, 7 };
static int forInitTArrayFromAnswer3[] = { 4, 3, 2, 1, 8, 7 };
static int forInitTArrayFromAnswer4[] = { 4, 1 };
static int forInitTArrayFromAnswer5[] = { 0 };

void initTestData() {
	for (int i = 0; i < SIZE_OF_TESTARRAYS; i++) {
		testArray1[i] = forInitTestArray1[i];
		testArray2[i] = forInitTestArray2[i];
		testArray3[i] = forInitTestArray3[i];
		testArray4[i] = forInitTestArray4[i];
		testArray5[i] = forInitTestArray5[i];
	}
	testsData[0] = *testData1;
	testsData[1] = *testData2;
	testsData[2] = *testData3;
	testsData[3] = *testData4;
	testsData[4] = *testData5;
}

void initExpectedData() {
	for (int i = 0; i < SIZE_OF_TESTARRAYS; i++) {
		arrayFromAnswer1[i] = forInitTArrayFromAnswer1[i];
		arrayFromAnswer2[i] = forInitTArrayFromAnswer2[i];
	}
	for (int i = 0; i < 6; i++) {
		arrayFromAnswer3[i] = forInitTArrayFromAnswer3[i];
	}
	for (int i = 0; i < 2; i++) {
		arrayFromAnswer4[i] = forInitTArrayFromAnswer4[i];
	}
	arrayFromAnswer5[0] = forInitTArrayFromAnswer5[0];
	expectedTestsData[0] = *expectedTestData1;
	expectedTestsData[1] = *expectedTestData2;
	expectedTestsData[2] = *expectedTestData3;
	expectedTestsData[3] = *expectedTestData4;
	expectedTestsData[4] = *expectedTestData5;
}

 
ArrayWithSize* solveTask(ArrayWithSize * forCalc) {
	int size = forCalc->size;
	int *array = forCalc->array;
	int *tempArray = new int[size];

	int curIndex = 0;
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

	ArrayWithSize *answer = new ArrayWithSize;
	answer->array = finalArray; 
	answer->size = curIndex;
	
	return answer;
}

bool unitTest(ArrayWithSize * forCalc, ArrayWithSize * expected) {
	ArrayWithSize * calculated = solveTask(forCalc);
	if (calculated->size != expected->size) 
		return false;
	bool isPass = true;
	for (size_t i = 0; i < calculated->size; i++) {
		if (calculated->array[i] != expected->array[i])
			isPass = false;
	}
	if (isPass)	return true;
	else return false;
}

void runUnitTests() {
	initExpectedData();
	initTestData();
	bool areAllTestsSuccessful = true;
	for (size_t i = 0; i < 5; i++) {
		if (!unitTest(&testsData[i], &expectedTestsData[i])) {
			areAllTestsSuccessful = false;
			cout << "Test " << i + 1 << " didn't pass!" << endl;
		}
	}
	if (areAllTestsSuccessful)
		cout << "Tests passed!" << endl;
	cout << endl;
}
	

bool isSystemWord(string forCheck) {
	for (auto str : SYSTEM_WORDS) {
		if (forCheck == str) 
			return true;	
		}
	return false;
}

void showResult(ArrayWithSize * answer) {
	cout << "Array after removing:" << endl;
	for (size_t i = 0; i < answer->size; i++) 
		cout << answer->array[i] << " ";
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

ArrayWithSize* enterArray() {
	int size;
	cout << "Enter size of array" << endl;
	do {
		cout << "Value must be a greater than 0" << endl;
		size = getValue<int>();
	} while (size <= 0);
		
	cout << "Enter elements of array" << endl;
	int *array = new int[size];
	for (size_t i = 0; i < size; i++) {
		cout << i + 1 << ". ";
		array[i] = getValue<int>();
	}
	ArrayWithSize *forCalc = new ArrayWithSize;
	forCalc->size = size;
	forCalc->array = array;
	
	return forCalc;
}

ArrayWithSize* readFromFile() {
	ifstream file;
	string path;
	int size = 0;
	do {
		cout << "Enter path to the file: " << endl;
		cin >> path;
		file.open(path);
		if (!is_regular_file(path)) {
			cout << "Wrong filename!" << endl;
			file.close();
			continue;
		}
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
		
	int *array = new int[size];
	size_t count = 0;
	while (count < size) {
		file >> num;
		if (file.fail()) {
			file.close();
			if (array) delete array;
			throw "Something's wrong!";
		}
		array[count++] = num;
	}
	ArrayWithSize *forCalc = new ArrayWithSize;
	forCalc->array = array;
	forCalc->size = size;

	file.close();
	for (size_t i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return forCalc;
}

void saveToFile(ArrayWithSize * answer) {
	string path;
	bool isWrotten = false;
	int rewrite = OVERRIDE_FILE;
	do {
		cout << "Enter a path: " << endl;
		cin >> path;
		if (isSystemWord(path)) {
			cout << "Incorrect name!" << endl;
			continue;
		}
		ifstream fout(path);
		if (fout.is_open()) {
			cout << "\nFile already exists! Press 1 to override, press any number to cancel\n";
			fout.close();
			rewrite = getValue<int>();
		}
		if (rewrite == OVERRIDE_FILE) {
			ofstream fout(path);
			if (fout.is_open()) {
				fout << answer->size << " ";
				for (size_t i = 0; i < answer->size; i++) {
					fout << answer->array[i] << " ";
				}
				fout.close();
				isWrotten = true;
				cout << "Succesfull!" << endl;
			}
		}
	} while (!isWrotten);
}

bool showSaveDialog() {
	int choice = 0;
	bool result = false;
	cout << "Press 1 to save that, any number to continue" << endl;
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
	ArrayWithSize *forCalc = new ArrayWithSize;
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
			ArrayWithSize *answer = new ArrayWithSize;
			answer = solveTask(forCalc);
			cout << "done!" << endl;
			showResult(answer);
			if (showSaveDialog()) 
				saveToFile(answer);
			isRead = false;
			if (forCalc) delete forCalc;
			if (answer) delete answer;
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
			cout << endl << "Goodbye!" ;
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
