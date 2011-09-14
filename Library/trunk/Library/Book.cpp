/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#include "Book.h"


Book::Book(long CID, string BN,string AN):BaseBook(CID),_BookName(BN),_AuthorName(AN)//c'tor
{
	_borrow_days=14;
	_type="book";
}
