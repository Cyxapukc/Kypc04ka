#include <iostream>
#include "Menu_Tools.h"
using namespace std;

int length(const char str[])
{
    int len = 0;
    for (; str[len] != '\0'; len++) {}
    return len;
}
void drawLine(char ch, const char str[], const char data[])
{
    if (ch == '-') {
        cout << "+";
        for (int i = 0; i < 78; i++)
            cout << "-";
        cout << "+";
        return;
    }
    if (str != "0" && data == "0") {
        cout << "|" << " " << str;
        for (int i = 0; i < 77 - length(str); i++)
            cout << " ";
        cout << "|" << endl;
        return;
    }
    if (ch == '|' && str == "0") {
        cout << "|";
        for (int i = 0; i < 78; i++)
            cout << " ";
        cout << "|";
        return;
    }
    if (data != "0") {
        cout << '|' << " " << str << data;
        for (int i = 0; i < 77 - (length(str) + length(data)); i++)
            cout << " ";
        cout << "|" << endl;
        return;
    }
}
void setInCenter(const char string[])
{
    int len = length(string);
    cout << '|';
    for (int i = 0; i < (78 - len) / 2; i++)
    {
        cout << " ";
    }
    cout << string;
    for (int i = 0; i < (78 - len) / 2; i++)
    {
        cout << " ";
    }
    if (len % 2) { cout << " "; }
    cout << '|';
}

void printMainMenu()
{
    drawLine('-');
    setInCenter("---<=== ГЛАВНОЕ МЕНЮ ===>---");
    drawLine('-');
    drawLine('|', "Выберите действие:");
    drawLine('-');
    drawLine('|', "1. Список студентов");
    drawLine('|', "2. Учебные планы");
    drawLine('|', "3. Выход из программы");
    drawLine('-');
}
void printStudentMenu()
{
    setInCenter("---<=== МЕНЮ ПРОСМОТРА И РЕДАКТИРОВАНИЯ СПИСКА СТУДЕНТОВ ===>---");
    drawLine('-');
    drawLine('|', "Выберите действие:");
    drawLine('-');
    drawLine('|', "1. Полный список студентов");
    drawLine('|', "2. Подробные данные о студенте");
    drawLine('|', "3. Добавить студента");
    drawLine('|', "4. Удалить студента");
    drawLine('|', "5. Изменить оценки студента");
    drawLine('|', "6. Изменить личные данные студента");
    drawLine('|', "7. Разбиение и сортировка");
    drawLine('|', "8. Назад");
    drawLine('-');
}
void printProgramMenu()
{
    drawLine('-');
    setInCenter("---<=== МЕНЮ ПРОСМОТРА И РЕДАКТИРОВАНИЯ УЧЕБНЫХ ПЛАНОВ ===>---");
    drawLine('-');
    drawLine('|', "Выберите действие:");
    drawLine('-');
    drawLine('|', "1. Просмотреть учебные планы");
    drawLine('|', "2. Добавить учебный план");
    drawLine('|', "3. Удалить учебный план");
    drawLine('|', "4. Назад");
    drawLine('-');
}
void printIdMenu()
{
    drawLine('-');
    setInCenter("---<=== МЕНЮ РЕДАКТИРОВАНИЯ СТУДЕНТА ===>---");
    drawLine('-');
    drawLine('|', "Выберите действие:");
    drawLine('-');
    drawLine('|', "1. Изменить ФИО");
    drawLine('|', "2. Изменить институт");
    drawLine('|', "3. Изменить подразделение");
    drawLine('|', "4. Изменить группу");
    drawLine('|', "5. Изменить личный номер");
    drawLine('|', "6. Изменить дату рождения");
    drawLine('|', "7. Изменить дату поступления");
    drawLine('|', "8. Изменить оценки");
    drawLine('|', "9. Назад");
    drawLine('-');
}
