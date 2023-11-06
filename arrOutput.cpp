#include "arrOutput.h"

//Миняев Виктор, 425.
//cpp-файл, реализует все функции для вывода отсортированного массива.

using namespace std;

void SortedArrOutput(int*& arrayOfNumbers, size_t & sizeOfArray) { //функция выводит отсортированный массив в консоль через горизонтальную табуляцию;
	cout << "Вывод отсортированного массива:" << endl;             //ничего не возвращает;
	for (int i = 0; i < sizeOfArray; i++) {                        //принимает в аргументах массив по ссылке, а также размер массива по ссылке;
		cout << arrayOfNumbers[i] << '\t';
	}
	cout << endl;
}