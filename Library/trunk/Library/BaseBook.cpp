#include "BaseBook.h"

BaseBook::BaseBook(long CID):_CatalogId(CID)
{
	_borrow_days=0;
	_borrow_date=NULL;
	_isborrow=false;
}