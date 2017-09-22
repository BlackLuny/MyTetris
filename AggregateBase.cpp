#include "AggregateBase.h"
#include <iostream>
using namespace std;
void AggregateBase::CopyFrom(AggregateBase* other)
{
	const int height = other->getHeight();
	const int width  = other->getWidth();
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			setMapXY(i, j , other->getMapXY(i,j));
		}
	}
}
ostream& operator<<(ostream& os, AggregateBase& aggregation)
{
	const int height = aggregation.getHeight();
	const int width  = aggregation.getWidth();
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (aggregation.getMapXY(i,j)==1)
				cout <<"*";
			else
				cout << " ";
			//os << aggregation.getMapXY(i,j) << " ,";
		}
		os << endl;
	}
	return os;
}