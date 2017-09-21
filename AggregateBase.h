#ifndef AGGREGATE_BASE_H
#define AGGREGATE_BASE_H
class IteratorBase;
class AggregateBase
{
public:
	virtual ~AggregateBase(){};
	virtual IteratorBase* iterator() = 0 ;
	virtual int getMapXY(int x, int y) = 0;
	virtual int setMapXY(int x, int y, int v) = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() =0;
};
#endif