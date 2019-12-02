#include <iostream>
#include <Windows.h>

using namespace std;

void printLongIntegerInBinary(long int inputFromOutside = 0, bool inputModeSwitch = false)
{
	long int* enteredNumber = new long int;
	if (inputModeSwitch == false)
	{
		system("cls");
		cout << "Enter an 'long' integer. (-2147483647 <= x <= 2147483647)\n";
		cin >> *enteredNumber;
	}
	else
	{
		*enteredNumber = inputFromOutside;
	}

	unsigned long int* movingBitForComparison = new unsigned long int(1 << 31);
	for (short int i = 0; i < 32; i++)
	{
		if ((*movingBitForComparison & *enteredNumber) == *movingBitForComparison)
		{
			if (i != 0)
			{
				if (*enteredNumber > 0)
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "1";
			}
			else
			{
				cout << "1 ";
			}
		}
		else
		{
			if (i != 0)
			{
				if (*enteredNumber < 0)
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "0";
			}
			else
			{
				cout << "0 ";
			}
		}
		*movingBitForComparison >>= 1;
	}

	cout << "\n";
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // DARKGRAY
	delete enteredNumber;
	delete movingBitForComparison;
}

void printShortIntegerInBinary()
{
	system("cls");

	short int* enteredNumber = new short int;
	cout << "Enter an 'short' integer. (-32767 <= x <= 32767)\n";
	cin >> *enteredNumber;

	unsigned short int* movingBitForComparison = new unsigned short int(1 << 15);
	for (short int i = 0; i < 16; i++)
	{
		if ((*movingBitForComparison & *enteredNumber) == *movingBitForComparison)
		{
			if (i != 0)
			{
				if (*enteredNumber > 0)
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "1";
			}
			else
			{
				cout << "1 ";
			}
		}
		else
		{
			if (i != 0)
			{
				if (*enteredNumber < 0)
				{
					HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				}
				cout << "0";
			}
			else
			{
				cout << "0 ";
			}
		}
		*movingBitForComparison >>= 1;
	}

	cout << "\n";
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // DARKGRAY
	delete enteredNumber;
	delete movingBitForComparison;
}

void printUnsignedLongIntegerInBinary()
{
	system("cls");

	unsigned long int* enteredNumber = new unsigned long int;
	cout << "Enter an 'unsigned long' integer. (0 <= x <= 4294967295)\n";
	cin >> *enteredNumber;

	unsigned long int* movingBitForComparison = new unsigned long int(1 << 31);
	for (short int i = 0; i < 32; i++)
	{
		if ((*movingBitForComparison & *enteredNumber) == *movingBitForComparison)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1";
		}
		else
		{
			cout << "0";
		}
		*movingBitForComparison >>= 1;
	}

	cout << "\n";
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // DARKGRAY
	delete enteredNumber;
	delete movingBitForComparison;
}

void printFloatInBinary(float inputFromOutside = 0, bool inputModeSwitch = false)
{
	union ReadingFloatAsInteger
	{
		float asFloat;
		long int asLongInteger;
	};
	ReadingFloatAsInteger memoryArea;

	if (inputModeSwitch == false)
	{
		system("cls");
		cout << "Enter an float. (1.8E-38 <= x <= 1.8E+38)\n";
		cin >> memoryArea.asFloat;
	}
	else
	{
		memoryArea.asFloat = inputFromOutside;
	}
	
	unsigned long int* movingBitForComparison = new unsigned long int(1 << 31);
	for (short int i = 0; i < 32; i++)
	{
		if (i == 0)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		if (i == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		}
		if (i == 9)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		}

		if ((*movingBitForComparison & memoryArea.asLongInteger) == *movingBitForComparison)
		{
			if (i != 0)
			{
				cout << "1";
			}
			else
			{
				cout << "1 ";
			}
		}
		else
		{
			if (i != 0)
			{
				cout << "0";
			}
			else
			{
				cout << "0 ";
			}
		}
		*movingBitForComparison >>= 1;
	}

	cout << "\n";
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // DARKGRAY
	delete movingBitForComparison;
}

void br_double(double input = 0, short int selector = 0) //with reinterpret_cast().
{
	double double_number;
	if (selector == 0)
	{
		cout << "Enter an double. (2.2E-308 <= x <= 1.8E+308)\n";
		cin >> double_number;
	}
	else
	{
		double_number = input;
	}
	long int* ptr_int = reinterpret_cast<long int*>(&double_number);
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

void shift_right_int()
{
	long int integer_number;
	cout << "Enter an integer. (-2147483647 <= x <= 2147483647)\n";
	cin >> integer_number;
	//Число до сдвига.
	cout << "Before:\n";
	printLongIntegerInBinary(integer_number, true);
	unsigned long int marker = 1 << 31;
	short int counter = 0;
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & integer_number) == marker)
		{
			if (counter == 0)
			{
				integer_number -= marker;
				counter = 1;
			}
		}
		else
		{
			if (counter == 1)
			{
				integer_number += marker;
				counter = 0;
			}
		}
		marker >>= 1;
	}
	//Число после сдвига.
	cout << "After:\n";
	printLongIntegerInBinary(integer_number, true);
	cout << integer_number << "\n";
}

void shift_right_float()
{
	float float_number;
	cout << "Enter an float. (1.8E-38 <= x <= 1.8E+38)\n";
	cin >> float_number;
	//Число до сдвига.
	cout << "Before:\n";
	printFloatInBinary(float_number, true);
	//Преобразование для побитового сравнения.
	long int* pointer = reinterpret_cast<long int*>(&float_number);
	unsigned long int marker = 1 << 31;
	short int counter = 0;
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & *pointer) == marker)
		{
			if (counter == 0)
			{
				*pointer -= marker;
				counter = 1;
			}
		}
		else
		{
			if (counter == 1)
			{
				*pointer += marker;
				counter = 0;
			}
		}
		marker >>= 1;
	}
	//Число после сдвига.
	cout << "After:\n";
	printFloatInBinary(float_number, true);
	cout << float_number << "\n";
}

void shift_right_double()
{
	double double_number;
	cout << "Enter an double. (2.2E-308 <= x <= 1.8E+308)\n";
	cin >> double_number;
	//Число до сдвига.
	cout << "Before:\n";
	br_double(double_number, 1);
	long int* pointer = reinterpret_cast<long int*>(&double_number);
	//Смещение указателя налево (на его размер - 4 байта), до знакового разряда мантиссы.
	pointer++;
	unsigned long int marker = 1 << 31;
	short int counter = 0;
	for (short int j = 0; j < 2; j++)
	{
		for (short int i = 0; i < 32; i++)
		{
			if ((marker & *pointer) == marker)
			{
				if (counter == 0)
				{
					*pointer -= marker;
					counter = 1;
				}
			}
			else
			{
				if (counter == 1)
				{
					*pointer += marker;
					counter = 0;
				}
			}
			marker >>= 1;
		}
		if (j == 0)
		{
			pointer--;
			marker = 1 << 31;
		}
	}
	//Число после сдвига.
	cout << "After:\n";
	br_double(double_number, 1);
	cout << double_number << "\n";
}

void shift_right()
{
	char end = 'y';
	while (end == 'y')
	{
		cout << "Enter the number corresponding to the type of argument. (Arabic numerals only.)\n";
		cout << "1 - int\n";
		cout << "2 - float\n";
		cout << "3 - double\n";
		short int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			shift_right_int();
			break;
		case 2:
			shift_right_float();
			break;
		case 3:
			shift_right_double();
			break;
		default:
			cout << "There is no type with this number!\n";
			break;
		}
		//Проверка на повторный запуск программы.
		cout << "Run this function again now? (y/n) (one lowercase letter and 'Enter')\n";
		cin >> end;
	}
}

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		cout << "Enter the number of the corresponding data type or function. (Arabic numerals only.)\n";
		cout << "1 - int\n";
		cout << "2 - short int\n";
		cout << "3 - unsigned int\n";
		cout << "4 - float\n";
		cout << "5 - double\n";
		cout << "6 - this function shifts all bits equal to one to the right\n";
		short int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			printLongIntegerInBinary();
			break;
		case 2:
			printShortIntegerInBinary();
			break;
		case 3:
			printUnsignedLongIntegerInBinary();
			break;
		case 4:
			printFloatInBinary();
			break;
		case 5:
			br_double();
			break;
		case 6:
			shift_right();
			break;
		default:
			cout << "There is no type or function with this number!\n";
			break;
		}
		//Проверка на повторный запуск программы.
		cout << "Run this program again now? (y/n) (one lowercase letter and 'Enter')\n";
		cin >> end;
	}
	return 0;
}