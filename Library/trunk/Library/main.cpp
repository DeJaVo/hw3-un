#include "Library.h"
#include "Book.h"
#include "ReservedBook.h"
#include "Journal.h"
#include "Student.h"
#include <time.h>
#include <iostream>
using namespace std;

int main(){
	Library library(time(NULL));
	Book b1(1,"my Book","Lolo");	
	library.addTitle(&b1);
	//check that book with same catalogid not inserted twice
	try{
		library.addTitle(&b1);
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"library cannot add title with the same catalogid twice (id=1)! **********"<<endl;

	ReservedBook r1(2,"my Reserved Book","Lili");
	library.addTitle(&r1);
	//check that reservedbook with same catalogid not inserted twice
	try{
		library.addTitle(&r1);
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"library cannot add title with the same catalogid twice!  (id=2)**********"<<endl;

	Journal j1(3,"my Journal",123);
	Journal jerr(3,"my duplicate journal",5);
	library.addTitle(&j1);
	//check that journal with same catalogid not inserted twice
	try{
		library.addTitle(&j1);
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"library cannot add title with the same catalogid twice (id=3)! **********"<<endl;
	try{
		library.addTitle(&jerr);
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"library cannot add title with the same catalogid twice (id=5)! **********"<<endl;

	Book b2(11,"my Book","Lolo");
    library.addTitle(&b2);
	//check that book with same title can be added
	Book b3(21,"my Book","Lolo");
    library.addTitle(&b3);

	ReservedBook r2(12,"my Reserved Book","Lili");
	library.addTitle(&r2);
	//check that book with same title can be added
	ReservedBook r3(22,"my Reserved Book","Lili");
	library.addTitle(&r3);

	Journal j2(13,"my Journal",123);
	library.addTitle(&j2);
	//check that journal with same title can be added
	Journal j3(23,"my Journal",122);
	library.addTitle(&j3);

	Student s1(1111,"Miko");
	library.addStudent(s1);
	Student s2(2222,"Miki");
	library.addStudent(s2);
	//check that a student with the same name can be added
	Student s3(3333,"Miki");
	library.addStudent(s3);
	Student serr(2222,"Duplicate Student");
	//check that student inserted twice
	try
	{
		library.addStudent(s2);
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"library cannot add student with the same id twice (id=2222)! **********"<<endl;
	try
	{
		library.addStudent(serr);
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"library cannot add student with the same id twice (id=2222)! **********"<<endl;


	library.borrowTitle(s1.getId(), b1.getCatalogId());
	library.borrowTitle(s1.getId(), r1.getCatalogId());
	library.borrowTitle(s1.getId(), j1.getCatalogId());

	//check that a student cannot borrow a book that she already borrowed
	try
	{
		library.borrowTitle(s1.getId(), b1.getCatalogId());
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"student " << s1.getId() << " already borrowed catalogid " << b1.getCatalogId() << " **********"<<endl;
	try
	{
		library.borrowTitle(s1.getId(), r1.getCatalogId());
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"student " << s1.getId() << " already borrowed catalogid " << r1.getCatalogId() << " **********"<<endl;
	try
	{
		library.borrowTitle(s1.getId(), j1.getCatalogId());
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"student " << s1.getId() << " already borrowed catalogid " << b1.getCatalogId() << " **********"<<endl;

	//check that you cannot borrow a book that is already borrowed
	try
	{
		library.borrowTitle(s2.getId(), b1.getCatalogId());
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"book with catalogid " << b1.getCatalogId() << " is already borrowed! **********"<<endl;
	try
	{
		library.borrowTitle(s2.getId(), r1.getCatalogId());
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"reserved book with catalogid " << r1.getCatalogId() << " is already borrowed! **********"<<endl;
	try
	{
		library.borrowTitle(s2.getId(), j1.getCatalogId());
	}catch(exception& e){
		cout<<e.what()<<endl;
	}
	cout<<"journal with catalogid " << j1.getCatalogId() << " is already borrowed! **********"<<endl;

	library.borrowTitle(s2.getId(), b2.getCatalogId());
	library.borrowTitle(s2.getId(), r2.getCatalogId());
	library.borrowTitle(s2.getId(), j2.getCatalogId());
	
	//check return date is checked on endDay for all types of titles
	library.endDay();
	library.returnTitle(s2.getId(), r2.getCatalogId());

	library.endDay();
	library.endDay();
	//here there should be an error message about the reserved books
	cout<<"Student " << s1.getId() << " has a fine of 10 NIS *********" << endl;

	library.returnTitle(s1.getId(), r1.getCatalogId());
	//here there should be no error messages
	library.endDay();
	library.endDay();
	library.borrowTitle(s2.getId(), r2.getCatalogId());
	library.endDay();
	library.returnTitle(s2.getId(), r2.getCatalogId());
	//check that you cannot return a title that is not borrowed
	try{
		library.returnTitle(s2.getId(), r2.getCatalogId());
	}
	catch(exception& e){
		cout << e.what() << endl;
	}
	cout << "student " << s2.getId() << " cannot return a book that is not borrowed (catalogid " << r2.getCatalogId() << ") **********"<<endl;
	
	//check that you cannot return a title that is not borrowed by the student
	try{
		library.returnTitle(s2.getId(), b1.getCatalogId());
	}
	catch(exception& e){
		cout << e.what() << endl;
	}
	cout << "student " << s2.getId() << " cannot return a book that is not borrowed (catalogid " << b1.getCatalogId() << ") **********"<<endl;

	library.endDay();
	//here there should be an error message about the journals books
	cout<<"Student " << s1.getId() << " has a fine of 20 NIS *********" << endl;
	cout<<"Student " << s2.getId() << " has a fine of 10 NIS *********" << endl;
	library.clearFines(s1.getId());

	library.endDay();
	cout<<"Student " << s1.getId() << " has a fine of 10 NIS *********" << endl;
	cout<<"Student " << s2.getId() << " has a fine of 20 NIS *********" << endl;
	library.endDay();
	cout<<"Student " << s1.getId() << " has a fine of 20 NIS *********" << endl;
	cout<<"Student " << s2.getId() << " has a fine of 30 NIS *********" << endl;
	
	library.returnTitle(s1.getId(), j1.getCatalogId());
	library.returnTitle(s2.getId(), j2.getCatalogId());

	library.endDay();
	library.endDay();
	library.endDay();
	library.endDay();
	library.endDay();
	//here there should be an error message about the books
	cout<<"Student " << s1.getId() << " has a fine of 30 NIS *********" << endl;
	cout<<"Student " << s2.getId() << " has a fine of 40 NIS *********" << endl;
	library.returnTitle(s1.getId(), b1.getCatalogId());
	library.returnTitle(s2.getId(), b2.getCatalogId());
	library.endDay();
	cout<<"Student " << s1.getId() << " has a fine of 30 NIS *********" << endl;
	cout<<"Student " << s2.getId() << " has a fine of 40 NIS *********" << endl;
	library.clearFines(s1.getId());
	library.clearFines(s2.getId());
	library.endDay();

	return 0;
}