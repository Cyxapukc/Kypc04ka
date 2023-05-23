#pragma once
#include <iostream>

using namespace std;

struct Exams
{
	char mark = '0';
	bool isEmpty = true;
};

class Student
{
public:
	string surname;
	string name;
	string midname;
	string institute;
	string department;
	string group;
	string id;
	string birthday;
	string enteranceYear;
	string sex;
	Exams examsData[9][10];
	void setDefault();
	void printInfo();
	void printShortInfo(int index);
	void editData();
};
