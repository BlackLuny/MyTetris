#ifndef STATE_BASE_H
#define STATE_BASE_H
#include "ENU_STATE.h"
#include "HandlerBase.h"
class StateBase
{
public:
	StateBase(STATE_TYPE state, HandlerBase *handler):m_state(state),m_handler(handler){};
	void stateHandle(MessageBase* msg)
	{
		m_handler->BeginHandle(msg);
	}
	virtual ~StateBase()
	{

	}
protected:
	HandlerBase *m_handler;
	STATE_TYPE m_state;
private:
};
#endif