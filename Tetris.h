#ifndef TETRIS_H
#define TETRIS_H
#include "TetrisBase.h"
#include "TetrisMap.h"
class Tetris : public TetrisBase
{
public:
	Tetris(PDCTYPE type);
	virtual ~Tetris();
	virtual int GetTetrisOffset();
private:
};
#endif