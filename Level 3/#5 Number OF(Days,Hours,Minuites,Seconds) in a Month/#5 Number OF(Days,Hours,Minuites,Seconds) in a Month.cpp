#include <iostream>
using namespace std;

short ReadNum(string Ask)
{
	cout << Ask << endl;
	short Year = 0;
	cin >> Year;
	return Year;
}

bool CheckLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOFDaysInMonth(bool Year, short Month)
{
	if (Month == 2)
	{
		if (Year)
		{
			return 29;
		}
		else
			return 28;
	}
	if (Month == 4 || Month== 6 ||Month== 11 ||Month== 9)
		return 31;
	else
		return 30;
}

int NumberOfHours(bool Year, short Month)
{
	return NumberOFDaysInMonth(Year, Month) * 24;
}

int NumberOfMunuites(bool Year, short Month)
{
	return NumberOfHours(Year, Month) * 60;
}

int NumberOfSeconds(bool Year, short Month)
{
	return NumberOfMunuites(Year, Month) * 60;
}

int main()
{
	short Num = ReadNum("Please enter the Year?");
	bool Year = CheckLeapYear(Num);
	short Month = ReadNum("Please enter The Month?");
	printf("Number Of Days in Month[%d] is : %d\n", Month, NumberOFDaysInMonth(Year, Month));
	printf("Number Of Hours in Month[%d] is : %d\n", Month, NumberOfHours(Year, Month));
	printf("Number Of Munuites in Month[%d] is : %d\n", Month, NumberOfMunuites(Year, Month));
	printf("Number Of Seconds in Month[%d] is : %d\n", Month, NumberOfSeconds(Year, Month));

	return 0;

}
