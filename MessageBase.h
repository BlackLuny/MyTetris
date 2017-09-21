#ifndef MESSAGE_BASE_H
#define MESSAGE_BASE_H
#include "ENU_MSG.h"
class MessageBase
{
public:
	MessageBase(MSG_TYPE type):m_msg(type),bHandled(0){};
	MSG_TYPE getMsg()
	{
		return m_msg;
	}
	bool ifHandled()
	{
		return bHandled;
	}
	void setHandled()
	{
		bHandled = true;
	}
	virtual ~MessageBase(){};
protected:
	bool bHandled;
	MSG_TYPE m_msg;
private:
};

#endif