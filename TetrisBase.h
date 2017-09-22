#ifndef TETRIS_BASE_H
#define TETRIS_BASE_H
#include "Point.h"
#include "Product.h"
#include "AggregateBase.h"
class TetrisBase : public Point,public Product
{
public:
	friend ostream& operator<<(ostream& os, const TetrisBase& tetris);
	TetrisBase(PDCTYPE type);
	virtual ~TetrisBase();
	virtual void use(){};

	//进行旋转
	virtual void rotate(int angle);

	virtual Vel2 getPosition()
	{
		return Point::getPosition();
	}
	virtual int GetAngle()
	{
		return m_angle;
	}
	//将自己的坐标填写到指定map上面；
	virtual bool PinToMap(AggregateBase* map);
	virtual void moveLeft()
	{
		Vel2 direction_left;
		direction_left(0,-1);
		Vel2 offset = direction_left*_v.speed;
		setPosition(_position + offset);
	}
	virtual void moveRight()
	{
		Vel2 direction_right;
		direction_right(0, 1);
		Vel2 offset = direction_right*_v.speed;
		setPosition(_position + offset);
	}
	virtual void moveUp()
	{
		Vel2 direction_up;
		direction_up(-1, 0);
		Vel2 offset = direction_up*_v.speed;
		setPosition(_position + offset);
	}
	virtual int GetTetrisOffset() = 0;  //真正的图形的相对偏移，用于校正
private:
	int 		   m_ID;
	int            m_angle;
	void 		   rotate90();
protected:
	AggregateBase *m_map;
};



#endif