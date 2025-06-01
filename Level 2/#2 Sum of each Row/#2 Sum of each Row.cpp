#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int Num = 0; 
	Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Coln,vector<int>&vSum)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
			Sum = Sum + Matrix[i][j];
		}
		vSum.push_back(Sum);
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Coln, vector<int>vSum)
{
	cout << "\nThe Following is 3x3 Random Matrix :\n\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Coln; j++)
		{
			cout << setw(3) << Matrix[i][j] << "	  ";
		}
		cout << endl;
	}

	cout << "\n\nThe Following is Sum of Each Row : \n";
	for (int& Sum : vSum)
	{
		static int Count = 1;
		printf("Row %d Sum = %d \n", Count, Sum);
		Count++;
	}
}
int main()
{
	srand((unsigned)time(NULL));

	vector<int>vSum;
	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3, vSum);
	PrintMatrix(Matrix, 3, 3, vSum);

	system("pause>0");
	return 0;

}


