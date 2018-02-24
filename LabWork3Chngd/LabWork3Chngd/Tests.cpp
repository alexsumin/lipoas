#include"Tests.h"
#include<string>
//
//static char* expectedString1 = "Примеры будут основываться на функциях стандартных библиотек, ";
//static char* expectedString2 = "Чем меньше женщину мы любим, тем ";
//static char* expectedString3 = "Представьте, что в городе ";
//static char* expectedString4 = "cultural and political contexts ";
//static char* expectedString5 = "для теста";
//
//static FilesForReading testFiles1("test1first.txt", "test1second.txt");
//static FilesForReading testFiles2("test2first.txt", "test2second.txt");
//static FilesForReading testFiles3("test3first.txt", "test3second.txt");
//static FilesForReading testFiles4("test4first.txt", "test4second.txt");
//static FilesForReading testFiles5("test5first.txt", "test5second.txt");

static char* expectedString1 = new char[62];
static char* expectedString2 = new char[33];
static char* expectedString3 = new char[26];
static char* expectedString4 = new char[32];
static char* expectedString5 = new char[9];

void initExpectedData() {
	string str1 = "Примеры будут основываться на функциях стандартных библиотек, ";
	string str2 = "Чем меньше женщину мы любим, тем ";
	string str3 = "Представьте, что в городе ";
	string str4 = "cultural and political contexts ";
	string str5 = "для теста";
	for (int i = 0; i < 62; i++) {
		expectedString1[i] = str1[i];
	}
	for (int i = 0; i < 33; i++) {
		expectedString2[i] = str2[i];
	}
	for (int i = 0; i < 26; i++) {
		expectedString3[i] = str3[i];
	}
	for (int i = 0; i < 32; i++) {
		expectedString4[i] = str4[i];
	}
	for (int i = 0; i < 9; i++) {
		expectedString5[i] = str5[i];
	}
}

void runUnitTests() {
	initExpectedData();

	FilesForReading testFiles1("test1first.txt", "test1second.txt");
	FilesForReading testFiles2("test2first.txt", "test2second.txt");
	FilesForReading testFiles3("test3first.txt", "test3second.txt");
	FilesForReading testFiles4("test4first.txt", "test4second.txt");
	FilesForReading testFiles5("test5first.txt", "test5second.txt");
	test(testFiles1, expectedString1);
	test(testFiles2, expectedString2);
	test(testFiles3, expectedString3);
	test(testFiles4, expectedString4);
	test(testFiles5, expectedString5);
	coutMod << endl;
};

void test(FilesForReading testFiles, char* expectedString) {
	Answer * answer = getSubstring(testFiles);
	for (size_t i = 0; i < answer->length; i++) {
		if (answer->substring[i] != expectedString[i]) {
			coutMod << "Test didn't pass!" << endl;
			return;
		}
	}
	coutMod << "Test passed!" << endl;
}


