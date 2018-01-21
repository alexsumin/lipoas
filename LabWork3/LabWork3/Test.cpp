#include "Test.h"
#include "Calculate.h"

bool test1() {
	size_t maxLength = 0;
	size_t currentLength;
	char* maxSubstring = 0; 
	int i,j,k;
	char *buffer;
	char *buffer2;
	int fileSize;
	string filename;
	filename="test1first.txt"; 
	buffer = filework(filename);
	filename = "test1second.txt";	
	buffer2 = filework(filename);
		
	int len1 = strlen(buffer);
	int len2 = strlen(buffer2);

	for (i = 0; i < len1 - maxLength; ++i) {
		for (j = 0; j < len2 - maxLength; ++j) {
			currentLength = getCommonLength(buffer + i, buffer2 + j);
			if (currentLength > maxLength) { 
				maxLength = currentLength;
				if (maxSubstring != NULL) {
					delete[] maxSubstring;
				}
				size_t maxStrSize = maxLength + 1;
				maxSubstring = new char[maxStrSize];
				for (int m = 0; m < maxLength; m++)
					maxSubstring[m] = buffer[i + m];
				maxSubstring[maxStrSize - 1] = '\0';
			}
		}
	}
	
	return (strcmp(maxSubstring, "Примеры будут основываться на функциях стандартных библиотек, ") == 0);
}

bool test2() {
	size_t maxLength = 0;
	size_t currentLength;
	char* maxSubstring = 0; int i, j, k;
	char *buffer3;
	char *buffer4;
	string filename;
	filename = "test2first.txt";
	buffer3 = filework(filename);
	filename = "test2second.txt";
	buffer4 = filework(filename);

	int len1 = strlen(buffer3);
	int len2 = strlen(buffer4);

	for (i = 0; i < len1 - maxLength; ++i) {
		for (j = 0; j < len2 - maxLength; ++j) {
			currentLength = getCommonLength(buffer3 + i, buffer4 + j);
			if (currentLength > maxLength) { 
				maxLength = currentLength;
				if (maxSubstring != NULL) {
					delete[] maxSubstring;
				}
				size_t maxStrSize = maxLength + 1;
				maxSubstring = new char[maxStrSize];
				for (int m = 0; m < maxLength; m++)
					maxSubstring[m] = buffer3[i + m];
				maxSubstring[maxStrSize - 1] = '\0';
			}
		}
	}
	return (strcmp(maxSubstring, "Чем меньше женщину мы любим, тем ") == 0);
}

bool test3() {
	size_t maxLength = 0;
	size_t currentLength;
	char* maxSubstring = 0; int i, j, k;
	char *buffer;
	char *buffer2;
	int fileSize;
	string filename;

	filename = "test3first.txt";
	buffer = filework(filename);
	filename = "test3second.txt";
	buffer2 = filework(filename);
	int len1 = strlen(buffer);
	int len2 = strlen(buffer2);

	for (i = 0; i < len1 - maxLength; ++i) {
		for (j = 0; j < len2 - maxLength; ++j) {
			currentLength = getCommonLength(buffer + i, buffer2 + j);
			if (currentLength > maxLength) { 
				maxLength = currentLength;
				if (maxSubstring != NULL) {
					delete[] maxSubstring;
				}
				size_t maxStrSize = maxLength + 1;
				maxSubstring = new char[maxStrSize];
				for (int m = 0; m < maxLength; m++)
					maxSubstring[m] = buffer[i + m];
				maxSubstring[maxStrSize - 1] = '\0';
			}
		}
	}
	return (strcmp(maxSubstring, "Представьте, что в городе ") == 0);
}

bool test4() {
	size_t maxLength = 0;
	size_t currentLength;
	char* maxSubstring = 0; int i, j, k;
	char *buffer;
	char *buffer2;
	int fileSize;
	string filename;
	filename = "test4first.txt";
	buffer = filework(filename);
	filename = "test4second.txt";
	buffer2 = filework(filename);
	int len1 = strlen(buffer);
	int len2 = strlen(buffer2);

	for (i = 0; i < len1 - maxLength; ++i) {
		for (j = 0; j < len2 - maxLength; ++j) {
			currentLength = getCommonLength(buffer + i, buffer2 + j);
			if (currentLength > maxLength) { 
				maxLength = currentLength;
				if (maxSubstring != NULL) {
					delete[] maxSubstring;
				}
				size_t maxStrSize = maxLength + 1;
				maxSubstring = new char[maxStrSize];
				for (int m = 0; m < maxLength; m++)
					maxSubstring[m] = buffer[i + m];
				maxSubstring[maxStrSize - 1] = '\0';
			}
		}
	}
	return (strcmp(maxSubstring, "cultural and political contexts ") == 0);
}

bool test5() {
	size_t maxLength = 0;
	size_t currentLength;
	char* maxSubstring = 0; int i, j, k;
	char *buffer;
	char *buffer2;
	int fileSize;
	string filename;
	filename = "test5first.txt";
	buffer = filework(filename);
	filename = "test5second.txt";
	buffer2 = filework(filename);

	int len1 = strlen(buffer);
	int len2 = strlen(buffer2);

	for (i = 0; i < len1 - maxLength; ++i) {
		for (j = 0; j < len2 - maxLength; ++j) {
			currentLength = getCommonLength(buffer + i, buffer2 + j);
			if (currentLength > maxLength) { 
				maxLength = currentLength;
				if (maxSubstring != NULL) {
					delete[] maxSubstring;
				}
				size_t maxStrSize = maxLength + 1;
				maxSubstring = new char[maxStrSize];
				for (int m = 0; m < maxLength; m++)
					maxSubstring[m] = buffer[i + m];
				maxSubstring[maxStrSize - 1] = '\0';
			}
		}
	}
	return (strcmp(maxSubstring, "для теста") == 0);
}