﻿#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdio>
#include "Menu.h"
#include "ClassList.h"
#include "ClassStudent.h"
#include "Menu_Tools.h"
#include "Tools.h"

void Crypt()
{
    srand(time(NULL));
    char* pass = new char[64];
    for (int i = 0; i < 64; ++i) {
        switch (rand() % 3) {
        case 0:
            pass[i] = rand() % 10 + '0';
            break;
        case 1:
            pass[i] = rand() % 26 + 'A';
            break;
        case 2:
            pass[i] = rand() % 26 + 'a';
        }
    }
    string command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -salt -in Student_base.txt -out Student_base.txt.enc -pass pass:";
    command = command + pass;
    system(command.c_str());
    if (remove("Student_base.txt") != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }
    ofstream file;
    file.open("key.txt", ios::binary);
    file << pass;
    file.close();
    command = "OpenSSL\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
    system(command.c_str());
    if (remove("key.txt") != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }
}

void Decrypt()
{
    string command = "OpenSSL\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
    system(command.c_str());
    if (remove("key.txt.enc") != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }
    char* pass = new char[64];
    ifstream file;
    file.open("key.txt", ios::binary);
    file >> pass;
    file.close();
    if (remove("key.txt") != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }
    command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -d -in Student_base.txt.enc -out Student_base.txt -pass pass:";
    command = command + pass;
    system(command.c_str());
    if (remove("Student_base.txt.enc") != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Decrypt();
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
    file.close();
    programm_file.close();
    Main_menu(list, programm, file_name, programm_file_name);
    Crypt();
    return 0;
}
