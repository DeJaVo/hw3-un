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

void Student::endOfDay(time_t _Current_date)
{
	list<Borrow*>::iterator it;
	_Sum_Fines=0;
	for(it=_BorrowL.begin();it!=_BorrowL.end();++it)
	{
			_Sum_Fines+=10*((*it)->Late(_Current_date));
	}
	if(_Sum_Fines>0)
		print();
}

void Student::NullifySumFines(time_t date)
{
	if(getSumFine()>0)
	{
		int num=0;
		list<Borrow*>::iterator it_b;
		for(it_b=beginIterator();it_b!=endIterator();it_b++)
		{
			num=(*it_b)->Late(date); //check if sending the library date is better
			if(num>0)
			{
				(*it_b)->setStartDate(num*86400);
			}
		}
		_Sum_Fines=0;
	}

}