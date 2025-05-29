#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a structure for representing a date
struct Date {
    short Year;
    short Month;
    short Day;
};

// Function to split a string based on a delimiter
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos); // Extract the word

        if (!sWord.empty()) {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length()); // Move to next word
    }

    if (!S1.empty()) {
        vString.push_back(S1); // Add the last word of the string
    }

    return vString;
}

// Function to replace all occurrences of a word in a string
string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo) {
    size_t pos = S1.find(StringToReplace);

    while (pos != string::npos) {
        S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace); // Find next occurrence
    }

    return S1;
}

// Function to convert a Date structure to a string in "dd/mm/yyyy" format
string DateToString(Date Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

// Function to convert a string in "dd/mm/yyyy" format to a Date structure
Date StringToDate(string DateString) {
    Date Date;
    vector<string> vDate = SplitString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

// Function to format a Date structure according to a specified format string
string FormatDate(Date Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDateString = DateFormat;

    FormattedDateString = ReplaceWordInString(FormattedDateString, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

// Function to prompt the user and read a string representing a date
string ReadStringDate(string Message) {
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);

    return DateString;
}

int main() {
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    Date Date = StringToDate(DateString);

    cout << "\n" << FormatDate(Date) << "\n";
    cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;
}
