#include <iostream>
#include <cctype>
#include<vector>
#include <string>
#include<iomanip>
#include <fstream>
using namespace std;


const string FileName = "FileOfClients.text";

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter Account Number ?\n";
	getline(cin, AccountNumber);
	return AccountNumber;
}

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

vector<string>SplitString(string S1, string Delemiter = "#//#")
{
	vector<string>Words;
	short Position = 0;

	string Token = "";

	while ((Position = S1.find(Delemiter)) != std::string::npos)
	{
		Token = S1.substr(0, Position);
		if (Token != "")
		{
			Words.push_back(Token);
		}
		S1.erase(0, Position + Delemiter.length());
	}
	if (S1 != "")
	{
		Words.push_back(S1);
	}
	return Words;
}

stClientData ConvertLineToRecord(vector<string>vClient)
{
	stClientData Clients;
	Clients.AccountNumber = vClient[0];
	Clients.PinCode = vClient[1];
	Clients.Name = vClient[2];
	Clients.Phone = vClient[3];
	Clients.AccountBalance = stod(vClient[4]);
	return Clients;
}

vector<stClientData>LoadClientsDataFromFile(string FileName)
{
	stClientData Client;
	vector<stClientData> vClients;
	string Line = "";

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(SplitString(Line));
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}


void PrintClientData(stClientData Client)
{
	cout << "The Following Are Clients Details:\n\n";
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code : " << Client.PinCode << endl;
	cout << "Name : " << Client.Name << endl;
	cout << "Phone : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool SearchForClient(string AccountNum,stClientData &Client)
{
	vector<stClientData>vClients;
	vClients = LoadClientsDataFromFile(FileName);
	for (stClientData& C : vClients)
	{
		if (C.AccountNumber == AccountNum)
		{
			Client = C;
			return true;
		}
	}
	return false;
}


int main()
{
	string AccountNum = ReadAccountNumber();
	stClientData Client;

	if (SearchForClient(AccountNum, Client))
	{
		PrintClientData(Client);
	}
	else
		cout << "\n\nSorry This Account is not excite";
	system("pause>0");


}

