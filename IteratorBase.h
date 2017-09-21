#ifndef ITERATOR_BASE_H
#define ITERATOR_BASE_H
class IteratorBase
{
public:
	virtual bool hasNext() = 0;
	virtual void* next() = 0;
};
#endif