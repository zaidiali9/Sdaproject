#include <iostream>
#include <vector>
class System {
	vector<Person> persons;
	vector<Complaient> complaients;

};
class Person {
	int pID;
	string name;
	string email;
	string address;

};
class Employee : public Person {
	Department *department;
	Manager *manager;
};
class Manager : public Person {
	Job *jobs[];
};
class Teacher : public Person {

};
class Job {

};

class Department {
	int ID;
	string name;
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

