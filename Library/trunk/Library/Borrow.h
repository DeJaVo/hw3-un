/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#ifndef _BORROW_H_ 
#define _BORROW_H_

#include <time.h>
#include <math.h>


class Borrow
{
	private:
			time_t _StartDate;
			long _CID;
			char* _type;
	public:
			Borrow():_type(NULL),_CID(0),_StartDate(time(NULL)){}//defualt c'tor
			Borrow(time_t date):_type(NULL),_CID(0),_StartDate(date){}//c'tor
			Borrow(long CID):_type(NULL),_CID( CID),_StartDate(time(NULL)){}//c'tor
			Borrow(char* type, long CID):_type(type), _CID(CID){_StartDate=time(NULL);}//c'tor
			long getCID() const {return _CID;}
			void setBookType(char* type){_type=type;}
			char* getBookType() const {return _type;}
			time_t getStartDate() const {return _StartDate;}
			void setCID(long CID){_CID=CID;}
			bool operator==(const Borrow& b);
			int Late(time_t _Current_date);//checking if borrow is late
			void setStartDate(time_t addition){_StartDate+=addition;}
};

#endif
