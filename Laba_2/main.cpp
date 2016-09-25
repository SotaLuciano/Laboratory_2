#include"Header.h"

void main()
{
		LinePrint();

		Stek *Stringns = NULL;
		// Print list of all files in directory
		ListofFiles();

		string road = "d:\\Visual Studio C++ Projects\\Laba_2\\Laba_2\\"; // Way to directory
		
		char choise; // For using Yes/No

		while (true)
		{
			cout << "Enter full name of your file: ";
			string name;
			cin >> name;
			cout << endl;
			LinePrint();
			LoadFileToStek(Stringns, name, road);
			Renumber(Stringns);
			Purge(Stringns);
			LinePrint();
			cout << "Do u want to open another file from this directory? Y/N: ";
			cin >> choise;
			if (choise == 'Y' || choise == 'y')
			{
				system("cls");

				ListofFiles();
			}
			else
			{
				break;
			}
		}
	_getch();
}