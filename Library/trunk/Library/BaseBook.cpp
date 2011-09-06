#include "BaseBook.h"

BaseBook::BaseBook(const long CID):_CatalogId(CID)
{
	_borrow_days=0;
	_borrow_date=NULL;
	_isborrow=false;
}
bool BaseBook::operator==(const long CID)
{
	return (_CatalogId==CID?true:false);
}

