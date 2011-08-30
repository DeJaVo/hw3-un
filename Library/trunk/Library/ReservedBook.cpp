#include"ReservedBook.h"

ReservedBook::ReservedBook(long CID,string BN,string AN):Book(CID,BN,AN)
{
	_borrow_days=3;
}
