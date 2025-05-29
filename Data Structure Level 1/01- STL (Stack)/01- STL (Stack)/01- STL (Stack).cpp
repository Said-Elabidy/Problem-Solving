#include <iostream>
#include<stack>
using namespace std;


int main()
{
	stack <int > stkNumbers;

	stkNumbers.push(10);
	stkNumbers.push(20);
	stkNumbers.push(30);
	stkNumbers.push(40);
	stkNumbers.push(50);


	cout << "Stack contains " << stkNumbers.size() << " Numbers\n\n";

	while (!stkNumbers.empty())
	{
		cout << stkNumbers.top() << endl;


		stkNumbers.pop();
	}


	system("pause>0");
}

