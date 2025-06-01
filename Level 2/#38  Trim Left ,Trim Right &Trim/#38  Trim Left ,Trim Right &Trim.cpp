#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S1 = " ";
    cout << "Please enter Your String?\n";
    getline(cin, S1);
    return S1;
}

string TrimLeft(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            S1.erase(0, i);
            return S1;
        }
    }
    return S1;
}

string TrimRight(string S1)
{

    for (int i = S1.length(); i >=0 ; i--)
    {
        if (S1[i-1] != ' ')
        {
            S1.erase(i, S1.length());
            return S1;
        }
    }
    return S1;
}

string Trim(string S1)
{
    S1 = TrimLeft(S1);
   S1 = TrimRight(S1);
    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\n\nString After Trim Left : " << TrimLeft(S1) << endl;

    cout << "\n\nString After Trim Rigth : " << TrimRight(S1);
    cout << "**";

    cout << "\n\nString After Trim : " << Trim (S1) ;

    cout << "**";


    system("pause>0");
    return 0;

}

