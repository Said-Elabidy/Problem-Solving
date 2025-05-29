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

	int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (CheckLeapYear(Year) ? 29 : 28) : DaysInMonth[Month - 1];
}
struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate AddOneDayToDate(stDate &Date)
{
	short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
	(Date.Day == MonthDays) ? (Date.Month++) && (Date.Day = 1) : Date.Day++;
	(Date.Month == 13) ? (Date.Month = 1) && (Date.Year++) : false;

	return Date;

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

	AddOneDayToDate(Date);
	printf("\n\nDate : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	system("pause>0");

}

