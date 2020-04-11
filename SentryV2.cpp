#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "Sentryv2.h"
#include "pwd.h"

using namespace std;

int main()
{
	string Content;
	ifstream File;
	string basepath = Pwd() +  "\\bin\\";


	int i = 0;
	while (1)
	{
		if (i >= 11) i = 1;
		else i++;
		string filename = basepath + "Person" + to_string(i) + ".txt";
		File.open(filename);
		if (File.is_open())
		{
			cout << "Sentry Mode..." << "\n";
			while (getline(File, Content))
			{
				cout << Content << "\n";
			}
			File.close();
			TestAlarm();
			Sleep(20);
			Clear();
		}
		else
		{
			cout << "Unable to open file: " << filename;
			break;
		}
	}

}


