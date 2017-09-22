#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "AggregateBase.h"
#include <iostream>
#include <deque>
using namespace std;
class GameMap: public AggregateBase
{
public:
	GameMap(int height, int width):m_height(height), m_width(width)
	{
		for(int i = 0; i < height; ++i)
		{
			int* cur = new int[width];
			memset((void*)cur, 0, sizeof(int)*width);
			m_deque.push_back(cur);
		}
	}
	virtual ~GameMap()
	{
		for(int i = 0; i < m_height; ++i)
		{
			delete [] m_deque[i];
		}
	}
	virtual IteratorBase* iterator(){return NULL;};
	virtual int getMapXY(int x, int y)
	{
		if ( x>=m_height || y>=m_width || x < 0 || y < 0) return -1;
		return m_deque[x][y];
	}
	virtual int setMapXY(int x, int y, int v)
	{
		if ( x>=m_height || y>=m_width || x < 0 || y < 0) return -1;
		m_deque[x][y] = v;
		return 0;
	}
	virtual int getWidth()
	{
		return m_width;
	}
	virtual int getHeight()
	{
		return m_height;
	}
private:
	int m_height;
	int m_width;
	deque<int*> m_deque;
};
#endif