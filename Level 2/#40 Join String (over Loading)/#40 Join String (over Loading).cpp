#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector<string>vString, string Delmiter)
{
	string S1 = "";
	for (string& S : vString)
	{
		S1 = S1 + S + Delmiter;
	}
	return S1.substr(0, S1.length() - Delmiter.length());
}

string JoinString(string Arra[], short ArrayLength, string Delmiter)
{
	string S1 = "";
	for (int i = 0; i < ArrayLength; i++)
	{
		S1 = S1 + Arra[i] + Delmiter;
	}

	return S1.substr(0, S1.length() - Delmiter.length());
}

int main()
{
	vector<string>vString = { "Ali","Said","osama","gamal" };
	string Arra[] = { "Ali","Said","osama","gamal" };
	cout << "Vector After Join:\n\n";
	cout << JoinString(vString, ";;")<<endl;

	cout << "\nArray After Join:\n\n";
	cout << JoinString(Arra, 4, ";;");

	system("pause>0");


}

