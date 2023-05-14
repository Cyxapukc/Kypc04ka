#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "Menu.h"
#include "ClassList.h"
#include "ClassStudent.h"
#include "Menu_Tools.h"
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

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClassList list;
    fstream file;
    string file_name = "Student_base.txt";
    fstream tmp;
    string tmp_name = "tmp.txt";
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
            list.addItem(value);
        }
    }
    Main_menu(list, file_name, tmp_name);
    return 0;
}
