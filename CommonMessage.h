#ifndef COMMON_MESSAGE_H
#define COMMON_MESSAGE_H
#include "MessageBase.h"
class CommonMessage:public MessageBase
{
public:
	CommonMessage(MSG_TYPE type, void* pInfo = NULL): ::MessageBase(type),m_pInfo(pInfo)
	{

	}
	virtual ~CommonMessage()
	{

	}
public:
	void* m_pInfo;
};
#endif