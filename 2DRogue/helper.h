#pragma once

enum InputPlayer
{
	INPUT_NONE,
	INPUT_LEFT,
	INPUT_RIGHT,
	INPUT_DOWN,
	INPUT_UP,
};

extern InputPlayer inputplayer;

void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);

void HandleKeyInput();