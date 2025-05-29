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


int main()
{
	cout << "Date 1 :\n";
	sDate Date1 = ReadFullDate();

	cout << "Date 2 :\n";
	sDate Date2 = ReadFullDate();

	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes,Date 1 is After Date 2.\n";
	else
		cout << "\nNo,Date 1 is Not After Date 2.\n";
	system("pause>0");

}

