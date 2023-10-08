#pragma once

#include "arrOutput.h"

//Миняев Виктор, 425.
//cpp-файл, реализует все функции для вывода отсортированного массива.

using namespace std;

void SortedArrOutput(int arrayOfNumbers[], int sizeOfArray) {
	cout << "Вывод отсортированного массива:" << endl;
	for (int i = 0; i < sizeOfArray; i++) {
		cout << arrayOfNumbers[i] << '\t';
	}
	cout << endl;
}