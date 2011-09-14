/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <list>
#include <iostream>
#include "Student.h"
#include <time.h>
#include <algorithm>
#include "BaseBook.h"
#include <typeinfo>
#include "Book.h"
#include "Journal.h"
#include "ReservedBook.h"
#include "FindElement.h"
#include "Exceptions.h"
#include "Borrow.h"

using namespace std;

class Library
{
	private:
			list<Student> _SL;
			list<BaseBook*> _BL;
			time_t _Date;
	public:
			Library(time_t date);//c'tor
			void addTitle(BaseBook* B);//adding a title to library's book list
			void addStudent(const Student& S);//adding a student to library's student list
			void borrowTitle(const long& SID,const long& CID);//borrwing a title
			void returnTitle(const long& SID, const long& CID);//returning a tilte
			void clearFines(const long& SID);//clearing fines
			void endDay();// updating to next and printing students with fines
};






#endif