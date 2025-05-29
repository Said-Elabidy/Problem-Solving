#include <iostream>
#include <string >
#include<cctype>
using namespace std;

string ReadString(string Ask)
{
	cout << Ask << endl;
	string UserString = " ";
	getline(cin, UserString);
	return UserString;
}

char ReadCharacter(string Ask)
{
	char C = ' ';
	cout << Ask << endl;
	cin >> C;
	return C;
}

short CountSpecificCharacter(string S1, char C)
{
	short Counter = 0;
	//for (int i = 0; i <= S1.length(); i++)
	//{
	//	if (S1[i] == C)
	//	{
	//		Counter++;
	//	}
 //    }

	for (char& C1 : S1)
	{
		if (C1 == C)
		{
			Counter++;
		}
	}
	return Counter;
}

short CountLetterMatchCase(string S1, char C)
{
	short Counter = 0;
	if (isupper(C))
	{
		C = tolower(C);
		return CountSpecificCharacter(S1, C);
	}
	if (islower(C))
	{
		C = toupper(C);
	return	CountSpecificCharacter(S1, C);
	}
}

char InvertChar(char C)
{
	if (isupper(C))
		return tolower(C);
	else
		return toupper(C);
}

int main()
{
	string S1 = ReadString("Please enter a String?");

	char C = ReadCharacter("\n\nPlease enter a Chracter?");

	printf("\n\nNumber of Character (%c) is : %d\n", C, CountSpecificCharacter(S1, C));

	printf("\n\nLetter '%c' Or '%c' Match Case Count = %d", C, InvertChar(C), CountSpecificCharacter(S1, C) + CountLetterMatchCase(S1, C));

	system("pause>0");
	return 0;


}
