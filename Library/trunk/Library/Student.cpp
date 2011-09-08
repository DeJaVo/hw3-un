#include "Student.h"

Student::Student(long SID, string Name)//c'tor+defualt c'tor
{
	_Sum_Fines=0;
	_Name=Name;
	_SID=SID;
	_BorrowL=list<Borrow*>();
}

//printing the student's fines
void Student::print() const
{
	cout<<"Student " << getId() << " has a fine of "<<getSumFine() <<" NIS "<<endl;
}

bool Student::operator==(const Student& ST)
{
	return (_SID==ST.getId()?true:false);
}

//overloaded push function in order to add a borrow
void Student::push(Borrow* bo)
{
	_BorrowL.push_back(bo);
}

//deleting a borrow from student's borrow list
void Student::erase(list<Borrow*>::iterator it)
{
	_BorrowL.erase(it);
}

//overloaded find function
list<Borrow*>::iterator Student::findBorrow(long CID)
{
	list<Borrow*>::iterator it;
	it=find_if(_BorrowL.begin(),_BorrowL.end(),FindElement(CID));
	return it;
}

//enday help function
void Student::endOfDay(time_t _Current_date)
{
	list<Borrow*>::iterator it;
	for(it=_BorrowL.begin();it!=_BorrowL.end();++it)
	{
		double current_fine=0;
		current_fine=10*((*it)->Late(_Current_date));//calculate sum of fines from the borrow time to current time
		if(current_fine>=10)//in case the fine is greater than one day fine
			_Sum_Fines+=10;//previous fines should grow by one day fine
	}
	if(_Sum_Fines>0)
		print();
}

//calculate date differences and nullfy the student's fines
void Student::NullifySumFines(time_t date)
{
	if(getSumFine()>0)//if fine student has fine
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