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
		endl << "Ëàáîðàòîðíàÿ ðàáîòà ¹2" << 
		endl << "Âàðèàíò 13" << endl << "Äðó÷åíêî Èëüÿ, Âèêòîð Ìèíÿåâ" << 
		endl << "_______________________________________________________________________" << endl;

	while (true) {
		cout << "1. Íà÷àòü ïðîãðàììó\n2. Âûéòè" << endl;
		cin >> usersChoice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "Íåêîððåêòíûé ââîä, ïîïðîáóéòå åù¸ ðàç" << endl;
			continue;
		}
		else {
			if (usersChoice == ExitProgram) {
				break;
			}
			else if (usersChoice == StartProgram) {
				while (true) {
					cout << "Âûáåðèòå ñïîñîá çàïîëíåíèÿ ìàññèâà:\n1. Çàïîëíèòü ìàññèâ èç ôàéëà\n2. Çàïîëíèòü ìàññèâ ñëó÷àéíûìè ÷èñëàìè" << endl;
					cin >> usersChoice;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(std::numeric_limits<int>::max(), '\n');
						cout << "Íåêîððåêòíûé ââîä, ïîïðîáóéòå åù¸ ðàç" << endl;
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
							cout << "Íåäîïóñòèìàÿ êîìàíäà, ïîïðîáóéòå åù¸ ðàç" << endl;
							continue;
						}
					}
					GnomeSort(arrayOfNumbers, sizeOfArray);
					SortedArrOutput(arrayOfNumbers, sizeOfArray);
					break;
				}
				continue;
			}
			else {
				cout << "Íåäîïóñòèìàÿ êîìàíäà, ïîïðîáóéòå åù¸ ðàç" << endl;
				continue;
			}
		}
	}

	if (arrayOfNumbers != nullptr) {
		delete[] arrayOfNumbers;
	}

	return 0;
}
