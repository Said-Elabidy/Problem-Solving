#include <iostream>
using namespace std;


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

struct sDate
{
	short Year;
	short Month;
	short Day;
};

bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year == Date2.Year)
	{
		short date1 = NumberOfDaysFromTheBegeiningofYear( Date1.Year,Date1.Month,Date1.Day);
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

short ReadDaysToAdd()
{
	short Days;
	cout << "\nHow many days to add? ";
	cin >> Days;
	return Days;
}


int main()
{
	cout << "	Date 1 \n";
	sDate Date1 = ReadFullDate();
	cout << "\n	Date 2 \n";
	sDate Date2 = ReadFullDate();

	if (IsDate1BeforDate2((Date1), (Date2)))
	{
		cout << "Yes, Date 1 Is less than date 2 .\n";
	}
	else
		cout << "No, Date 1 Is Not less than date 2 .\n";


	system("pause>0");
	return 0;
}

