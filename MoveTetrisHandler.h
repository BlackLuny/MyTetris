#ifndef MOVE_TETRIS_HANDLER_H
#define MOVE_TETRIS_HANDLER_H
#include "HandlerBase.h"
#include "GameFram.h"
#include "CommonFunc.h"
#include "TetrisBase.h"
#include "TetrisFactory.h"
class MoveTetrisHandler: public HandlerBase
{
public:
	MoveTetrisHandler(){};
	virtual ~MoveTetrisHandler()
	{

	}
	virtual bool doHandle(MessageBase *msg, MessageBase *&newMsg)
	{
		MSG_TYPE type = msg->getMsg();
		if (type != MSG_UPDATE_GAME) return false;
		GameFram * game = GameFram::getInstance();
		TetrisBase* tetris = game->cur_tetris;
		if (tetris != NULL)
		{
			tetris->move();
			if (!illTest())
			{
				//碰到了底部或者别的方块
				tetris->moveUp();//恢复自己
				tetris->PinToMap(game->m_gameMap);
				TetrisFactory *factory = TetrisFactory::getInstance();
				factory->DestroyTetris(game->cur_tetris);
				game->cur_tetris = NULL;  //当前没有俄罗斯方块了
			}
		}
			
		return false;
	}
};
#endif