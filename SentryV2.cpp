#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Sentryv2.h"

using namespace std;


int main()
{
	string Content;
	ifstream File;

	int i = 0;
	while (1)
	{
		if (i >= 11) i = 1;
		else i++;
		string basepath = "B:\\SOURCES\\Repos\\SentryV2\\bin\\";
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
			system("cls");
		}
		else
		{
			cout << "Unable to open file: " << filename;
			break;
		}
	}

}


