#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

#include <vector>
#include <string>

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    // Use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != string::npos) 
    {
        // Extract the word before the delimiter
        sWord = S1.substr(0, pos);

        // Check if the extracted word is not empty before adding to vector
        if (!sWord.empty())
        {
            vString.push_back(sWord);
        }

        // Erase the processed part including the delimiter
        S1.erase(0, pos + Delim.length());
    }

    // Add the last word of the string if it's not empty
    if (!S1.empty())
    {
        vString.push_back(S1);
    }

    return vString;
}

stDate ConvertStringToDate(string StringOfDate)
{
    stDate Date;
    vector<string>vDate;

    vDate = SplitString(StringOfDate, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string ConvertDateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReadStringDate(string Ask)
{
    cout << Ask << endl;
    string Date;
    getline(cin >> ws, Date);
    return Date;
}
int main()
{
    string Date = ReadStringDate("Please enter a date DD/MM/YYYY ?");

    stDate sDate = ConvertStringToDate(Date);

    cout << "\nDay : " << sDate.Day << endl;
    cout << "Month : " << sDate.Month << endl;
    cout << "Year : " << sDate.Year << endl;

    cout << "\n\nYou Enterd : " << ConvertDateToString(sDate) << endl;
    system("pause>0");

}

