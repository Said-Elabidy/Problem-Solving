#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int Num = 0;
    Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrix(int Matrix[3][3], int Rows, int Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            Matrix[j][i] = RandomNumber(1, 20);
        }
    }
}

int MaxNumberInMatrix(int Matrix[3][3], int Rows, int Colms)
{
    int MaxNum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if(Matrix[j][i]>MaxNum)
            {
                MaxNum = Matrix[j][i];
            }
        }
    }
    return MaxNum;
}

int MinNumberInMatrix(int Matrix[3][3], int Rows, int Colms)
{
    int MinNum = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (MinNum > Matrix[j][i])
            {
                MinNum = Matrix[j][i];
            }

        }
        
    }
    return MinNum;
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
void PrintMaxAndMixNumberInMatrix(int Max, int Min)
    {
        printf("\nMaximum Number in Matrix is : %d\n\n",Max);
        printf("\nMinimum Number in Matrix is : %d\n\n", Min);

    }
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];

    cout << "Matrix 1 :\n\n";
    FillMatrix(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);

   
    PrintMaxAndMixNumberInMatrix(MaxNumberInMatrix(Matrix, 3, 3), MinNumberInMatrix(Matrix, 3, 3));


    system("pause>0");
    return 0;

}
