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


short NumberOfDaysFromTheBegeiningofYear(short Year, short Month, short Day)
{
	short Sum = 0;
	for (int i = 1; i < Month; i++)
	{
		Sum += NumberOfDaysInAMonth(i, Year);
	}
	Sum = Sum + Day;
	return Sum;
}


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

bool IsOverLapPeriods(sPeriod Period1, sPeriod Period2)
{
	if (
		CompareDate(Period2.EndDate, Period1.StartDate) == eCompareResult::Befor
		||
		CompareDate(Period2.StartDate, Period1.EndDate) == eCompareResult::After
		)
		return false;
	else
		return true;
}
short DiffrenceBetweenTwoDates(sDate Date1, sDate Date2, bool EndDay = false)
{
	int DiffrenceDays = 0;

	if (IsDate1BeforeDate2(Date1, Date2))
	{
		DiffrenceDays = NumberOfDaysFromTheBegeiningofYear(Date2.Year, Date2.Month, Date2.Day) - NumberOfDaysFromTheBegeiningofYear(Date1.Year, Date1.Month, Date1.Day);
		while (Date1.Year != Date2.Year)
		{
			Date2.Year = Date2.Year - 1;
			if (CheckLeapYear(Date2.Year))
			{
				DiffrenceDays = DiffrenceDays + 366;
			}
			else
				DiffrenceDays = DiffrenceDays + 365;

		}
	}
	return EndDay == false ? DiffrenceDays : DiffrenceDays + 1;
}

short PeriodDuration(sPeriod Period, bool EndDay=false)
{
	return DiffrenceBetweenTwoDates(Period.StartDate, Period.EndDate, EndDay);
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
	sPeriod Period;
	cout << "\nPeriod 1 : \n";
	Period = ReadPeriod();

	cout << "\nPeriod Length is : " << PeriodDuration(Period) << endl;
	cout << "\nPeriod Length (Incled End of the Day) : " <<PeriodDuration(Period,true) << endl; 
	system("pause>0");
}

