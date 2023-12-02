#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include "classesh.h"
using namespace std;
void System::loaddept() {
	fstream file;
	file.open("departments.txt", ios::in);
	string line;
	while (getline(file, line))
	{
		int id = stoi(line.substr(0, line.find(",")));
		line = line.substr(line.find(",") + 1, line.length());
		Department* dept = new Department(id, line);
		departments.push_back(dept);
	}
}
void System::loadManagers()
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
		Manager* mgr = new Manager(id, name, email, add);
		mgr->setDept(this->getDepartmentID(deptid));
		persons.push_back(mgr);
		this->deptManager(mgr->getDept(), mgr);
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
		Employee* emp = new Employee(id, name, email, add);
		emp->setDept(this->getDepartmentID(deptid));
		persons.push_back(emp);
		this->deptEmployee(emp->getDept(), emp);
	}
}
void Employee::setDept(Department*& d)
{
	this->dept = d;
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
string Department::getName() {
	return this->name;
}
void Employee::userdetails() {
	cout << "--- Employee Details ---" << endl << endl << endl;
	Person::userdetails();
	cout << " Employee of \t";
	this->dept->deptDetails();
	this->dept->deptManager();
}
void Employee::userdetail() {
	Person::userdetails();
}
void Department::deptEmployees()
{
	cout << "Employee in the Department are: \n";
	for (int i = 0; i < this->emp.size(); i++)
	{
		cout << "Employee " << i + 1 << endl;
		emp[i]->userdetail();
		cout << endl << endl;
	}
}
void System::addPerson(Person* p) {
	this->persons.push_back(p);
}
void System::getDepartment(Department*& d)
{
	d = this->departments[d->getID() - 1];
}
Department*& System::getDepartmentID(int d)
{
	return this->departments[d - 1];
}
void Manager::setDept(Department*& d)
{
	this->dept = d;
}

void System::deptManager(Department* d, Manager* m)
{
	d->setManager(m);
}
void System::deptEmployee(Department* d, Employee* e)
{
	d->setEmployee(e);
}
void Department::setEmployee(Employee* e)
{
	this->emp.push_back(e);
}
void Department::setManager(Manager* mgr) {
	this->mgr = mgr;
}

void System::viewEmployes() {
	for (int i = 0; i < persons.size(); i++) {
		if (persons[i]->getID() >= 200 && persons[i]->getID() < 300)
		{
			persons[i]->userdetails();
		}
	}
}
void Manager::userdetails() {
	Person::userdetails();
	cout << "Mananger of\t";
	this->dept->deptDetails();
	this->dept->deptEmployees();
}
void System::viewManagers() {
	cout << "--- Manager Details ---" << endl << endl << endl;
	for (int i = 0; i < persons.size(); i++) {
		if (persons[i]->getID() >= 100 && persons[i]->getID() < 200)
		{
			persons[i]->userdetails();
		}
	}
}
void System::deptDetails() {
	for (int i = 0; i < this->departments.size(); i++)
	{
		departments[i]->deptDetails();
	}
}
int Manager::getID()
{
	return dept->getID();
}
void System::TecherMenu() {
}
Department*& Manager::getDept()
{
	return this->dept;
}
string Manager::getName()
{
	return Person::getName();
}
int Manager::getDeptID()
{
	return this->dept->getID();
}
void System::AdminMenu() {
	system("cls");	
	cout<<"--------Welcome to The Admin---------"<<endl;
	cout<<"Please select an option from the following: "<<endl;
	cout<<"1. View Departments"<<endl;
	cout<<"2. View Managers"<<endl;
	cout<<"3. View Employees"<<endl;
	cout<<"4. View Teachers"<<endl;
	cout<<"5. Remove Manager"<<endl;
	cout<<"6. Remove Employee"<<endl;
	cout<<"7. Remove Teacher"<<endl;
	cout<<"8. Logout"<<endl;
label:
	int choice;
	cin>>choice;
	if (choice > 8 || choice < 1)
	{
		cout<<"Invalid Choice Enter Again"<<endl;
		goto label;
	}
	switch (choice)
	{
		case 1:
			this->deptDetails();
			break;
		case 2:
			this->viewManagers();
			break;
		case 3:
			this->viewEmployes();
			break;
		case 4:
			this->TecherMenu();
			break;
		case 5:
			this->Remove("Manager","managers.txt");
			break;
		case 6:
			this->Remove("Employee","employees.txt");
			break;
		case 7:
			this->Remove("Teacher","teachers.txt");
			break;
		case 8:
			return;
			break;
	}
label2:
	cout<<"Press 1 to go back to Admin Menu"<<endl;
	cout<<"Press 2 to Logout"<<endl;
	int choice2;
	cin>>choice2;
	if (choice2 == 1)
	{
		this->AdminMenu();
	}
	else if (choice2 == 2)
	{
		return;
	}
	else
	{
		cout<<"Invalid Choice"<<endl;
		goto label2;
	}
}
void System::ManagerMenu() {

}
void System::EmployeeMenu() {

}

void System::Remove(string entity,string filename)
{
	int flag = 0;
	if (entity == "Manager")
	{
		flag = 1;
	}
	else if (entity == "Employee")
	{
		flag = 2;
	}
	else if (entity == "Teacher")
	{
		flag = 3;
	}
	cout<<"Enter the ID of the "<<entity<<" you want to remove"<<endl;
	int id;
	cin>>id;
	for (int i = 0; i < persons.size(); i++)
	{
		if (persons[i]->getID() == id)
		{
			persons.erase(persons.begin() + i);
			cout<<entity<<" Removed"<<endl;
			writeFiles(flag, filename);
			return;
		}
	}
	cout<<entity<<" not found"<<endl;
}
void System::writeFiles(int flag, string filename)
{
	fstream file;
	file.open(filename, ios::out);
	if (flag == 1)
	{
		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i]->getID() >= 100 && persons[i]->getID() < 200)
			{
				file << persons[i]->getID() << "," << persons[i]->getName() << "," << persons[i]->getEmail() << "," << persons[i]->getAddress() << "," << persons[i]->getDeptID()<< endl;
			}
		}
	}
	else if (flag == 2)
	{
		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i]->getID() >= 200 && persons[i]->getID() < 300)
			{
				file << persons[i]->getID() << "," << persons[i]->getName() << "," << persons[i]->getEmail() << "," << persons[i]->getAddress() << "," << persons[i]->getDeptID() << endl;
			}
		}
	}
	file.close();
}
void System::run() {
	cout << "--------Welcome to The Complaint Management System---------" << endl;
	cout << "Please select an option from the following: " << endl;
	cout << "1. Techer"<< endl;
	cout << "2. Admin" << endl;
	cout << "3. Manager" << endl;
	cout << "4. Employee" << endl;
	cout << "5. Exit" << endl;
	label:
	int choice;
	cin >> choice;
	if (choice > 5 || choice < 1) {
		cout<<"Invalid Choice Enter Again"<<endl;
		goto label;
	}
	switch (choice) {
		case 1:
			this->TecherMenu();
			break;
		case 2:
			this->AdminMenu();
			break;
		case 3:
			this->ManagerMenu();
			break;
		case 4:
			this->EmployeeMenu();
			break;
		case 5:
			return;
			break;
	}
}
Department*& Employee::getDept()
{
	return this->dept;
}
int Employee::getDeptID()
{
	return this->dept->getID();
}
int Department::getID()
{
	return this->ID;
}
void Department::deptDetails()
{
	cout << "Department " << ID << " " << name << endl;
}
void Department::deptManager()
{
	cout << "Department Manager is " << this->mgr->getName() << endl;
}

int Person::getID()
{
	return this->pID;
}
string Person::getName()
{
	return name;
}
string Person::getEmail()
{
	return email;
}
string Person::getAddress()
{
	return address;
}
