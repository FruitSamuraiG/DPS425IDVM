#include "arrOutput.h"
#include "gnomeSort.h"
#include "arrInput.h"
#include <locale>

using namespace std;

//пункты главного меню
enum programMenu {
	StartProgram = 1,
	ExitProgram = 2,
};

//пункты меню выбора заполнения массива
enum arrayInput {
	LoadFromFile = 1,
	LoadWithRandomNumbers = 2
};

int main() {
	setlocale(LC_ALL, "ru"); //локализация

	//стартовые переменные
	int usersChoice = 0; //переменная для перемещения по меню
	int* arrayOfNumbers = nullptr;
	size_t sizeOfArray = 0;

	//приветствие
	cout << "_______________________________________________________________________" <<
		endl << "Лабораторная работа №2" <<
		endl << "Вариант 13" << endl << "Друченко Илья, Виктор Миняев" <<
		endl << "_______________________________________________________________________" << endl;

	//зацикленное меню
	while (true) { 
		cout << "1. Начать программу\n2. Выйти" << endl;

		//выбор пункта меню пользователем
		cin >> usersChoice;
		if (cin.fail()) { //проверка ввода
			
			//очистка буффера ввода
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			
			cout << "Некорректный ввод, попробуйте ещё раз" << endl;
			continue;
		}
		
		else {
			switch (usersChoice) {

			case ExitProgram:
				break;

			case StartProgram:
				while (true) {
					cout << "Выберите способ заполнения массива:\n1. Заполнить массив из файла\n2. Заполнить массив случайными числами" << endl;
					cin >> usersChoice;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(std::numeric_limits<int>::max(), '\n');
						cout << "Некорректный ввод, попробуйте ещё раз" << endl;
						continue;
					}
					switch (usersChoice) {

						case LoadFromFile:
							LoadArrayFromFile(sizeOfArray, arrayOfNumbers);
							break;

						case LoadWithRandomNumbers:
							MakeRandomArray(sizeOfArray, arrayOfNumbers);
							break;

						default:
							cout << "Недопустимая команда, попробуйте ещё раз" << endl;
							continue;
							break;

					}

					GnomeSort(arrayOfNumbers, sizeOfArray); //вызов функции сортировки
					SortedArrOutput(arrayOfNumbers, sizeOfArray); //вывод отсортированного массива
					break;

				}

			default:
				cout << "Недопустимая команда, попробуйте ещё раз" << endl;
				continue;
				break;

			}
		}
		
		break;
	}
			
	if (arrayOfNumbers != nullptr) { //очистка памяти
		delete[] arrayOfNumbers;
	}

	return 0;
}