#include "Calculate.h"
#include <experimental/filesystem>

using namespace std::experimental::filesystem;
enum io { OVERRIDE_FILE = 1, WRITE = 1 };

int GetInt() {
	int tmp;
	cin >> tmp;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\n Enter a valid value!" << endl;
		cin >> tmp;
	}
	return tmp;
}
size_t getCommonLength(char* str1, char* str2) {
	size_t length = 0;
	while (*str1 && *str1++ == *str2++) {
		++length;
	}
	return length;
}

string getFilename(string number, char * &buffer) {
	string filename;
	while (true) {
		cout << "Enter a name of a " << number << " file: ";
		cin >> filename;
		bool isOpened = false;
		if (!is_regular_file(filename)) {
			cout << "File doesn't exist or file is empty. Try again. " << endl;
			isOpened = false;
			continue;
		}
		isOpened = true;
		buffer = filework(filename);
		if (isOpened)
			break;
	}
	return filename;
}
void calculate() {
	string filename1;
	string filename2;
	size_t currentLength;
	size_t maxLenght = 0;
	char* maxSubstring = 0;
	int type;
	char *buffer1 = 0;
	char *buffer2 = 0;
	filename1 = getFilename("first", buffer1);
	filename2 = getFilename("second", buffer2);

	while (filename1 == filename2) {
		cout << "Files are same!" << endl;
		filename2 = getFilename("second", buffer2);
	} 
		

	int len1 = strlen(buffer1);
	int len2 = strlen(buffer2);
	int indexOfFirstFile;
	int indexOfSecondFile;

	for (int i = 0; i < len1 - maxLenght; ++i) {
		for (int j = 0; j < len2 - maxLenght; ++j) {
			currentLength = getCommonLength(buffer1 + i, buffer2 + j);
			if (currentLength > maxLenght) {
				maxLenght = currentLength;
				maxSubstring = buffer1 + i;
				indexOfFirstFile = i;
				indexOfSecondFile = j;
			}
		}
	}
	cout << "Substring of files: " << endl;
	for (int k = 0; k < maxLenght; ++k) {
		cout << maxSubstring[k];
	}
	cout << " " << endl;
	cout << "Length of substring: " << endl;
	cout << maxLenght << endl;
	cout << "Starting position of a substring of " << filename1 << " is " << endl;
	cout << (indexOfFirstFile) << endl;
	cout << "Starting position of a substring of " << filename2 << " is " << endl;
	cout << (indexOfSecondFile) << endl;
	cout << "\nPress 1 to write to file. Press any number to cancel" << endl;
	type = GetInt();
	if (type == WRITE) {
		string fileToSave;
		int rewrite = 1;
		cout << "Enter a filename: ";
		cin >> fileToSave;
		ifstream finCheck(fileToSave);
		if (!is_regular_file(fileToSave) | finCheck.is_open()) {
			cout << "Incorrect name or file already exists. Press 1 to override, press any number to cancel" << endl;
			rewrite = GetInt();
		}
		/*if (finCheck.is_open()) {
			cout << "File already exists. Press 1 to override, press any number to cancel" << endl;
			rewrite = GetInt();
		}*/
		finCheck.close();
		if (rewrite == OVERRIDE_FILE) {
			ofstream fin(fileToSave);
			if (fin.is_open()) {
				fin << "Substring of files: " << endl;
				for (int k = 0; k < maxLenght; ++k) {
					fin << maxSubstring[k];
				}
				fin << " " << endl;
				fin << "Length of substring: " << endl;
				fin << maxLenght << endl;
				fin << "Starting position of a substring of " << filename1 << " is " << endl;
				fin << (indexOfFirstFile) << endl;
				fin << "Starting position of a substring of " << filename2 << " is " << endl;
				fin << (indexOfSecondFile) << endl;
				fin.close();
				cout << "\nFile created! " << endl;
			}
			else {
				cout << "\nFile '" << fileToSave << "' can't be created!\n";
			}
		}
	}
	system("pause");
}
