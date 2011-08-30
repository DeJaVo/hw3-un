#include"ReservedBook.h"

ReservedBook::ReservedBook(long CID,string BN,string AN):Book(CID,BN,AN)
{
	_borrow_days=3;
}

bool ReservedBook::operator==(const ReservedBook& RB)
{
	return (_CatalogId)==(RB.getCatalogId())?true:false;
}