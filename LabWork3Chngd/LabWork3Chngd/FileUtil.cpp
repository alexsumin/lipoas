#include "FileUtil.h"
#include <experimental/filesystem>

using namespace std::experimental::filesystem;
static int CRLF = 4;
enum io { OVERRIDE_FILE = 1 };
static string SYSTEM_WORDS[] = { "con", "prn", "aux", "nul", "com1", "com2", "com3", "com4", "com5", "com5", 
							"com6", "com7", "com9", "lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

void saveToFile(Answer answer) {
	string path;
	bool isWrite = false;
	size_t rewrite = OVERRIDE_FILE;
	do {
		coutMod << "Enter a path: " << endl;
		cin >> path;
		if (isSystemWord(path)) {
			coutMod << "Incorrect name!" << endl;
			continue;
		}
		ifstream fout(path);
		if (fout.is_open()) {
			coutMod << "\nFile already exists! Press 1 to override, press any key number to cancel\n";
			fout.close();
			rewrite = getUsersInput();
		}
		if (rewrite == OVERRIDE_FILE) {
			ofstream fout(path);
			if (fout.is_open()) {
				fout << "Substring of files: " << endl;
				for (size_t k = 0; k < answer.length; ++k) {
					fout << answer.substring[k];
				}
				fout << " " << endl;
				fout << "Length of substring: " << endl;
				fout << answer.length << endl;
				fout << "Starting position of a substring of " << answer.files.firstFile << " is " << endl;
				fout << answer.indexOfFirstFile << endl;
				fout << "Starting position of a substring of " << answer.files.secondFile << " is " << endl;
				fout << answer.indexOfSecondFile << endl;
				fout.close();
				isWrite = true;
				coutMod << "\nFile created!" << endl;
			}
			else {
				coutMod << "\nFile '" << path << " can't be created!\n";
			}
		}
	} while (!isWrite);
}

bool isSystemWord(string forCheck) {
	for (auto str : SYSTEM_WORDS) { 
		if (forCheck == str) {
			return true;
		}
	}
	return false;
}

string getFilename(string number) {
	string filename;
	bool isOpened = false;
	do  {
		coutMod << "Enter a name of a " << number << " file: ";
		cin >> filename;
		if (!is_regular_file(filename)) {
			cout << "File doesn't exist or file is empty. Try again. " << endl;
			continue;
		}
		else {
			isOpened = true;
		}
	} while (!isOpened);
	return filename;
}

char * getBuffer(string filename) {
	int fileSize = 0;
	char *buffer;
	ifstream fin(filename, ios::binary);
	if (fin.is_open()) {
		fin.seekg(0, ifstream::end);
		fileSize = fin.tellg();
		fin.seekg(0);
		buffer = new char[fileSize - CRLF];
		fin.read(buffer, fileSize);
		fin.close();
		return buffer;
	}
}



