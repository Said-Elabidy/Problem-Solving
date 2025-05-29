#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int Num = 0;
	Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void printMatrix(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			cout << setw(3) << Matrix[i][j] << "    ";
		}
		cout << endl;
	}

}

int SumOfEachRow(int Matrix[3][3], int Rows, int Colms)
{
	int Sum = 0;
	for (int i = 0; i < Colms; i++)
	{
		Sum += Matrix[Rows][i];
	}
	return Sum;
}

void SumOfEachRowInMatrixInArray(int Arra[3],int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < 3; i++)
	{
		Arra[i] =  SumOfEachRow(Matrix, i, Colms);
	}
}

void PrintSum(int Matrix[3][3], int Rows, int Colms,int Arra[3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("Row %d Sum = %d\n", i + 1, Arra[i]);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	int Arra[3];
	cout << "Matrix 3x3 With Random Numbers:\n";
	FillMatrixWithRandomNumbers( Matrix , 3,3);
	printMatrix(Matrix, 3, 3);

	cout << "\nSum of each Row : \n";
	SumOfEachRowInMatrixInArray(Arra, Matrix, 3, 3);
	PrintSum(Matrix, 3, 3,Arra);

	system("pause>0");
	return 0;
}
