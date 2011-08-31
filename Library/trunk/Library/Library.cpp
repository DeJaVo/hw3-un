#include "Library.h"
#include "Book.h"
#include "FindElement.h"

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
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	it_s=find(_SL.begin(),_SL.end(),SID);
	it_b= find_if(_BL.begin(), _BL.end(), FindElement(CID));
    if((*it_b)->getIsBorrowed()) //checks if it_b is already borrowed
	{
		// need to handle!
	}
	Borrow btemp;// create new borrow
	if(typeid(**(it_b)).name()==string("class Book"))
		btemp.setBookType(_Book);
	else if(typeid(**it_b).name()==string("class ReservedBook"))
		btemp.setBookType(_ReservedBook);
	else
		btemp.setBookType(_Journal);
	btemp.setCID((*it_b)->getCatalogId());
	it_s->push(btemp);
	(*it_b)->setIsBorrowed();
}

void Library::returnTitle(const long& SID, const long& CID)
{
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	list<Borrow>::iterator it_e;// iterator for Borrow
	it_s=find(_SL.begin(),_SL.end(),SID);
	it_b= find_if(_BL.begin(), _BL.end(), FindElement(CID));
	it_e=it_s->findBorrow(CID);//calling find borrow to find the to be deleted borrow
	it_s->erase(it_e);//deletes the borrow from the list
	(*it_b)->setIsBorrowed();//return it to not borrowed
}

void Library::clearFines(const long& SID)
{
	list<Student>::iterator  it;
	it=find(_SL.begin(),_SL.end(),SID);
	it->NullifySumFines();
}

void Library::endDay()
{
	list<Student>::iterator  it_s;
	for(it_s=_SL.begin();it_s!=_SL.end();++it_s)
	{
		it_s->endOfDay();
	}
	_Date+=86400;//update date to next date

}