#include "gnomeSort.h"
using namespace std;

void GnomeSort(int arrayOfNumber[], int sizeOfArray) {
	for (size_t i = 1; i < sizeOfArray;) {
		if (arrayOfNumber[i - 1] < arrayOfNumber[i]) {
			swap(arrayOfNumber[i - 1], arrayOfNumber[i]);
			if (i > 1) i--;
		}
		else {
			if (i < sizeOfArray) i++;
		}
	}
}