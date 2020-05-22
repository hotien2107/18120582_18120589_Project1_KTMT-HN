#include "qint.h"

int main()
{
	unsigned int test[4];

	for (int i = 0; i < 4; i++)
	{
		test[i] = 12407443;
	}
	for (int i = 0; i < 4; i++)
	{
		cout << test[i] << '.';
	}
	cout << endl;
	QInt qint(test);


	string k = qint.QIntToBin();
	cout << k;
	cout << endl;

	QInt qint1 = qint;
	qint1.XuatData();
	cout << endl;
	string h = qint.BinToDec(k);
	cout << h;
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}
