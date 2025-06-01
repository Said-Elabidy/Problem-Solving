#include <iostream>
#pragma warning (disable:4996)
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

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year == Date2.Year)
	{
		short date1 = NumberOfDaysFromTheBegeiningofYear(Date1.Year, Date1.Month, Date1.Day);
		short date2 = NumberOfDaysFromTheBegeiningofYear(Date2.Year, Date2.Month, Date2.Day);

		if (date1 < date2)
			return true;
		else
			return false;
	}
	else if (Date1.Year > Date2.Year)
		return false;
	else
		return true;
}

int DiffrenceBetweenTwoDates(sDate Date1, sDate Date2, bool EndDay = false)
{
	int DiffrenceDays = 0;

	if (IsDate1BeforDate2(Date1, Date2))
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

sDate IncreaseDateByOneDay(sDate  Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month)) {
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else {
			Date.Day = 1;
			Date.Month++;
		}
	}
	else {
		Date.Day++;
	}
	return Date;
}

short DayOrder(short Year, short Month, short Day)
{
	short A = (14 - Month) / 12;
	short Y = Year - A;
	short M = Month + (12 * A) - 2;

	short D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	//0:sunday , 1:Monday , 2:Tuesday etc...
	return D;
}

short DayOrder(sDate Date)
{
	return DayOrder(Date.Year, Date.Month, Date.Day);
}

string DayName(short DayOrder)
{
	string Arra[7] = { "Sun","Mon","Tues","Wed","Thurs","Fri","Sat" };

	return Arra[DayOrder];
}


bool IsEndOfWeek(short DayOrder)
{
	return DayOrder == 6 ? true : false;
}

bool IsWeekEnd(short DayOrder)
{
	return (DayOrder == 5 || DayOrder == 6) ? true : false;
}

bool IsBusinessDay(short DayOrder)
{
	return !IsWeekEnd(DayOrder);
}

short DaysUntilTheEndOfWeek(sDate Date)
{

	return 6 - DayOrder(Date);
}

short CalculateActualVacation(sDate StartDate, sDate EndDate)
{
	short VacationDays = 0;
        while(IsDate1BeforDate2(StartDate,EndDate))
        {
		if (IsBusinessDay(DayOrder(StartDate)))
		{
			VacationDays += 1;
		}
		StartDate = IncreaseDateByOneDay(StartDate);
	    }
	return VacationDays;
}
int main()
{
	cout << "Vacation Starts :\n\n";
	sDate VacationStart = ReadFullDate();

	cout << "Vacation Ends :\n\n";
	sDate VacationEnd = ReadFullDate();

	cout << "Vacation From " << DayName(DayOrder(VacationStart)) << ", " << VacationStart.Day << "/" << VacationStart.Month << "/" << VacationStart.Year << endl << endl;
	cout << "Vacation To " << DayName(DayOrder(VacationEnd)) << ", " << VacationEnd.Day << "/" << VacationEnd.Month << "/" << VacationEnd.Year << endl << endl;

	cout << "Actual Days of Vacation : " << CalculateActualVacation(VacationStart, VacationEnd) << endl;

	system("pause>0");
}

