#include <iostream>
#include <queue>

using namespace std;





int main()
{
	queue<int> qNum;

	qNum.push(10);
	qNum.push(20);
	qNum.push(30);
	qNum.push(40);

	cout << "Count : " << qNum.size() << endl;

	cout << "Front : " << qNum.front() << endl;

	cout << "Back : " << qNum.back() << endl;

	while (!qNum.empty())
	{
		cout << qNum.front() << endl;

		qNum.pop();
	}

	system("pause>0");

}

