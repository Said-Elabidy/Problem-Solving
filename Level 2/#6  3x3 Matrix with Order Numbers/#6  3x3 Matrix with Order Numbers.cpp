#include <iostream>
#include<iomanip>
using namespace std;

void FillMatrixWithOrderNumbers(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			static int Num = 1;
			Matrix[i][j] = Num;
			Num++;
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			cout << setw(3) << Matrix[i][j]<<"    ";
		}
		cout << endl;
	}
}

int main()
{
	int Matrix[3][3];
	cout << "3x3 Matrix fill with Order Numbers :\n\n";
	
	FillMatrixWithOrderNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	system("pause>0");
	return 0;
}

