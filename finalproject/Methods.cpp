#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include "Classesh.h"
using namespace std;
string Department::getName() {
	return this->name;
}
void Employee::userdetails() {
	cout << "Employee Details" << endl;
	cout << "ID: " << this->pID << endl;
	cout << "Name: " << this->name << endl;
	cout << "Email: " << this->email << endl;
	cout << "Address: " << this->address << endl;
	cout << "Department: " << this->dept->getName() << endl;
}

void System::addPerson(Person* p) {
	this->persons.push_back(p);
}
void System::loaddept() {
	fstream file;
	file.open("departments.txt", ios::in);
	string line;
	while (getline(file, line))
	{
		int id = stoi(line.substr(0, line.find(",")));
		line = line.substr(line.find(",") + 1, line.length() - 1);
		Department *dept = new Department(id, line);
		departments.push_back(dept);
	}
}
void System::loadEmployess() {
	fstream file;
	file.open("employees.txt", ios::in);
	string line;
	while (getline(file, line)) {
		int id = stoi(line.substr(0, line.find(',')));
		line = line.substr(line.find(',') + 1);
		string name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		string email = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		string add = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		int deptid = stoi(line.substr(0, line.find(',')));
		Department* dept = new Department(deptid, departments[deptid - 1]->getName());
		Person* emp = new Employee(id, name, email, add, dept);
		persons.push_back(emp);

	}
}
void System::loadMangers()
{
	fstream file;
	file.open("managers.txt", ios::in);
	string line;
	while (getline(file, line)) {
		int id = stoi(line.substr(0, line.find(',')));
		line = line.substr(line.find(',') + 1);
		string name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		string email = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		string add = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		int deptid = stoi(line.substr(0, line.find(',')));
		Department* dept = new Department(deptid, departments[deptid - 1]->getName());
		Manager* mgr = new Manager(id, name, email, add, dept);
		persons.push_back(mgr);
		this->deptManager(dept, mgr);
	}
}
void System::deptManager(Department* d, Manager* m)
{
	for (int i = 0; i < departments.size(); i++)
	{
		if (departments[i]->getID() == m->getID()) {
			departments[i]->setManager(m);
		}
	}
}
void Department::setManager(Manager* mgr) {
	this->mgr = mgr;
}
void System::loadTeachers()
{
	fstream f;
	f.open("teacher.txt", ios::in);
	string obj; int id; string name, email, add;
	while (getline(f, obj))
	{
		id = stoi(obj.substr(0, obj.find(",")));
		obj = obj.substr(obj.find(",") + 1);
		name = obj.substr(0, obj.find(","));
		obj = obj.substr(obj.find(",") + 1);
		email = obj.substr(0, obj.find(","));
		obj = obj.substr(obj.find(",") + 1);
		add = obj;
	}
}
void System::viewEmployes() {
	for (int i = 0; i < persons.size(); i++) {
		persons[i]->userdetails();
	}
}
void Manager::userdetails() {
	cout << "Manger Details" << endl;
	cout << "ID: " << this->pID << endl;
	cout << "Name: " << this->name << endl;
	cout << "Email: " << this->email << endl;
	cout << "Address: " << this->address << endl;
	cout << "Department: " << this->dept->getName() << endl;
}
void System::viewMangers() {
	for (int i = 0; i < persons.size(); i++) {
		persons[i]->userdetails();
	}
}