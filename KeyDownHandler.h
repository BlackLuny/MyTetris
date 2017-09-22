#ifndef KEY_DOWN_HANDLER_H
#define KEY_DOWN_HANDLER_H
#include "HandlerBase.h"
#include "KeyboardMessage.h"
class KeyDownHandler: public HandlerBase
{
public:
	KeyDownHandler(){};
	virtual ~KeyDownHandler()
	{

	}
	virtual bool doHandle(MessageBase *msg, MessageBase *&newMsg)
	{
		MSG_TYPE type = msg->getMsg();
		if (!(type == MSG_KEY_DOWN || type == MSG_KEY_UP)) return false;
		KeyboardMessage* keyMsg = (KeyboardMessage*) msg;
		bool res = true;
		switch(keyMsg->m_key)
		{
			case KEY_UP:
				res = proc_key_rotate();
				break;
			case KEY_DOWN:
				res = proc_key_down();
				break;
			case KEY_LEFT:
				res = proc_key_left();
				break;
			case KEY_RIGHT:
				res = proc_key_right();
				break;
			default:
				break;
		}
		return res;
	}
	virtual bool proc_key_rotate();
	virtual bool proc_key_down();
	virtual bool proc_key_left();
	virtual bool proc_key_right();

};
#endif