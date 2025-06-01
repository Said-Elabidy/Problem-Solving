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

float MySqrt(float Num)
{
	return pow((Num),.5);
}
int main()
{
	float Num = ReadNum();
	cout << "My sqrt : " << MySqrt(Num) << endl;
	cout << "C++ sqrt : " << sqrt(Num) << endl;

	return 0;


}
