#ifndef CREATE_TETRIS_HANDLER_H
#define CREATE_TETRIS_HANDLER_H
#include "HandlerBase.h"
#include "GameFram.h"
#include "TetrisFactory.h"
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
		if (type != MSG_UPDATE_GAME) return false;

		GameFram * game = GameFram::getInstance();
		TetrisFactory* factory = TetrisFactory::getInstance();
		TetrisBase* cur_tetris = game->cur_tetris;
		TetrisBase* nextTetris = game->next_tetris;
		if (cur_tetris == NULL)
		{
			if (nextTetris == NULL)
				cur_tetris = factory->CreateTetris((PDCTYPE)2); //第一次创建
			else 
				cur_tetris = nextTetris;   //等于下一个俄罗斯方块
			game->cur_tetris = cur_tetris;
			nextTetris = NULL;
		}
		if (nextTetris == NULL)
		{
			nextTetris = factory->CreateTetris((PDCTYPE)(rand()%7));
			game->next_tetris = nextTetris;
		}
		return false;	
	}
};


#endif