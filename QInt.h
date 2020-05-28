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
//Ham chuyen Qint sang Bin
	string QIntToBin();
//Ham chuyen Bin thanh dang Qint de luu tru
	QInt BinToQInt(const string& str);
//Ham chuyen Bin sang Dec
	static string BinToDec(const string& str);
//Ham chuyen Dec sang Bin
	static string DecToBin(const string& str);
//Ham chuyen Bin sang Hex
	static string BinToHex(const string& str);
//Ham chuyen Hex sang Bin
	static string HexToBin(const string& str);
//Ham chuyen Dec sang Hex
	static string DecToHex(const string& str);
//Ham chuyen Hex sang Dec
	static string HexToDec(const string& str);

public:

//Ham dich trai lpgic
	string SHL(const string& bin, int x);
//Ham dich phai so hoc
	string SAR(const string& bin, int x);
//Ham xoay trai cho so 128 bit
	string ROL(const string& bin);
//Ham xoay phai cho so 128 bit
	string ROR(const string& bin);
//Toan tu &
	QInt operator&(const QInt& str);
//Toan tu |
	QInt operator|(const QInt& str);
//Toan tu ^
	QInt operator^(const QInt& str);
//Toan tu ~
	QInt& operator~();
//Toan tu  gan =
	QInt& operator=(const QInt& qint);

public:
//Ham cong hai so Bin
	static string addBin(const string& str1, const string& str2);
//Ham tru hai so Bin
	static string subBin(const string& str1, const string& str2);
//Ham nhan hai so Bin
	static string MulBin(const string& str1, const string& str2);
//Ham chia hai so Bin
//Chi co so du khi 2 so deu lon hon 0 va so dau lon hon so thu hai
	static string DivBin(const string& str1, const string& str2, string& surplus);

	
public:
//Ham tinh 2^n
	static string Two_Pow_n(int n);
//Ham cong 2 so nguyen
	static string Add(string str1, string str2);
//Ham kiem tra so nguyen dau co nho hon so nguyen sau hay ko
	static bool isSmaller(string str1, string str2);
//Ham tru hai so nguyen
	static string Subtract(string str1, string str2);
//Ham chia mot so nguyen cho 2
	static string DivideTwo(string number);
//Ham chuyen 1 so Bin ve dang bu 2 
	static string TwoComplement(const string& str);
//Ham xoa cac so 0 phia truoc mot so Bin
	static string StandarBit(const string& str);
//Ham them cac so 0 phia truoc mot so Bin sao cho du 128 so
	static string FullBit(const string& str);
//Ham kiem tra 1 so Bin co bi tran hay khong
	static bool OverFlowBin(const string& Bin);
//Ham chon ra bit trai nhat cua mot so Bin
	static char MSB(const string& Bin);
//Ham chon ra bit trai nhat cua so lon hon trong 2 so Bin
	static char CheckMSB(string str1, string str2);
//Ham cong 2 bit
	static char AddBit(const char& bit1, const char& bit2, char& var_memory);
};
