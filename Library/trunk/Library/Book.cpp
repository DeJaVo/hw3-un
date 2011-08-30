#include "Book.h"


Book::Book(long CID, string BN,string AN):BaseBook(CID),_BookName(BN),_AuthorName(AN)
{
	_borrow_days=14;
}

//bool Book::operator==(const Book& B)
//{
//	return (_CatalogId)==(B.getCatalogId())?true:false;
//}