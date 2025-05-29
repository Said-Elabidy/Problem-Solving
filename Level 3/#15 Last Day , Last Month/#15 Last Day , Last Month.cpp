#include <iostream>
using namespace std;

short ReadData(string Ask)
{
	cout << Ask << endl;
	short Num = 0;
	cin >> Num;
	return Num;
}

bool CheckLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{

	if (Month < 1 || Month>12)
		return 0;

	int DaysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	return (Month == 2) ? (CheckLeapYear(Year) ? 29 : 28) : DaysInMonth[Month - 1];
}
struct stDate
{
	short Year;
	short Month;
	short Day;
};
bool IsLastDay(stDate Date)
{
	short LastDay = NumberOfDaysInAMonth(Date.Month, Date.Year);

	return (Date.Day == LastDay) ? true : false;
}

bool IsLastMonth(short Month)
{
	return (Month == 12) ? true : false;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadData("Please Enter a Day ?");
	Date.Month = ReadData("Please Enter a Month ?");
	Date.Year = ReadData("Please Enter a Year ?");
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	if (IsLastDay(Date))
	{
		printf("\nYes, Day %d Is Last Day .\n\n", Date.Day);
	}
	else
		printf("\nNo, Day %d Is Not Last Day .\n\n", Date.Day);

	if (IsLastMonth(Date.Month))
	{
		printf("\nYes, Month %d Is Last Month .\n\n", Date.Month);
	}
	else
		printf("\nNo, Month %d Is Not Last Month .\n\n", Date.Month);

	system("pause>0");

}

