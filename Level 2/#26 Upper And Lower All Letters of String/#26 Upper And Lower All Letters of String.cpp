#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Ask)
{
	string S1 = " ";
	cout << Ask << endl;
	getline(cin, S1);
	return S1;
}

string ToUpper(string S1)
{
	for (int i = 0; i <= S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}

string ToLower(string S1)
{
	for (int i = 0; i <= S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}


int main()
{
	string S1 = ReadString("Please enter Your String ?");

	cout << "\n\nString after Upper :\n\n";
	cout << ToUpper(S1) << endl;

	cout << "\n\nString after Lower :\n\n";
	cout << ToLower(S1) << endl;

	system("pause>0");
	return 0;
}

