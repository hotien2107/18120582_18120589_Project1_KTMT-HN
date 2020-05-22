#pragma once

#define MAX_SIZE_BLOCK 32
#define NUM_BLOCK 4
#define MAX_SIZE 128

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>


using namespace std;

class QInt
{
private:

	unsigned int data[4];

public:

	QInt();
	QInt(unsigned int Data[4]);
	~QInt();

public:

	void setData(unsigned int Data[4]);

public:

	void XuatData();

public:

	string QIntToBin();
	QInt BinToQInt(const string& str);
	string BinToDec(const string& str);
	string DecToBin(const string& str);
	string BinToHex(const string& str);
	string HexToBin(const string& str);
	string DecToHex(const string& str);
	string HexToDec(const string& str);

	string operator<<(const string& str);
	string operator>>(const string& str);
	string operator&(const string& str);
	string operator|(const string& str);
	string operator^(const string& str);
	string& operator~();

public:

	string operator+(const string& str);
	string operator-(const string& str);
	string operator*(const string& str);
	string operator/(const string& str);
	QInt& operator=(const QInt& qint);

	string& ROL();
	string& ROR();
	
public:
	static string Two_Pow_n(int n);
	static string Add(string str1, string str2);
	static bool isSmaller(string str1, string str2);
	static string Subtract(string str1, string str2);
};
