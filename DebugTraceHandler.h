#ifndef DEBUG_TRACE_HANDLER_H
#define DEBUG_TRACE_HANDLER_H
#include "HandlerBase.h"
#include "GameFram.h"
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
		GameFram * game = GameFram::getInstance();
		cout << "cur_tetris = \n" << *(game->cur_tetris) << endl;
		cout << "next_tetris = \n" << *(game->next_tetris) << endl;
		return true;	
	}
};


#endif