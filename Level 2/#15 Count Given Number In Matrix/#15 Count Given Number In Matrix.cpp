#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int Num = 0;
    Num = rand() % (To - From + 1) + From;
    return Num;
}

int NumToCount()
{
    int Num = 0;
    do
    {
        cout << "\n\n Please enter a Number to Count in Matrix ?";
        cin >> Num;
    } while (Num < 0);
    return Num;
}

void FillMatrix(int Matrix[3][3], int Rows, int Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            Matrix[j][i] = RandomNumber(1, 10);
        }
    }
}

int CountOfNumberInMatrix(int Matrix[3][3], int Rows, int Colms, int NumToCheck)
{
    int Counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Matrix[j][i] == NumToCheck)
            {
                Counter++;
           }
        }
    }
    return Counter;
}

void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            printf("%0*d     ", 2, Matrix[j][i]);
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
  int   Matrix[3][3];
    cout << "\nMatrix 1: \n";

    FillMatrix(Matrix, 3, 3);

    PrintMatrix(Matrix, 3, 3);

    int NumberGiven = NumToCount();
    int Count = CountOfNumberInMatrix(Matrix, 3, 3,NumberGiven);

    printf("\n\nNumber %d count in Matrix is %d Time(s).\n", NumberGiven, Count);

    system("pause>0");
    return 0;

}

