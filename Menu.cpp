#include "Menu.h"
#include "ClassStudent.h"
#include "ClassList.h"
#include "Tools.h"
#include "ClassList.h"
#include "Menu_Tools.h"
#include <iostream>
#include <fstream>
#include <conio.h>

void Program_menu(string** programm, string programm_file_name)
{
    char Action;
    string program_base = "Program_base.txt";
    while (true)
    {
        system("cls");
        printProgramMenu();
        Action = menuIntInput(1, 4, "program");
        switch (Action)
        {
        case '1': {
            drawLine('-');
            drawLine('|', "Выберите нужный семестр от 1 до 9:");
            drawLine('-');
            char* Action = new char;
            *Action = menuIntInput(1, 9, "programm_choose");
            int index = atoi(Action) - 1;
            for (int i = 0; i < 9; i++)
            {
                string item = programm[index][i];
                cout << "| " << i + 1 << ". " << item;
                for (int j = 0; j < 80 - 6 - item.length(); j++) { cout << " "; }
                cout << "|";
            }
            drawLine('-');
            drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
            drawLine('-');
            _getche();
            delete Action;
            break;
        }
        case '2': {
            drawLine('-');
            drawLine('|', "Выберите семестр, который хотите изменить, от 1 до 9:");
            drawLine('-');
            char* Action = new char;
            *Action = menuIntInput(1, 9, "programm_choose");
            int sem_index = atoi(Action) - 1;
            for (int i = 0; i < 9; i++)
            {
                string item = programm[sem_index][i];
                cout << "| " << i + 1 << ". " << item;
                for (int j = 0; j < 80 - 6 - item.length(); j++) { cout << " "; }
                cout << "|" << endl;
            }

            drawLine('-');
            drawLine('|', "Выберите учебную дисциплину, которую хотите изменить/добавить, от 1 до 9:");
            drawLine('-');
            char* choose = new char;
            *choose = menuIntInput(1, 9, "discipline_choose");
            int dis_index = atoi(choose) - 1;
            drawLine('-');
            drawLine('|', "Введите название учебной дисциплины");
            string name = ConsoleInput(60, "char");
            drawLine('-');
            programm[sem_index][dis_index] = name;

            fstream programm_file;
            programm_file.open(programm_file_name, fstream::out);
            programm_file.close();
            programm_file.open(programm_file_name, fstream::in | fstream::out | fstream::app);
            if (!programm_file.is_open())
            {
                drawLine('-');
                setInCenter("Ошибка открытия файла!");
                drawLine('-');
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                        programm_file << programm[i][j] << "\n";
                }
            }
            programm_file.close();
            break;
        }
        case '3': {
            drawLine('-');
            drawLine('|', "Выберите семестр, который хотите удалить, от 1 до 9:");
            drawLine('-');
            char* Action = new char;
            *Action = menuIntInput(1, 9, "programm_choose");
            int index = atoi(Action) - 1;
            delete[] programm[index];

            fstream programm_file;
            programm_file.open(programm_file_name, fstream::out);
            programm_file.close();
            programm_file.open(programm_file_name, fstream::in | fstream::out | fstream::app);
            if (!programm_file.is_open())
            {
                drawLine('-');
                setInCenter("Ошибка открытия файла!");
                drawLine('-');
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                        programm_file << programm[i][j];
                }
            }
            programm_file.close();
            break;
        }
        case '4': {

            system("cls");
            return;
        }
        }
        system("cls");
    }
}
void Student_menu(ClassList* list, std::string** programm, std::string file_name, std::string programm_file_name)
{
    char Action;
    while (true)
    {
        system("cls");
        printStudentMenu();
        Action = menuIntInput(1, 8, "student");
        switch (Action)
        {
        case '1': {
            system("cls");
            drawLine('-');
            setInCenter("---<=== ПОЛНЫЙ СПИСОК СТУДЕНТОВ ===>---");
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
            Student* current = new Student;
            system("cls");
            drawLine('-');
            drawLine('|', "Введите номер зачётной книжки");
            id = ConsoleInput(10);
            drawLine('-');
            system("cls");
            *current = *(list->getItem(id));
            current->printInfo();
            drawLine('-');
            drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
            drawLine('-');
            _getche();
            delete current;
            break;
        }
        case '3': {
            Student* st = new Student;
            string value;
            drawLine('-');
            drawLine('|', "Фамилия: ");
            value = ConsoleInput(20, "char");
            drawLine('-');
            st->surname = value;
            drawLine('|', "Имя: ");
            value = ConsoleInput(20, "char");
            drawLine('-');
            st->name = value;
            drawLine('|', "Отчество: ");
            value = ConsoleInput(20, "char");
            drawLine('-');
            st->midname = value;
            drawLine('|', "Институт: ");
            value = ConsoleInput(20, "char");
            drawLine('-');
            st->institute = value;
            drawLine('|', "Подразделение: ");
            value = ConsoleInput(40, "char");
            drawLine('-');
            st->department = value;
            drawLine('|', "Группа: ");
            value = ConsoleInput(10);
            drawLine('-');
            st->group = value;
            drawLine('|', "Номер зачётной книжки: ");
            value = ConsoleInput(10, "num");
            drawLine('-');
            st->id = value;
            do {
                drawLine('|', "Дата рождения (ДД.ММ.ГГГГ): ");
                value = ConsoleInput(10);
            } while (!DateCheck(value));
            drawLine('-');
            st->birthday = value;
            drawLine('|', "Год поступления: ");
            value = ConsoleInput(4, "num");
            drawLine('-');
            st->enteranceYear = value;
            drawLine('|', "Пол: ");
            value = ConsoleInput(7, "char");
            drawLine('-');
            st->sex = value;

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
            break;
        }
        case '5': {
            string id;
            system("cls");
            drawLine('-');
            drawLine('|', "Введите номер зачётной книжки");
            id = ConsoleInput(10);
            drawLine('-');

            Student* st = new Student;
            *st = *list->getItem(id);
            int st_index = list->getIndex(id);
            for (int i = 0; i < 9; i++) {
                drawLine('-');
                string tmp = to_string(i + 1) + " Семестр";
                drawLine('|', tmp.c_str());
                drawLine('-');
                for (int j = 0; j < 9; j++) {
                    string mark;
                    if (st->examsData[i][j].mark == '0') { mark = "Незачёт"; }
                    if (st->examsData[i][j].mark == '1') { mark = "Зачёт"; }
                    if (st->examsData[i][j].mark == '2') { mark = "Неудовлетворительно"; }
                    if (st->examsData[i][j].mark == '3') { mark = "Удовлетворительно"; }
                    if (st->examsData[i][j].mark == '4') { mark = "Хорошо"; }
                    if (st->examsData[i][j].mark == '5') { mark = "Отлично"; }
                    string tmpout = to_string(j + 1) + " " + programm[i][j] + " | Оценка: " + mark;
                    drawLine('|', tmpout.c_str());
                }
            }

            drawLine('-');
            drawLine('|', "Нажмите 0, если хотите вернуться, или выберите нужный семестр от 1 до 9:");
            drawLine('-');
            char* Action = new char;
            *Action = menuIntInput(0, 9, "programm_choose");
            if (*Action == '0')
            {
                delete Action;
                delete st;
                system("cls");
                break;
            }
            else
            {
                int sem_index = atoi(Action) - 1;
                system("cls");
                drawLine('-');
                for (int i = 0; i < 9; i++)
                {
                    string mark;
                    if (st->examsData[sem_index][i].mark == '0') { mark = "Незачёт"; }
                    if (st->examsData[sem_index][i].mark == '1') { mark = "Зачёт"; }
                    if (st->examsData[sem_index][i].mark == '2') { mark = "Неудовлетворительно"; }
                    if (st->examsData[sem_index][i].mark == '3') { mark = "Удовлетворительно"; }
                    if (st->examsData[sem_index][i].mark == '4') { mark = "Хорошо"; }
                    if (st->examsData[sem_index][i].mark == '5') { mark = "Отлично"; }
                    string item = to_string(i + 1) + ". " + programm[sem_index][i] + " | Оценка: " + mark;
                    drawLine('|', item.c_str());
                }
                drawLine('-');
                drawLine('|', "Выберите учебную дисциплину, по которой хотите добавить оценку, от 1 до 9:");
                drawLine('-');
                char* choose = new char;
                *choose = menuIntInput(1, 9, "discipline_choose");
                int dis_index = atoi(choose) - 1;
                drawLine('-');
                drawLine('|', "Введите оценку от 0 до 5");
                drawLine('|', "(0 - незачёт, 1 - зачёт, 2 - неуд, 3 - удовл, 4 - хорошо, 5 - отлично)");
                drawLine('-');
                char mark = menuIntInput(1, 5, "mark");
                st->examsData[sem_index][dis_index].mark = mark;
                list->editItem(st_index, *st);
                drawLine('-');
            }
            delete Action;
            delete st;
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
            st = list->getItem(id);
            int index = list->getIndex(id);
            st->editData();
            list->editItem(index, *st);
            delete st;
            break;
        }
        case '7': {
            ClassList* sort_1 = new ClassList;
            ClassList* sort_2 = new ClassList;

            for (int i = 0; i < list->getCount(); i++)
            {
                Student tmp_st = *list->getItem(i);
                if (-64 <= tmp_st.surname[0] && tmp_st.surname[0] <= -49)
                {
                    sort_1->addItem(tmp_st);
                }
                else
                {
                    sort_2->addItem(tmp_st);
                }
            }

            float *marks_1 = new float[sort_1->getCount()];
            for (int i = 0; i < sort_1->getCount(); i++)
            {
                int summ = 0;
                int mark_count = 0;
                float average_mark = 0;
                for (int row = 0; row < 9; row++)
                {
                    for (int col = 0; col < 9; col++)
                    {
                        Student st = *sort_1->getItem(i);
                        if (st.examsData[row][col].mark != '0' && st.examsData[row][col].mark != '1')
                        {
                            mark_count++;
                            char* mark = new char;
                            *mark = st.examsData[row][col].mark;
                            summ += atoi(mark);
                        }
                    }
                }
                average_mark = 1.0 * summ / mark_count;
                marks_1[i] = average_mark;
            }
            for (int i = 0; i < sort_1->getCount() - 1; i++)
            {
                for (int j = 0; j < sort_1->getCount() - 1 - i; j++)
                {
                    Student tmp_st_1 = *sort_1->getItem(j);
                    Student tmp_st_2 = *sort_1->getItem(j + 1);
                    Student tmp_st;
                    float tmp;
                    if (marks_1[j] < marks_1[j + 1])
                    {
                        tmp_st = tmp_st_1;
                        sort_1->editItem(j, tmp_st_2);
                        sort_1->editItem(j + 1, tmp_st);
                        tmp = marks_1[j];
                        marks_1[j] = marks_1[j + 1];
                        marks_1[j + 1] = tmp;
                    }
                }
            }


            float* marks_2 = new float[sort_2->getCount()];
            for (int i = 0; i < sort_2->getCount(); i++)
            {
                int summ = 0;
                int mark_count = 0;
                float average_mark = 0;
                for (int row = 0; row < 9; row++)
                {
                    for (int col = 0; col < 9; col++)
                    {
                        Student st = *sort_2->getItem(i);
                        if (st.examsData[row][col].mark != '0' && st.examsData[row][col].mark != '1')
                        {
                            mark_count++;
                            char* mark = new char;
                            *mark = st.examsData[row][col].mark;
                            summ += atoi(mark);
                        }
                    }
                }
                average_mark = 1.0 * summ / mark_count;
                marks_2[i] = average_mark;
            }
            for (int i = 0; i < sort_2->getCount() - 1; i++)
            {
                for (int j = 0; j < sort_2->getCount() - 1 - i; j++)
                {
                    Student tmp_st_1 = *sort_2->getItem(j);
                    Student tmp_st_2 = *sort_2->getItem(j + 1);
                    Student tmp_st;
                    float tmp;
                    if (marks_2[j] < marks_2[j + 1])
                    {
                        tmp_st = tmp_st_1;
                        sort_2->editItem(j, tmp_st_2);
                        sort_2->editItem(j + 1, tmp_st);
                        tmp = marks_2[j];
                        marks_2[j] = marks_2[j + 1];
                        marks_2[j + 1] = tmp;
                    }
                }
            }

            system("cls");
            drawLine('-');
            drawLine('|', "Студенты от А до П:");
            drawLine('-');
            for (int i = 0; i < sort_1->getCount(); i++)
            {
                Student st = *sort_1->getItem(i);
                string out = to_string(i + 1) + ". " + st.surname + "  " + st.name + "  " + st.midname + "  " + st.id + "  Средняя оценка: " + to_string(marks_1[i]);
                drawLine('|', out.c_str());
            }
            drawLine('-');
            drawLine('|', "Студенты от Р до Я:");
            drawLine('-');
            for (int i = 0; i < sort_2->getCount(); i++)
            {
                Student st = *sort_2->getItem(i);
                string out = to_string(i + 1) + ". " + st.surname + "  " + st.name + "  " + st.midname + "  " + st.id + "  Средняя оценка: " + to_string(marks_2[i]);
                drawLine('|', out.c_str());
            }
            drawLine('-');
            drawLine('-');
            drawLine('|', "(Нажмите любую клавишу, чтобы вернуться...)");
            drawLine('-');
            _getche();
            break;
        }
        case '8': {
            system("cls");
            return;
        }
        }
        system("cls");
    }
}
void Main_menu(ClassList *list, string** programm, std::string file_name, std::string programm_file_name)
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
            Student_menu(list, programm, file_name, programm_file_name);
            break;
        }
        case '2': {
            Program_menu(programm, programm_file_name);
            break;
        }
        case '3': {
            system("cls");
            drawLine('-');
            drawLine('|', "Вы хотите сохранить внесённые изменения? (0 - нет, 1 - да)");
            drawLine('-');
            char Action;
            Action = menuIntInput(0, 1);
            switch (Action) {
            case '0':{
                system("cls");
                drawLine('-');
                setInCenter("---<=== ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ ===>---");
                drawLine('-');
                exit(0);
                }
            case '1': {
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
                    for (int i = 0; i < list->getCount(); i++)
                    {
                        Student value = *(list->getItem(i));
                        string marks = "";
                        for (int i = 0; i < 9; i++) {
                            for (int j = 0; j < 9; j++) {
                                marks += value.examsData[i][j].mark;
                            }
                        }
                        file << value << endl;
                        file << marks;
                    }
                }
                system("cls");
                drawLine('-');
                setInCenter("ДАННЫЕ УСПЕШНО СОХРАНЕНЫ");
                drawLine('-');
                setInCenter("---<=== ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ ===>---");
                drawLine('-');
                exit(0);
            }
            }
        }
        }
    }
    return;
}

ostream& operator<<(ostream& os, Student& st)
{
    os << endl << st.get(1) << " " << st.get(2) << " " << st.get(3) << " " << st.get(4) << " " << st.get(5) << " " << st.get(6) << " " << st.get(7) << " " << st.get(8) << " " << st.get(9) << " " << st.get(10);
    return os;
}
istream& operator>>(istream& is, Student& st)
{
    is >> st.surname >> st.name >> st.midname >> st.institute >> st.department >> st.group >> st.id >> st.birthday >> st.enteranceYear >> st.sex;
    return is;
}

ifstream& operator>>(ifstream& is, string& str)
{
    is >> str;
    return is;
}
ofstream& operator<<(ofstream& os, string& str)
{
    os << endl << str;
    return os;
}
