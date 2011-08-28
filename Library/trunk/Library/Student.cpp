#include "Student.h"

Student::Student(long SID, string Name)
{
	_Sum_Fines=0;
	_Name=Name;
	_SID=SID;
	_BorrowL=list<Borrow>();
}


void Student::print() const
{
	cout<<"Student " << getId() << " has a fine of "<<getSumFine() <<" NIS "<<endl;
}

bool Student::operator==(const Student& ST)
{
	return (_SID==ST.getId()?true:false);
}

void Student::push(const Borrow& bo)
{
	_BorrowL.push_back(bo);
}

void Student::erase(list<Borrow>::iterator it)
{
	_BorrowL.erase(it);

}

list<Borrow>::iterator Student::findBorrow(long CID)
{
	list<Borrow>::iterator it;
	it=find(_BorrowL.begin(),_BorrowL.end(),CID);
	return it;
}