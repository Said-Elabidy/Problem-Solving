#include <iostream>
#include <string>
#include<cctype>
using namespace std;

string ReadString(string Ask)
{
	string S1 = " ";
	cout << Ask << endl;
	getline(cin, S1);
	return S1;
}

string LowerFirstLetter(string S1)
{
	bool IsFirstLetter = true;

	for (int i = 0; i <= S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}
		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

int main()
{
	string S1 = " ";

	S1 = LowerFirstLetter(ReadString("Please enter Your String ?"));

	cout << "\n\nString After Conversion :\n";
	cout << S1 << endl;
	system("pause>0");
	return 0;

}
