#ifndef _BASEBOOK_H_
#define _BASEBOOK_H_

#include <time.h>
#include <iostream>

using namespace std;

class BaseBook
{
	protected:
		long _CatalogId;
		int _borrow_days;
		time_t _borrow_date;
		bool _isborrow;
		char* _type;
	public:
		BaseBook(long CID=0);//c'tor
		long getCatalogId() const {return _CatalogId;} 
		int get_borrow_days() const {return _borrow_days;}
		bool operator==(const long CID);
		bool getIsBorrowed()const {return _isborrow;}
		void setIsBorrowed(){_isborrow=!(_isborrow);}
		void setBorrowDate(time_t date){_borrow_date=date;}
		virtual char* getType() const {return _type;}

};

#endif