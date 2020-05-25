#pragma once

#define MAX_SIZE_BLOCK 32
#define NUM_BLOCK 4
#define MAX_SIZE 128

#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>


using namespace std;

class QInt
{
private:

	uint32_t data[4];

public:

	QInt();
	QInt(uint32_t Data[4]);
	~QInt();

public:

	void setData(uint32_t Data[4]);

public:

	void PrintData();
	void ReadData();

public:

	string QIntToBin();
	QInt BinToQInt(const string& str);
	static string BinToDec(const string& str);
	static string DecToBin(const string& str);
	static string BinToHex(const string& str);
	static string HexToBin(const string& str);
	static string DecToHex(const string& str);
	static string HexToDec(const string& str);

	string SHL(const string& bin, int x);
	string SAR(const string& bin, int x);
	string ROL(string bin);
	string ROR(string bin);
	QInt operator&(const QInt& str);
	QInt operator|(const QInt& str);
	QInt operator^(const QInt& str);
	QInt& operator~();

public:

	static string addBin(const string& str1, const string& str2);
	static string subBin(const string& str1, const string& str2);
	QInt& operator=(const QInt& qint);

	string& ROL();
	string& ROR();
	
public:
	static string Two_Pow_n(int n);
	static string Add(string str1, string str2);
	static bool isSmaller(string str1, string str2);
	static string Subtract(string str1, string str2);
	static string DivideTwo(string number);
	static string TwoComplement(const string& str);
	static string StandarString(const string& str);
	static bool OverFlowBin(const string& Bin);
	static char MSB(const string& Bin);
	static char CheckMSB(string str1, string str2);
	static char AddBit(const char& bit1, const char& bit2, char& var_memory);
};
