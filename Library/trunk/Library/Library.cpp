#include "Library.h"
#include "Book.h"
#include <sstream>
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
	stringstream ss;
	ss<<CID;
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	it_s=find(_SL.begin(),_SL.end(),SID);
	it_b=find(_BL.begin(),_BL.end(),ss);
    if((*it_b)->getIsBorrowed()) //checks if it_b is already borrowed
	{
		// need to handle!
	}
	Borrow btemp;// create new borrow
	if(typeid(*it_b).name()=="Book")
		btemp.setBookType(_Book);
	else if(typeid(*it_b).name()=="ReservedBook")
		btemp.setBookType(_ReservedBook);
	else
		btemp.setBookType(_Journal);
	btemp.setCID((*it_b)->getCatalogId());
	it_s->push(btemp);
	(*it_b)->setIsBorrowed();
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