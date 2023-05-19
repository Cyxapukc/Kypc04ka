#include "Tools.h"
#include "ClassStudent.h"
#include "Menu_Tools.h"
#include <conio.h>
#include <iostream>
using namespace std;

bool IsNum(char ch)
{
    if ((47 < (int)(ch) && (int)(ch) < 58)) { return false; }
    return true;
}
char menuIntInput(int first, int end, const char fl[])
{
    int count = 0;
    drawLine('|', "������� ������ ����� � ������� ����� �������");
    cout << "| �����: ";
    char ch = '0';
    ch = _getche();
    for (int i = 0; i < 69; i++) { cout << " "; } cout << "|";
    drawLine('-');
    _getch();
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
            count = 0;
        }
        cout << "|" << " ��������� �������� ������: " << ch;
        for (int i = 0; i < 48; i++) { cout << " "; } cout << "|";
        if (IsNum(ch))
        {
            cout << "| ������, ��������� ������ " << ch << " �� �������� ������, ������� ����� � ���������[" << first << ";" << end << "]|";
            drawLine('-');
            drawLine('|', "������� ������ ����� � ������� ����� �������");
            cout << "| �����: ";
            ch = _getche();
            for (int i = 0; i < 69; i++) { cout << " "; }
            cout << "|";
            drawLine('-');
            _getch();
        }
        else
        {
            cout << "| ������, ����� �� ������ � �������� �������� [" << first << ";" << end << "], ���������� ��� ���!       |" << endl;
            drawLine('|', "������� ������ ����� � ������� ����� �������");
            cout << "| �����: ";
            ch = _getche();
            for (int i = 0; i < 69; i++) { cout << " "; }
            cout << "|";
            drawLine('-');
            _getch();
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
            if ((ch >= 48 && ch <= 57) || (ch >= -64 && ch <= -1) || (ch >= 33 && ch <= 47) || (ch == 200) || (ch == 216))
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
        for (int i = 0; i < 68 - data.length(); i++) { cout << " "; }
        cout << "|" << endl;
        return data;
    }
    if (tag == "char")
    {
        data = "";
        cout << "| ���� --> ";
        while (ch != 13) {
            ch = _getche();
            if (ch == 8) { if (data.length() > 0) data.pop_back(); }
            if ((ch >= -64 && ch <= -1) || (ch == 200) || (ch == 216))
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
        for (int i = 0; i < 68 - data.length(); i++) { cout << " "; }
        cout << "|" << endl;
        return data;
    }
    if (tag == "num")
    {
        data = "";
        cout << "| ���� --> ";
        while (ch != 13) {
            ch = _getche();
            if (ch == 8) { if (data.length() > 0) data.pop_back(); }
            if (ch >= 48 && ch <= 57 || (ch >= 33 && ch <= 47))
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
        for (int i = 0; i < 68 - data.length(); i++) { cout << " "; }
        cout << "|";
        return data;
    }
}
int countRecords(string filename) {
    FILE* File;
    fopen_s(&File, filename.c_str(), "r");
    fseek(File, 0L, SEEK_END);
    int size = ftell(File);
    fclose(File);
    return size / sizeof(Student);
}
