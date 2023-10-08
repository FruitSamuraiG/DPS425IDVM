#include "arrInput.h"

using namespace std;

void MakeRandomArray(size_t& sizeOfArray, int*& arrayOfNumbers) {
	srand(time(0));
	cout << "Введите размер массива: ";
	while (true) {
		cin >> sizeOfArray;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "Некорректный ввод, попробуйте ещё раз" << endl;
			continue;
		}
		if (sizeOfArray < 1) {
			cout << "Недопустимый размер массива, попробуйте ещё раз" << endl;
			continue;
		}
		break;
	}

	arrayOfNumbers = new int[sizeOfArray];

	for (size_t i = 0; i < sizeOfArray; i++) {
		arrayOfNumbers[i] = rand() % 100;
	}

}

void StringReverse(string& text) {
	char temp = ' ';
	for (size_t i = 0; i < (text.size() / 2); i++) {
		temp = text[i];
		text[i] = text[text.size() - i - 1];
		text[text.size() - i - 1] = temp;
	}
}

string StringInputCheck() {
	string tmp;
	string tmp2;
	while (true) {
		bool isStringCorrect = true;
		getline(cin, tmp);
		if (IsAReservedName(tmp2))
		{
			cout << "Зарезервированное имя нельзя! Попробуй снова:" << endl;
			continue;
		}
		for (size_t i = tmp.size(); i > 0; i--) {
			if (tmp[i] != '\\') {
				tmp2 = tmp2 + tmp[i];
			}
			else break;
		}
		StringReverse(tmp2);
		isStringCorrect = true;
		for (size_t i = 0; i < tmp2.size(); i++) {
			if (tmp2[i] == '/' or tmp2[i] == ':' or tmp2[i] == '*' or tmp2[i] == '"' or tmp2[i] == '?' or tmp2[i] == '<' or tmp2[i] == '>' or tmp2[i] == '|') {
				cout << "Название содержит запрещённые символы! Попробуй снова:" << endl;
				isStringCorrect = false;
				break;
			}
		}
		if (isStringCorrect) break;
		else continue;
	}
	return tmp;
}

bool IsAReservedName(string string1) {

	const size_t amountOfReservedNames = 22;
	string reservedNames[amountOfReservedNames] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

	bool isPointExist = false;
	size_t point = 0;

	string tmp = string1;

	for (size_t i = 0; i < tmp.size(); i++) {
		tmp[i] = char(tolower(string1[i]));
	}

	for (size_t i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '.') {
			point = i;
			isPointExist = true;
			break;
		}
	}

	for (size_t i = 0; i < amountOfReservedNames; i++) {
		if (isPointExist) {
			size_t counter = 0;
			if (point == reservedNames[i].size()) {
				for (size_t j = 0; j < point; j++) {
					if (tmp[j] == reservedNames[i][j]) {
						counter++;
					}
					if (counter == point) {
						return true;
						break;
					}
				}
			}
		}
		else {
			if (tmp.size() == reservedNames[i].size()) {
				if (tmp == reservedNames[i]) {
					return true;
					break;
				}
			}
		}
	}

	return false;
}

void LoadArrayFromFile(size_t& sizeOfArray, int* arrayOfNumbers) {
	ifstream file;
	string path = "input.txt";
	cout << "Введите путь файла для чтения:\t" << endl;
	path = StringInputCheck();
	file.open(path);
	while (!file.is_open()) {
		cout << "Ошибка при открытии файла! Попробуйте ввести путь снова." << endl;
		path = StringInputCheck();
		file.open(path);
	}

	int size = 0;
	int counter = 0;
	int symbol = 0;
	while (!file.eof()) if ((symbol = file.get()) == '\n') {
		size++;
		counter++;
	}
	if (counter > 0) {
		size++;
	}
	file.clear();
	file.seekg(0, ios::beg);

	char sym = '0';
	int spacesInARow = 0;
	bool isCool = false;
	while (sym != EOF) {
		if (sym == '\n') break;
		sym = static_cast <char>(file.get());
		if (spacesInARow == 1 and sym == '\n') {
			size--;
		}
		if (sym == ' ') {
			spacesInARow++;
			if (spacesInARow > 1) {
				spacesInARow = 1;
			}
		}
		else {
			spacesInARow = 0;
		}
		isCool = true;
	}
	file.clear();
	file.seekg(0, ios::beg);

	if (size == 0) {
		cout << "Файл пуст" << endl;
	}
	else {
		sizeOfArray = size;

		arrayOfNumbers = new int[size];

		for (size_t i = 0; i < size; i++) {
			file >> arrayOfNumbers[i];
			if (file.fail()) {
				cout << "" << endl;
				cout << "Не удалось считать элемент " << i + 1 << " из файла. Установлено нулевое значение. Желательно исправить файл." << endl;
				arrayOfNumbers[i] = 0;
				file.clear();
			}
		}
	}
}