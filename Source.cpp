#include <iostream>
#include <Windows.h>

using namespace std;

void br_int()
{
	cout << "Enter an integer. (-2147483647 <= x <= 2147483647)\n";
	long int integer_number;
	cin >> integer_number;
	//Значение для сравнения с битами вводимого числа.
	unsigned long int marker = 1 << 31;
	//Для отображения значащих разрядов.
	short int significant_rank;
	//Двигаемся от страшего (знакового) бита к младшему.
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & integer_number) == marker)
		{
			if (i == 0)
			{
				significant_rank = -1;
				cout << "1 ";
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
			}
		}
		else
		{
			if (i == 0)
			{
				significant_rank = 0;
				cout << "0 ";
			}
			else
			{
				if (significant_rank == -1)
				{
					significant_rank += 2;
					//Выделение значащих разрядов цветом.
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "0";
			}
		}
		marker >>= 1;
	}
	cout << endl;
	//Обратная процедура.
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
}

void br_short_int()
{
	cout << "Enter an short integer. (-32767 <= x <= 32767)\n";
	short int short_integer_number;
	cin >> short_integer_number;
	//Значение для сравнения с битами вводимого числа.
	unsigned short int marker = 1 << 15;
	//Для отображения значащих разрядов.
	short int significant_rank;
	//Двигаемся от страшего (знакового) бита к младшему.
	for (short int i = 0; i < 16; i++)
	{
		if ((marker & short_integer_number) == marker)
		{
			if (i == 0)
			{
				significant_rank = -1;
				cout << "1 ";
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
			}
		}
		else
		{
			if (i == 0)
			{
				significant_rank = 0;
				cout << "0 ";
			}
			else
			{
				if (significant_rank == -1)
				{
					significant_rank += 2;
					//Выделение значащих разрядов цветом.
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "0";
			}
		}
		marker >>= 1;
	}
	cout << endl;
	//Обратная процедура.
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
}

void br_unsigned_int()
{
	cout << "Enter an unsigned integer. (0 <= x <= 4294967295)\n";
	unsigned long int integer_unsigned_number;
	cin >> integer_unsigned_number;
	//Значение для сравнения с битами вводимого числа.
	unsigned long int marker = 1 << 31;
	//Для отображения значащих разрядов.
	short int significant_rank = 0;
	//Двигаемся от страшего бита к младшему.
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & integer_unsigned_number) == marker)
		{
			if (significant_rank == 0)
			{
					significant_rank += 1;
					//Выделение значащих разрядов цветом.
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			}
			cout << "1";
		}
		else
		{
			cout << "0";
		}
		marker >>= 1;
	}
	cout << endl;
	//Обратная процедура.
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
}

float br_float_reinterpret_cast() //reinterpret_cast - no unions.
{
	cout << "Enter an float. (1.8E-38 <= x <= 1.8E+38)\n";
	float float_number;
	cin >> float_number;
	//Указатель типа int ссылается на значение по адресу переменной типа float.
	long int* pointer = reinterpret_cast<long int*>(&float_number);
	//Переменная типа int получает двоичное представление переменной float через указатель.
	//Компилятор будет интерпретировать этот двоичный код как переменную типа int.
	long int gross_transformation = * pointer;
	//Значение для сравнения с битами вводимого числа.
	unsigned long int marker = 1 << 31;
	//Двигаемся от страшего бита к младшему.
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & gross_transformation) == marker)
		{
			if (i == 0)
			{
				//Выделение знакового разряда синим цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "1 ";
				//Переход на цвет зеленый порядка.
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			else if (i == 9)
			{
				//Выделение мантиссы красным цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "1";
			}
			else
			{
				cout << "1";
			}
		}
		else
		{
			if (i == 0)
			{
				//Выделение знакового разряда синим цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "0 ";
				//Переход на цвет зеленый порядка.
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			else if (i == 9)
			{
				//Выделение мантиссы красным цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "0";
			}
			else
			{
				cout << "0";
			}
		}
		marker >>= 1;
	}
	//Обратная процедура.
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
	cout << " -- By means of a rough conversion.\n";
	return float_number;
}

void br_float_union(float float_var) //union - no reinterpret_cast.
{
	union float_to_int
	{
		float source;
		long int conversion;
	};
	float_to_int fti;
	fti.source = float_var;
	//Значение для сравнения с битами вводимого числа.
	unsigned long int marker = 1 << 31;
	//Двигаемся от страшего бита к младшему.
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & fti.conversion) == marker)
		{
			if (i == 0)
			{
				//Выделение знакового разряда синим цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "1 ";
				//Переход на цвет зеленый порядка.
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			else if (i == 9)
			{
				//Выделение мантиссы красным цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "1";
			}
			else
			{
				cout << "1";
			}
		}
		else
		{
			if (i == 0)
			{
				//Выделение знакового разряда синим цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "0 ";
				//Переход на цвет зеленый порядка.
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			else if (i == 9)
			{
				//Выделение мантиссы красным цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "0";
			}
			else
			{
				cout << "0";
			}
		}
		marker >>= 1;
	}
	//Обратная процедура.
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
	cout << " -- With the help of the union.\n";
}

void br_double() //with reinterpret_cast().
{
	cout << "Enter an double. (2.2E-308 <= x <= 1.8E+308)\n";
	double double_number;
	cin >> double_number;
	//Создание double указателя на вводимое число.
	double* ptr_double = &double_number;
	//Перевод double указателя к типу long int.
	long int* ptr_int = reinterpret_cast<long int*>(ptr_double);
	//Смещение указателя налево (на его размер - 4 байта), до знакового разряда мантиссы.
	ptr_int++;
	//Значение для сравнения с битами вводимого числа.
	unsigned long int marker = 1 << 31;
	for (short int i = 0; i < 32; i++)
	{
		if ((*ptr_int & marker) == marker)
		{
			if (i == 0)
			{
				//Выделение знакового разряда синим цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "1 ";
				//Переход на цвет зеленый порядка.
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			else if (i == 12)
			{
				//Выделение мантиссы красным цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "1";
			}
			else
			{
				cout << "1";
			}
		}
		else
		{
			if (i == 0)
			{
				//Выделение знакового разряда синим цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "0 ";
				//Переход на цвет зеленый порядка.
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			else if (i == 12)
			{
				//Выделение мантиссы красным цветом.
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "0";
			}
			else
			{
				cout << "0";
			}
		}
		marker >>= 1;
	}
	//Смещение указателя направо, до конца двоичной записи мантиссы.
	ptr_int--;
	marker = 1 << 31;
	for (short int i = 0; i < 32; i++)
	{
		if ((*ptr_int & marker) == marker)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
		marker = marker >> 1;
	}
	//Конец функции.
	cout << endl;
	//Обратная процедура.
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // = DARKGRAY
}

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		cout << "Enter the number of the corresponding data type or function. (Arabic numerals only.)\n";
		cout << "1 - int.\n";
		cout << "2 - short int.\n";
		cout << "3 - unsigned int.\n";
		cout << "4 - float.\n";
		cout << "5 - double.\n";
		cout << "6 - function shifts all bits equal to one to the right.\n";
		short int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			br_int();
			break;
		case 2:
			br_short_int();
			break;
		case 3:
			br_unsigned_int();
			break;
		case 4:
			br_float_union(br_float_reinterpret_cast()); // Две функции разными методами выводят двоичное представление float.
			break;
		case 5:
			br_double();
			break;
		case 6:

			break;
		default:
			cout << "There is no type or function with this number!\n";
		}
		//Проверка на повторный запуск программы.
		cout << "Run this program again now? (y/n) (one lowercase letter and 'Enter')\n";
		cin >> end;
	}
	return 0;
}