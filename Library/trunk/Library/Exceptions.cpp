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

 book_is_borrowed::book_is_borrowed(long CID, int type)
 {
	 _CID=CID;
	 _type=type;
	stringstream ss;
	switch(_type)
	{
	case 3://ReservedBook
		{
		ss<<"reserved book with catalogid "<<_CID<<" is already borrowed! ";
		break;
		}
	case 7://Journal
		{
		ss<<"journal with catalogid "<<_CID<<" is already borrowed! ";
		break;
		}
	case 14://Book
		{
		ss<<"book with catalogid "<<_CID<<" is already borrowed! ";
		break;
		}
	}
	
	_msg = new char [ss.str().length() + 1];
	strcpy(_msg, ss.str().c_str());
 }

 const char* book_is_borrowed::what() const throw()
{
	return _msg;
}

 already_borrowed::already_borrowed(long SID, long CID)
{
_CID=CID;
_SID=SID;
stringstream ss;
ss<<"student "<<_SID<<" already borrowed catalogid "<< _CID;
_msg = new char [ss.str().length() + 1];
strcpy(_msg, ss.str().c_str());
}

const char* already_borrowed::what() const throw()
{
	return _msg;
}

TitleIsNotBorrowed::TitleIsNotBorrowed(long SID,long CID)
{
_CID=CID;
_SID=SID;
stringstream ss;
ss<<"student "<<SID<<" cannot return a book that is not borrowed (catalogid "<<CID<<")";
_msg = new char [ss.str().length() + 1];
strcpy(_msg, ss.str().c_str());

}

const char* TitleIsNotBorrowed::what() const throw()
{
	return _msg;
}

StudentDidNotBorrowThisTitle::StudentDidNotBorrowThisTitle(long SID,long CID)
{
	_CID=CID;
	_SID=SID;
	stringstream ss;
	ss<<"student "<<SID<<" cannot return a book that is not borrowed (catalogid "<<CID<<")";
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
	ss<<"student with ID number:"<<_SID<<"does not exit in the library."<<endl;
	_msg=new char[ss.str().length()+1];
	strcpy(_msg,ss.str().c_str());
}

const char* no_Student_With_This_ID::what() const throw()
{
	return _msg;
}