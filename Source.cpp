#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

short int mainMenu()
{
	system("cls");

	short int numberOfSelectedOption = 1;
	short int* pressedButtonCode = new short int;
	while (true)
	{
		if (numberOfSelectedOption == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Long Integer\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Long Integer\n";
		}
		if (numberOfSelectedOption == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Short Integer\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Short Integer\n";
		}
		if (numberOfSelectedOption == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. Unsigned Long Integer\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. Unsigned Long Integer\n";
		}
		if (numberOfSelectedOption == 4)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "4. Float\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "4. Float\n";
		}
		if (numberOfSelectedOption == 5)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "5. Long Double\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "5. Long Double\n";
		}
		if (numberOfSelectedOption == 6)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "6. Shifts all bits equal to one to the right\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "6. Shifts all bits equal to one to the right\n";
		}

		*pressedButtonCode = _getch();
		system("cls");
		switch (*pressedButtonCode)
		{
		case 72: // 'Стрелка вверх'


		case 87: // 'W'


		case 119: // 'w'


		case 150: // 'Ц'


		case 230:  // 'ц'
			numberOfSelectedOption -= 1;
			if (numberOfSelectedOption < 1)
			{
				numberOfSelectedOption = 6;
			}
			break;

		case 80: // 'Стрелка вниз'


		case 83: // 'S'


		case 115: // 's'


		case 155: // 'Ы'


		case 235: // 'ы'
			numberOfSelectedOption += 1;
			if (numberOfSelectedOption > 6)
			{
				numberOfSelectedOption = 1;
			}
			break;

		case 13: // 'Enter'
			delete pressedButtonCode;
			return numberOfSelectedOption;
			break;

		default:
			break;
		}
	}
}

short int shiftBitsMenu()
{
	system("cls");

	short int numberOfSelectedOption = 1;
	short int* pressedButtonCode = new short int;
	while (true)
	{
		if (numberOfSelectedOption == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Long Integer\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Long Integer\n";
		}
		if (numberOfSelectedOption == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Float\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Float\n";
		}
		if (numberOfSelectedOption == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. Double\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. Double\n";
		}

		*pressedButtonCode = _getch();
		system("cls");
		switch (*pressedButtonCode)
		{
		case 72: // 'Стрелка вверх'


		case 87: // 'W'


		case 119: // 'w'


		case 150: // 'Ц'


		case 230:  // 'ц'
			numberOfSelectedOption -= 1;
			if (numberOfSelectedOption < 1)
			{
				numberOfSelectedOption = 3;
			}
			break;

		case 80: // 'Стрелка вниз'


		case 83: // 'S'


		case 115: // 's'


		case 155: // 'Ы'


		case 235: // 'ы'
			numberOfSelectedOption += 1;
			if (numberOfSelectedOption > 3)
			{
				numberOfSelectedOption = 1;
			}
			break;

		case 13: // 'Enter'
			delete pressedButtonCode;
			return numberOfSelectedOption;
			break;

		default:
			break;
		}
	}
}

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

void printLongDoubleInBinary(double inputFromOutside = 0, bool inputModeSwitch = false)
{
	long double* enteredNumber = new long double;
	if (inputModeSwitch == false)
	{
		system("cls");
		cout << "Enter an 'long' double. (2.2E-308 <= x <= 1.8E+308)\n";
		cin >> *enteredNumber;
	}
	else
	{
		*enteredNumber = inputFromOutside;
	}

	long int* recastPointerToLongInteger = reinterpret_cast<long int*>(enteredNumber);
	//Смещение указателя налево (на его размер - 4 байта), до знакового разряда мантиссы.
	recastPointerToLongInteger++;

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
		if (i == 12)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		}
		if ((*recastPointerToLongInteger & *movingBitForComparison) == *movingBitForComparison)
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

	//Смещение указателя направо, до конца двоичной записи мантиссы.
	recastPointerToLongInteger--;
	*movingBitForComparison = 1 << 31;
	for (short int i = 0; i < 32; i++)
	{
		if ((*recastPointerToLongInteger & *movingBitForComparison) == *movingBitForComparison)
		{
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

template <class T> void shiftFunction(T inputFromOutside, short int numberType)
{
	T processedNumber(inputFromOutside);
	long int* processedNumberPointerLongInteger = reinterpret_cast<long int*>(&processedNumber);

	cout << "Before:\n";
	cout << processedNumber << "\n";
	if (numberType == 0)
	{
		printLongIntegerInBinary(processedNumber, true);
	}
	else if (numberType == 1)
	{
		printFloatInBinary(processedNumber, true);
	}
	else
	{
		printLongDoubleInBinary(processedNumber, true);
		processedNumberPointerLongInteger++;
	}

	unsigned long int* movingBitForComparison = new unsigned long int(1 << 31);
	bool* equalToOne = new bool(false);
	for (short int j = 0; j < 2; j++)
	{
		for (short int i = 0; i < 32; i++)
		{
			if ((*movingBitForComparison & *processedNumberPointerLongInteger) == *movingBitForComparison)
			{
				if (*equalToOne == false)
				{
					*processedNumberPointerLongInteger -= *movingBitForComparison;
					*equalToOne = true;
				}
			}
			else
			{
				if (*equalToOne == true)
				{
					*processedNumberPointerLongInteger += *movingBitForComparison;
					*equalToOne = false;
				}
			}
			*movingBitForComparison >>= 1;
		}
		if (numberType == 2)
		{
			processedNumberPointerLongInteger--;
			*movingBitForComparison = 1 << 31;
		}
	}
	cout << "After:\n";
	cout << processedNumber << "\n";
	if (numberType == 0)
	{
		printLongIntegerInBinary(processedNumber, true);
	}
	else if (numberType == 1)
	{
		printFloatInBinary(processedNumber, true);
	}
	else
	{
		printLongDoubleInBinary(processedNumber, true);
	}

	delete movingBitForComparison;
	delete equalToOne;
}

void shiftBitsToRight()
{
	long int* argForGeneralizedFunctionLongInteger = new long int;
	float* argForGeneralizedFunctionFloat = new float;
	long double* argForGeneralizedFunctionLongDouble = new long double;

	short int* selectedFunctionNumber = new short int(shiftBitsMenu());
	switch (*selectedFunctionNumber)
	{
	case 1:
		cout << "Enter an 'long' integer. (-2147483647 <= x <= 2147483647)\n";
		cin >> *argForGeneralizedFunctionLongInteger;
		shiftFunction(*argForGeneralizedFunctionLongInteger, 0);
		break;

	case 2:
		cout << "Enter an float. (1.8E-38 <= x <= 1.8E+38)\n";
		cin >> *argForGeneralizedFunctionFloat;
		shiftFunction(*argForGeneralizedFunctionFloat, 1);
		break;

	case 3:
		cout << "Enter an 'long' double. (2.2E-308 <= x <= 1.8E+308)\n";
		cin >> *argForGeneralizedFunctionLongDouble;
		shiftFunction(*argForGeneralizedFunctionLongDouble, 2);
		break;

	default:
		break;
	}
	delete selectedFunctionNumber;

	delete argForGeneralizedFunctionLongInteger;
	delete argForGeneralizedFunctionFloat;
	delete argForGeneralizedFunctionLongDouble;
}

int main()
{
	short int* selectedFunctionNumber = new short int;
	short int* pressedButtonCode = new short int(0);
	while (true)
	{
		*selectedFunctionNumber = mainMenu();
		switch (*selectedFunctionNumber)
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
			printLongDoubleInBinary();
			break;

		case 6:
			shiftBitsToRight();
			break;

		default:
			break;
		}

		cout << "Press 'Enter' to return to the main menu\n";
		cout << "Press 'Escape' to complete the work of this programme\n";
		while (*pressedButtonCode != 13)
		{
			*pressedButtonCode = _getch();
			if (*pressedButtonCode == 27)
			{
				delete selectedFunctionNumber;
				delete pressedButtonCode;
				return 0;
			}
		}
		*pressedButtonCode = 0;
	}
}