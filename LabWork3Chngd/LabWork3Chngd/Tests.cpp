#include"Tests.h"
#include<string>

static char* expectedString1 = "Примеры будут основываться на функциях стандартных библиотек, ";
static char* expectedString2 = "Чем меньше женщину мы любим, тем ";
static char* expectedString3 = "Представьте, что в городе ";
static char* expectedString4 = "cultural and political contexts ";
static char* expectedString5 = "для теста";

static FilesForReading testFiles1("test1first.txt", "test1second.txt");
static FilesForReading testFiles2("test2first.txt", "test2second.txt");
static FilesForReading testFiles3("test3first.txt", "test3second.txt");
static FilesForReading testFiles4("test4first.txt", "test4second.txt");
static FilesForReading testFiles5("test5first.txt", "test5second.txt");

void runUnitTests() {
	test(testFiles1, expectedString1);
	test(testFiles2, expectedString2);
	test(testFiles3, expectedString3);
	test(testFiles4, expectedString4);
	test(testFiles5, expectedString5);
	coutMod << endl;
};

void test(FilesForReading testFiles, char* expectedString) {
	Answer answer = getSubstring(testFiles);
	for (size_t i = 0; i < answer.length; i++) {
		if (answer.substring[i] != expectedString[i]) {
			coutMod << "Test didn't pass!" << endl;
			return;
		}
	}
	coutMod << "Test passed!" << endl;
}


