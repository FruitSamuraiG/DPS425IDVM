#pragma once
#include <ctime>
#include <random>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void LoadArrayFromFile(size_t& sizeOfArray, int* & arrayOfNumbers);
void MakeRandomArray(size_t& sizeOfArray, int* & arrayOfNumbers);
void StringReverse(string& text);
string StringInputCheck();
bool IsAReservedName(string string1);