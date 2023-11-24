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
class Complaient;
class ComplaientStatus;
class newComplaient;
class assignComplaient;
class resolvedComplaient;
class closedComplaient;
class System;
class Department {
	int ID;
	string name;
public:
	Department(int id = 0, string name = "") {
		this->ID = id;
		this->name = name;
	}
	string getName();
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
	virtual void userdetails() = 0;
};
class Employee : public Person {
	Department *department;
	public:
		Employee(int pid = 0, string name = "", string email = "", string address = "", Department* dept = nullptr) : Person(pid, name, email, address) {
			this->department = dept;
		}
		void userdetails();
};
class Manager : public Person {
	Employee *employees;
	Job *jobs;
	public:
		Manager(int pid = 0, string name = "", string email = "", string address = "", Employee* employees = nullptr) : Person(pid, name, email, address) {

		}
};
class Teacher : public Person {

};
class Job {

};

class Complaient {
	ComplaientStatus *status;
	string description;
	string date;
	string time;
	int compid;
	string feedback;
	int pID;
};
class ComplaientStatus {
	
};
class newComplaient : public ComplaientStatus {
	
};
class assignComplaient : public ComplaientStatus {

};
class resolvedComplaient : public ComplaientStatus {

};
class closedComplaient : public ComplaientStatus {

};

class System {
	vector<Person*> persons;
	vector<Complaient> complaients;
	vector<string> departments;
public:
	void addPerson(Person* p);
	System();
	void loaddept();
	void loadEmployess();
	void viewEmployes();
};

