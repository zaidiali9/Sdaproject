#pragma once
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
class Person {
private:
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
	virtual void userdetails()
	{
		cout << "ID:" << this->pID;
		cout << "\t" << this->name << endl << endl;
		cout << "Email: " << this->email << endl;
		cout << "Address: " << this->address << endl << endl << endl;
	}
	int getID();
	string getName();
	string getEmail();
	string getAddress();
	virtual int getDeptID() {
		return 0;
	}
};
class Manager : public Person {
	vector<Job*> jobs; // an array
	Department* dept;
public:
	Manager(int pid = 0, string name = "", string email = "", string address = "") : Person(pid, name, email, address) {

	}
	void userdetails();
	int getID();
	void setDept(Department*& d);
	Department*& getDept();
	string getName();
	int getDeptID();
};
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
	void setManager(Manager* mgr);
	void setEmployee(Employee*);
	string getName();
	int getID();
	void deptDetails();
	void deptManager();
	void deptEmployees();
};

class Employee : public Person {
	Department* dept;
	Job* j;
public:
	Employee(int pid = 0, string name = "", string email = "", string address = "") : Person(pid, name, email, address) {
		this->dept = dept;
		this->j = nullptr;
	}
	void userdetails();
	void userdetail();
	void setDept(Department*& d);
	Department*& getDept();
	int getDeptID();
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
		loadManagers();
		loadEmployess();
	}
	void run();
	void addPerson(Person* p);
	void loaddept();
	void loadEmployess();
	void loadManagers();
	void loadTeachers();
	void viewManagers();
	void viewEmployes();
	void deptManager(Department* d, Manager* m);
	void deptEmployee(Department*, Employee*);
	void getDepartment(Department*& d);
	Department*& getDepartmentID(int);
	void deptDetails();
	void TecherMenu();
	void ManagerMenu();
	void EmployeeMenu();
	void AdminMenu();
	void Remove(string entity, string filname);
	void writeFiles(int flag,string filename);
};
