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
	book_is_borrowed(long CID,char* type);
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
	already_borrowed(long SID,long CID,char* type);
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
	TitleIsNotBorrowed(long SID,long CID,char* type);
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
	StudentDidNotBorrowThisTitle(long SID,long CID,char* type);
	virtual const char* what() const throw();
	virtual ~StudentDidNotBorrowThisTitle(){ delete[] _msg;}
};

//empty list 
class Empty:public exception
{
public:
	virtual const char* what() const throw(){return "The list is empty";}
};

//trying to find a student who doesn't exist in the student list (according to the ID)
class no_Student_With_This_ID:public exception{
	protected:
		long _SID;
		char* _msg;
	public:
	no_Student_With_This_ID(long SID);
	virtual const char* what() const throw();
	virtual ~no_Student_With_This_ID(){delete[] _msg;}
};

// trying to find a title that does not exost in the books list (according to the catalog ID)
class no_Title_With_This_Catalog_ID:public exception{
	protected:
		long _CID;
		char* _msg;
	public:
		no_Title_With_This_Catalog_ID(long CID);
		virtual const char* what() const throw();
};

#endif