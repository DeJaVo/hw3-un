#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>
#include "Borrow.h"
#include <sstream>
#include <string>

using namespace std;

//in case catalog ID already exist
class existing_book_exception: public exception{
protected:
	long _CID;
	char* _msg;
public:
	existing_book_exception(long CID);
	virtual const char* what() const throw();
	virtual ~existing_book_exception(){ delete[] _msg;}
};

//in case student ID already exist
class existing_student_exception: public exception{
protected:
	long _SID;
	char* _msg;
public:
	existing_student_exception(long SID);
	virtual const char* what() const throw();
	virtual ~existing_student_exception(){ delete[] _msg;}
};

//in case book is borrowed by someone 
class book_is_borrowed: public exception{
protected:
	long _CID;
	char* _msg;
	int _type;
public:
	book_is_borrowed(long CID,int type);
	virtual const char* what() const throw();
	virtual ~book_is_borrowed(){ delete[] _msg;}
};

//in case student already borrowed this title
class already_borrowed: public exception {
protected:
	long _CID;
	long _SID;
	char* _msg;
public:
	already_borrowed(long SID,long CID);
	virtual const char* what() const throw();
	virtual ~already_borrowed(){ delete[] _msg;}
};

//when trying to delete a not borrowed title
class TitleIsNotBorrowed:public exception
{
protected:
	long _CID;
	long _SID;
	char* _msg;
public:
	TitleIsNotBorrowed(long SID,long CID);
	virtual const char* what() const throw();
	virtual ~TitleIsNotBorrowed(){ delete[] _msg;}
};

//trying to delete a title that is not borrowed by the student
class StudentDidNotBorrowThisTitle: public exception
{
protected:
	long _CID;
	long _SID;
	char* _msg;
public:
	StudentDidNotBorrowThisTitle(long SID,long CID);
	virtual const char* what() const throw();
	virtual ~StudentDidNotBorrowThisTitle(){ delete[] _msg;}
};


#endif