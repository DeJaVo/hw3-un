#include "Book.h"


Book::Book(long CID, string BN,string AN):BaseBook(CID),_BookName(BN),_AuthorName(AN)//c'tor
{
	_borrow_days=14;
}
