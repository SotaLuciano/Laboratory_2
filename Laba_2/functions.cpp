#include "Header.h"

void Print(ifstream & Text)
{
	Text.seekg(0, ios::beg);
	char n[50];
	while (!Text.eof() )
	{
		Text >> n;
		cout << n << endl;
	}
}

void push(char *info, Stek *& Stringns)
{
	Stek *tmp = new Stek;
	tmp->text = info;
	tmp->next = Stringns;
	Stringns = tmp;
}

char *pop(Stek *& Stringns)
{
	if (Stringns == NULL)
	{
		cout << "Stek is empty" << endl;
		return 0;
	}
	Stek *tmp = Stringns;
	Stringns = tmp->next;
	char *array = tmp->text;
	delete tmp;
	return array;
}

void LoadFileToStek(ifstream & file, Stek *& Stringns)
{
	Stringns = NULL;
	file.seekg(0, ios::beg);
	char C[6];
	while (!file.eof())
	{
		char *array = new char[N];
		file >> array;

			push(array, Stringns);
		}
	char *temp = pop(Stringns);
}

void Renumber(Stek *& Stringns)
{
	int i = 1;

	Stek *p = Stringns;

	while (p != NULL)
	{
		char *a = new char[10];
		p->text = strcat(strcat(itoa(i, a, 10), ": "), p->text);
		p = p->next;
		++i;
	}
}

void Purge(Stek *& Stringns)
{
	while (Stringns != NULL)
	{
		char *c = pop(Stringns);
		cout << c;
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