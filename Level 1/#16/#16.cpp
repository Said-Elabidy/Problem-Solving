#include <iostream>
#include <string>
using namespace std;

void PrintAllPosabilitiesFromAaaToZzz()
{
	for (int X = 65; X <= 90; X++)
	{
		for (int Y = 65; Y <= 90; Y++)
		{
			for (int Z = 65; Z <= 90; Z++)
			{
				cout << char(X) << char(Y) << char(Z) << endl;
			}
		}
	}
}
int main()
{
	PrintAllPosabilitiesFromAaaToZzz();
		return 0;
}

