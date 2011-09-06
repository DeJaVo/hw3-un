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
			Student(long SID=0, string Name="");
			void print() const;
			long getId() const {return _SID;}
			double getSumFine() const {return _Sum_Fines;}
			void NullifySumFines() {_Sum_Fines=0;} 
			bool operator==(const Student& ST);
			list<Borrow*>::iterator beginIterator(){return _BorrowL.begin();}
			list<Borrow*>::iterator endIterator(){return _BorrowL.end();}
			void push(Borrow* bo);
			void erase(list<Borrow*>::iterator it);
			list<Borrow*>::iterator findBorrow(long CID);
			void endOfDay();
};



#endif