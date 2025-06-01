#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char ReadCharacter(string Ask)
{
	char C = ' ';
	cout << Ask << endl;
	cin >> C;
	return C;

}

bool IsVowel(char Vowels[5], char C)
{
	C = tolower(C);

	for (short i =0 ; i < 5 ; i++)
	{
		if ((Vowels[i] == C))
		{
			return true;
		}
	}
	return false;
}

void PrintIsVowels(bool IsVowelCharacter,char C)
{
	if (IsVowelCharacter)
	{
		printf("\n\nYes , Characte %c is Vowel",C);
	}
	else
		printf("\n\nNo , Characte %c is Not Vowel",C);

}
int main()
{

	char Vowels[5] = { 'a','i','e','o','u' };
	char C = ReadCharacter("Please enter a Character?");

	PrintIsVowels(IsVowel(Vowels, C),C);
	system("pause>0");
	return 0;
}

