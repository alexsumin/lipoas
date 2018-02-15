#pragma once
#include <iostream>
#include <fstream> 
#include <string>
#include "Solver.h"
#include "CoutModified.h"

using namespace std;
struct Answer;
extern CoutModified coutMod;
void saveToFile(Answer answer);
string getFilename(string number);
char * getBuffer(string filename);
bool isSystemWord(string forCheck);

