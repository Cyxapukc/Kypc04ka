#include "Menu.h"
#include "ClassStudent.h"
#include "ClassList.h"
#include "Tools.h"
#include "ClassList.h"
#include "Menu_Tools.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

ostream& operator<<(ostream& os, Student& st)
{
    os << st.sn.surname << " " << st.sn.name << " " << st.sn.midname << " " << st.sn.institute << " " << st.sn.department << " " << st.sn.group << " " << st.sn.id << " " << st.sn.birthday << " " << st.sn.enteranceYear << " " << st.sn.sex << endl;
    return os;
}
istream& operator>>(istream& is, Student& st)
{
    is >> st.sn.surname >> st.sn.name >> st.sn.midname >> st.sn.institute >> st.sn.department >> st.sn.group >> st.sn.id >> st.sn.birthday >> st.sn.enteranceYear >> st.sn.sex;
    return is;
}

void Program_menu()
{
    char Action;
    string program_base = "Program_base.txt";
    system("cls");
    printProgramMenu();
    Action = menuIntInput(1, 4, "program");
    switch (Action)
    {
    case '1': {
        break;
    }
    case '2': {

        break;
    }
    case '3': {

        break;
    }
    case '4': {

        system("cls");
        return;
    }
    }
    system("cls");
}
void Student_menu(ClassList list, string file_name)
{
    char Action;
    system("cls");
    drawLine('-');
    printStudentMenu();
    Action = menuIntInput(1, 8, "student");
    switch (Action)
    {
    case '1': {
        system("cls");
        drawLine('-');
        list.printItems();
        drawLine('-');
        drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
        drawLine('-');
        _getche();
        break;
    }
    case '2': {
        string id;
        Student current;
        system("cls");
        drawLine('-');
        drawLine('|', "Введите номер зачётной книжки: ");
        id = ConsoleInput(10);
        drawLine('-');
        system("cls");
        current = list.getItem(id);
        current.printInfo();
        drawLine('-');
        drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
        drawLine('-');
        _getche();
        break;
    }
    case '3': {
        Student st;
        st.setDefaultData();
        fstream file;
        file.open(file_name, fstream::in | fstream::out | fstream::app);
        file << st;
        file.close();
        break;
    }
    case '4': {
        string id;
        system("cls");
        drawLine('-');
        drawLine('|', "Введите номер зачётной книжки: ");
        id = ConsoleInput(10);
        drawLine('-');
        list.deleteItem(list.getIndex(id));
        Student st;


        break;
    }
    case '5': {
        break;
    }
    case '6': {
        string id;
        system("cls");
        drawLine('-');
        drawLine('|', "Введите номер зачётной книжки: ");
        id = ConsoleInput(10);
        drawLine('|', id.c_str());
        drawLine('-');
        list.getItem(id).editData();
        break;
    }
    case '7': {

        break;
    }
    case '8': {
        system("cls");
        return;
    }
    }
    system("cls");
}

void Main_menu(ClassList list, string file_name, string tmp_name)
{
    char Action = '0';
    fstream file;
    fstream tmp;
    system("cls");
    drawLine('-');
    setInCenter("---<=== ДОБРО ПОЖАЛОВАТЬ В ПРОГРАММУ 'БАЗА ДАННЫХ СТУДЕНТОВ'! ===>---");
    drawLine('|', "");
    drawLine('-');
    while (true)
    {
        printMainMenu();
        Action = menuIntInput(1, 3, "main");
        switch (Action)
        {
        case '1': {
            Student_menu(list, file_name);
            break;
        }
        case '2': {
            Program_menu();
            break;
        }
        case '3': {
            tmp.open(tmp_name, fstream::in | fstream::out | fstream::app);
            file.open(file_name, fstream::in | fstream::out | fstream::app);
            file.clear();
            if (!tmp.is_open())
            {
                drawLine('-');
                setInCenter("Ошибка открытия файла!");
                drawLine('-');
            }
            else
            {
                for (int i = 0; i < list.getCount(); i++)
                {
                    Student value = list.getItem(i);
                    file << value;
                }
            }
            tmp.swap(file);
            system("cls");
            drawLine('-');
            setInCenter("---<=== ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ ===>---");
            drawLine('-');
            exit(0);

        }
        }
    }
    return;
}

