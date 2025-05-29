#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNum()
{
	int Num = 0;
	do
	{
		cout << "Please enter Choose one (enter Num From 1 to 4 )" << endl;
		cout << "\n1) Small Letter.\n" << "\n2) Capital Letter.\n" << "\n3) Special Character.\n" << "\n4) Digit.\n"<< "\n5) All.\n\n";
		cin >> Num;
		cout << endl;
	} while (Num > 5 || Num < 1);
		return Num;
}
int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

enum enRandom { Small_letter = 1, Capital_letter = 2, Special_character = 3, Digit = 4 , All=5};

enRandom Random(int Num)
{
	if (Num == 1)
		return enRandom::Small_letter;
	else if (Num == 2)
		return enRandom::Capital_letter;
	else if (Num == 3)
		return enRandom::Special_character;
	else if (Num == 4)
		return enRandom::Digit;
	else
		return enRandom::All;
}

void PrintRandom(enRandom Random)
{
	if (Random == enRandom::Small_letter)
		cout << (char)RandomNumber(97, 122) << endl;
	else if (Random == enRandom::Capital_letter)
		cout << (char)RandomNumber(65, 90) << endl;
	else if (Random == enRandom::Special_character)
		cout << (char)RandomNumber(33, 47) << endl;
	else if (Random == enRandom::Digit)
		cout << RandomNumber(1, 10) << endl;
	else
	{
		cout << (char)RandomNumber(97, 122) << endl;
		cout << (char)RandomNumber(65, 90) << endl;
		cout << (char)RandomNumber(33, 47) << endl;
		cout << RandomNumber(1, 10) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	PrintRandom(Random(ReadNum()));
	return 0;

}

