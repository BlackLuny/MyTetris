#ifndef GAME_FRAM_H
#define GAME_FRAM_H
#include "MessageBase.h"
#include "StateBase.h"
#include "TetrisBase.h"
class GameFram
{
public:
	static GameFram *getInstance()
	{
		if (m_instance == NULL)
			m_instance = new GameFram();
		return m_instance;
	}
public:
	//接收并处理message
	void PushMsg(MessageBase* msg)
	{
		cur_state->stateHandle(msg);
	}
	TetrisBase* cur_tetris;
	TetrisBase* next_tetris;
private:
	GameFram();
	virtual ~GameFram()
	{
		for (int i = 0; i < 100; ++i)
		{
			if (m_totalHandler[i] != NULL)
				delete m_totalHandler[i];
		} 
		delete [] m_totalHandler;

		delete cur_state;
	}
	StateBase* cur_state;
	HandlerBase* *m_totalHandler;
	static GameFram *m_instance;
};
#endif