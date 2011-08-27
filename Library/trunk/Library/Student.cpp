#include "Student.h"

Student::Student(long SID, string Name)
{


}

Student::Student(const Student& S)
{

}

void Student::print() const
{
	cout<<"Student " << getId() << " has a fine of "<<getSumFine() <<" NIS "<<endl;
}
