#ifndef KEYBOARD_MESSAGE_H
#define KEYBOARD_MESSAGE_H
#include "MessageBase.h"
class KeyboardMessage:public MessageBase
{
public:
	KeyboardMessage(MSG_TYPE type, int key): ::MessageBase(type),m_key(key)
	{

	}
	virtual ~KeyboardMessage()
	{

	}
public:
	int m_key;
};
#endif