#ifndef PRODUCT_H
#define PRODUCT_H
#include "enu_type.h"
class Product
{
public:
	PDCTYPE m_type;
	Product(PDCTYPE type):m_type(type){};
	PDCTYPE getType()
	{
		return m_type;
	}
	virtual ~Product(){};
	virtual void use() = 0;
};
#endif