#ifndef DEBUG_TRACE_HANDLER_H
#define DEBUG_TRACE_HANDLER_H
#include "HandlerBase.h"
#include "GameFram.h"
#include "AggregateBase.h"
#include "GameMap.h"
class DebugTraceHandler: public HandlerBase
{
public:
	DebugTraceHandler(){};
	virtual ~DebugTraceHandler()
	{

	}
	virtual bool doHandle(MessageBase *msg, MessageBase *&newMsg)
	{
		MSG_TYPE type = msg->getMsg();
		if (type != MSG_DEBUG_TRACE) return false;
		cout <<"DebugTrace:\n";
		GameFram * game = GameFram::getInstance();
		if (game->cur_tetris == NULL) 
		{
			cout << " end of map is \n";
			cout << *(game->m_gameMap) << endl;
			return true;
		}
		cout << "cur_tetris = \n" << *(game->cur_tetris) << endl;
		cout <<"Position = " << game->cur_tetris->getPosition() << endl;
		cout << "next_tetris = \n" << *(game->next_tetris) << endl;
		AggregateBase* map = new GameMap(100,40);
		map->CopyFrom(game->m_gameMap);  //拷贝原始的
		game->cur_tetris->PinToMap(map);
		cout << *map << endl;
		delete map;
		return true;	
	}
};


#endif