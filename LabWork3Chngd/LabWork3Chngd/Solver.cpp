#include<iostream>
#include<string>
#include"FileUtil.h"
#include"Solver.h"

enum menuItem { OVERRIDE_FILE = 1, SAVE_RESULT = 1 };

int max(int a, int b) {
	return (a > b) ? a : b;
}

int getUsersInput() {
	int tmp;
	cin >> tmp;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		coutMod << "\nEnter a valid value!" << endl;
		cin >> tmp;
	}
	return tmp;
}

bool showSaveDialog() {
	int choice = 0;
	bool result = false;
	coutMod << "Press 1 to write to file. Press any number to cancel" << endl;
	choice = getUsersInput();
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

void showAnswer(Answer * answer) {
	coutMod << "Substring of files: " << endl;
	for (size_t i = 0; i < answer->length; i++) {
		coutMod << answer->substring[i];
	}
	coutMod << " " << endl;
	coutMod << "Length of substring: " << endl;
	coutMod << answer->length << endl;
	coutMod << "Starting position of a substring of " << answer->files.firstFile << " is " << endl;
	coutMod << answer->indexOfFirstFile << endl;
	coutMod << "Starting position of a substring of " << answer->files.secondFile << " is " << endl;
	coutMod << answer->indexOfSecondFile << endl;
}

void solveTask() {
	string filename1 = getFilename("first");
	string filename2 = getFilename("second");

	while (filename1 == filename2) {
		coutMod << "Files are same!" << endl;
		filename2 = getFilename("second");
	}
	FilesForReading filesForReading = { filename1, filename2 };
	Answer * answer = getSubstring(filesForReading);
	showAnswer(answer);
	if (showSaveDialog()) {
		saveToFile(answer);
	}
	if (answer) delete answer;
}

Answer* getSubstring(FilesForReading filesForReading) {

	char * buffer1 = getBuffer(filesForReading.firstFile);
	char * buffer2 = getBuffer(filesForReading.secondFile);

	size_t length1 = strlen(buffer1);
	size_t length2 = strlen(buffer2);

	size_t **LCSuff = new size_t*[length1 + 1];
	for (size_t count = 0; count < length1 + 1; count++)
		LCSuff[count] = new size_t[length2 + 1];
	size_t result = 0;

	for (size_t i = 0; i <= length1; i++) {
		for (size_t j = 0; j <= length2; j++) {
			if (i == 0 || j == 0) {
				LCSuff[i][j] = 0;
			}
			else if (buffer1[i - 1] == buffer2[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else LCSuff[i][j] = 0;
		}
	}
	char *lcs = new char[result];

	size_t index1 = 0; size_t index2 = 0;
	size_t max = 0, imax = 0, jmax = 0;

	for (size_t i = 0; i <= length1; i++) {
		for (size_t j = 0; j <= length2; j++) {
			if (LCSuff[i][j] > max) {
				max = LCSuff[i][j];
				imax = i;
				jmax = j;
			}
		}
	}

	index1 = imax - result;
	index2 = jmax - result;

	for (size_t i = 0; i < result; i++) {
		lcs[i] = buffer1[index1 + i];
	}
	
	for (size_t count = 0; count < length1 + 1; count++)
		delete[] LCSuff[count];
		
	delete[] LCSuff;

	Answer *answer = new Answer();
	answer->substring = lcs;
	answer->length = result;
	answer->indexOfFirstFile = index1;
	answer->indexOfSecondFile = index2;
	answer->files = filesForReading;
	return answer;
}