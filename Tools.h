#pragma once
#include <iostream>
using namespace std;

bool IsNum(char ch);
char menuIntInput(int first, int end, const char fl[]);
bool DateCheck(string date);
string ConsoleInput(const int len, const char tag[] = "all");
int countRecords(string filename);
