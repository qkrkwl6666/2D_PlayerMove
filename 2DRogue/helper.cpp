#include "helper.h"
#include <Windows.h>

InputPlayer inputplayer;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)x,(SHORT)y };
	::SetConsoleCursorPosition(output, pos);
}

void SetCursorOnOff(bool visible)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = visible;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

void HandleKeyInput()
{
	if (::GetAsyncKeyState(VK_LEFT) & 0x8000)
		inputplayer = INPUT_LEFT;
	else if (::GetAsyncKeyState(VK_RIGHT) & 0x8000)
		inputplayer = INPUT_RIGHT;
	else if (::GetAsyncKeyState(VK_DOWN) & 0x8000)
		inputplayer = INPUT_DOWN;
	else if (::GetAsyncKeyState(VK_UP) & 0x8000)
		inputplayer = INPUT_UP;
	else
		inputplayer = INPUT_NONE;
}