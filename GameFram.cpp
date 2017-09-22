#include "GameFram.h"
#include "CreateTetrisHandler.h"
#include "DebugTraceHandler.h"
#include "MoveTetrisHandler.h"
#include "KeyDownHandler.h"
#include "PlayingState.h"
#include "GameMap.h"
TetrisFactory* TetrisFactory::m_instance = NULL;
GameFram *GameFram::m_instance = NULL;
GameFram::GameFram()
{
	cur_tetris = NULL;
	next_tetris = NULL;
	m_totalHandler = new HandlerBase*[100];
	memset((void*)m_totalHandler, 0 , 100 * sizeof(HandlerBase*));
	HandlerBase * create_handler = new CreateTetrisHandler();
	HandlerBase * debug_handler = new DebugTraceHandler();
	HandlerBase * move_handler = new MoveTetrisHandler();
	HandlerBase * keydown_handler = new KeyDownHandler();
	m_totalHandler[0] = create_handler;
	m_totalHandler[1] = debug_handler;
	m_totalHandler[2] = move_handler;
	m_totalHandler[3] = keydown_handler;
	create_handler->setNextHandler(move_handler)->setNextHandler(keydown_handler)->setNextHandler(debug_handler);
	cur_state = new PlayingState(create_handler);

	//创建棋盘
	m_gameMap = new GameMap(100, 40);
}