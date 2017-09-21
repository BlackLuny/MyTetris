#ifndef TETRIS_MAP_H
#define TETRIS_MAP_H
#include "IteratorBase.h"
#include "AggregateBase.h"
class TetrisMap: public AggregateBase
{
	#define _(X,Y) map[ (X) * size + (Y)]
public:
	TetrisMap(bool *map, int size)
	{
		m_vec2 = new int*[size];
		for (int i = 0; i < size; ++i)
			m_vec2[i] = new int[size];
		for (int x = 0; x < size; ++x)
			for (int y = 0; y < size; ++y)
				m_vec2[x][y] = _(x,y);
		m_size = size;
	}
	virtual ~TetrisMap()
	{
		for (int i = 0; i < m_size; ++i)
			delete [] m_vec2[i];
		delete [] m_vec2;
	}


	virtual IteratorBase* iterator(){return NULL;};
	virtual int getMapXY(int x, int y)
	{
		if ( x>=m_size || y>=m_size) return -1;
		return m_vec2[x][y];
	}
	virtual int setMapXY(int x, int y, int v)
	{
		if ( x>=m_size || y>=m_size) return -1;
		m_vec2[x][y] = v;
		return 0;
	}
	virtual int getWidth()
	{
		return m_size;
	}
	virtual int getHeight()
	{
		return m_size;
	}
private:
	int **m_vec2;
	int m_size;
};

#endif