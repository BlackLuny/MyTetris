#ifndef KEYBOARD_MESSAGE_H
#define KEYBOARD_MESSAGE_H
#include "MessageBase.h"
#include "ENU_KEY.h"
class KeyboardMessage:public MessageBase
{
public:
	KeyboardMessage(MSG_TYPE type, KEY_VALUE key): ::MessageBase(type),m_key(key)
	{

	}
	virtual ~KeyboardMessage()
	{

	}
public:
	KEY_VALUE m_key;
};
#endif