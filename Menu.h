#pragma once
#include <iostream>
#include "ClassList.h"

void Program_menu(string** programm, string programm_file_name);
void Student_menu(ClassList *list, string** programm, string file_name, string programm_file_name);
void Main_menu(ClassList *list, string** programm, string file_name, string programm_file_name);

ostream& operator<<(ostream& os, Student& st);
istream& operator>>(istream& is, Student& st);

ifstream& operator>>(ifstream& is, string& str);
ofstream& operator<<(ofstream& os, string& str);