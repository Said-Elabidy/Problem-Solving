#include <iostream>
#include <string>
using namespace std;

string ReadString(string Ask)
{
	string UserSrtring = " ";
	cout << Ask << endl;
	getline(cin, UserSrtring);
	return UserSrtring;
}

void PrintFirstLetters(string Sentense)
{
	bool IsFirstLetter = true;

	for (int i = 0; i < Sentense.length(); i++)
	{
		if (Sentense[i] != ' ' && IsFirstLetter)
		{
			cout << Sentense.at(i) << endl;

		}
		IsFirstLetter = (Sentense[i] == ' ' ? true : false);
	}
}
int main()
{
	PrintFirstLetters(ReadString("Please enter a Sentense ?"));

	system("pause>0");

	return 0;


}

