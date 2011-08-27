#ifndef _BOOK_H_
#define _BOOK_H_

#include "BaseBook.h"
#include <string>


class Book:public BaseBook
{
	protected:
			string _BookName;
			string _AuthorName;
	public:
			Book(long id=0,string BN="",string AN="");
};



#endif