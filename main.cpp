#include "arrOutput.h"
#include "gnomeSort.h"
#include "arrInput.h"
#include <locale>

using namespace std;

enum programMenu {
	StartProgram = 1,
	ExitProgram = 2,
};

enum arrayInput {
	LoadFromFile = 1,
	LoadWithRandomNumbes = 2
};

int main() {
	setlocale(LC_ALL, "ru");

	int usersChoice = 0;
	int* arrayOfNumbers = nullptr;
	size_t sizeOfArray = 0;

	cout << "_______________________________________________________________________" << 
		endl << "Лабораторная работа №2" << 
		endl << "Вариант 13" << endl << "Друченко Илья, Виктор Миняев" << 
		endl << "_______________________________________________________________________" << endl;

	while (true) {
		cout << "1. Начать программу\n2. Выйти" << endl;
		cin >> usersChoice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "Некорректный ввод, попробуйте ещё раз" << endl;
			continue;
		}
		else {
			if (usersChoice == ExitProgram) {
				break;
			}
			else if (usersChoice == StartProgram) {
				while (true) {
					cout << "Выберите способ заполнения массива:\n1. Заполнить массив из файла\n2. Заполнить массив случайными числами" << endl;
					cin >> usersChoice;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(std::numeric_limits<int>::max(), '\n');
						cout << "Некорректный ввод, попробуйте ещё раз" << endl;
						continue;
					}
					else {
						if (usersChoice == LoadFromFile) {
							LoadArrayFromFile(sizeOfArray, arrayOfNumbers);
						}
						else if (usersChoice == LoadWithRandomNumbes) {
							MakeRandomArray(sizeOfArray, arrayOfNumbers);
						}
						else {
							cout << "Недопустимая команда, попробуйте ещё раз" << endl;
							continue;
						}
					}
					GnomeSort(arrayOfNumbers, sizeOfArray);
					SortedArrOutput(arrayOfNumbers, sizeOfArray);
					break;
				}
				break;
			}
			else {
				cout << "Недопустимая команда, попробуйте ещё раз" << endl;
				continue;
			}
		}
	}

	if (arrayOfNumbers != nullptr) {
		delete[] arrayOfNumbers;
	}

	return 0;
}