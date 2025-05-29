#include <iostream>
using namespace std;
struct sDate
{
	short Year;
	short Month;
	short Day;
};

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "\nPlease enter a Year? ";
	cin >> Year;
	return Year;
}
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ?
			(Date1.Month < Date2.Month ? true :
				(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
			: false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ?
		((Date1.Month == Date2.Month) ?
			((Date1.Day == Date2.Day) ? true : false)
			: false)
		: false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

bool IsOverLapPeriods(sDate Date1Start, sDate Date1End, sDate Date2Start, sDate Date2End)
{
	if (IsDate1BeforeDate2(Date1Start, Date2End) && IsDate1AfterDate2(Date1Start,Date2Start))
	{
		return true;
	}
	else if (IsDate1BeforeDate2(Date1End, Date2End) && IsDate1AfterDate2(Date1End, Date2Start))
	return true;
	if (IsDate1EqualDate2(Date1Start, Date2Start))
		return true;
	else
		return false;
}
int main()
{
	sDate Date1Start, Date1End, Date2Start, Date2End;
	cout << "\nPeriod 1 : \n";
	cout << "Enter Start Date :\n";
	Date1Start = ReadFullDate();
	
	cout << "\nEnter end Date :\n";
	Date1End = ReadFullDate();

	cout << "\nPeriod 2 : \n";
	cout << "Enter Start Date :\n";
	Date2Start = ReadFullDate();

	cout << "\nEnter end Date :\n";
	Date2End = ReadFullDate();

	if (IsOverLapPeriods(Date1Start, Date1End, Date2Start, Date2End))
		cout << "\n\nYes, Periods OverLap.\n";
	else
		cout << "\n\nNo,Periods Won't OverLap.\n";


	system("pause>0");

}

