#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemovePunc(string S1)
{
	string S2 = "";
	for (int i =0 ; i < S1.length();i++)
	{
		if ((ispunct(S1[i]))==false)
		{
			S2 = S2 + S1[i];

		}
	}
	return S2;
}
int main()
{
	string S1 = "This is how to remove Punctuation,,, like this : and This. And *";

	cout << S1 << endl;

	cout << endl << RemovePunc(S1) << endl;


	system("pause>0");

}

