#ifndef _FINDELEMENT_H_
#define _FINDELEMENT_H_

#include "BaseBook.h"

class FindElement
{
long elem;
public:
explicit FindElement(long Elem=0) : elem(Elem) {}
bool operator() (BaseBook* b) const
{
	return (b->getCatalogId() == elem);
}
bool operator() (Borrow* b) const
{
	return (b->getCID() == elem);
}
};

#endif