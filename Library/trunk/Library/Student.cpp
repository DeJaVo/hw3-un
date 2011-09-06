#include "Student.h"

Student::Student(long SID, string Name)
{
	_Sum_Fines=0;
	_Name=Name;
	_SID=SID;
	_BorrowL=list<Borrow*>();
}


void Student::print() const
{
	cout<<"Student " << getId() << " has a fine of "<<getSumFine() <<" NIS "<<endl;
}

bool Student::operator==(const Student& ST)
{
	return (_SID==ST.getId()?true:false);
}

void Student::push(Borrow* bo)
{
	_BorrowL.push_back(bo);
}

void Student::erase(list<Borrow*>::iterator it)
{
	_BorrowL.erase(it);

}

list<Borrow*>::iterator Student::findBorrow(long CID)
{
	list<Borrow*>::iterator it;
	it=find_if(_BorrowL.begin(),_BorrowL.end(),FindElement(CID));
	return it;
}

void Student::endOfDay()
{
	list<Borrow*>::iterator it;
	for(it=_BorrowL.begin();it!=_BorrowL.end();++it)
	{
			_Sum_Fines=0;
			_Sum_Fines+=10*((*it)->Late());
	}
	if(_Sum_Fines>0)
		print();
}