#include <iostream>

using namespace std;

void br_int()
{
	cout << "Enter an integer. (-2147483648 <= x <= 2147483647)\n";
	int integer_number;
	cin >> integer_number;
	//Значение для сравнения с битами вводимого числа. проверка
	int marker = 1 << 31;
	//Двигаемся от страшего (знакового) бита к младшему.
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & integer_number) == marker)
		{
			if (i == 0)
			{
				cout << "1 ";
				marker = 1 << 30;
			}
			else
			{
				cout << "1";
				marker = marker >> 1;
			}
		}
		else
		{
			if (i == 0)
			{
				cout << "0 ";
				marker = 1 << 30;
			}
			else
			{
				cout << "0";
				marker = marker >> 1;
			}
		}
	}
	cout << endl;
}

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		cout << "Enter the number of the corresponding data type or function. (Arabic numerals only.)\n";
		cout << "1 - int. 2 - short int. 3 - unsigned int.\n";
		cout << "4 - float. 5 - double.\n";
		cout << "6 - function that swaps bits by number.\n";
		int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			br_int();
		case 2:
			;
		case 3:
			;
		case 4:
			;
		case 5:
			;
		case 6:
			;
		default:
			cout << "There is no type or function with this number!\n";
		}
		//Проверка на повторный запуск программы.
		cout << "Run this program again now? (y/n) (one lowercase letter and 'Enter')\n";
		cin >> end;
	}
	return 0;
}
