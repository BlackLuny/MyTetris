#include "GameMap.h"
#include "GameFram.h"
#include "TetrisBase.h"
bool illTest()
{
	GameFram* game = GameFram::getInstance();
	AggregateBase* gameMap = game->m_gameMap;
	TetrisBase* tetris = game->cur_tetris;
	if (tetris == NULL) return true;
	int width = gameMap->getWidth();
	int height = gameMap->getHeight();
	AggregateBase* tmp_map = new GameMap(height, width);
	tmp_map->CopyFrom(gameMap);
	bool check = tetris->PinToMap(tmp_map);
	delete tmp_map;
	return check;
}
		