#include <iostream>
#include <vector>
using namespace std;

int RandomNumber(int From, int To)
{
    int Num = 0;
    Num = rand() % (To - From + 1) + From;
    return Num;
}

int NumToSearchFor()
{
    int Num = 0;
    do
    {
        cout << "\n\n Please enter a Number to Look for it in Matrix ?";
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
            Matrix[j][i] = RandomNumber(1, 20);
        }
    }
}

bool IsNumberInMatrix(int Matrix[3][3], int Rows, int Colms, int NumToCheck)
{
    int Counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Matrix[j][i] == NumToCheck)
            {
                return true;

            }
        }
    }
    return false;
}

void IntersectedNumberInTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Colms,vector<int>&vIntersectedNums)
{
    
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (IsNumberInMatrix(Matrix2, Rows, Colms, Matrix1[j][i]))
            {
                vIntersectedNums.push_back(Matrix1[j][i]);
            }
        }
    }
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

void PrintArra(vector<int>&vIntersectedNums)
{
    for (int &i :vIntersectedNums)
    {
       cout << i << "     ";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3], Matrix2[3][3];
    vector<int>vIntersectedNums;

    cout << "Matrix 1 :\n\n";
    FillMatrix(Matrix1, 3, 3);
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix 2 :\n\n";
    FillMatrix(Matrix2, 3, 3);
    PrintMatrix(Matrix2, 3, 3);

    cout << "\n\nIntersected Numbers Are :-\n";
    IntersectedNumberInTwoMatrix(Matrix1, Matrix2, 3, 3, vIntersectedNums);
    PrintArra(vIntersectedNums);



    system("pause>0");
    return 0;

}
