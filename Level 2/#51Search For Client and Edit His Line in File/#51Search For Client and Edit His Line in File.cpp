#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.text";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
    bool MarkForEdit = false;
};

vector<string> SplitString(string S1, string Delim) 
{
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (!sWord.empty()) {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (!S1.empty())
    {
        vString.push_back(S1);
    }

    return vString;
}

stClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
    stClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Separator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // Convert string to double

    return Client;
}

string ConvertRecordToLine(stClient Client, string Separator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

vector<stClient> LoadClientsDataFromFile(string FileName) 
{
    vector<stClient> vClients;
    ifstream MyFile(FileName, ios::in);  //read Mode

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            stClient Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }

    return vClients;
}

stClient EditClientRecord(stClient& ClientRecord)
{
    cout << "Please enter Pin Code ? ";
    getline(cin>>ws, ClientRecord.PinCode);
    cout << "\nPlease enter New Name ? ";
    getline(cin, ClientRecord.Name);
    cout << "\n Please enter New Phone? ";
    getline(cin, ClientRecord.Phone);
    cout << "\n Please enter New Account Balance? ";
    cin >> ws >> ClientRecord.AccountBalance;
    return ClientRecord;
}
void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, const vector<stClient>& vClients, stClient& Client)
{
    for (const stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForEditByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForEdit = true;
            return true;
        }
    }
    return false;
}

vector<stClient> SaveClientsDataToFile(string FileName,  vector<stClient>& vClients)
{
    fstream MyFile(FileName,ios::out);

    if (MyFile.is_open())
    {
        for ( stClient& C : vClients)
        {
            if (C.MarkForEdit==true)
            {
                string DataLine = ConvertRecordToLine(EditClientRecord(C));
                MyFile << DataLine << endl;
            }
            else
            {
                string DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }

    return vClients;
}

bool EditClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to Edit this client Record ? (y/n): ";
        cin >>ws>> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            MarkClientForEditByAccountNumber(AccountNumber, vClients);
            vClients = SaveClientsDataToFile(ClientsFileName, vClients); // Refresh Clients
            cout << "\n\nClient Data Has been updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }

    return false;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

int main() 
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    EditClientByAccountNumber(AccountNumber, vClients);
    system("pause>0");
    return 0;
}
