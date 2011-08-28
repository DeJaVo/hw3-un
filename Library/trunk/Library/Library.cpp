#include "Library.h"

Library::Library(time_t date)
{
	_Date=date;
	_SL=list<Student>();
	_BL=list<BaseBook*>();
}


void Library::addStudent(const Student& S)
{
	_SL.push_back(S);
}


void Library::addTitle(BaseBook* B)
{
	_BL.push_back(B);
}

void Library::borrowTitle(const long& SID, const long& CID)
{
	list<Student>::iterator  it_s;
	it_s=find(_SL.begin(),_SL.end(),SID);
	list<BaseBook*>::iterator it_b;
	it_b=find(_BL.begin(),_BL.end(),CID);
	if(find(it_s->beginIterator(),it_s->endIterator(),CID)==it_s->endIterator())
	{
		if(typeid(*it_b).name()=="Book")
			Borrow btemp(_Book,CID);
		else if(typeid(*it_b).name()=="ReservedBook")
			Borrow btemp(_ReservedBook,CID);
		else 
			Borrow btemp(_Journal,CID);
		it_s->push();
	}
}

void Library::returnTitle(const long& SID, const long& CID)
{

}
void Library::clearFines(const long& SID)
{
	list<Student>::iterator  it;
	it=find(_SL.begin(),_SL.end(),SID);
	it->NullifySumFines();
}

void Library::endDay()
{

}