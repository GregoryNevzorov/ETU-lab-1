#include <iostream>
#include <Windows.h> //Дает возможность изменять цвет выводимых в консоль символов.

using namespace std;

void br_int()
{
	cout << "Enter an integer. (-2147483648 <= x <= 2147483647)\n";
	int integer_number;
	cin >> integer_number;
	//Значение для сравнения с битами вводимого числа.
	int marker = 1 << 31;
	//Для отображения значащих разрядов.
	short int significant_rank = 0;
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
				if (significant_rank == 0)
				{
					significant_rank += 1;
					//Выделение значащих разрядов цветом.
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
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
	//Обратная процедура
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
}

void br_short_int()
{
	cout << "Enter an short integer. (-32768 <= x <= 32767)\n";
	int short_integer_number;
	cin >> short_integer_number;
	//Значение для сравнения с битами вводимого числа.
	int marker = 1 << 15;
	//Для отображения значащих разрядов.
	short int significant_rank = 0;
	//Двигаемся от страшего (знакового) бита к младшему.
	for (short int i = 0; i < 16; i++)
	{
		if ((marker & short_integer_number) == marker)
		{
			if (i == 0)
			{
				cout << "1 ";
				marker = 1 << 14;
			}
			else
			{
				if (significant_rank == 0)
				{
					significant_rank += 1;
					//Выделение значащих разрядов цветом.
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "1";
				marker = marker >> 1;
			}
		}
		else
		{
			if (i == 0)
			{
				cout << "0 ";
				marker = 1 << 14;
			}
			else
			{
				cout << "0";
				marker = marker >> 1;
			}
		}
	}
	cout << endl;
	//Обратная процедура
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
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
			br_short_int();
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