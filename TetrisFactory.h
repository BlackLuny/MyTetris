#ifndef TETRIS_FACTORY_H
#define TETRIS_FACTORY_H
#include "Tetris.h"
#include "TetrisLine.h"
#include "TetrisSquare.h"
class TetrisFactory
{
public:
	static TetrisFactory *getInstance()
	{
		if (m_instance == NULL)
			m_instance = new TetrisFactory();
		return m_instance;
	}
	TetrisBase* CreateTetris(PDCTYPE type)
	{
		TetrisBase *newtetris = NULL;
		if (type == TYP_TETRIS_6)
			newtetris = new TetrisLine();
		else if(type == TYP_TETRIS_7)
			newtetris = new TetrisSquare();
		else if (type < TYP_TETRIS_6)
			newtetris = new Tetris(type);
		return newtetris;
	}
	void DestroyTetris(TetrisBase* tetris)
	{	
		delete tetris;
	}
	/*TetrisBase* CreateCopy(TetrisBase* tetris)
	{

	}*/
private:
	TetrisFactory()
	{

	}
	virtual ~TetrisFactory()
	{

	}
	static TetrisFactory *m_instance;
};
#endif