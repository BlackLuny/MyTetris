#include "KeyDownHandler.h"
#include "GameFram.h"
#include "GameMap.h"
#include "CommonFunc.h"
	//处理旋转
 bool KeyDownHandler::proc_key_rotate()
{	
	GameFram * game = GameFram::getInstance();
	TetrisBase* tetris = game->cur_tetris;
	AggregateBase* gameMap = game->m_gameMap;
	if (tetris != NULL)
	{
		tetris->rotate(90);
		if (!illTest())
			tetris->rotate(270);
	}
		
	return true;
}
bool KeyDownHandler::proc_key_down()
{
	return true;
}
bool KeyDownHandler::proc_key_left()
{
	GameFram * game = GameFram::getInstance();
	TetrisBase* tetris = game->cur_tetris;
	if (tetris != NULL)
	{
		tetris->moveLeft();
		if (!illTest())
			tetris->moveRight();
	}
		
	return true;
}
bool KeyDownHandler::proc_key_right()
{
	GameFram * game = GameFram::getInstance();
	TetrisBase* tetris = game->cur_tetris;
	if (tetris != NULL)
	{
		tetris->moveRight();
		if (!illTest())
			tetris->moveLeft();
	}
		
	return true;
	return true;
}