#pragma once
#include <iostream>
#include "ClassList.h"

void Program_menu();
void Student_menu(ClassList *list, string file_name);
void Main_menu(ClassList *list, string file_name);

ostream& operator<<(ostream& os, Student& st);
istream& operator>>(istream& is, Student& st);