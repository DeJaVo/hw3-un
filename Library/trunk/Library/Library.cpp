#include "Library.h"


Library::Library(time_t date)
{
	_Date=date;
	_SL=list<Student>();
	_BL=list<BaseBook*>();
}


void Library::addStudent(const Student& S)
{
	list<Student>::iterator it_s; //iterator for student list
	it_s=find(_SL.begin(),_SL.end(),S.getId());
	if(it_s!=_SL.end())
		throw (existing_student_exception(S.getId()));
	_SL.push_back(S);
}


void Library::addTitle(BaseBook* B)
{
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	it_b= find_if(_BL.begin(), _BL.end(),FindElement(B->getCatalogId()));
	if(it_b!=_BL.end())
		throw(existing_book_exception(B->getCatalogId()));
	_BL.push_back(B);
}

void Library::borrowTitle(const long& SID,const long& CID)
{
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	list<Borrow*>::iterator it_e; //iterator for Borrow* list
	it_s=find(_SL.begin(),_SL.end(),SID);
	it_b= find_if(_BL.begin(), _BL.end(),FindElement(CID));
	it_e=find_if(it_s->beginIterator(),it_s->endIterator(),FindElement(CID));//search if student already borrowed CID
	if(it_e!=it_s->endIterator())
		throw(already_borrowed(it_s->getId(),(*it_e)->getCID()));
    if((*it_b)->getIsBorrowed()) //checks if it_b is already borrowed
		throw(book_is_borrowed((*it_b)->getCatalogId(),(*it_b)->get_borrow_days()));
	Borrow* btemp=new Borrow();// create new borrow
	if((*it_b)->get_borrow_days()==14)
		(btemp)->setBookType(_Book);
	else if((*it_b)->get_borrow_days()==3)
		(btemp)->setBookType(_ReservedBook);
	else
		(btemp)->setBookType(_Journal);
	(btemp)->setCID((*it_b)->getCatalogId());
	it_s->push(btemp);
	(*it_b)->setIsBorrowed();
}
void Library::returnTitle(const long& SID, const long& CID)
{
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	list<Borrow*>::iterator it_e;// iterator for Borrow
	it_s=find(_SL.begin(),_SL.end(),SID);
	it_b= find_if(_BL.begin(), _BL.end(), FindElement(CID));
	if((*it_b)->getIsBorrowed())
	{
	it_e=it_s->findBorrow(CID);//calling find borrow to find the to be deleted borrow
	if(it_e==it_s->endIterator())//if title wasnt borrowed by the student
		throw(StudentDidNotBorrowThisTitle(SID,CID));
	it_s->erase(it_e);//deletes the borrow from the list
	(*it_b)->setIsBorrowed();//return it to not borrowed
	}
	else
		throw(TitleIsNotBorrowed(SID,CID));
}

void Library::clearFines(const long& SID)
{
	list<Student>::iterator  it;
	it=find(_SL.begin(),_SL.end(),SID);
	it->NullifySumFines(_Date);
}

void Library::endDay()
{
	list<Student>::iterator  it_s;
	_Date+=86400;//update date to next date
	for(it_s=_SL.begin();it_s!=_SL.end();++it_s)
	{
		it_s->endOfDay(_Date);
	}
}