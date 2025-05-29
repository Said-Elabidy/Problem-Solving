#include <iostream>
#include <cmath>
using namespace std;

float ReadNum()
{
	float Num = 0;

	cout << "Please enter a Negative Number ?\n";
	cin >> Num;

	return Num;
}

float GetFractionPart(float Num)
{
	return Num - int(Num);
}

int MyRound(float Num)
{
	int InPart;
	InPart = int(Num);

	float FractionPart = GetFractionPart(Num);
	if (abs(FractionPart) >= .5)
	{
		if (Num > 0)
			return ++InPart;
		else
			return --InPart;
	}
	else
		return InPart;
}
int main()
{
	float Num = ReadNum();

	cout << "My Round Num : " << MyRound(Num) << endl;
	cout << "C++ Round Num : " << round(Num) << endl;
	return 0;

}

