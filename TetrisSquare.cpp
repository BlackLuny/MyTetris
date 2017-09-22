#include "TetrisSquare.h"
static bool g_Tetris_model[][4] = 
{
	{
		1, 1, // **
		1, 1  // **
	}
};
TetrisSquare::TetrisSquare(): ::TetrisBase(TYP_TETRIS_6)
{

	m_map = new TetrisMap(g_Tetris_model[0], 2);

}
TetrisSquare::~TetrisSquare()
{
	delete m_map;
}
void TetrisSquare::rotate(int angele)
{
	//cout << "Square type can't rotate!\n";
}

int TetrisSquare::GetTetrisOffset()
{
	return 2;
}
