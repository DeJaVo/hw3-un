#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <list>
#include <iostream>
#include "Student.h"
#include <time.h>
#include <algorithm>
#include "BaseBook.h"
#include <typeinfo>


using namespace std;

class Library
{
	private:
			long elem;
			list<Student> _SL;
			list<BaseBook*> _BL;
			time_t _Date;
	public:
			Library(time_t date);
			void addTitle(BaseBook* B);
			void addStudent(const Student& S);
			void borrowTitle(const long& SID, const long& CID);
			void returnTitle(const long& SID, const long& CID);
			void clearFines(const long& SID);
			void endDay();
};






#endif