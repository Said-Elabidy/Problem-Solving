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

		S1=S1.erase(0, Position + Delimeter.length());
	}
	if (S1 != "")
	{
		vWord.push_back(S1);
	}
	return vWord;
}

string PrintInvetedString(vector<string>vWord, string Delimeter)
{
	string S1 = "";
	for (int i = (vWord.size() - 1); i >= 0; i--)
	{
		S1 = S1 + vWord[i] + Delimeter;
	}
	return S1.substr(0, S1.length() - Delimeter.length());
}

int main()
{
	string S1 = ReadString();

	cout << "\nYour String After Inverted : \n";
	cout << PrintInvetedString(SeperatString(S1, " "), " ");

	system("pause>0");



}

