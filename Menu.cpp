#include "Menu.h"
#include "ClassStudent.h"
#include "ClassList.h"
#include "Tools.h"
#include "ClassList.h"
#include "Menu_Tools.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <string.h>

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
void Student_menu(ClassList *list, std::string file_name)
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
        list->printItems();
        drawLine('-');
        drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
        drawLine('-');
        _getche();
        break;
    }
    case '2': {
        string id;
        Student *current = new Student;
        system("cls");
        drawLine('-');
        drawLine('|', "Введите номер зачётной книжки");
        id = ConsoleInput(10);
        drawLine('-');
        system("cls");
        *current = list->getItem(id);
        current->printInfo();
        drawLine('-');
        drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
        drawLine('-');
        _getche();
        delete current;
        break;
    }
    case '3': {
        Student *st = new Student;
        st->setDefaultData();
        list->addItem(*st);
        fstream file;
        file.open(file_name, fstream::in | fstream::out | fstream::app);
        file << *st;
        file.close();
        delete st;
        break;
    }
    case '4': {
        string id;
        system("cls");
        drawLine('-');
        drawLine('|', "Введите номер зачётной книжки");
        id = ConsoleInput(10);
        drawLine('-');
        list->deleteItem(list->getIndex(id));
        Student *st = new Student;
        delete st;
        break;
    }
    case '5': {
        break;
    }
    case '6': {
        string id;
        Student* st = new Student;
        system("cls");
        drawLine('-');
        drawLine('|', "Введите номер зачётной книжки");
        id = ConsoleInput(10);
        drawLine('|', id.c_str());
        drawLine('-');
        *st = list->getItem(id);
        st->editData();
        list->deleteItem(list->getIndex(id));
        list->insertItem(list->getIndex(id), *st);
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
void Main_menu(ClassList *list, std::string file_name)
{
    char Action = '0';
    fstream file;
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
            file.open(file_name, fstream::out);
            file.close();
            file.open(file_name, fstream::in | fstream::out | fstream::app);
            if (!file.is_open())
            {
                drawLine('-');
                setInCenter("Ошибка открытия файла!");
                drawLine('-');
            }
            else
            {
                for (int i = 1; i < list->getCount(); i++)
                {
                    Student value = list->getItem(i);
                    file << value;
                }
            }
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

ostream& operator<<(ostream& os, Student& st)
{
    os << st.get(1) << " " << st.get(2) << " " << st.get(3) << " " << st.get(4) << " " << st.get(5) << " " << st.get(6) << " " << st.get(7) << " " << st.get(8) << " " << st.get(9) << " " << st.get(10) << endl;
    return os;
}

istream& operator>>(istream& is, Student& st)
{
    string surname = st.get(1);
    string name = st.get(2);
    string midname = st.get(3);
    string institute = st.get(4);
    string department = st.get(5);
    string group = st.get(6);
    string id = st.get(7);
    string birthday = st.get(8);
    string enteranceYear = st.get(9);
    string sex = st.get(10);
    is >> surname >> name >> midname >> institute >> department >> group >> id >> birthday >> enteranceYear >> sex;
    return is;
}
