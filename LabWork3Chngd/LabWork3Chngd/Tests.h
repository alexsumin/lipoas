#pragma once
#include"Solver.h"
#include"FileUtil.h"
#include "CoutModified.h"
extern CoutModified coutMod;

using namespace std;
void runUnitTests(); 
bool test(FilesForReading testFiles, char * expectedString);
void initExpectedData();