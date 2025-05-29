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

int MyFloor(float Num)
{
	if (Num>=0)
	{
		return int(Num);
	}
	else
	{
		if (abs(GetFractionPart(Num)) > 0)
		{
			return int(--Num);
		}
		else
			return Num;
	}
	
}
int main()
{
	float Num = ReadNum();
	cout << "My Floor Num : " << MyFloor(Num) << endl;
	cout << "C++ Floor Num : " << floor (Num) << endl;
	return 0;

}

