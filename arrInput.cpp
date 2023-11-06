#include "arrInput.h"

using namespace std;

void MakeRandomArray(size_t& sizeOfArray, int*& arrayOfNumbers) { //функция реализует возможность создания случайного целочисленного массива
	srand(time(0));                                               //ничего не возвращает
	cout << "Введите размер массива: ";                           //принимает в качестве аргумента переменную размера массива по ссылке, а также сам массив по ссылке
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

	cout << "Вывод неотсортированного массива" << endl;
	for (size_t i = 0; i < sizeOfArray; i++) {
		arrayOfNumbers[i] = rand() % 100;
		cout << arrayOfNumbers[i] << '\t';
	}
	cout << endl;

}

void StringReverse(string& text) {                         //функция выполняет реверс символов в строке
	char temp = ' ';                                       //функция ничего не возвращает
	for (size_t i = 0; i < (text.size() / 2); i++) {       //функция принимает в качестве аргумента строковую переменную text по ссылке
		temp = text[i];
		text[i] = text[text.size() - i - 1];
		text[text.size() - i - 1] = temp;
	}
}

string StringInputCheck() {                                //функция выполняет правильность ввода строки (имени файла), запрещает вводить одно из резервированных имен или запрещенные символы
	string tmp;                                            //функция возвращает строку-имя
	string tmp2;                                           //функция не принимает аргументов
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

bool IsAReservedName(string string1) {                       //функция выполняет проверку на зарезервированное имя файла  
	                                                         //функция возвращает булевую переменную, сигнализирующую об успехе или провале проверки
	const size_t amountOfReservedNames = 22;                 //функция принимает в качестве аргумента строку, содержащую имя файла
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

void LoadArrayFromFile(size_t& sizeOfArray, int* & arrayOfNumbers) {            //функция позволяет загрузить массив из файла
	ifstream file;                                                              //функция ничего не возвращает
	string path = "input.txt";                                                  //в качестве аргументов принимает размер массива по ссылке, а также сам массив
	cout << "Введите путь файла для чтения:\t" << endl;
	cin.ignore();
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
	while (!file.eof()) if ((symbol = file.get()) == ' ') {
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

	cout << "Вывод неотсортированного массива:" << endl;
	for (int i = 0; i < sizeOfArray; i++) {
		cout << arrayOfNumbers[i] << '\t';
	}
	cout << endl;
}