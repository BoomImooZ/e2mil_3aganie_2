#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int counter=0;
	char ch = 0;
	bool isNice = true;
	long long int number = 0;
	int number2 = 0;
	char symbol;
	ifstream fin("e2mil.txt");
	int x[10];
	int temp = 0;
	for (int i = 0; i < 7; i++) { fin.get(symbol); }				//����������� "� =  2."
	for (int i = 0; i < 10; i++) {									//����������� ����������
		fin.get(symbol);
		if (symbol != '\n') {
			x[i] = symbol - '0';
			number = number + x[i] * pow(10.0, 9.0 - double(i));
			number2 = number2 + x[i];
		}
		else {
			fin.get(symbol);
			x[i] = symbol - '0';
			number = number + x[i];
			number2 = number2 + x[i];
		}
	}
	while (fin.is_open()) {
			if (number2%49 != 0) {
				isNice = false;
			}
			else { isNice = true; }
		
		if (isNice == false) {
			number = 0;
			number2 = 0;
			for (int i = 0; i < 9; i++) {							//����� �� ������ ����� ���� �� ������� �����
				x[i] = x[i + 1];
				number = number + x[i] * pow(10.0, 9.0 - double(i));
				number2 = number2 + x[i];
			}
			fin.get(symbol);										//���������� ���������� ������� � �����
			if (symbol != '\n') { x[9] = symbol - '0'; }
			else {
				fin.get(symbol); x[9] = symbol - '0';
			}
			number = number + x[9];
			number2 = number2 + x[9];
		}
		if (isNice == true) {										// ����� �������� �����
			counter++;
			cout << "is correct  f"<< counter <<" = " << number << '\n';
			number = 0;
			number2 = 0;
			for (int i = 0; i < 9; i++) {							//����� �� ������ ����� ���� �� ������� �����
				x[i] = x[i + 1];
				number = number + x[i] * pow(10.0, 9.0 - double(i));
				number2 = number2 + x[i];
			}
			fin.get(symbol);										//���������� ���������� ������� � �����
			if (symbol != '\n') { x[9] = symbol - '0'; }
			else {
				fin.get(symbol); x[9] = symbol - '0';
			}
			number = number + x[9];
			number2 = number2 + x[9];
			if (counter ==5){ fin.close();}
		}
	}
	system("pause");
	return 0;
}