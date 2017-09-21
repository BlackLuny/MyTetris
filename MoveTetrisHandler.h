#ifndef MOVE_TETRIS_HANDLER_H
#define MOVE_TETRIS_HANDLER_H
#include "HandlerBase.h"
class MoveTetrisHandler: public HandlerBase
{
public:
	MoveTetrisHandler(){};
	virtual ~MoveTetrisHandler()
	{

	}
	virtual bool doHandle(MessageBase *msg, MessageBase *&newMsg)
	{
		cout << "msg type = " << msg->getMsg() << endl;
		cout << "so now tetris is moving……\n";
		return false;
	}
};
#endif