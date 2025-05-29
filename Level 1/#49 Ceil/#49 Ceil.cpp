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

int MyCeil(float Num)
{
	if (abs(GetFractionPart(Num)) > 0)
	{
		if (Num > 0)
			return Num + 1;
		else
			return int(Num);
	}
	else
		return int(Num);
}

int main()
{
	float Num = ReadNum();
	cout << "My Ceil : " << MyCeil(Num) << endl;
	cout << "C++ Ceil : " << ceil(Num) << endl;

	return 0;


}

