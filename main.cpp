#include "QInt.h"

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

	string add = qint.addBin("101101110111000011000110110100", "1001101011001001101001011010011010100110");
	cout << "Tong 2 so he nhi phan: \n";
	cout << "101101110111000011000110110100\n";
	cout << "+\n";
	cout << "1001101011001001101001011010011010100110\n";
	cout << "------------------------------------------------------\n";
	cout << add;
	cout << endl;
	cout << endl;

	string sub = qint.subBin("101101110111000011000110110100", "1001101011001001101001011010011010100110");
	cout << "Hieu 2 so he nhi phan: \n";
	cout << "               101101110111000011000110110100\n";
	cout << "-\n";
	cout << "1001101011001001101001011010011010100110\n";
	cout << "------------------------------------------------------\n";
	cout << sub;
	cout << endl;
	cout << endl;

	string u = qint.TwoComplement("1001101011001001101001011010011010100110");
	cout << u;
	cout << endl;
	cout << endl;


	qint.BinToQInt(k);
	cout << "Du lieu luu duoi dang block 4:\n";
	qint.PrintData();
	cout << endl;
	cout << endl;

	QInt qint1(test1);

	qint.BinToQInt(k);
	string Bin_qint1 = qint1.QIntToBin();
	qint1.BinToQInt(Bin_qint1);

	QInt qint2 = qint1 & qint;
	string AndBin = qint2.QIntToBin();


	string AndDec = qint.BinToDec(AndBin);

	cout << AndBin;

	cout << endl;
	cout << endl;

	
	system("pause");
	return 0;
}
