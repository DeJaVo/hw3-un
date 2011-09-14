/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#include"ReservedBook.h"

ReservedBook::ReservedBook(long CID,string BN,string AN):Book(CID,BN,AN)//c'tor+defualt c'tor
{
	_borrow_days=3;
	_type="reserved book";
}
