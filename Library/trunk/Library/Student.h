#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
using namespace std;

class Student
{
	private:
			long _SID;
			string _Name;
			double _Sum_Fines;
			//list <>;
	public:
			Student(long SID=0, string Name="");
			Student(const Student& S);
			void print() const;
			long getId() const {return _SID;}
			void NullifySumFines(){_Sum_Fines=0;}
};



#endif