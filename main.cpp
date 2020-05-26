#include "QInt.h"

string SAR11(const string& bin)
{
	string str = bin;

	str.pop_back();
	str = str[0] + str;

	return str;
}

int main()
{
	uint32_t test[4];

	for (int i = 0; i < 4; i++)
	{
		test[i] = 10;
	}
	uint32_t test1[4];

	for (int i = 0; i < 4; i++)
	{
		test1[i] = 11;
	}
	QInt qint(test);

	string k = qint.QIntToBin();
	cout << "Chuoi nhi nhap vao:\n" << k;
	cout << endl;
	cout << endl;

	string h = qint.BinToDec(k);
	cout << "Chuyen chuoi nhi phan thanh thap phan:\n" << h;
	cout << endl;
	cout << endl;

	string h1 = qint.DecToBin(h);
	cout << "Chuyen chuoi thap phan thanh nhi phan:\n"  << h1;
	cout << endl;
	cout << endl;

	string l = qint.BinToHex(k);
	cout << "Chuyen chuoi nhi phan thanh thap luc phan:\n" << l;
	cout << endl;
	cout << endl;

	string l1 = qint.HexToBin(l);
	cout << "Chuyen chuoi thap luc phan thanh nhi phan:\n" << l1;
	cout << endl;
	cout << endl;

	string p = qint.HexToDec(l);
	cout << "Chuyen chuoi thap luc phan thanh thap phan:\n" << p;
	cout << endl;
	cout << endl;

	string p1 = qint.DecToHex(p);
	cout << "Chuyen chuoi thap phan thanh thap luc phan:\n" << p1;
	cout << endl;
	cout << endl;

	string sar = qint.SAR(k, 5);
	cout << "Dich phai so hoc 5 don vi:\n" << sar;
	cout << endl;
	cout << endl;

	string shl = qint.SHL(k, 5);
	cout << "Dich trai logic 5 don vi:\n" << shl;
	cout << endl;
	cout << endl;

	string a = "-1234";
	string a1 = "1234";
	string b = "-56789";
	string b1 = "5678901";

	a = QInt::DecToBin(a);
	a1 = QInt::DecToBin(a1);
	b = QInt::DecToBin(b);
	b1 = QInt::DecToBin(b1);

	a = "0000000000000" + a;
	string add = qint.addBin(b1, a);
	cout << QInt::BinToDec(b1);
	cout << " + ";
	cout << QInt::BinToDec(a) << " = ";
	add = qint.BinToDec(add);
	cout << add;
	cout << endl;
	cout << endl;

	
	string sub = qint.subBin(b1, a);
	cout << QInt::BinToDec(b1);
	cout << " - ";
	cout << QInt::BinToDec(a) << " = ";
	sub = qint.BinToDec(sub);
	cout << sub;
	cout << endl;
	cout << endl;

	string mul = qint.MulBin(b1, a);
	cout << QInt::BinToDec(b1);
	cout << " * ";
	cout << QInt::BinToDec(a) << " = ";
	mul = qint.BinToDec(mul);
	cout << mul;

	cout << endl;
	cout << endl;

	string surplus;
	string div = QInt::DivBin(b1, a, surplus);
	cout << QInt::BinToDec(b1) ;
	cout << " / ";
	cout << QInt::BinToDec(a) << " = ";
	div = qint.BinToDec(div);
	surplus = QInt::BinToDec(surplus);
	cout << div;

	cout << endl;
	cout << endl;

	cout << endl;
	cout << endl;

	qint.BinToQInt(k);
	cout << "Du lieu luu duoi dang block 4:\n";
	qint.PrintData();
	cout << endl;
	cout << endl;

	


	cout << endl;
	cout << endl;


	cout << endl;
	cout << endl;
	
	system("pause");
	return 0;
}
