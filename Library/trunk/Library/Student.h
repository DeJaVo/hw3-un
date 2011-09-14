/***************************************************************************
 *
 * HW 3
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <list>
#include "Borrow.h"
#include <iostream>
#include <algorithm>
#include "FindElement.h"

using namespace std;

class Student
{
	private:
			long _SID;
			string _Name;
			double _Sum_Fines;
			list<Borrow*> _BorrowL;
	public:
			Student(long SID=0, string Name="");//c'tor+defualt c'tor
			void print() const;
			long getId() const {return _SID;}
			double getSumFine() const {return _Sum_Fines;}
			void NullifySumFines(time_t date);//calculate date differences and nullfy the student's fines
			bool operator==(const Student& ST);
			list<Borrow*>::iterator beginIterator(){return _BorrowL.begin();}//overloaded begin function
			list<Borrow*>::iterator endIterator(){return _BorrowL.end();}//overloaded end function
			void push(Borrow* bo);//overloaded push function in order to add a borrow
			void erase(list<Borrow*>::iterator it);//deleting a borrow from student's borrow list
			list<Borrow*>::iterator findBorrow(long CID);//overloaded find function
			void endOfDay(time_t _Current_date);//enday help function
};



#endif