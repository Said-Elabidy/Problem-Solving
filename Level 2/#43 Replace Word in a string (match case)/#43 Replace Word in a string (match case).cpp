#include <iostream>
#include <vector>
#include<string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S1 = " ";
	cout << "Please enter your string?\n";
	getline(cin, S1);
	return S1;
}

vector<string> SeperatString(string S1, string Delimeter)
{
	vector<string>vWord;
	string Word = " ";
	short Position = 0;

	while ((Position = S1.find(Delimeter)) != std::string::npos)
	{
		Word = S1.substr(0, Position);
		vWord.push_back(Word);

		S1 = S1.erase(0, Position + Delimeter.length());
	}
	if (S1 != "")
	{
		vWord.push_back(S1);
	}
	return vWord;
}

string ToLower(string Word)
{
	for (char& c : Word)
	{
		c = tolower(c);
	}
	return Word;
}

string ReplaceWord(string S1, string OrignalWord, string WordToReplace,bool MatchCase=false)
{
	string S2 = "";
	vector<string>vString = SeperatString(S1, " ");

	if (MatchCase==true)
	{
		string McOrignalWord = ToLower(OrignalWord);
		for (string& s : vString)
		{
			s = ToLower(s);
			if (s == McOrignalWord)
			{
				s = WordToReplace;
			}
			S2 = S2 + s + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}
	else
	{
		for (string& s : vString)
		{
			if (s == OrignalWord)
			{
				s = WordToReplace;
			}
			S2 = S2 + s + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}
}
int main()
{
	string S1 = "I Live in Portsaid , Portsaid is a beautiful city.";

	cout << "Original String: "<<S1 << endl;

	cout << "\nReplace with match case :\n";
	cout << ReplaceWord(S1, "portsaid", "Alex")<<endl;

	cout << "\nReplace without match case :\n";
	cout << ReplaceWord(S1, "portsaid", "Alex",true) << endl;

	system("pause>0");


}
