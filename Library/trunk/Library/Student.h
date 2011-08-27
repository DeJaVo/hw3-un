#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <list>
#include "Borrow.h"
#include <iostream>
using namespace std;

class Student
{
	private:
			long _SID;
			string _Name;
			double _Sum_Fines;
			list<Borrow> _BorrowL;
	public:
			Student(long SID=0, string Name="");
			void print() const;
			long getId() const {return _SID;}
			void NullifySumFines(){_Sum_Fines=0;}
			double getSumFine() const {return _Sum_Fines;}
			bool operator==(const Student& ST);
			list<Borrow>::iterator beginIterator(){return _BorrowL.begin();}
			list<Borrow>::iterator endIterator(){return _BorrowL.end();}
			void push(const Borrow& bo);
};



#endif