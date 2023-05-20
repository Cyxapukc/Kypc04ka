#include "Tools.h"
#include "ClassStudent.h"
#include "Menu_Tools.h"
#include <conio.h>
#include <iostream>
#include <sstream>
using namespace std;

bool IsNum(char ch)
{
    if ((47 < (int)(ch) && (int)(ch) < 58)) { return false; }
    return true;
}
char menuIntInput(int first, int end, const char fl[])
{
    int count = 0;
    drawLine('|', "������� ������ �����");
    cout << "| �����: ";
    char ch = '0';
    ch = _getche();
    for (int i = 0; i < 69; i++) { cout << " "; } cout << "|";
    drawLine('-');
    _getch;
    while (!(47 + first < (int)(ch) && (int)(ch) < 58 - (9 - end)))
    {
        count++;
        if (count == 3)
        {
            system("cls");
            if (fl == "main") { printMainMenu(); }
            if (fl == "student") { printStudentMenu(); }
            if (fl == "program") { printProgramMenu(); }
            if (fl == "id") { printIdMenu(); }
            if (fl == "exit") {
                drawLine('-');
                drawLine('|', "�� ������ ��������� �������� ���������? (0 - ���, 1 - ��)");
                drawLine('-');
            }
            if (fl == "programm_choose") {
                drawLine('-');
                drawLine('|', "�������� ������ ������� �� 1 �� 9:");
                drawLine('-');
            }
            if (fl == "discipline_choose") {
                drawLine('-');
                drawLine('|', "�������� ������� ����������, ������� ������ ��������/��������, �� 0 �� 9:");
                drawLine('-');
            }
            if (fl == "mark") {
                drawLine('-');
                drawLine('|', "������� ������ �� 0 �� 5 (0 - �������, 1 - �����, 2 - ����, 3 - �����, 4 - ������, 5 - �������)");
                drawLine('-');
            }
            count = 0;
        }
        cout << "|" << " ��������� �������� ������: " << ch;
        for (int i = 0; i < 48; i++) { cout << " "; } cout << "|";
        if (IsNum(ch))
        {
            cout << "| ������, ��������� ������ " << ch << " �� �������� ������, ������� ����� � ���������[" << first << ";" << end << "]|";
            drawLine('-');
            drawLine('|', "������� ������ �����");
            cout << "| �����: ";
            ch = _getche();
            for (int i = 0; i < 69; i++) { cout << " "; }
            cout << "|";
            drawLine('-');
            _getch;
        }
        else
        {
            cout << "| ������, ����� �� ������ � �������� �������� [" << first << ";" << end << "], ���������� ��� ���!       |" << endl;
            drawLine('|', "������� ������ �����");
            cout << "| �����: ";
            ch = _getche();
            for (int i = 0; i < 69; i++) { cout << " "; }
            cout << "|";
            drawLine('-');
            _getch;
        }
    }
    return ch;
}
bool DateCheck(string date)
{
    if (not(date[2] == '.' && date[5] == '.')) { return false; }
    for (int i = 0; i < 2; i++) {
        if (not(47 < (int)(date[i]) && (int)(date[i]) < 58))
        {
            return false;
        }
    }
    for (int i = 3; i < 5; i++) {
        if (not(47 < (int)(date[i]) && (int)(date[i]) < 58))
        {
            return false;
        }
    }
    for (int i = 6; i < 10; i++) {
        if (not(47 < (int)(date[i]) && (int)(date[i]) < 58))
        {
            return false;
        }
    }

    int dd = atoi(date.substr(0, 2).c_str());
    int mm = atoi(date.substr(3, 2).c_str());
    int yyyy = atoi(date.substr(6, 4).c_str());
    if (not(dd >= 1 && dd <= 31))
    {
        return false;
    }
    if (not(mm >= 1 && mm <= 12))
    {
        return false;
    }
    if ((mm == 2 || mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31)
    {
        return false;
    }
    if (mm == 2 && dd == 29 && !((yyyy % 4 == 0 && yyyy % 100) || yyyy % 400 == 0))
    {
        return false;
    }
    return true;
}
string ConsoleInput(const int len, const char tag[])
{
    string data;
    drawLine('|', "(��� ����� ������������ ������� ����������� �� �����)");
    char ch = 0;
    if (tag == "all") {
        data = "";
        cout << "| ���� --> ";
        while (ch != 13) {
            ch = _getche();
            if (ch == 8) { if (data.length() > 0) data.pop_back(); }
            if ((ch >= 48 && ch <= 57) || (ch >= -64 && ch <= -1) || (ch >= 32 && ch <= 47) || (ch == 200) || (ch == 216))
            {
                data += ch;
                if (data.length() > len) {
                    for (int i = 0; i < 68 - len; i++) { cout << " "; }
                    cout << "|" << endl;
                    cout << endl;
                    drawLine('|', "�������� ����� �����, ��������� �������");
                    cout << "| ���� --> ";
                    data = "";
                }
            }
        }
        drawLine('|', "�� �����: ", data.c_str());
        return data;
    }
    if (tag == "char")
    {
        data = "";
        cout << "| ���� --> ";
        while (ch != 13) {
            ch = _getche();
            if (ch == 8) { if (data.length() > 0) data.pop_back(); }
            if ((ch >= -64 && ch <= -1) || (ch >= 32 && ch <= 47))
            {
                data += ch;
                if (data.length() > len) {
                    for (int i = 0; i < 68 - len; i++) { cout << " "; }
                    cout << "|";
                    cout << endl;
                    drawLine('|', "�������� ����� �����, ��������� �������");
                    cout << "| ���� --> ";
                    data = "";
                }
            }
        }
        drawLine('|', "�� �����: ", data.c_str());
        return data;
    }
    if (tag == "num")
    {
        data = "";
        cout << "| ���� --> ";
        while (ch != 13) {
            ch = _getche();
            if (ch == 8) { if (data.length() > 0) data.pop_back(); }
            if (ch >= 48 && ch <= 57 || (ch >= 32 && ch <= 47))
            {
                data += ch;
                if (data.length() > len) {
                    for (int i = 0; i < 68 - len; i++) { cout << " "; }
                    cout << "|";
                    drawLine('|', "�������� ����� �����, ��������� �������");
                    cout << "| ���� --> ";
                    data = "";
                }
            }
        }
        drawLine('|', "�� �����: ", data.c_str());
        return data;
    }
}
string to_string(const int &x)
{
    stringstream buf;
    buf << x;
    return buf.str();
}
string to_string(const float& x)
{
    stringstream buf;
    buf << x;
    return buf.str();
}
