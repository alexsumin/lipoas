#include "solver.h"
static int CRLF = 4;

char * filework(string filename) {
	int fileSize = 0;
	char *buffer;
	ifstream fin(filename, ios::binary);
		if (fin.is_open()) {
			fin.seekg(0, ifstream::end);
			fileSize = fin.tellg();
			fin.seekg(0);
			buffer = new char[fileSize-CRLF];
			fin.read(buffer, fileSize);
			fin.close();
			return buffer;
		}
	}
		
	

