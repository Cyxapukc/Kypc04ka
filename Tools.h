#pragma once
#include <iostream>
using namespace std;

bool IsNum(char ch);
char menuIntInput(int first, int end, const char fl[] = "0");
bool DateCheck(string date);
string ConsoleInput(const int len, const char tag[] = "all");
string to_string(const int& x);
string to_string(const float& x);