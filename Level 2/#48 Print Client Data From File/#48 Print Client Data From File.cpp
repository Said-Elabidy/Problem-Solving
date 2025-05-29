#include <iostream>
#include <cctype>
#include<vector>
#include <string>
#include<iomanip>
#include <fstream>
using namespace std;


const string FileName = "FileOfClients.text";

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

vector<string>SplitString(string S1, string Delemiter="#//#")
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

void PrintClientRecord(stClientData Client)
{
	cout << "| " << left << setw(20) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(20) << Client.Name;
	cout << "| " << left << setw(15) << Client.Phone;
	cout << "| " << left << setw(15) << Client.AccountBalance;
}

void PrintAllClientData(vector<stClientData>Clients)
{
	cout << "\t\t\t\t\t" << "Clients ("<<Clients.size()<<")Clients list" << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout<< "| " << left << setw(20) << "Account Number";
	cout<< "| " << left << setw(10) << "Pin Code";
	cout<< "| " << left << setw(20) << "Client Name";
	cout<< "| " << left << setw(15) << "Phone";
	cout<< "| " << left << setw(15) << "Balance" << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl<<endl;
	for (stClientData& Client : Clients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
}


int main()
{
	
	vector<stClientData>Clinets;
	Clinets = LoadClientsDataFromFile(FileName);
	PrintAllClientData(Clinets);
	system("pause>0");

}
