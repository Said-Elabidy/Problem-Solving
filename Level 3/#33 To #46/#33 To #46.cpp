#include <iostream>
using namespace std;

struct sDate
{
	short year;
	short month;
	short day;
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
	Date.day = ReadDay();
	Date.month = ReadMonth();
	Date.year = ReadYear();
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
	return (Date.day == NumberOfDaysInAMonth(Date.month, Date.year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

sDate DecreaseDateByOneDay(sDate &Date)
{
	if (Date.day == 1)
	{
		if (Date.month == 1)
		{
			Date.month = 12;
			Date.day = NumberOfDaysInAMonth(Date.month, Date.year);
			Date.year = Date.year - 1;

		}
		else
		{
			Date.month = Date.month - 1;
			Date.day = NumberOfDaysInAMonth(Date.month, Date.year);
		}

	}
	else
		Date.day--;
	return Date;
}

sDate DecreaseDateByXDays(sDate& Date, short X)
{
	for (short i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByOneWeek(sDate& Date)
{
	Date = DecreaseDateByXDays(Date, 7);
	return Date;
}

sDate DecreaseDateByXWeek(sDate& Date, short X)
{
	for (short i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate DecreaseDateByOneMonth(sDate& Date)
{
	if (Date.month == 1)
	{
		if (IsLastDayInMonth(Date))
		{
			Date.month = 12;
			Date.day = NumberOfDaysInAMonth(Date.month, Date.year);
			Date.year = Date.year - 1;
		}
		else
			Date.month = 12;
		Date.year = Date.year - 1;
	}
	else
	{
		if (IsLastDayInMonth(Date))
		{
			Date.month--;
			Date.day = NumberOfDaysInAMonth(Date.month, Date.year);
		}
		else
		{
			Date.month--;
		}
	}
	return Date;
}

sDate DecreaseDateByXMonth(sDate& Date, short X)
{
	for (short i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate DecreaseDateByOneYear(sDate& Date)
{
	Date.year--;
	return Date;
}

sDate DecreaseDateByXYear(sDate& Date, short X)
{
	for (short i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXYearFaster(sDate& Date, short X)
{
	Date.year = Date.year - X;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate& Date)
{
	Date = DecreaseDateByXYearFaster(Date, 10);
	return Date;
}

sDate DecreaseDateByXDecade(sDate& Date,short X)
{
	for (short i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

sDate DecreaseDateByXDecadeFaster(sDate& Date, short X)
{
	Date.year = Date.year - X * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate& Date)
{
	Date.year = Date.year - 100;
	return Date;
}

sDate DecreaseDateByOneMillennuim(sDate& Date)
{
	for (short i = 0; i < 10; i++)
	{
		Date = DecreaseDateByOneCentury(Date);
	}
	return Date;
}

int main()
{
	sDate Date1 = ReadFullDate();
	cout << "\nDate After : \n\n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "01-Substracting one day is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXDays(Date1,10);
	cout << "02-Substracting 10 days is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "03-Substracting one week is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXWeek(Date1, 10);
	cout << "04-Substracting 10 weeks is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "05-Substracting one month is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXMonth(Date1,5);
	cout << "06-Substracting 5 months is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "07-Substracting one year is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXYear(Date1, 10);
	cout << "08-Substracting 10 Years is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXYearFaster(Date1, 10);
	cout << "09-Substracting 10 Years (faster) is : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "10-Substracting one Decade is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXDecade(Date1, 10);
	cout << "11-Substracting 10 Decades is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByXDecadeFaster(Date1, 10);
	cout << "12-Substracting 10 Decade (faster) is: " << Date1.day << "/" << Date1.month << "/" << Date1.year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Substracting One Century is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	Date1 = DecreaseDateByOneMillennuim(Date1);
	cout << "14-Substracting One Millennium is: " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;

	system("pause>0");
}

