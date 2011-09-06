#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>
#include "Borrow.h"
#include <sstream>
#include <string>

using namespace std;

class existing_book_exception: public exception{
protected:
	long _CID;
	char* _msg;
public:
	existing_book_exception(long CID);
	virtual const char* what() const throw();
	virtual ~existing_book_exception(){ delete[] _msg;}
};

class existing_student_exception: public exception{
protected:
	long _SID;
	char* _msg;
public:
	existing_student_exception(long SID);
	virtual const char* what() const throw();
	virtual ~existing_student_exception(){ delete[] _msg;}
};

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


#endif