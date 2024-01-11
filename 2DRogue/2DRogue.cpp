#include <iostream>
#include <Windows.h>
#include "helper.h"
#include "Map2D.h"
#include "PlayerMove.h"

using namespace std;

int main()
{
	SetCursorOnOff(false);
	while (true)
	{
		SetCursorPosition(0, 0);
		// 입력
		HandleKeyInput();
		// 로직
		HandleMoveInput();
		// 출력
		Print2DMap();
		
	}

	return 0;
}

