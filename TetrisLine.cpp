#include "TetrisLine.h"
static bool g_Tetris_model[][16] = 
{
	{
		0, 0, 0, 0,	//	
		1, 1, 1, 1, // ****
		0, 0, 0, 0, // 
		0, 0, 0, 0  //
	}
};
TetrisLine::TetrisLine(): ::TetrisBase(TYP_TETRIS_6)
{

	m_map = new TetrisMap(g_Tetris_model[0], 4);

}
TetrisLine::~TetrisLine()
{
	delete m_map;
}