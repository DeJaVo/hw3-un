#include "Borrow.h"

//checking if borrow is late
int Borrow::Late(time_t _Current_date)
{ 
	double diff=difftime(_Current_date,getStartDate());
	double days= (diff/86400);//Calculate days 
	days=ceil(days);//Round up
	if(_type=="reserved book")//Reserved Book
	{
		if(days>3)
			return static_cast<int>(days-3);	
	}
	if(_type=="journal")//Jourrnal
	{
		if(days>7)
		   return static_cast<int>(days-7);
	}			
	if(_type=="book")//Book
	{
	  if(days>14)
		return static_cast<int>(days-14);
	}		
return 0; //days of borrow do not exceed the limit
}

bool Borrow::operator==(const Borrow& b)
{
	return _CID==b._CID?true:false;
}

