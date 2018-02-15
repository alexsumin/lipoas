#pragma once
#include"Solver.h"
#include"FileUtil.h"
#include "CoutModified.h"
extern CoutModified coutMod;

using namespace std;
void runUnitTests(); 
void test(FilesForReading testFiles, char * expectedString);
