#ifndef TETRIS_SQUARE_H
#define TETRIS_SQUARE_H
#include "TetrisBase.h"
#include "TetrisMap.h"
#include "enu_type.h"
class TetrisSquare : public TetrisBase
{
public:
	TetrisSquare();
	virtual void rotate(int angle);  //覆盖掉这个函数
	virtual ~TetrisSquare();
	virtual  int GetTetrisOffset();
private:

};
#endif