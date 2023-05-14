#pragma once
#include <iostream>
using namespace std;

enum class mark : char { ����� = 1, ������� = 0, ����2 = 2, ��3 = 3, ���4 = 4, ���5 = 5 };

struct Exams
{
	string name;
	enum class mark;
	bool isEmpty;
};

struct StudentNote
{
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
};

class Student
{
public:
	Student();
	~Student();
	StudentNote sn;
	void setDefaultData();
	void printInfo();
	void printShortInfo(int index);
	void editData();
};