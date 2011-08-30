#ifndef _JOURNAL_H
#define _JOURNAL_H

#include "BaseBook.h"

class Journal:public BaseBook
{
	protected:
			string _journal_name;
			int _journal_num;
	public:
		Journal(long CID=0,string JN="",int journal_num=0);
		/*bool operator==(const Journal& J);*/

};

#endif