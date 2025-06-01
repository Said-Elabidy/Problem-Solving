#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector<string>vString, string Delimiter)
{
	string S1 = "";
	for (string& S : vString)
	{
		S1 = S1 + S + Delimiter;
	}
	return S1.substr(0, S1.length() - Delimiter.length());
}


int main()
{
	vector<string>vString;
	vString.push_back("Ali");
	vString.push_back("Said");
	vString.push_back("osama");
	vString.push_back("gamal");

cout <<	JoinString(vString, "###");

	system("pause>0");


}

