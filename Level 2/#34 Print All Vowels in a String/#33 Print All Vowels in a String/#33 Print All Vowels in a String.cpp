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

bool IsVowel(char Vowels[5], char C)
{
	C = tolower(C);

	for (short i = 0; i < 5; i++)
	{
		if ((Vowels[i] == C))
		{
			return true;
		}
	}
	return false;
}

void PrintVowels(string S1)
{
	char Vowels[5] = { 'a','i','e','o','u' };
	short Counter = 0;
	for (int i = 0; i <= S1.length(); i++)
	{
		if (IsVowel(Vowels, S1[i]))
		{
			cout << S1[i] << "   ";
		}
	}
	
}
int main()
{

	string S1 = ReadString("Please enter a Character?");

	cout << "\n\nVowels in your string are : ";
	PrintVowels(S1);


	system("pause>0");
	return 0;
}
