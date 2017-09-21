#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H
#include "StateBase.h"
class PlayingState: public StateBase
{
public:
	PlayingState(HandlerBase* handle) : ::StateBase(STATE_GAME_PLAY, handle)
	{
		
	}
	virtual ~PlayingState()
	{

	}

};
#endif