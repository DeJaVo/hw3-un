/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#include "Library.h"


Library::Library(time_t date)//c'tor
{
	_Date=date;
	_SL=list<Student>();
	_BL=list<BaseBook*>();
}

//adding a student to library's student list
void Library::addStudent(const Student& S)
{
	list<Student>::iterator it_s; //iterator for student list
	it_s=find(_SL.begin(),_SL.end(),S.getId());
	if(it_s!=_SL.end())
		throw (existing_student_exception(S.getId()));
	_SL.push_back(S);
}

//adding a title to library's book list
void Library::addTitle(BaseBook* B)
{
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	it_b= find_if(_BL.begin(), _BL.end(),FindElement(B->getCatalogId()));
	if(it_b!=_BL.end())
		throw(existing_book_exception(B->getCatalogId()));
	_BL.push_back(B);
}

//borrwing a title
void Library::borrowTitle(const long& SID,const long& CID)
{
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	list<Borrow*>::iterator it_e; //iterator for Borrow* list
	if(_BL.empty())//check if Book list is empty
		throw (Empty());
	if(_SL.empty())//check if Student list is empty
		throw (Empty());
	it_s=find(_SL.begin(),_SL.end(),SID);
	if(it_s==_SL.end())
		throw(no_Student_With_This_ID(SID));// in case no student was found with current SID
	it_b= find_if(_BL.begin(), _BL.end(),FindElement(CID));
	if(it_b==_BL.end())
		throw(no_Title_With_This_Catalog_ID(CID));// in case no book with current CID was found
	it_e=find_if(it_s->beginIterator(),it_s->endIterator(),FindElement(CID));//search if student already borrowed CID
	if(it_e!=it_s->endIterator())//in case student already borrowed this title
		throw(already_borrowed(it_s->getId(),(*it_e)->getCID(),(*it_b)->getType()));
    if((*it_b)->getIsBorrowed()) //in case book is borrowed by someone 
		throw(book_is_borrowed((*it_b)->getCatalogId(),(*it_b)->getType()));
	Borrow* btemp=new Borrow(_Date);// create a new borrow
	(*it_b)->setBorrowDate(_Date);//setting book borrow date
	(btemp)->setBookType((*it_b)->getType());
	(btemp)->setCID((*it_b)->getCatalogId());
	it_s->push(btemp);//add to student borrow list
	(*it_b)->setIsBorrowed();
}

//returning a tilte
void Library::returnTitle(const long& SID, const long& CID)
{
	list<Student>::iterator  it_s; //iterator for student list
	list<BaseBook*>::iterator it_b; // iterator for basebook* list
	list<Borrow*>::iterator it_e;// iterator for Borrow
	if(_BL.empty())//check if list is empty
		throw (Empty());
	if(_SL.empty())//check if list is empty
		throw (Empty());
	it_s=find(_SL.begin(),_SL.end(),SID);
	if(it_s==_SL.end())
		throw(no_Student_With_This_ID(SID));//in case no student with current ID was found
	it_b= find_if(_BL.begin(), _BL.end(), FindElement(CID));
	if(it_b==_BL.end())
		throw(no_Title_With_This_Catalog_ID(CID));// in case no title with catalog ID was found
	if((*it_b)->getIsBorrowed())//if the title is borrowed
	{
		it_e=it_s->findBorrow(CID);//calling find borrow to find the to be deleted borrow
		if(it_e==it_s->endIterator())//if title wasnt borrowed by the student
			throw(StudentDidNotBorrowThisTitle(SID,CID,(*it_b)->getType()));

		it_s->erase(it_e);//deletes the borrow from the list
		(*it_b)->setIsBorrowed();//return it to not borrowed
		(*it_b)->setBorrowDate(0);//nullifying date
	}
	else
		throw(TitleIsNotBorrowed(SID,CID,(*it_b)->getType()));
}

//clearing fines
void Library::clearFines(const long& SID)
{
	list<Student>::iterator  it;
	it=find(_SL.begin(),_SL.end(),SID);//find the student by its ID
	if(it==_SL.end())
		throw(no_Student_With_This_ID(SID));//in case no student with current ID was found
	it->NullifySumFines(_Date);
}

// updating to next and printing students with fines
void Library::endDay()
{
	_Date+=86400;//update date to next date
	if(!_SL.empty())//check if list is not empty
	{
		list<Student>::iterator  it_s;
		for(it_s=_SL.begin();it_s!=_SL.end();++it_s)//running over students' list
		{
			it_s->endOfDay(_Date);
		}
	}
}