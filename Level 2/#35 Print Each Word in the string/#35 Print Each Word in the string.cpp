#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string ReadString(string Ask)
{
	string S1 = " ";
	cout << Ask << endl;
	getline(cin, S1);
	return S1;
}

void PrintEachWord(string S1)
{
	cout << "\n\nYour String Words Are :\n\n";
	for (int i = 0; i <= S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			cout << S1[i];
		}
		else
			cout << endl;
	}
}
int main()
{
	string S1 = ReadString("Please enter your String?");

	PrintEachWord(S1);

	system("pause>0");



}

