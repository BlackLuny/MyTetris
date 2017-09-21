#include "TetrisBase.h"

TetrisBase::TetrisBase(PDCTYPE type): 
	::Product(type),::Point(), m_angle(0){};
TetrisBase::~TetrisBase(){};
void TetrisBase::rotate(int angle)
{
	if (angle % 90 != 0 ) return;
	int rotate_cnt = (angle / 90);
	for (int i = 0; i < rotate_cnt; ++i)
		rotate90();
	m_angle += angle;
	m_angle %= 360;
}
void TetrisBase::rotate90()
{
	int width = m_map->getWidth();
	int height = m_map->getHeight();

	//申请内存
	int **tmp_arr = new int*[height];
	for (int i = 0; i < width; ++i)
		tmp_arr[i] = new int[height];

	//旋转数组
	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j)	
			tmp_arr[i][j] = m_map->getMapXY(height - 1 - j, i);
		
	//拷贝回去
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			m_map->setMapXY(i, j, tmp_arr[i][j]);

	//释放内存
	for (int i = 0; i < width; ++i)
		delete [] tmp_arr[i];
	delete [] tmp_arr;
}

ostream& operator<<(ostream& os, const TetrisBase& tetris)
{
	int height = tetris.m_map->getHeight();
	int width = tetris.m_map->getWidth();
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if ((tetris.m_map)->getMapXY(i,j))
				os << "*";
			else
				os << " ";
		}
		os << endl;
	}
	return os;
}