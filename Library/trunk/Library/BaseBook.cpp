#include "BaseBook.h"

BaseBook::BaseBook(long CID):_CatalogId(CID)
{
	_borrow_days=0;
	_borrow_date=NULL;
	_isborrow=false;
}
bool BaseBook::operator==(const BaseBook& B)
{
	return (_CatalogId==B.getCatalogId()?true:false);
}

