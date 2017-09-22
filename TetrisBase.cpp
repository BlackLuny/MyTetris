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

//将自己写到容器中，同时检查合法性，一部分在容器外边就是不合法的，全部在里面或者全部不在里面就是合法的。
bool TetrisBase::PinToMap(AggregateBase* map)
{
	int tetris_width = m_map->getWidth();
	int tetris_height = m_map->getHeight();
	int map_widht = map->getWidth();
	int map_height = map->getHeight();
	Vel2 cur_position = getPosition();
	int pos_x = cur_position[0];
	int pos_y = cur_position[1];

	bool bOutOfAgg = false;//是否有方块在外面；

	//以左上角为tetris原点
	pos_x -= tetris_height;
	pos_y -= tetris_width;

	//加上相对map的原点位置；
	pos_y += (map_widht/2 + GetTetrisOffset());
	//cout << "pos_x = " << pos_x << " pos_y = " << pos_y << endl;
	//开始填充
	for (int i = 0; i < tetris_height; ++i)
	{
		int cur_pos_x = i + pos_x;
		//if (cur_pos_x < 0 || cur_pos_x >= map_height) continue;
		for (int j = 0; j < tetris_width; ++j)
		{
			int cur_pos_y = j + pos_y;
			int value_tetris = m_map->getMapXY(i, j);
			if (cur_pos_y < 0 || cur_pos_y >= map_widht || cur_pos_x < 0 || cur_pos_x >= map_height) 
			{
				if (value_tetris == 1 && cur_pos_x >= 0)
					bOutOfAgg = true;//有方块在容器外面,且
				else 
					continue;
			}
			int value_map = map->getMapXY(cur_pos_x, cur_pos_y);
			if (value_tetris == 1 && bOutOfAgg) 
				return false;  //有方块在里面，有方块在外面
			if (value_map + value_tetris > 1) 
				return false;  //有方块重叠
			map->setMapXY(cur_pos_x, cur_pos_y, value_map + value_tetris);  //设置为相加的值
		}
	}
	return true;

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