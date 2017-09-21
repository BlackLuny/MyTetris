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
		if (msg->getMsg() == MSG_KEY_DOWN)
		{
			cout << " You have key down the " << ((KeyboardMessage*)msg)->m_key << endl;
		}
		if (((KeyboardMessage*)msg)->m_key != 888)
			newMsg = new KeyboardMessage(MSG_KEY_DOWN, 888);
		return true;
	}
};
#endif