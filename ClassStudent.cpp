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
}

Student::~Student()
{
}


void Student::setDefaultData()
{
	sn.surname = "Иванов";
	sn.name = "Иван";
	sn.midname = "Иванович";
	sn.institute = "ИКБ";
	sn.department = "Информационная_безопасность";
	sn.group = "БАСО-00-00";
	sn.id = "1234567890";
	sn.birthday = "01.01.1982";
	sn.sex = "Мужской";
	sn.enteranceYear = "2000";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			sn.examsData[i][j].isEmpty = true;
		}
}

void Student::printInfo()
{
	drawLine('-');
	drawLine('|', "Фамилия: ", sn.surname.c_str());
	drawLine('|', "Имя: ", sn.name.c_str());
	drawLine('|', "Отчество: ", sn.midname.c_str());
	drawLine('|', "Институт: ", sn.institute.c_str());
	drawLine('|', "Подразделение: ", sn.department.c_str());
	drawLine('|', "Группа: ", sn.group.c_str());
	drawLine('|', "Номер зачётной книжки: ", sn.id.c_str());
	drawLine('|', "Дата рождения: ", sn.birthday.c_str());
	drawLine('|', "Год поступления: ", sn.enteranceYear.c_str());
	drawLine('|', "Пол: ", sn.sex.c_str());
	drawLine('-');
}
void Student::printShortInfo(int index)
{
	ostringstream str;
	str << index;
	string data = str.str() + ". " + sn.surname + " " + sn.name + " " + sn.midname + " " + sn.id;
	drawLine('|', data.c_str());
}
void Student::editData()
{
	char Action;
	string value;
	system("cls");
	drawLine('-');
	printIdMenu();
	Action = menuIntInput(1, 9, "id");
	switch (Action)
	{
	case '1': {
		cout << "Имя: ";
		value = ConsoleInput(20, "char");
		sn.name = value;
		cout << "Фамилия: ";
		value = ConsoleInput(20, "char");
		sn.surname = value;
		cout << "Отчество: ";
		value = ConsoleInput(20, "char");
		sn.midname = value;
		break;
	}
	case '2': {
		cout << "Институт: ";
		value = ConsoleInput(20, "char");
		sn.institute = value;
		break;
	}
	case '3': {
		cout << "Подразделение: ";
		value = ConsoleInput(20, "char");
		sn.department = value;
		break;
	}
	case '4': {
		cout << "Группа: ";
		value = ConsoleInput(10);
		sn.group = value;
		break;
	}
	case '5': {
		cout << "Номер зачётной книжки: ";
		value = ConsoleInput(10, "num");
		sn.id = value;
		break;
	}
	case '6': {
		while (!DateCheck(value)) {
			cout << "Дата рождения (ДД.ММ.ГГГГ): ";
			value = ConsoleInput(10);
		}
		sn.birthday = value;
		break;
	}
	case '7': {
		cout << "Год поступления: ";
		value = ConsoleInput(4, "num");
		sn.enteranceYear = value;
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