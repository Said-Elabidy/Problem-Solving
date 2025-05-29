#include <iostream>
#include<cmath>
using namespace std;

int ReadNum()
{
	int Num = 0;
	
		cout << "Please enter a Negative Number ?\n";
		cin >> Num;
	
	return Num;
}
int MyAbsNum(int Num)
{
	if (Num < 0)
	{
		Num = Num * -1;
		return Num;
	}
	else 
	return Num;
}

int main()
{
	int Num =ReadNum();
	cout << "My Abs Resualt : " << MyAbsNum(Num) << endl;
	cout << "C++ Abs Resualt : " << abs(Num) << endl;
	return 0;

}

