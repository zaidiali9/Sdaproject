#include<iostream>
#include"Classesh.h"
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
	cout << "Department: " << this->department->getName() << endl;
}


System::System() {
	loaddept();
	loadEmployess();
	viewEmployes();
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
		line = line.substr(line.find(" ") + 1, line.length() - 1);
		departments.push_back(line);
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
		int deptid = stoi(line.substr(0, line.find(',')));
		Department* dept = new Department(deptid, departments[deptid - 1]);
		Person* emp = new Employee(id, name, email, "", dept);
		persons.push_back(emp);
	}
}
void System::viewEmployes() {
	for (int i = 0; i < persons.size(); i++) {
		persons[i]->userdetails();
	}
}
