#include "QInt.h"

QInt::QInt()
{
}
QInt::QInt(unsigned int Data[4])
{
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		this->data[i] = Data[i];
	}
}
QInt::~QInt()
{
}

void QInt::setData(unsigned int Data[4])
{
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		this->data[i] = Data[i];
	}
}

void QInt::XuatData()
{
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		cout << this->data[i] << '.';
	}
}

string QInt::QIntToBin()
{
	string str;
	for (int i = 3; i >= 0; i--)
	{
		int temp = this->data[i];
		for (int j = 0; temp > 0; j++)
		{
			char k = temp % 2;
			str.insert(str.begin(), k + '0');
			temp = temp / 2;
		}
	}
	return str;
}

QInt QInt::BinToQInt(const string& str)
{
	QInt qint;
	string str1 = str;
	//gan tung block bang 0
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		qint.data[i] = 0;
	}
	if (str.length() > 128)
		return 0;
	int i = 3, k = 0; //i la bien dem cho QInt, k la bien dem cho Bin
	while (str1.length() > 0)
	{
		if (i >= 0)
		{
			if (k < MAX_SIZE_BLOCK)
			{
				char temp = str1[str1.length() - 1];
				temp -= '0';
				qint.data[i] += (int)temp * pow(2, k);
				str1.pop_back();
				k++;
			}
			else
			{
				k = 0;
				i--;
			}
		}
	}
	return qint;
}

string QInt::Two_Pow_n(int n)
{
	string str;
	int i, j;
	int blen = n / 32 + 1;
	int dlen = n / 29 + 1;
	uint32_t* bin = new uint32_t[blen];
	uint32_t* dec = new uint32_t[dlen];
	uint64_t num;

	for (i = 0; i < blen; i++)
		bin[i] = 0;
	bin[n / 32] = (uint32_t)1 << (n % 32);

	for (j = 0; blen > 0; ) {
		for (num = 0, i = blen; i-- > 0;) {
			num = (num << 32) | bin[i];
			bin[i] = num / 1000000000;
			num = num % 1000000000;
		}
		dec[j++] = (uint32_t)num;
		while (blen > 0 && bin[blen - 1] == 0)
			blen--;
	}
	while (j > 0)
	{
		j--;
		stringstream ss;
		ss << dec[j];
		string temp = ss.str();
		for (int k = 0; k < temp.length(); k++)
		{
			str.push_back(temp[k]);
		}
	}
	return str;
}

string QInt::Add(string str1, string str2)
{
	int flat = 0;
	if (str1[0] == '-' && str2[0] == '-')
		flat = 1;
	
	if (str1[0] == '-' && str2[0] != '-')
	{
		str1.erase(0);
		return Subtract(str2, str1);
	}
	if (str1[0] != '-' && str2[0] == '-')
	{
		str2.erase(0);
		return Subtract(str1, str2);
	}
	if (str1.length() > str2.length())
		swap(str1, str2);

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{

		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		str.push_back(carry + '0');

	reverse(str.begin(), str.end());

	if (flat == 1)
		str.insert(str.begin(), '-');

	return str;
}

bool QInt::isSmaller(string str1, string str2)
{
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;

	for (int i = 0; i < n1; i++)
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;

	return false;
}

string QInt::Subtract(string str1, string str2)
{
	int flat = 0;
	if (isSmaller(str1, str2))
	{
		swap(str1, str2);
		flat = 1;
	}

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n2; i++)
	{
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}
	for (int i = n2; i < n1; i++)
	{
		int sub = ((str1[i] - '0') - carry);
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	reverse(str.begin(), str.end());
	if (flat == 1)
	{
		str.insert(str.begin(), '-');
	}

	return str;
}

string QInt::BinToDec(const string& str)
{
	string Dec = "";
	string str1 = str;
	int k = 0;
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '1')
		{
			Dec = Add(Dec, Two_Pow_n(k));
		}
		if (k == 127)
		{
			string temp = '-' + Two_Pow_n(k);
			Dec = Add(Dec, temp);
		}
		k++;
	}
	return Dec;
}

