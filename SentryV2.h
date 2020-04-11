#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

UINT32 PressedDown = 0x8000;

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
	if (KeyPress())
	{
		while (1)
		{
			Beep(523, 500);
			if (GetKeyState(VK_SHIFT) & PressedDown & (GetKeyState('B') & GetKeyState('F'))) exit(0);
		}
	}
}
