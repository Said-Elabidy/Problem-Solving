#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

int CalculateReversedDigits(int Num)
{
	int Remainder = 0;
	int Num2 = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;
		Num = Num / 10;
		Num2 = Num2 * 10 + Remainder;
	}

	return Num2;
}

void CheckPalindromeNum(int Num)
{
	int ReversedNum = CalculateReversedDigits(Num);
	if (Num == ReversedNum)
	{
		cout << "Yes, its a Palindrome Number . " << endl;
	}
	else 
		cout << "No, its not aPalindrome Number . " << endl;

}

int main()
{
	CheckPalindromeNum(ReadPositiveNumber("Please enter a Positive Number ?"));
	return 0;
}