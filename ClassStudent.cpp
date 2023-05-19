#include "ClassStudent.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <Windows.h>
#include "Menu.h"
#include "Tools.h"
#include "Menu_Tools.h"

using namespace std;

Student::Student()
{
	this->surname = "Иванов";
	this->name = "Иван";
	this->midname = "Иванович";
	this->institute = "ИКБ";
	this->department = "Информационная_безопасность";
	this->group = "БАСО-00-00";
	this->id = "1234567890";
	this->birthday = "01.01.1982";
	this->sex = "Мужской";
	this->enteranceYear = "2000";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			this->examsData[i][j].isEmpty = true;
		}
}

Student::~Student()
{
}

string Student::get(const int Action)
{
	switch (Action)
	{
	case 1: {return this->surname; }
	case 2: {return this->name; }
	case 3: {return this->midname; }
	case 4: {return this->institute; }
	case 5: {return this->department; }
	case 6: {return this->group; }
	case 7: {return this->id; }
	case 8: {return this->birthday; }
	case 9: {return this->enteranceYear; }
	case 10: {return this->sex; }
	case 11: {; } //EXAMS
	}
}

void Student::setDefaultData()
{
	this->surname = "Иванов";
	this->name = "Иван";
	this->midname = "Иванович";
	this->institute = "ИКБ";
	this->department = "Информационная_безопасность";
	this->group = "БАСО-00-00";
	this->id = "1234567890";
	this->birthday = "01.01.1982";
	this->sex = "Мужской";
	this->enteranceYear = "2000";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			this->examsData[i][j].isEmpty = true;
		}
}
void Student::printInfo()
{
	drawLine('-');
	drawLine('|', "Фамилия: ", this->surname.c_str());
	drawLine('|', "Имя: ", this->name.c_str());
	drawLine('|', "Отчество: ", this->midname.c_str());
	drawLine('|', "Институт: ", this->institute.c_str());
	drawLine('|', "Подразделение: ", this->department.c_str());
	drawLine('|', "Группа: ", this->group.c_str());
	drawLine('|', "Номер зачётной книжки: ", this->id.c_str());
	drawLine('|', "Дата рождения: ", this->birthday.c_str());
	drawLine('|', "Год поступления: ", this->enteranceYear.c_str());
	drawLine('|', "Пол: ", this->sex.c_str());
	drawLine('-');
}
void Student::printShortInfo(int index)
{
	ostringstream str;
	str << index;
	string data = str.str() + ". " + this->surname + " " + this->name + " " + this->midname + " " + this->id;
	drawLine('|', data.c_str());
}
void Student::editData()
{
	char Action;
	string value;
	system("cls");
	printIdMenu();
	Action = menuIntInput(1, 9, "id");
	switch (Action)
	{
	case '1': {
		cout << "Новое имя: ";
		value = ConsoleInput(20, "char");
		this->name = value;
		cout << "Новая фамилия: ";
		value = ConsoleInput(20, "char");
		this->surname = value;
		cout << "Новое отчество: ";
		value = ConsoleInput(20, "char");
		this->midname = value;
		break;
	}
	case '2': {
		cout << "Новый институт: ";
		value = ConsoleInput(20, "char");
		this->institute = value;
		break;
	}
	case '3': {
		cout << "Новое подразделение: ";
		value = ConsoleInput(20, "char");
		this->department = value;
		break;
	}
	case '4': {
		cout << "Новая группа: ";
		value = ConsoleInput(10);
		this->group = value;
		break;
	}
	case '5': {
		drawLine('|', "Новый номер зачётной книжки: ");
		value = ConsoleInput(10, "num");
		this->id = value;
		break;
	}
	case '6': {
		while (!DateCheck(value)) {
			cout << "Новая дата рождения (ДД.ММ.ГГГГ): ";
			value = ConsoleInput(10);
		}
		this->birthday = value;
		break;
	}
	case '7': {
		cout << "Новый год поступления: ";
		value = ConsoleInput(4, "num");
		this->enteranceYear = value;
		break;
	}
	case '8': {
		cout << " ";
		value = ConsoleInput(20);
		break;
	}
	case '9': {
		system("cls");
		return;
	}
	default:
		break;
	}
}
