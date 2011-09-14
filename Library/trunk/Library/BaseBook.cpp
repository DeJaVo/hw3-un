/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#include "BaseBook.h"

BaseBook::BaseBook(const long CID):_CatalogId(CID)//c'tor
{
	_borrow_days=0;
	_borrow_date=NULL;
	_isborrow=false;
	_type="";
}
bool BaseBook::operator==(const long CID)
{
	return (_CatalogId==CID?true:false);
}

