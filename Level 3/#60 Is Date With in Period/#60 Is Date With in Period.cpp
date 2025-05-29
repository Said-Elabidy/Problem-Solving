#include <iostream>
using namespace std;
struct sDate
{
	short Year;
	short Month;
	short Day;
};
struct sPeriod
{
	sDate StartDate;
	sDate EndDate;
};

enum eCompareResult { Befor = -1, Equal = 0, After = 1 };

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
eCompareResult CompareDate(sDate Date1, sDate Date2)
{
	if (IsDate1EqualDate2(Date1, Date2))
		return eCompareResult::Equal;

	if (IsDate1AfterDate2(Date1, Date2))
		return eCompareResult::After;

	else
		return eCompareResult::Befor;
}

bool IsDayWithinPeriod(sDate Date, sPeriod Period)
{
	if (CompareDate(Date, Period.StartDate) == eCompareResult::After
		&&
		CompareDate(Date, Period.EndDate) == eCompareResult::Befor
		)
		return true;
	if (CompareDate(Date, Period.StartDate) == eCompareResult::Equal
		||
		CompareDate(Date, Period.EndDate) == eCompareResult::Equal
		)
		return true;
	else
		return false;
}
sPeriod ReadPeriod()
{
	sPeriod Period;
	cout << "Enter Start Date :\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter end Date :\n";
	Period.EndDate = ReadFullDate();
	return Period;
}
int main()
{
	sDate Date;
	sPeriod Period1;
	cout << "\nPeriod : \n";
	Period1 = ReadPeriod();

	cout << "\nEnter Date to Check : \n";
	Date = ReadFullDate();

	if (IsDayWithinPeriod(Date,Period1))
		cout << "\n\nYes, Date is within Period .\n";
	else
		cout << "\n\nNo, Date is not within Period.\n";

	system("pause>0");
}

