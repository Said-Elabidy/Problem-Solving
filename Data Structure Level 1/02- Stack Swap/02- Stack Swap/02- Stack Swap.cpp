#include <iostream>
#include <stack>

using namespace std;


int main()
{
	stack <int> stkNum1;
	stack <int>stkNum2;

	stkNum1.push(10);
	stkNum1.push(20);
	stkNum1.push(30);
	stkNum1.push(40);
	stkNum1.push(50);

	stkNum2.push(60);
	stkNum2.push(70);
	stkNum2.push(80);
	stkNum2.push(90);
	stkNum2.push(100);

	stkNum1.swap(stkNum2);

	cout << "stack 1 = ";


	while (!stkNum1.empty())
	{
		cout << stkNum1.top() << " ";
		stkNum1.pop();
	}

	cout << "\n\nstack 2 = ";

	while (!stkNum2.empty())
	{

		cout << stkNum2.top() << " ";
		stkNum2.pop();
	}

	system("pause>0");



}

