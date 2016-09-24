#include "Header.h"

void Print(fstream & Text)
{
	Text.seekg(0, ios::beg);
	char n[Max_Len];
	while (!Text.eof() )
	{
		Text >> n;
		cout << n << endl;
	}
	Text.flush();
}

void push(char *info, Stek *& Stringns)
{
	Stek *tmp = new Stek;
	tmp->text = info;
	tmp->next = Stringns;
	Stringns = tmp;
}

void pop(Stek *& Stringns)
{
	if (Stringns == NULL)
	{
		cout << "Stek is empty" << endl;
		return;
	}
	Stek *tmp = Stringns;
	Stringns = tmp->next;
	cout << tmp->text << endl;;
	delete tmp;
	return;
}

void LoadFileToStek(Stek *& Stringns, string name, string road)
{
	Stringns = NULL;
	int i = 0;
	char c;
	fstream file(road + name);
	file.seekg(-1, ios::end);
	if ((c = file.get()) != '\n')
	{
		file.seekg(0, ios::end);
		file << '\n';
	}
	file.seekg(0, ios::beg);
	while (file.good())
	{
		c = file.get();
		++i;

		if (c == '\n' || file.eof())
		{
			if (!file.good())
				break;
			char *arr = new char[i + 1];
			file.seekg(-i - 1, ios::cur);
			file.getline(arr, i);
			push(arr, Stringns);
			i = 0;
		}
	}

	file.close();
}

void Renumber(Stek *&Strings)
{
	int i = 1, SizeString= 0;
	int Number;
	int count = 0;
	Stek *p = Strings;

	while (p != NULL)
	{
		Number = i;
		SizeString = sizeof(p->text);
		///////////////////////////Рахуємо кількість цифр в числі
		while (( Number % 10) != 0)
		{
			Number /= 10;
			count++;
		}
		//////////////////////////
		char *a = new char[(Number + 2 + sizeof(p->text)) * sizeof(char*)];

		sprintf(a, "%i: ", i);

		sprintf(a, "%s%s", a, p->text);

		strcpy(p->text, a);

		p = p->next;
		i++;
	}
}

void Purge(Stek *& Stringns)
{
	while (Stringns != NULL)
	{
		pop(Stringns);
	}
	delete[] Stringns;
}

char *ChangeName(char *Name1)
{
	if (Name1[0] == 'T')
	{
		char * LastName = "Text.txt";
		return LastName;
	}
	else if(Name1[0] == 'I')
	{
		char * LastName = "Info.txt";
		return LastName;
	}
	else
	{
		cout << "Wrong name";
		return 0;
	}

}

void LinePrint(void)
{
	for (int i = 0; i < 160;i++)
		cout << '*';
}

void ListofFiles(void)
{
	WIN32_FIND_DATAA FindFileData;

	HANDLE hSearch;

	cout << "\t\t\t\t\tStart searching" << endl;

	LinePrint();

	cout << "\t\t\t\t\tRESULTS:" << endl;

	//Пошук файлів

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
}