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

bool ValidateDate(sDate Date)
{
	//return ((Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year) ? false : (Date.Month > 12) ? false : true));
	if (Date.Day < 1)
		return false;
	if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
		return false;
	if (Date.Month > 12)
		return false;
	else
		return true;
}
int main()
{
	sDate Date = ReadFullDate();

	if (ValidateDate(Date))
		cout << "\nYes ,Date Is Valid Date.\n";
	else
		cout << "\nNo , Date Is Not Valid Date.\n";

	system("pause>0");
	return 0;


}

