#include "gnomeSort.h"
using namespace std;

void GnomeSort(int*& arrayOfNumber, size_t & sizeOfArray) {    //функция гномьей сортировки
	for (size_t i = 1; i < sizeOfArray;) {                     //ничего не возвращает
		if (arrayOfNumber[i - 1] < arrayOfNumber[i]) {         //в качестве аргумента принимает массив по ссылке, а также размер массива по ссылке
			swap(arrayOfNumber[i - 1], arrayOfNumber[i]);
			if (i > 1) i--;
		}
		else {
			if (i < sizeOfArray) i++;
		}
	}
}