#include <iostream>
using namespace std;

short ReadNum()
{
	cout << "Please enter the Year ?\n";
	short Year = 0;
	cin >> Year;
	return Year;
}

bool CheckLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

int NumberOFDays(bool Year)
{
	return CheckLeapYear(Year) ? 366 : 365;
}

int NumberOfHours(bool Year)
{
	return NumberOFDays(Year) * 24;
}

int NumberOfMunuites(bool Year)
{
	return NumberOfHours(Year) * 60;
}

int NumberOfSeconds(bool Year)
{
	return NumberOfMunuites(Year) * 60;
}

int main()
{
	short Num = ReadNum();
	bool Year = CheckLeapYear(Num);
	
	printf("Number Of Days in Year[%d] is : %d\n", Num, NumberOFDays(Year));
	printf("Number Of Hours in Year[%d] is : %d\n", Num, NumberOfHours(Year));
	printf("Number Of Munuites in Year[%d] is : %d\n", Num, NumberOfMunuites(Year));
	printf("Number Of Seconds in Year[%d] is : %d\n", Num, NumberOfSeconds(Year));

	return 0;

}
