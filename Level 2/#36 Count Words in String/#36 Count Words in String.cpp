#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Please enter Your String?\n";
	getline(cin, S1);
	return S1;
}

int CountOfWords(string S1)
{
	short Position = 0;
	short Counter = 0;

	string Word = "";
	string Space = " ";

	while ((Position = S1.find(Space)) != std::string::npos)
	{
		Word = S1.substr(0, Position);
		if (Word != "")
		{
			Counter++;
        }
		S1.erase(0, Position + Space.length());
	}
	if (S1 != "")
	{
		Counter++;
	}
	return Counter;
}


int main()
{
	string S1 = " ";
	S1 = ReadString();
	printf("\n\nNumber of Word is : %d\n\n", CountOfWords(S1));

	system("pause>0");
	return 0;
}

