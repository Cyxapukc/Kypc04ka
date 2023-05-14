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
    setInCenter("---<=== ������� ���� ===>---");
    drawLine('-');
    drawLine('|', "�������� ��������:");
    drawLine('-');
    drawLine('|', "1. ������ ���������");
    drawLine('|', "2. ������� �����");
    drawLine('|', "3. ����� �� ���������");
    drawLine('-');
}
void printStudentMenu()
{
    setInCenter("---<=== ���� ��������� � �������������� ������ ��������� ===>---");
    drawLine('-');
    drawLine('|', "�������� ��������:");
    drawLine('-');
    drawLine('|', "1. ������ ������ ���������");
    drawLine('|', "2. ��������� ������ � ��������");
    drawLine('|', "3. �������� ��������");
    drawLine('|', "4. ������� ��������");
    drawLine('|', "5. �������� ������ ��������");
    drawLine('|', "6. �������� ������ ������ ��������");
    drawLine('|', "7. ��������� � ����������");
    drawLine('|', "8. �����");
    drawLine('-');
}
void printProgramMenu()
{
    drawLine('-');
    setInCenter("---<=== ���� ��������� � �������������� ������� ������ ===>---");
    drawLine('-');
    drawLine('|', "�������� ��������:");
    drawLine('-');
    drawLine('|', "1. ����������� ������� �����");
    drawLine('|', "2. �������� ������� ����");
    drawLine('|', "3. ������� ������� ����");
    drawLine('|', "4. �����");
    drawLine('-');
}
void printIdMenu()
{
    drawLine('-');
    setInCenter("---<=== ���� �������������� �������� ===>---");
    drawLine('-');
    drawLine('|', "�������� ��������:");
    drawLine('-');
    drawLine('|', "1. �������� ���");
    drawLine('|', "2. �������� ��������");
    drawLine('|', "3. �������� �������������");
    drawLine('|', "4. �������� ������");
    drawLine('|', "5. �������� ������ �����");
    drawLine('|', "6. �������� ���� ��������");
    drawLine('|', "7. �������� ���� �����������");
    drawLine('|', "8. �������� ������");
    drawLine('|', "9. �����");
    drawLine('-');
}
