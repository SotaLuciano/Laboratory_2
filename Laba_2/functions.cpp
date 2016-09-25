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

void push(char *info, Stek *& Stringns)//Add new element  of stack
{
	Stek *tmp = new Stek;
	tmp->text = info;
	tmp->next = Stringns;
	Stringns = tmp;
}

void pop(Stek *& Stringns)//Extract element of stack
{
	if (Stringns == NULL)
	{
		cout << "Stek is empty" << endl;
		return;
	}
	Stek *tmp = Stringns;
	Stringns = tmp->next;
	cout << tmp->text << endl;;
	delete tmp; // deleting element of stack
	return;
}

void LoadFileToStek(Stek *& Stringns, string name, string road)
{
	Stringns = NULL;
	int i = 0;	//counter
	char c;		// for reading
	fstream file(road + name);
	file.seekg(-1, ios::end);
	if ((c = file.get()) != '\n') //checking '\n' 
	{
		file.seekg(0, ios::end);
		file << '\n';	// Add '\n'
	}
	file.seekg(0, ios::beg);
	while (file.good())
	{
		c = file.get();	//reading
		++i;

		if (c == '\n' || file.eof())
		{
			if (!file.good())
				break;
			char *arr = new char[i + 1];//create array
			file.seekg(-i - 1, ios::cur);
			file.getline(arr, i);//reading string
			push(arr, Stringns);//push sting into stack
			i = 0;
		}
	}

	file.close();
}

void Renumber(Stek *&Strings)
{
	int i = 1;// i - Number of String	
	int Number;// Number - figure in number
	int count = 0;
	Stek *p = Strings;

	while (p != NULL)
	{
		Number = i;
		///////////////////////////Ðàõóºìî ê³ëüê³ñòü öèôð â ÷èñë³
		while (( Number % 10) != 0)
		{
			Number /= 10;
			count++;
		}
		//////////////////////////
		char *a = new char[(Number + 2 + sizeof(p->text)) * sizeof(char*)];

		sprintf(a, "%i: ", i);// Modification string : Add in string "a" number of string

		sprintf(a, "%s%s", a, p->text);// Modification string: Add to "a" text from stack;

		strcpy(p->text, a);//Add "a" to stack

		p = p->next;//next element
		i++;//Number of next string
	}
}

void Purge(Stek *& Stringns)// Purge all stack
{
	while (Stringns != NULL)
	{
		pop(Stringns);//extracting top element
	}
	delete[] Stringns;
}

void LinePrint(void)
{
	for (int i = 0; i < 160;i++)
		cout << '*';
}

void ListofFiles(void)
{
	WIN32_FIND_DATAA FindFileData; // function for searching files

	HANDLE hSearch;

	cout << "\t\t\t\t\tStart searching" << endl;

	LinePrint();

	cout << "\t\t\t\t\tRESULTS:" << endl;

	//Searching files

	hSearch = FindFirstFileA(("d:\\Visual Studio C++ Projects\\Laba_2\\Laba_2\\*.txt"), &FindFileData); // Way to directory

	if (hSearch == INVALID_HANDLE_VALUE)
	{
		printf("Invalid File Handle. GetLastError reports %d\n", GetLastError());
	}
	else
	{
		do
		{
			printf("%s\n", FindFileData.cFileName);			// Print files
		} while (FindNextFileA(hSearch, &FindFileData));	//Search next file
		FindClose(hSearch);
	}
}