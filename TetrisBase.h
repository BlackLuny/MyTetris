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
private:
	int 		   m_ID;
	int            m_angle;
	void 		   rotate90();
protected:
	AggregateBase *m_map;
};



#endif