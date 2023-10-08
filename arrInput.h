#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void StringReverse(string& text);

string StringInputCheck();

bool IsAReservedName(string string1);

void LoadArrayFromFile(size_t& sizeOfArray, int* arrayOfNumbers);