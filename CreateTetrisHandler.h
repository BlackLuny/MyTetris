#ifndef CREATE_TETRIS_HANDLER_H
#define CREATE_TETRIS_HANDLER_H
#include "HandlerBase.h"
#include "TetrisFactory.h"
#include "GameFram.h"
class CreateTetrisHandler: public HandlerBase
{
public:
	CreateTetrisHandler(){};
	virtual ~CreateTetrisHandler()
	{

	}
	virtual bool doHandle(MessageBase *msg, MessageBase *&newMsg)
	{
		MSG_TYPE type = msg->getMsg();
		if (type != MSG_CREATE_TETRIS) return false;

		GameFram * game = GameFram::getInstance();
		TetrisFactory* factory = TetrisFactory::getInstance();
		TetrisBase* cur_tetris = game->cur_tetris;
		if (cur_tetris == NULL)
		{
			cur_tetris = factory->CreateTetris((PDCTYPE)6);
			game->cur_tetris = cur_tetris;
		}
		TetrisBase* nextTetris = game->next_tetris;
		if (nextTetris == NULL)
		{
			nextTetris = factory->CreateTetris((PDCTYPE)5);
			game->next_tetris = nextTetris;
		}
		return true;	
	}
};


#endif