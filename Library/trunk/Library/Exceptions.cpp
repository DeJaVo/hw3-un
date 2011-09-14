/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#include "Exceptions.h"


existing_book_exception::existing_book_exception(long CID)
{
_CID=CID;
stringstream ss;
ss<<"library cannot add title with the same catalogid twice " << "(id=" << _CID << ")!";
_msg = new char [ss.str().length() + 1];
strcpy(_msg, ss.str().c_str());
}

const char* existing_book_exception::what() const throw()
{
	return _msg;
}

existing_student_exception::existing_student_exception(long SID)
{
	_SID=SID;
	stringstream ss;
	ss<<"library cannot add student with the same id twice "<<"(id="<<_SID<<")!";
	_msg = new char [ss.str().length() + 1];
	strcpy(_msg, ss.str().c_str());
}
const char* existing_student_exception::what() const throw()
{
	return _msg;
}

 book_is_borrowed::book_is_borrowed(long CID, char* type)
 {
	 _CID=CID;
	stringstream ss;
	ss<<type<<" with catalogid "<<_CID<<" is already borrowed! ";
	_msg = new char [ss.str().length() + 1];
	strcpy(_msg, ss.str().c_str());
 }

 const char* book_is_borrowed::what() const throw()
{
	return _msg;
}

 already_borrowed::already_borrowed(long SID, long CID,char* type)
{
_CID=CID;
_SID=SID;
stringstream ss;
ss<<"student "<<_SID<<" already borrowed "<<type<<" with catalogid "<<_CID;
_msg = new char [ss.str().length() + 1];
strcpy(_msg, ss.str().c_str());
}

const char* already_borrowed::what() const throw()
{
	return _msg;
}

TitleIsNotBorrowed::TitleIsNotBorrowed(long SID,long CID, char* type)
{
_CID=CID;
_SID=SID;
stringstream ss;
ss<<"student "<<SID<<" cannot return a book (type: "<<type<<") that is not borrowed (catalogid "<<CID<<")";
_msg = new char [ss.str().length() + 1];
strcpy(_msg, ss.str().c_str());

}

const char* TitleIsNotBorrowed::what() const throw()
{
	return _msg;
}

StudentDidNotBorrowThisTitle::StudentDidNotBorrowThisTitle(long SID,long CID,char* type)
{
	_CID=CID;
	_SID=SID;
	stringstream ss;
	ss<<"student "<<SID<<" cannot return a book (type: "<<type<<") that is not borrowed (catalogid "<<CID<<")";
	_msg = new char [ss.str().length() + 1];
	strcpy(_msg, ss.str().c_str());
}

const char* StudentDidNotBorrowThisTitle::what() const throw()
{
	return _msg;
}

no_Student_With_This_ID::no_Student_With_This_ID(long SID)
{
	_SID=SID;
	stringstream ss;
	ss<<"Student with ID number: "<<_SID<<" does not exit in the library.";
	_msg=new char[ss.str().length()+1];
	strcpy(_msg,ss.str().c_str());
}

const char* no_Student_With_This_ID::what() const throw()
{
	return _msg;
}

no_Title_With_This_Catalog_ID::no_Title_With_This_Catalog_ID(long CID)
{
	_CID=CID;
	stringstream ss;
	ss<<"Title with catalog ID: "<<_CID<<" does not exist in the library.";
	_msg=new char[ss.str().length()+1];
	strcpy(_msg,ss.str().c_str());
}

const char* no_Title_With_This_Catalog_ID::what() const throw()
{
	return _msg;
}