#include "GameFram.h"
#include "CreateTetrisHandler.h"
#include "DebugTraceHandler.h"
#include "PlayingState.h"
TetrisFactory* TetrisFactory::m_instance = NULL;
GameFram::GameFram()
{
	cur_tetris = NULL;
	next_tetris = NULL;
	m_totalHandler = new HandlerBase*[100];
	memset((void*)m_totalHandler, 0 , 100 * sizeof(HandlerBase*));
	HandlerBase * create_handler = new CreateTetrisHandler();
	HandlerBase * debug_handler = new DebugTraceHandler();
	m_totalHandler[0] = create_handler;
	m_totalHandler[1] = debug_handler;
	create_handler->setNextHandler(debug_handler);
	cur_state = new PlayingState(create_handler);
}