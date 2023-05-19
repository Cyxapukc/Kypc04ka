#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "Menu.h"
#include "ClassList.h"
#include "ClassStudent.h"
#include "Menu_Tools.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClassList *list = new ClassList;
    fstream file;
    string file_name = "Student_base.txt";
    file.open(file_name, fstream::in | fstream::out | fstream::app);
    if (!file.is_open())
    {
        drawLine('-');
        setInCenter("Ошибка открытия файла!");
        drawLine('-');
    }
    else
    {
        while (!(file.eof()))
        {
            Student value;
            file >> value;
            list->addItem(value);
        }
    }
    Main_menu(list, file_name);
    return 0;
}
