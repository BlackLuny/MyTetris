#ifndef TETRISMAP_ITERATOR_H
#define TETRISMAP_ITERATOR_H
#include "IteratorBase.h"
class TetrisMapIterator: public IteratorBase
{
public:
	virtual ~TetrisMapIterator(){};
	virtual bool hasNext(){return false};
	virtual void* next(){return NULL};

};
#endif