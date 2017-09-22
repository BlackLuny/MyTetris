#ifndef AGGREGATE_BASE_H
#define AGGREGATE_BASE_H
#include <iostream>
using namespace std;
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
	virtual void CopyFrom(AggregateBase* other);
	friend ostream& operator<<(ostream& os, AggregateBase& aggregation);
};
#endif