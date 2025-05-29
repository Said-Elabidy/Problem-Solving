#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

		return RandNum;
}
int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;

	cout << RandomNumber(20 , 30) << endl;
	cout << RandomNumber(20 , 30) << endl;
	cout << RandomNumber(20 , 30) << endl;

	cout << RandomNumber(30, 40) << endl;
	cout << RandomNumber(30, 40) << endl;
	cout << RandomNumber(30, 40) << endl;
 
	return 0;

}

