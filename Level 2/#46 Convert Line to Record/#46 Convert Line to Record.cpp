#include <iostream>
#include <cctype>
#include<vector>
#include <string>
#include<iomanip>
using namespace std;


struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

stClientData ReadClinentData(stClientData Data)
{
	cout << "Please enter your Account Number?";
	getline(cin, Data.AccountNumber);

	cout << "\nPlease enter your Pin Code?";
	getline(cin, Data.PinCode);

	cout << "\nPlease enter your Name?";
	getline(cin, Data.Name);

	cout << "\nPlease enter your Phone?";
	getline(cin, Data.Phone);

	cout << "\nPlease enter your Account Balance?";
	cin >> Data.AccountBalance;

	return Data;
}

vector<string>SplitString(string S1, string Delmiter)
{
	vector<string>Words;
	short Position = 0;

	string Token = "";

	while ((Position = S1.find(Delmiter)) != std::string::npos)
	{
		Token = S1.substr(0, Position);
		if (Token != "")
		{
			Words.push_back(Token);
		}
		S1.erase(0, Position + Delmiter.length());
	}
	if (S1 != "")
	{
		Words.push_back(S1);
	}
	return Words;
}


string ConvertRecordToLine(stClientData CData, string Delimeter)
{
	string Line = "";
	Line += CData.AccountNumber + Delimeter;
	Line += CData.PinCode + Delimeter;
	Line += CData.Name + Delimeter;
	Line += CData.Phone + Delimeter;
	Line += to_string(CData.AccountBalance);
	return Line;
}

stClientData ConvertLineToRecord(string Line, string Delimeter)
{
	stClientData Client;
	short Position = 0;
	vector<string>vClient;
	vClient = SplitString(Line, Delimeter);

	Client.AccountNumber = vClient[0];
	Client.PinCode       = vClient[1];
	Client.Name          = vClient[2];
	Client.Phone         = vClient[3];
	Client.AccountBalance =stoi(vClient[4]);

	return Client;
}

void PrintRecrod(stClientData Client)
{
	cout <<setw(20)<< "Account Number " << setw(10) << ": " << Client.AccountNumber << endl;
	cout <<setw(20)<< "Account Pin Code " << setw(10) << ": " << Client.PinCode << endl;
	cout <<setw(20)<< "Account Name " << setw(10) << ": " << Client.Name << endl;
	cout <<setw(20)<< "Account Phone " << setw(10) << ": " << Client.Phone << endl;
	cout <<setw(20)<< "Account Balance " << setw(10) << ": " << Client.AccountBalance << endl;

}
int main()
{
	stClientData Client;

	Client = ReadClinentData(Client);
	cout << "\n\nLine of Recrod : \n\n";

	string Line= ConvertRecordToLine(Client,"#//#");
	cout << Line << endl;

	cout << "Record of client :\n\n";
	PrintRecrod(ConvertLineToRecord(Line, "#//#"));

	system("pause>0");

}

