#ifndef _BORROW_H_ 
#define _BORROW_H_

#include <time.h>
#include <math.h>

enum BookType {None=0,_ReservedBook=3,_Journal=7,_Book=14};

class Borrow
{
	private:
			time_t _StartDate;
			long _CID;
			BookType _type;
	public:
			Borrow():_type(None),_CID(0),_StartDate(time(NULL)){}
			Borrow(long CID):_type(None),_CID( CID),_StartDate(time(NULL)){}
			long getCID() const {return _CID;}
			Borrow(BookType type, long CID):_type(type), _CID(CID){_StartDate=time(NULL);}
			void setBookType(BookType type){_type=type;}
			int getBookType() const {return _type;}
			time_t getStartDate() const {return _StartDate;}
			void setCID(long CID){_CID=CID;}
			bool operator==(const Borrow& b);
			int Late();
};

#endif
