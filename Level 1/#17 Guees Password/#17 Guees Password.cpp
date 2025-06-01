#include <iostream>
#include <string>
using namespace std;

string ReadPassword(string Ask)
{
	string Password = "";
	cout << Ask << endl;
	cin >> Password;
	return Password;
}
bool PrintAllPosabilitiesFromAaaToZzz(string Password)
{
	int Counter = 1;
	string Word = "";
	for (int X = 65; X <= 90; X++)
	{
		for (int Y = 65; Y <= 90; Y++)
		{
			for (int Z = 65; Z <= 90; Z++)
			{
				Word = Word+char(X);
				Word = Word + char(Y);
				Word = Word + char(Z);
				cout << "Trial[" << Counter << "]" << " : " << Word << endl;
				if (Word == Password)
				{
					cout <<"\n"<< "Password is " << Word << endl;
					cout << "Found after " << Counter << " Trial(s)." << endl;
					return true;
				}
				Counter++;
				Word = "";

			}
		}
	}
	return false;
}
int main()
{
	PrintAllPosabilitiesFromAaaToZzz(ReadPassword("Please enter your Password in Capital Letters?"));
	return 0;


}

