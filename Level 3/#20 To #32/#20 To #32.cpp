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

sDate IncreaseDateByOneDay(sDate &Date)
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

sDate IncreaseDateByXDay(sDate& Date, short Days)
{
	for (int i = 0; i < Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByOneWeek(sDate& Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;

}

sDate IncreaseDateByXWeek(sDate& Date, short Week)
{
	for (int i = 0; i < Week; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;

}

sDate IncreaseDateByOneMonth(sDate& Date)
{
	if (IsLastMonthInYear(Date.Month))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
		Date.Month++;
	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Month > DaysInMonth)
	{
		Date.Month = DaysInMonth;
	}

	return Date;
}

sDate IncreaseDateByXMonth(sDate& Date, short Months)
{
	for (int i = 0; i < Months; i++)
	{
		Date=IncreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate IncreaseDateByOneYear(sDate& Date)
{
	Date.Year++;
	return Date;
}

sDate IncreasDateByXYears(sDate& Date,short Years)
{
	for (int i = 0; i < Years; i++)
	{
		Date=IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearFaster(sDate& Date, short Years)
{
	Date.Year += Years;
	return Date;
}

sDate IncreaseDateByOneDecade(sDate &Date)
{
	IncreaseDateByXYearFaster(Date, 10);
	return Date;
}

sDate IncreaseDateByXDecade(sDate& Date, short Decade)
{
	for (int i = 0; i < Decade; i++)
	{
	Date=	IncreaseDateByOneDecade(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadeFaster(sDate& Date, short Decade)
{
	Date.Year = Date.Year + (Decade * 10);
	return Date;
}

sDate IncreaseDateByOneCentury(sDate& Date)
{
	for (int i = 0; i < 10; i++)
	{
		Date=IncreaseDateByXDecadeFaster(Date, 1);
	}
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate& Date)
{
	for (int i = 0; i < 10; i++)
	{
		Date=IncreaseDateByOneCentury(Date);
	}
	return Date;
}

int main()
{
	sDate Date1 = ReadFullDate();
	cout << "\nDate After : \n\n";

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByXDay(Date1,10);
	cout << "02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByXWeek( Date1,10);
	cout << "04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByXMonth(Date1, 5);
	cout << "06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreasDateByXYears(Date1, 10);
	cout << "08-Adding 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByXYearFaster(Date1, 10);
	cout << "09-Adding 10 Years (faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "10-Adding one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByXDecade(Date1,10);
	cout << "11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByXDecadeFaster(Date1, 10);
	cout << "12-Adding 10 Decade (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "14-Adding One Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;


	system("pause>0");
}


