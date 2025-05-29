#include <iostream>
#include <cctype>
#include<vector>
#include <string>
#include<iomanip>
#include <fstream>
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
	// cin>>ws To remove all spaces its used when using cin and getline in loops
	getline(cin>>ws, Data.AccountNumber);

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

void AddingLineOfRecordToFile()
{
	char C = 'Y';
	do
	{
		system("cls");
		stClientData Client;
		fstream ClientDataFile;

		ClientDataFile.open("FileOfClients.text", ios::out | ios::app);

		cout << "Adding New Client :\n\n";
		Client = ReadClinentData(Client);

		string Line = ConvertRecordToLine(Client, "#//#");
		
		if(ClientDataFile.is_open())
		{
			ClientDataFile << Line << endl;
		}

		cout << "\n\nDo You Want To Add More Clients?";
		cin >> C;
	} while (toupper(C) == 'Y');

}

int main()
{
	AddingLineOfRecordToFile();

	system("pause>0");

}
