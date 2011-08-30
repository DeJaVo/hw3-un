#include "Borrow.h"

int Borrow::Late()
{
	time_t _CurrentDate=time(NULL);//check if null -exception 
	double diff=difftime(_CurrentDate,getStartDate());
	double days= (diff/86400);//Calculate days
	days=ceil(days);//Round up
	switch(_type)
	{
		case 3://ReservedBook
			{
				if(days>3)
					return static_cast<int>(days-3);
			}
		case 7://Journal
			{
				if(days>7)
					return static_cast<int>(days-7);
			}
		case 14://Book
			{
				if(days>14)
					return static_cast<int>(days-14);
			}
		default:
			return 0; //days of borrow do not exceed the limit
	}
}

bool Borrow::operator==(const Borrow& b)
{
	return _CID==b._CID?true:false;
}

