#pragma once
#include <string>
#include "FileUtil.h"
#include "CoutModified.h"

using namespace std;
extern CoutModified coutMod;
struct FilesForReading {
	string firstFile;
	string secondFile;
	FilesForReading() {}
	FilesForReading(string filename1, string filename2) {
		firstFile = filename1;
		secondFile = filename2;
	}
};
struct Answer {
	char *substring;
	size_t length = 0;
	size_t indexOfFirstFile = 0;
	size_t indexOfSecondFile = 0;
	FilesForReading files;
};

void showAnswer(Answer answer);
Answer getSubstring(FilesForReading filesForReading);
void solveTask();
int getUsersInput();
