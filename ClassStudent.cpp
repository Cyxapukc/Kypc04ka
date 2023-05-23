#include "ClassStudent.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <Windows.h>
#include "Menu.h"
#include "Tools.h"
#include "Menu_Tools.h"
using namespace std;

void Student::setDefault()
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
			this->examsData[i][j].mark = '0';
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
	Action = menuIntInput(1, 8, "id");
	switch (Action)
	{
	case '1': {
		drawLine('|', "Новое имя: ");
		value = ConsoleInput(20, "char");
		this->name = value;
		drawLine('|', "Новая фамилия: ");
		value = ConsoleInput(20, "char");
		this->surname = value;
		drawLine('|', "Новое отчество: ");
		value = ConsoleInput(20, "char");
		this->midname = value;
		break;
	}
	case '2': {
		drawLine('|', "Новый институт: ");
		value = ConsoleInput(20, "char");
		this->institute = value;
		break;
	}
	case '3': {
		drawLine('|', "Новое подразделение: ");
		value = ConsoleInput(20, "char");
		this->department = value;
		break;
	}
	case '4': {
		drawLine('|', "Новая группа: ");
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
		do {
			drawLine('|', "Новая дата рождения (ДД.ММ.ГГГГ): ");
			value = ConsoleInput(10);
		} while (!DateCheck(value));
		this->birthday = value;
		break;
	}
	case '7': {
		drawLine('|', "Новый год поступления: ");
		value = ConsoleInput(4, "num");
		this->enteranceYear = value;
		break;
	}
	case '8': {
		system("cls");
		break;
	}
	default:
		break;
	}
}
