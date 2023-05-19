#pragma once
#include <iostream>
#include "ClassStudent.h"

struct  node
{
    Student data;
    struct node* next;
};

class ClassList
{
private:
    struct node* myHead;
    int countItem = 0;

public:
    ClassList();
    ~ClassList();
    void addItem(Student data);
    void insertItem(int index, Student data); 
    void push_back(Student data);
    void editItem(int index, Student data);
    int getIndex(string id);
    void deleteItem(int index);
    int getCount();
    Student getItem(string id);
    Student getItem(int index);
    void printItems();
};