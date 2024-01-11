#include "PlayerMove.h"
#include "Map2D.h"
#include "helper.h"

int GPlayerX = 5;
int GPlayerY = 5;

bool canMove = true;

void PlayerMove(int x, int y)
{
	// 벽 충돌
	if (Map2D[y][x] == 1)
		return;
	// 배열 밖 충돌
	if (y < 0 || y >= 10)
		return;
	if (x < 0 || x >= 10)
		return;

	Map2D[GPlayerY][GPlayerX] = 0;

	GPlayerX = x;
	GPlayerY = y;

	Map2D[GPlayerY][GPlayerX] = 2;
}

void HandleMoveInput()
{
	if (inputplayer == INPUT_NONE)
	{
		canMove = true;
		return;
	}

	if (canMove == false)
		return;

	canMove = false;

	switch (inputplayer)
	{
	case INPUT_LEFT:
		PlayerMove(GPlayerX - 1, GPlayerY);
		break;
	case INPUT_RIGHT:
		PlayerMove(GPlayerX + 1, GPlayerY);
		break;
	case INPUT_DOWN:
		PlayerMove(GPlayerX, GPlayerY + 1);
		break;
	case INPUT_UP:
		PlayerMove(GPlayerX, GPlayerY - 1);
		break;
	}

}