#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Ask)
{
	cout << Ask << endl;
	string UserString = " ";
	getline(cin, UserString);
	return UserString;
}

enum enCountLetters { CapitalLetters = 0, SmallLetters = 1, CountAll=2 };

short WhatToCount(string S1, enCountLetters CountLetters = enCountLetters::CountAll)
{
	int Counter = 0;
	if (CountLetters == enCountLetters::CountAll)
	{
		return S1.length();
	}

	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]) && CountLetters == enCountLetters::CapitalLetters)
		{
			Counter++;
		}

		else if (islower(S1[i]) && CountLetters == enCountLetters::SmallLetters)
		{
			Counter++;
		}

}
	return Counter;
}

unsigned short CountCapitalLetters(string S1)
{
	unsigned short Counter = 0;
	for (char &C : S1)
	{
		if (C = isupper(C))
		{
			Counter++;
        }
	}
	return Counter;
}

unsigned short CountSmallLetters(string S1)
{
	unsigned short Counter = 0;
	for (char& C : S1)
	{
		if (C = islower(C))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString("Please enter a String?");

	cout << "\n\nMethod 1 :\n\n";

	printf("\nString Length = %d\n\n", S1.length());
	printf("Small Letters Count = %d\n\n", CountSmallLetters(S1));
	printf("Capital Letters Count = %d\n\n", CountCapitalLetters(S1));

	cout << "\n\nMethod 2 :\n\n";

	printf("\nString Length = %d\n\n", WhatToCount(S1));
	printf("Small Letters Count = %d\n\n", WhatToCount(S1,enCountLetters::SmallLetters));
	printf("Capital Letters Count = %d\n\n", WhatToCount(S1,enCountLetters::CapitalLetters));



	system("pause>0");

}

