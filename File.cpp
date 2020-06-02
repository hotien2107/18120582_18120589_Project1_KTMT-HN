#include "File.h"
#include "QInt.h"


//Kiem tra chuoi co bao nhieu khoang trang
int Count(string temp)
{
	int count = 0;
	for (int i = 0; i < temp.length(); ++i)
		if (temp[i] == ' ')
			++count;
	return count;
}

//Xu ly khi co 3 doi so
string BT1(string a, string b, string c)
{
	c = QInt::StandarBit(c);

	if (a == "2")
	{
		if (b == "2" || b == "10" || b == "16")
		{
			if (b == "2")
				return c;


			if (b == "10")
			{
				return QInt::BinToDec(c);
			}
			if (b == "16")
				return QInt::BinToHex(c);
		}
		else
		{
			QInt q;
			q.BinToQInt(c);
			if (b == "~")
			{
				q = ~q;
				return(q.QIntToBin());
			}
			if (b == "rol")
			{
				return q.ROL(c);
			}
			if (b == "ror")
				return q.ROR(c);
		}
	}
	if (a == "16")
	{
		if (b == "2" || b == "10" || b == "16")
		{
			if (b == "16")
				return c;

			
			if (b == "10")
				return QInt::HexToDec(c);
			if (b == "2")
				return QInt::HexToBin(c);
		}
		else
		{
			string d = QInt::HexToBin(c);
			QInt q;
			q.BinToQInt(d);
			if (b == "~")
			{
				q = ~q;
				return q.BinToHex(q.QIntToBin());
			}
			if (b == "rol")
			{
				return q.BinToHex(q.ROL(d));
			}
			if (b == "ror")
				return q.BinToHex(q.ROR(d));
		
		}
	}
	if (a == "10")
	{
		if (b == "2" || b == "10" || b == "16")
		{
			if (b == "10")
				return c;
			
			if (b == "16")
			{
				return QInt::DecToHex(c);
			}
			if (b == "2")
				return QInt::DecToBin(c);
		}
		else
		{
			string d  = QInt::DecToBin(c);
			QInt q;
			q.BinToQInt(d);
			if (b == "~")
			{
				q = ~q;
				return q.BinToDec(q.QIntToBin());
			}
			if (b == "rol")
			{
				return q.BinToDec(q.ROL(d));
			}
			if (b == "ror")
				return q.BinToDec(q.ROR(d));
		}
	}
}

//Xu ly khi co 4 doi so
string BT2(string a, string b, string c, string d)
{
	if (a == "2")
	{

		QInt q;
		if (c == "+" || c == "-" || c == "*" || c == "/")
		{
			if (c == "+")
				return q.addBin(b, d);
			if (c == "-")
				return q.subBin(b, d);
			if (c == "*")
				return q.MulBin(b, d);
			if (c == "/")
			{
				return q.DivBin(b, d);
			}
		}
		else
		{
			QInt q1;
			q1.BinToQInt(b);
			if (c == "&" || c == "|" || c == "^")
			{
				QInt q2;
				q2.BinToQInt(d);
				if (c == "&")
				{
					q = q1 & q2;
					return q.QIntToBin();
				}
				if (c == "|")
				{
					q = q1 | q2;
					return q.QIntToBin();
				}
				if (c == "^")
				{
					q = q1 ^ q2;
					return q.QIntToBin();
				}
			}
			if (c == ">>" || c == "<<")
			{
				int n;
				n = stoi(d);
				if (c == ">>")
					return q.SAR(b, n);
				if (c == "<<")
					return q.SHL(b, n);
			}
		}
	}
	if (a == "10")
	{

		QInt q;
		b = QInt::DecToBin(b);
		
		if (c == "+" || c == "-" || c == "*" || c == "/")
		{
			d = QInt::DecToBin(d);
			if (c == "+")
				return q.BinToDec(q.addBin(b, d));
			if (c == "-")
				return q.BinToDec(q.subBin(b, d));
			if (c == "*")
			{
				return q.BinToDec(q.MulBin(b, d));
			}
			if (c == "/")
			{
				return q.BinToDec(q.DivBin(b, d));
			}
		}
		else
		{
			QInt q1;
			q1.BinToQInt(b);
			if (c == "&" || c == "|" || c == "^")
			{
				d = QInt::DecToBin(d);
				QInt q2 = q2.BinToQInt(d);
				if (c == "&")
				{
					q = q1 & q2;
					return q.BinToDec(q.QIntToBin());
				}
				if (c == "|")
				{
					q = q1 | q2;
					return q.BinToDec(q.QIntToBin());
				}
				if (c == "^")
				{
					q = q1 ^ q2;
					return q.BinToDec(q.QIntToBin());
				}
			}
			if (c == ">>" || c == "<<")
			{
				int n;
				n = stoi(d);
				if (c == ">>")
					return q.BinToDec(q.SAR(b, n));
				if (c == "<<")
					return q.BinToDec(q.SHL(b, n));
			}
		}
	}
	if (a == "16")
	{

		QInt q;
		b = QInt::HexToBin(b);

		if (c == "+" || c == "-" || c == "*" || c == "/")
		{
			d = QInt::HexToBin(d);
			if (c == "+")
				return q.BinToHex(q.addBin(b, d));
			if (c == "-")
				return q.BinToHex(q.subBin(b, d));
			if (c == "*")
				return q.BinToHex(q.MulBin(b, d));
			if (c == "/")
			{
				return q.BinToHex(q.DivBin(b, d));
			}
		}
		else
		{
			QInt q1;
			q1.BinToQInt(b);
			if (c == "&" || c == "|" || c == "^")
			{
				d = QInt::HexToBin(d);
				QInt q2;
				q2.BinToQInt(d);
				if (c == "&")
				{
					q = q1 & q2;
					return q.BinToHex(q.QIntToBin());
				}
				if (c == "|")
				{
					q = q1 | q2;
					return q.BinToHex(q.QIntToBin());
				}
				if (c == "^")
				{
					q = q1 ^ q2;
					return q.BinToHex(q.QIntToBin());
				}
			}
			if (c == ">>" || c == "<<")
			{
				int n;
				n = stoi(d);
				if (c == ">>")
					return q.BinToHex(q.SAR(b, n));
				if (c == "<<")
					return q.BinToHex(q.SHL(b, n));
			}
		}
	}
}

//Doc file, ghi file
void RWFile(string input, string output)
{
	//Mo file input
	ifstream infile(input, ios::in);
	//Mo file output
	ofstream outfile(output, ios::out);
	if (infile.fail())
	{
		cout << "The file does not exist! " << endl;
		cout << "Enter to continue! " << endl;
		system("pause");
		return;
		
	}
	string temp;
	int khtr;
	string k;

	while (!infile.eof())
	{
		if (getline(infile, temp))
		{
			if (temp == "")
				getline(infile, temp);
			else
			{
				khtr = Count(temp);
				//Thuc hien tach chuoi doi voi chuoi 2 khoang trang
				if (khtr == 2)
				{
					string s1, s2, s3;
					int index = 0, index1;
					index1 = temp.find_first_of(' ');
					s1 = temp.substr(index, index1 - index);
					index = index1 + 1;
					index1 = temp.find_first_of(' ', index);
					s2 = temp.substr(index, index1 - index);
					index = index1 + 1;
					index1 = temp.find_first_of(' ', index);
					s3 = temp.substr(index, index1 - index);

					k = BT1(s1, s2, s3);		//Goi den ham thuc thi phep tinh
					outfile << k << endl;		//Ghi ket qua vao file
				}

				else
				{
					//Thuc hien tach chuoi voi chuoi co 3 khoang trang
					if (khtr == 3)
					{
						string s1, s2, s3, s4;
						int index = 0, index1;
						index1 = temp.find_first_of(' ');
						s1 = temp.substr(index, index1 - index);
						index = index1 + 1;
						index1 = temp.find_first_of(' ', index);
						s2 = temp.substr(index, index1 - index);
						index = index1 + 1;
						index1 = temp.find_first_of(' ', index);
						s3 = temp.substr(index, index1 - index);
						index = index1 + 1;
						index1 = temp.find_first_of(' ', index);
						s4 = temp.substr(index, index1 - index);
						k = BT2(s1, s2, s3, s4);		//Goi den ham thuc thi phep tinh
						outfile << k << endl;		//Ghi ket qua vao file
					}
				}
			}
		}
	}
	//Dong file
	infile.close();
	outfile.close();
}

