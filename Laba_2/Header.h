#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#pragma warning(disable: 4996) 
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
const int N = 6;

struct Stek
{
	char *text;
	Stek *next;
};

void Print(ifstream& Text);

void push(char* info, Stek *& Stringns);

char *pop(Stek *& Stringns);

void LoadFileToStek(ifstream& file, Stek *& Stringns);

void Renumber(Stek *& Stringns);

char *ChangeName(char *Name1);

void Purge(Stek *& Stringns);