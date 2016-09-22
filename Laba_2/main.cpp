#include"Header.h"
const int Max_Len = 256;
void main()
{
	/*	ifstream Text("Text.txt");
		if (!Text)
		{
			cout << "Problem with Text.txt" << endl;
			return;
		}
		Print(Text);
		Text.close();
		Stek *Stringns = NULL;
		ifstream Text1("Text.txt");
		if (!Text1)
		{
			cout << "Problem with Text.txt" << endl;
			return;
		}
		LoadFileToStek(Text1, Stringns);
		Renumber(Stringns);
		cout << "Purge: " << endl;
		Purge(Stringns);
		cout << endl;
	//////////////////////////////////////////////////////////*/
	WIN32_FIND_DATAA FindFileData;
	HANDLE hSearch;
	cout << "***************\tStart searching\t***************" << endl;
	cout << "***************\tRESULTS:\t***************" << endl;
	hSearch = FindFirstFileA(("d:\\Visual Studio C++ Projects\\Laba_2\\Laba_2\\*.txt"), &FindFileData);
	if (hSearch == INVALID_HANDLE_VALUE)
	{
		printf("Invalid File Handle. GetLastError reports %d\n", GetLastError());
	}
	else
	{
		do
		{
		
		printf("%s\n", FindFileData.cFileName);
		} while (FindNextFileA(hSearch, &FindFileData));
		FindClose(hSearch);
	}
	// Вибираємо файл зі списку!
	cout << "Enter full name of file: ";
	char ShortName[Max_Len];
	cin.getline(ShortName, Max_Len);
	//Міняємо скорочену назву файла на повну.
//	char *FullName = ChangeName(ShortName);            ------- Проблема з WIN32_FIND_DATА ------ Функція зміни імені-----
	cout << "***************\tYour file:\t***************" << endl;
	ifstream Text(ShortName);
	if (!Text)
	{
		cout << "Problem with " << ShortName << endl;
		return;
	}
	Print(Text);
	_getch();
}