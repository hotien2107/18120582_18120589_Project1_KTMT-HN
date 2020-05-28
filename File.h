#pragma once
#include "QInt.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Tach chuoi
//Tach chuoi 2 khoang trang
string Format1(string, string, string);
//Tach chuoi 3 khoang trang
string Format2(string, string, string, string);
//Doc file, ghi file
void RWFile(string, string);
//Kiem tra chuoi co bao nhieu khoang trang
int Count(string);
