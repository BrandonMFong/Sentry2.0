#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <direct.h>
#define GetCurrentDir _getcwd

using namespace std;

UINT32 PressedDown = 0x8000;

string Pwd()
{
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}

void RevserseString(string & string, int begin, int end) // recurse
{
	char temp;
	if (begin >= end) return;

	temp = string[begin];
	string[begin] = string[end];
	string[end] = temp;
	RevserseString(string, ++begin, --end);
}


string LeafDir()
{
	string Path = Pwd();
	string word = "";
	for (int i = Path.length(); i > 0; i--)
	{
		if (Path[i] == '\\') break;
		else
		{
			word += Path[i];
		}
	}
	RevserseString(word, 0, word.length() - 1);
	return word;
}

void Clear()
{
	system("cls");
}

bool KeyPress() // Tests any of the ASCII characters
{
	char key = 0x20;
	bool out = false;
	for (int i = 32; i < 128; i++)
	{
		out = out | GetKeyState(key);
		key++;
	}
	return out;
}

void TestAlarm()
{
	while (1)
	{
		if (KeyPress())
		{
			while (1)
			{
				Beep(523, 500);
			}
		}
	}
}

void TestIfExit()
{
	while(1) 
		if (PressedDown & GetKeyState('Q')) exit(0);
}