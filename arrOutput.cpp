#include "arrOutput.h"

//������ ������, 425.
//cpp-����, ��������� ��� ������� ��� ������ ���������������� �������.

using namespace std;

void SortedArrOutput(int*& arrayOfNumbers, size_t & sizeOfArray) {
	cout << "����� ���������������� �������:" << endl;
	for (int i = 0; i < sizeOfArray; i++) {
		cout << arrayOfNumbers[i] << '\t';
	}
	cout << endl;
}