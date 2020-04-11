#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#define GetCurrentDir _getcwd

using namespace std;

string Pwd()
{
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}