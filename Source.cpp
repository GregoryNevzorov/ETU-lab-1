#include <iostream>

using namespace std;

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		cout << "Enter the number of the corresponding data type. (Arabic numerals only.)\n";
		cout << "1 - int. 2 - short int. 3 - unsigned int.\n";
		cout << "4 - float. 5 - double.\n";
		cout << "6 - function that swaps bits by number.\n";
		int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			;
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