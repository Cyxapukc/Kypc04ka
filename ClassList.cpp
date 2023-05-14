#include <iostream>
#include "ClassList.h"
using namespace std;

ClassList::ClassList()
{
    myHead = new struct node;
    countItem = 0;
}

ClassList::~ClassList()
{
    struct node* old = NULL;
    struct node* current = myHead;
    while (current != NULL) {
        old = current;
        current = current->next;
        delete old;
    }
}

void ClassList::addItem(Student data)
{
    struct node* newItem = new node();
    newItem->data = data;
    if (&countItem == 0)
        newItem->next = NULL;
    else
        newItem->next = myHead;
    myHead = newItem;
    countItem++;
}
void ClassList::insertItem(int index, Student data) {
    if (not (index >= 0 and index <= countItem and countItem >= 0))
        return;
    if (index == 0)
        addItem(data);
    else {
        struct node* current = myHead;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        struct node* newItem = new node();
        newItem->data = data;
        newItem->next = current->next;
        current->next = newItem;
        countItem++;
    }
}
void ClassList::push_back(Student data) {
    insertItem(countItem, data);
}
void ClassList::editItem(int index, Student data) {
    if (index >= 0 and index < countItem and countItem>0) {
        struct node* current = myHead;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
    }
    else {
        cout << endl << "Техническая ошибка отладки (недопустимый индекс листа)";
    }
}
int ClassList::getIndex(string id)
{
    int index = 0;
    Student data;
    struct node* current = myHead;
    for (; index < countItem; index++, current = current->next)
    {
        data = current->data;
        if (data.sn.id == id)
        {
            return index;
        }
    }
}
void ClassList::deleteItem(int index) {
    if (index >= 0 and index < countItem and countItem>0) {
        struct node* current = myHead;
        struct node* old;
        if (index == 0) {
            old = myHead;
            myHead = current->next;
            delete old;
            countItem--;
        }
        else {
            int i = 0;
            while (current) {
                if (i == index - 1) {
                    old = current->next->next;
                    delete current->next;
                    current->next = old;
                    countItem--;
                    break;
                }
                i++;
                current = current->next;
            }
        }
    }

}
int ClassList::getCount() {
    return countItem;
}
Student ClassList::getItem(string id)
{
    Student data;
    struct node* current = myHead;
    for (int i = 0; i < countItem; i++, current = current->next)
    {
        data = current->data;
        if (data.sn.id == id)
        {
            return data;
        }
    }
}
Student ClassList::getItem(int index)
{
    Student data;
    struct node* current = myHead;
    for (int i = 0; i < countItem; i++, current = current->next)
    {
        data = current->data;
        if (i == index)
        {
            return data;
        }
    }
}
void ClassList::printItems()
{
    int index = 0;
    struct node* current = myHead;
    while (current != NULL) {
        current->data.printShortInfo(index);
        current = current->next;
        index++;
    }
}
