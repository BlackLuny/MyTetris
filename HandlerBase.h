#ifndef HANDLER_BASE_H
#define HANDLER_BASE_H
#include "MessageBase.h"
class HandlerBase
{
public:
	HandlerBase()
	{
		m_next = NULL;
	}
	void BeginHandle(MessageBase *msg)
	{
		MessageBase *newMsg = NULL;
		int state = doHandle(msg, newMsg);
		if (newMsg != NULL)
		{
			m_next->BeginHandle(newMsg);  //先处理newMsg
			delete newMsg;
		}
		if (state == true)
			return;
		else if (m_next != NULL)
			m_next->BeginHandle(msg);
		
			
	}
	HandlerBase* setNextHandler(HandlerBase * next)
	{
		m_next = next;
		return this;
	}
	virtual bool doHandle(MessageBase *msg, MessageBase*& newMsg) = 0;  //处理msg,可选发送新的msg给后续链条
virtual ~HandlerBase()
{

}	
protected:
	HandlerBase* m_next;
private:
	
};
#endif