#include "Tetris.h"
static bool g_Tetris_model[][9] = 
{
	{
		1, 1, 0, // **
		0, 1, 1, //  **
		0, 0, 0  //
	},
	{
		1, 0, 0, // *
		1, 1, 1, // ***
		0, 0, 0  //
	},
	{
		0, 0, 1, //   *
		1, 1, 1, // ***
		0, 0, 0  //
	},
	{
		0, 1, 1, //   **
		1, 1, 0, // ***
		0, 0, 0  //
	},
	{
		0, 1, 0, //  *
		1, 1, 1, // ***
		0, 0, 0 //
	}
};
Tetris::Tetris(PDCTYPE type): ::TetrisBase(type)
{
	m_map = new TetrisMap(g_Tetris_model[(int)type], 3);
}

Tetris::~Tetris()
{
	delete m_map;
}

int Tetris::GetTetrisOffset()
{
	return 2;
}
