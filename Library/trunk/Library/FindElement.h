/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#ifndef _FINDELEMENT_H_
#define _FINDELEMENT_H_

#include "BaseBook.h"
#include "Borrow.h"

class FindElement
{
long elem;
public:
explicit FindElement(long Elem=0) : elem(Elem) {}// explict c'tor in order to convert to long
bool operator() (BaseBook* b) const//converstion operator from basebook*
{
	return (b->getCatalogId() == elem);
}
bool operator() (Borrow* b) const//conversion operator from borrow*
{
	return (b->getCID() == elem);
}
};

#endif