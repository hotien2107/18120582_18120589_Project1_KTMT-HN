#include "QInt.h"

QInt::QInt()
{
}

QInt::QInt(uint32_t Data[4])
{
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		this->data[i] = Data[i];
	}
}

QInt::~QInt()
{
}

void QInt::setData(uint32_t Data[4])
{
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		this->data[i] = Data[i];
	}
}

void QInt::PrintData()
{
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		cout << this->data[i] << '.';
	}
}

char QInt::MSB(const string& Bin)
{
	if (Bin.length() < MAX_SIZE)
		return '0';
	return '1';
}

bool QInt::OverFlowBin(const string& Bin)
{
	string str = Bin;
	str = StandarBit(str);
	if (str.length() > MAX_SIZE)
		return false;
	return true;
}

string QInt::QIntToBin()
{
	string str;
	for (int i = 3; i >= 0; i--)
	{
		uint32_t temp = this->data[i];
		for (int j = 0; temp > 0; j++)
		{
			char k = temp % 2;
			str.insert(str.begin(), k + '0');
			temp = temp / 2;
		}
		while (str.length() % 32 != 0)
			str.insert(str.begin(), '0');
	}

	str = StandarBit(str);
	return str;
}

string QInt::StandarBit(const string& str)
{
	string str1 = str;
	if (str1[0] == '-')
	{
		str1.erase(0, 1);
		while (str1[0] == '0')
		{
			str1.erase(0, 1);
		}
		str1.insert(str1.begin(), '-');
	}
	else
	{
		while (str1[0] == '0')
		{
			str1.erase(0, 1);
		}
	}

	return str1;
}

string QInt::FullBit(const string& str)
{
	string bin = str;

	while (bin.length() < MAX_SIZE)
		bin = '0' + bin;

	return bin;
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
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		this->data[i] = qint.data[i];
	}
	return *this;
}

//Ham nhan mot so cho 2
int multiply(int res[], int res_size)
{

	// Initialize carry 
	int carry = 0;

	// One by one multiply n with 
	// individual digits of res[] 
	for (int i = 0; i < res_size; i++)
	{
		int prod = res[i] * 2 + carry;

		// Store last digit of 
		// 'prod' in res[] 
		res[i] = prod % 10;

		// Put rest in carry 
		carry = prod / 10;
	}

	// Put carry in res and 
	// increase result size 
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

string QInt::Two_Pow_n(int n)
{
	string pow;
	//printing value "1" for power = 0 
	if (n == 0)
	{
		pow.push_back('1');
		return pow;
	}


	int res[100000];
	int res_size = 0;
	int temp = 2;

	// Initialize result 
	while (temp != 0) {
		res[res_size++] = temp % 10;
		temp = temp / 10;
	}

	// Multiply x n times 
	// (x^n = x*x*x....n times) 
	for (int i = 2; i <= n; i++)
		res_size = multiply(res, res_size);

	for (int i = res_size - 1; i >= 0; i--)
	{
		char temp = (char)res[i] + '0';
		pow.push_back(temp);
	}
	return pow;
}

string QInt::Add(string str1, string str2)
{
	string str;

	if (str1[0] == '-' && str2[0] == '-')
	{
		str1.erase(str1.begin());
		str2.erase(str2.begin());

		if (str1.length() > str2.length())
			swap(str1, str2);

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

		str.insert(str.begin(), '-');
	}
	else if (str1[0] == '-' && str2[0] != '-')
	{
		str1.erase(str1.begin());
		return Subtract(str2, str1);
	}
	else if (str1[0] != '-' && str2[0] == '-')
	{
		str2.erase(str2.begin());
		return Subtract(str1, str2);
	}
	else 	if (str1[0] != '-' && str2[0] != '-')
	{
		if (str1.length() > str2.length())
			swap(str1, str2);

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
	}
	str = StandarBit(str);
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
	str = StandarBit(str);
	if (flat == 1)
	{
		str.insert(str.begin(), '-');
	}
	return str;
}

string QInt::BinToDec(const string& str)
{
	if (str == "0")
		return "0";
	string Dec;
	string str1 = str;
	int k = 0;
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (k == 127)
		{
			Dec = Subtract(Dec, Two_Pow_n(k));
			return Dec;
		}
		if (str1[i] == '1')
		{
			Dec = Add(Dec, Two_Pow_n(k));
		}
		k++;
	}
	return Dec;
}

string QInt::DivideTwo(string number)
{
	string ans;

	int idx = 0;
	int temp = number[idx] - '0';
	while (temp < 2)
		temp = temp * 10 + (number[++idx] - '0');

	while (number.size() > idx)
	{
		ans += (temp / 2) + '0';

		temp = (temp % 2) * 10 + number[++idx] - '0';
	}

	if (ans.length() == 0)
		return "0";

	return ans;
}

string QInt::TwoComplement(const string& str)
{
	string str1 = str;
	while (str1.length() < MAX_SIZE)
	{
		str1.insert(str1.begin(), '0');
	}
	int i = str1.length() - 1;
	int flat = 0;
	while (i >= 0)
	{
		if (flat == 0 && str1[i] == '1')
		{
			flat = 1;
			i--;
		}
		else if (flat == 1)
		{
			if (str1[i] == '1')
				str1[i] = '0';
			else
				str1[i] = '1';
			i--;
		}
		else
			i--;
	}

	str1 = StandarBit(str1);

	return str1;
}

string QInt::DecToBin(const string& str)
{
	string Bin;
	string str1 = str;

	str1 = StandarBit(str1);

	if (str1[0] != '-')
	{
		while (str1.length() > 0)
		{
			if (str1.length() == 1 && str1[0] == '1')
			{
				Bin.insert(Bin.begin(), '1');
				Bin = StandarBit(Bin);
				return Bin;
			}
			else
			{
				int temp = (int)str1[str1.length() - 1] - '0';
				if (temp % 2 == 1)
				{
					Bin.insert(Bin.begin(), '1');
					str1 = DivideTwo(str1);
				}
				else
				{
					Bin.insert(Bin.begin(), '0');
					str1 = DivideTwo(str1);
				}
			}
		}
	}
	else
	{
		str1.erase(str1.begin());

		while (str1.length() > 0)
		{
			if (str1.length() == 1 && str1[0] == '1')
			{
				Bin.insert(Bin.begin(), '1');
				Bin = TwoComplement(Bin);
				Bin = StandarBit(Bin);
				return Bin;
			}
			else
			{
				int temp = (int)str1[str1.length() - 1] - '0';
				if (temp % 2 == 1)
				{
					Bin.insert(Bin.begin(), '1');
					str1 = DivideTwo(str1);
				}
				else
				{
					Bin.insert(Bin.begin(), '0');
					str1 = DivideTwo(str1);
				}
			}
		}
	}
}

string QInt::BinToHex(const string& str)
{
	string Hex;
	string str1 = str;
	while (str1.length() % 4 != 0)
	{
		str1.insert(str1.begin(), '0');
	}

	while (str1.length() > 0)
	{
		string temp;
		for (int i = 0; i < 4; i++)
		{
			temp.insert(temp.begin(), str1[str1.length() - 1]);
			str1.pop_back();
		}

		if (temp == "0000")
			Hex.insert(Hex.begin(), '0');
		else if (temp == "0001")
			Hex.insert(Hex.begin(), '1');
		else if (temp == "0010")
			Hex.insert(Hex.begin(), '2');
		else if (temp == "0011")
			Hex.insert(Hex.begin(), '3');
		else if (temp == "0100")
			Hex.insert(Hex.begin(), '4');
		else if (temp == "0101")
			Hex.insert(Hex.begin(), '5');
		else if (temp == "0110")
			Hex.insert(Hex.begin(), '6');
		else if (temp == "0111")
			Hex.insert(Hex.begin(), '7');
		else if (temp == "1000")
			Hex.insert(Hex.begin(), '8');
		else if (temp == "1001")
			Hex.insert(Hex.begin(), '9');
		else if (temp == "1010")
			Hex.insert(Hex.begin(), 'A');
		else if (temp == "1011")
			Hex.insert(Hex.begin(), 'B');
		else if (temp == "1100")
			Hex.insert(Hex.begin(), 'C');
		else if (temp == "1101")
			Hex.insert(Hex.begin(), 'D');
		else if (temp == "1110")
			Hex.insert(Hex.begin(), 'E');
		else if (temp == "1111")
			Hex.insert(Hex.begin(), 'F');
	}
	return Hex;
}

string QInt::HexToBin(const string& str)
{
	string Bin;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
			Bin = Bin + "0000";
		else if (str[i] == '1')
			Bin = Bin + "0001";
		else if (str[i] == '2')
			Bin = Bin + "0010";
		else if (str[i] == '3')
			Bin = Bin + "0011";
		else if (str[i] == '4')
			Bin = Bin + "0100";
		else if (str[i] == '5')
			Bin = Bin + "0101";
		else if (str[i] == '6')
			Bin = Bin + "0110";
		else if (str[i] == '7')
			Bin = Bin + "0111";
		else if (str[i] == '8')
			Bin = Bin + "1000";
		else if (str[i] == '9')
			Bin = Bin + "1001";
		else if (str[i] == 'A')
			Bin = Bin + "1010";
		else if (str[i] == 'B')
			Bin = Bin + "1011";
		else if (str[i] == 'C')
			Bin = Bin + "1100";
		else if (str[i] == 'D')
			Bin = Bin + "1101";
		else if (str[i] == 'E')
			Bin = Bin + "1110";
		else if (str[i] == 'F')
			Bin = Bin + "1111";
	}
	Bin = StandarBit(Bin);
	return Bin;
}

string QInt::DecToHex(const string& str)
{
	return BinToHex(DecToBin(str));
}

string QInt::HexToDec(const string& str)
{
	return BinToDec(HexToBin(str));
}

string QInt::SHL(const string& bin, int x)
{
	string str = bin;

	str = StandarBit(str);

	for (int i = 0; i < x; ++i)
		str.push_back('0');

	while (str.length() > MAX_SIZE)
		str.erase(0, 1);

	str = StandarBit(str);

	return str;
}

string QInt::SAR(const string& bin, int x)
{
	string str = bin;
	str = StandarBit(str);

	if (str.length() < MAX_SIZE && str.length() < x)
	{
		return "0";
	}

	if (str.length() < MAX_SIZE)
	{
		str.erase(str.length() - x, str.length());
	}
	else
	{
		for (int i = 0; i < x; ++i)
			str = '1' + str;
		str.erase(str.length() - x, str.length());
		
	}

	str = StandarBit(str);

	if (str.length() == 0)
		return "0";

	return str;
}

string QInt::ROL(const string& bin)
{
	string str = bin;
	str = FullBit(str);

	if (str[0] == '0')
		str += "0";
	else
		str += "1";

	str.erase(0, 1);

	str = StandarBit(str);

	return str;
}

string QInt::ROR(const string& bin)
{
	string str = bin;
	str = FullBit(str);

	if (str[str.length() - 1] == '1')
		str = "1" + str;
	else
		str = "0" + str;

	str.erase(str.length() - 1, 1);

	str = StandarBit(str);

	return str;
}

char QInt::AddBit(const char& bit1, const char& bit2, char& var_memory)
{
	if (bit1 == '0' && bit2 == '0')
	{
		if (var_memory == '0')
		{
			return '0';
		}
		else
		{
			var_memory = '0';
			return '1';
		}
	}
	else if (bit1 == '0' && bit2 == '1')
	{
		if (var_memory == '1')
		{
			var_memory = '1';
			return '0';
		}
		else
		{
			var_memory = '0';
			return '1';
		}

	}
	else if (bit1 == '1' && bit2 == '0')
	{
		if (var_memory == '1')
		{
			var_memory = '1';
			return '0';
		}
		else
		{
			var_memory = '0';
			return '1';
		}
	}
	else if (bit1 == '1' && bit2 == '1')
	{
		if (var_memory == '0')
		{
			var_memory = '1';
			return '0';
		}
		else
		{
			var_memory = '1';
			return '1';
		}
	}
}

char QInt::CheckMSB(string str1, string str2)
{
	if (str1.length() == str2.length())
	{
		if (str1.length() == MAX_SIZE)
			return '1';
		else
			return '0';
	}
	else if (str1.length() < str2.length())
	{
		if (str2.length() == MAX_SIZE)
		{
			string str = str2;
			str = TwoComplement(str);
			if (isSmaller(str1, str) == true)
				return '1';
			else
				return '0';
		}
		return '0';

	}
	else
	{
		if (str1.length() == MAX_SIZE)
		{
			string str = str1;
			str = TwoComplement(str);
			if (isSmaller(str2, str) == true)
				return '1';
			else
				return '0';
		}
		return '0';

	}
}

//Ham can bang do dai cua 2 chuoi
void Resize(string& str1, string& str2)
{
	while (str1.length() < str2.length())
		str1.insert(str1.begin(), '0');
	while (str1.length() > str2.length())
		str2.insert(str2.begin(), '0');
}

string QInt::addBin(const string& str1, const string& str2)
{
	string error = "";
	string ans;
	string a = str1, b = str2;

	a = StandarBit(a);
	b = StandarBit(b);
	int flag = -1;
	if (a.length() == MAX_SIZE && b.length() == MAX_SIZE)
		flag = 1;
	else if (a.length() < MAX_SIZE && b.length() < MAX_SIZE)
		flag = 0;

	char MSB = CheckMSB(a, b);

	Resize(a, b);

	char var_memory = '0';

	for (int i = a.length() - 1; i >= 0; i--)
	{
		char temp = AddBit(a[i], b[i], var_memory);
		ans.insert(ans.begin(), temp);
	}

	ans = StandarBit(ans);
	
	if (flag == 1 && ans.length() < MAX_SIZE)
		return error;

	if (flag == 0 && ans.length() == MAX_SIZE)
		return error;

	if (MSB == '1')
		while (ans.length() > MAX_SIZE)
			ans.erase(0, 1);

	return ans;
}

string QInt::subBin(const string& str1, const string& str2)
{
	string a = str1, b = str2;

	a = StandarBit(a);
	b = StandarBit(b);

	b = TwoComplement(b);
	return addBin(a, b);
}

QInt& QInt::operator=(const QInt& qint)
{
	for (int i = 0; i < NUM_BLOCK; i++)
		this->data[i] = qint.data[i];
	return *this;
}

QInt QInt::operator&(const QInt& str)
{
	QInt ans;
	for (int i = 0; i < NUM_BLOCK; i++)
	{
		ans.data[i] = this->data[i] & str.data[i];
	}
	return ans;
}

QInt QInt::operator|(const QInt& str)
{
	QInt ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.data[i] = this->data[i] | str.data[i];
	}
	return ans;
}

QInt QInt::operator^(const QInt& str)
{
	QInt ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.data[i] = this->data[i] ^ str.data[i];
	}
	return ans;
}

QInt QInt::operator~()
{
	QInt temp = *this;

	QInt ans;
	for (int i = 0; i < 4; ++i)
		ans.data[i] = ~temp.data[i];

	return ans;
}

//Ham dich phai so hoc cua 1 so khong gioi han so chu so
string SAR1(const string& bin)
{
	string str = bin;

	str.pop_back();
	str = str[0] + str;

	return str;
}

//Ham thay doi n bit dau cua chuoi 2 theo chuoi 1
void UploadStr1ToStr2(string& str1, string& str2)
{
	for (int i = 0; i < str1.length(); i++)
		str2[i] = str1[i];
}

//Ham lay ra n bit dau cua chuoi 2 dua vao chuoi 1
void UploadStr2ToStr1(string& str1, string& str2)
{
	for (int i = 0; i < str1.length(); i++)
		str1[i] = str2[i];
}

string QInt::MulBin(const string& str1, const string& str2)
{
	string A = "0", Q = str1, M = str2, Q1 = "0";
	string error = "";
	int flag = -1;

	Q = StandarBit(Q);
	M = StandarBit(M);

	if (Q.length() < MAX_SIZE && M.length() < MAX_SIZE)
		flag = 0;
	else if (Q.length() < MAX_SIZE && M.length() == MAX_SIZE)
		flag = 1;
	else if (Q.length() == MAX_SIZE && M.length() < MAX_SIZE)
		flag = 2;
	else if (Q.length() == MAX_SIZE && M.length() == MAX_SIZE)
		flag = 3;

	A = FullBit(A);
	Q = FullBit(Q);

	string AQQ1 = A + Q + Q1;

	int k = MAX_SIZE;

	while (k > 0)
	{

		string temp;
		temp.push_back(AQQ1[AQQ1.length() - 2]);
		temp.push_back(AQQ1[AQQ1.length() - 1]);
		if (temp == "10")
		{
			UploadStr2ToStr1(A, AQQ1);
			A = subBin(A, M);
			A = FullBit(A);
			UploadStr1ToStr2(A, AQQ1);
		}
		else if (temp == "01")
		{
			UploadStr2ToStr1(A, AQQ1);
			A = addBin(A, M);
			A = FullBit(A);
			UploadStr1ToStr2(A, AQQ1);
		}

		AQQ1 = SAR1(AQQ1);

		k--;
	}

	AQQ1.pop_back();

	for (int i = 0; i < MAX_SIZE; i++)
	{
		Q[i] = AQQ1[MAX_SIZE + i];
	}

	Q = StandarBit(Q);

	if (flag == 0)
	{
		if (Q.length() == MAX_SIZE)
			return error;
		
		if (isSmaller(Q, str1) == true || isSmaller(Q, str2) == true)
			return error;
	}

	if (flag == 1)
	{
		if (Q.length() < MAX_SIZE)
			return error;

		if (isSmaller(TwoComplement(Q), str1) == true || isSmaller(TwoComplement(Q), TwoComplement(str2)) == true)
			return error;
	}

	if (flag == 2)
	{
		if (Q.length() < MAX_SIZE)
			return error;

		if (isSmaller(TwoComplement(Q), TwoComplement(str1)) == true || isSmaller(TwoComplement(Q), str2) == true)
			return error;
	}

	if (flag == 2)
	{
		if (Q.length() == MAX_SIZE)
			return error;

		if (isSmaller(Q, TwoComplement(str1)) == true || isSmaller(Q, TwoComplement(str2)) == true)
			return error;
	}

	return Q;
}

//Ham dich trai logic cua 1 so khong gioi han chu so
string SHL1(const string& bin)
{
	string str = bin;

	str += '0';
	str.erase(0, 1);

	return str;
}

string QInt::DivBin(const string& str1, const string& str2)
{
	string A, Q = str1, M = str2;

	Q = StandarBit(Q);
	M = StandarBit(M);

	int flag = 0;

	if (Q.length() == MAX_SIZE  && M.length() < MAX_SIZE)
	{
		flag = 1;
		Q = TwoComplement(Q);
		Q = StandarBit(Q);
	}
	else if (M.length() == MAX_SIZE && Q.length() < MAX_SIZE)
	{
		flag = 1;
		M = TwoComplement(M);
		M = StandarBit(M);
	}
	else if (M.length() == MAX_SIZE && Q.length() == MAX_SIZE)
	{
		flag = 2;
		Q = TwoComplement(Q);
		Q = StandarBit(Q);
		M = TwoComplement(M);
		M = StandarBit(M);
	}

	bool check = isSmaller(BinToDec(Q), BinToDec(M));
	if (check == true)
		return "0";

	while (A.length() < MAX_SIZE)
		A += '0';


	int k = MAX_SIZE;

	Q = FullBit(Q);

	string AQ = A + Q;


	while (k > 0)
	{
		AQ = SHL1(AQ);

		UploadStr2ToStr1(A, AQ);
		string A1 = subBin(A, M);

		if (A1.length() == MAX_SIZE)
		{
			AQ[AQ.length() - 1] = '0';
			UploadStr1ToStr2(A, AQ);
		}
		else
		{
			A1 = FullBit(A1);
			UploadStr1ToStr2(A1, AQ);
			AQ[AQ.length() - 1] = '1';
		}

		k--;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		Q[i] = AQ[MAX_SIZE + i];
	}

	Q = StandarBit(Q);

	if (flag == 1)
		Q = TwoComplement(Q);

	return Q;
}
