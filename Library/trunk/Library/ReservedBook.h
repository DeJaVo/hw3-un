#ifndef _RESERVED_BOOK_H
#define _RESERVED_BOOK_H

#include "Book.h"

class ReservedBook:public Book
{
	public:
		ReservedBook(long CID=0,string BN="",string AN="");
		bool operator==(const ReservedBook& RB);
};

#endif