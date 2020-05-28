#include "File.h"

int main()
{
	string input;
	string output;
	
	cout << "\nEnter name's input: ";
	getline(cin, input);

	cout << "\nEnter name's outfile: ";
	getline(cin, output);
	
	RWFile(input, output);


	system("pause");
	return 0;
}
