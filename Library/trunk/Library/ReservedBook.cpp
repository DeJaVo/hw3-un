#include"ReservedBook.h"

ReservedBook::ReservedBook(long CID,string BN,string AN):Book(CID,BN,AN)//c'tor+defualt c'tor
{
	_borrow_days=3;
}
