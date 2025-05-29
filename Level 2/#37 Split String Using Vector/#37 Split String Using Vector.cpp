#include <iostream>
#include <vector>
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

 vector<string>SplitString (string S1,string Delemiter)
{
	 vector<string>Words;
	short Position = 0;

	string Token = "";

	while ((Position = S1.find(Delemiter)) != std::string::npos)
	{
		Token = S1.substr(0, Position);
		if (Token != "")
		{
			Words.push_back(Token);
		}
		S1.erase(0, Position + Delemiter.length());
	}
	if (S1 != "")
	{
		Words.push_back(S1);
	}
	return Words;
}

 void PrintWordsAndNumOfTokens(vector<string>vWords)
 {
	 cout << "\n\nNumber Of Tokens = " << vWords.size() << endl;
	 for (string& Word : vWords)
	 {
		 cout << Word << endl;
	 }
 }
int main()
{
	string S1 = ReadString();

	PrintWordsAndNumOfTokens(SplitString(S1, " "));
	system("pause>0");
		return 0;

}
