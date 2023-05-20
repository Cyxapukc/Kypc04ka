#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "Menu.h"
#include "ClassList.h"
#include "ClassStudent.h"
#include "Menu_Tools.h"
#include "Tools.h"

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClassList *list = new ClassList;
    string** programm = new string * [9];
    for (int i = 0; i < 9; i++)
    {
        programm[i] = new string[9];
    }
    fstream programm_file;
    fstream file;
    string file_name = "Student_base.txt";
    string programm_file_name = "Programm_base.txt";

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
            string marks;
            file >> value;
            file >> marks;
            if (marks.length() < 80)
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        value.examsData[i][j].mark = '0';
                        value.examsData[i][j].isEmpty = true;
                    }
                }
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        string num = std::to_string(i) + std::to_string(j);
                        int index = atoi(num.c_str()) - i;
                        value.examsData[i][j].mark = marks[index];
                        value.examsData[i][j].isEmpty = false;
                    }
                }
            }
            list->push_back(value);
        }
    }
    
    programm_file.open(programm_file_name, fstream::in | fstream::out | fstream::app);
    if (!programm_file.is_open())
    {
        drawLine('-');
        setInCenter("Ошибка открытия файла!");
        drawLine('-');
    }
    else
    {
        while (!(programm_file.eof()))
        {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    string str;
                    std::getline(programm_file, str, '\n');
                    if (str != "") { programm[i][j] = str; }
                }
            }
        }
    }

    Main_menu(list, programm, file_name, programm_file_name);
    return 0;
}
