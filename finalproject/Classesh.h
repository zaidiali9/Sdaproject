#include <iostream>
#include <vector>
#include<fstream>
#include<string>
using namespace std;
class Department;
class Person;
class Employee;
class Manager;
class Teacher;
class Job;
class Complaint;
class ComplaintStatus;
class newComplaint;
class assignComplaint;
class resolvedComplaint;
class closedComplaint;
class System;
class Department {
	int ID;
	string name;
	Manager* mgr;
	vector<Employee*> emp; // we might not be able to manipulate vectors as pointers.
	vector<Complaint*> c;
public:
	Department(int id = 0, string name = "", Manager* m = nullptr) {
		this->ID = id;
		this->name = name;
		this->mgr = m;
	}
	string getName();
	int getID()
	{
		return this->ID;
	}
	void setManager(Manager* mgr);
};
class Person {
protected:
	int pID;
	string name;
	string email;
	string address;
public:
	Person(int pid = 0, string name = "", string email = "", string address = "") {
		this->pID = pid;
		this->name = name;
		this->email = email;
		this->address = address;
	}
	virtual void userdetails() {}
};
class Employee : public Person {
	Department* dept;
	Job* j;
public:
	Employee(int pid = 0, string name = "", string email = "", string address = "", Department* dept = nullptr) : Person(pid, name, email, address) {
		this->dept = dept;
		this->j = nullptr;
	}
	void userdetails();
};
class Manager : public Person {
	vector<Job*> jobs; // an array
	Department* dept;
public:
	Manager(int pid = 0, string name = "", string email = "", string address = "", Department* dept = nullptr) : Person(pid, name, email, address) {
		this->dept = dept;
	}
	void userdetails();
	int getID()
	{
		return dept->getID();
	}
};
class Teacher : public Person {
	Complaint* c;
public:
	Teacher(Complaint*& c1)
	{
		c = c1; // shalllow copy cuz we want to deal with pointers
	}

};
class Job {
	Complaint* c;
	Manager* mgr;
	Employee* emp;
public:
	Job()
	{
		c = nullptr;
		mgr = nullptr;
		emp = nullptr;
	}
};

class Complaint {
	ComplaintStatus* status;
	Teacher* t;
	string description;
	string date; //date class kiu nahi use ki?
	string time;
	int compid;
	string feedback; //usko dekhna
};
class ComplaintStatus {

};
class newComplaient : public ComplaintStatus {

};
class assignComplaint : public ComplaintStatus {

};
class resolvedComplaint : public ComplaintStatus {

};
class closedComplaint : public ComplaintStatus {

};

class System {
	vector<Person*> persons;
	vector<Department*> departments;
public:
	System() {
		loaddept();
		loadEmployess();
		viewEmployes();
		cout << "Managers" << endl;
		loadMangers();
		viewMangers();
	}
	void addPerson(Person* p);
	void loaddept();
	void loadEmployess();
	void loadMangers();
	void viewEmployes();
	void loadTeachers();
	void viewMangers();
	void deptManager(Department* d, Manager* m);
};		