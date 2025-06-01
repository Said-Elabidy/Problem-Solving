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

string ConvertRecordToLine(stClientData Client, string Delimeter = "#//#")
{
	string S1 = "";
	string S2 = "";
	S1 = S1 + Client.AccountNumber+Delimeter;
	S1 = S1 + Client.PinCode + Delimeter + Client.Name + Delimeter;
	S1 = S1 + Client.Phone + Delimeter	+to_string(Client.AccountBalance);
	return S1;
}

vector<string>SplitString(string S1, string Delimiter = "#//#")
{
	vector<string>Words;
	short Position = 0;

	string Token = "";

	while ((Position = S1.find(Delimiter)) != std::string::npos)
	{
		Token = S1.substr(0, Position);
		if (Token != "")
		{
			Words.push_back(Token);
		}
		S1.erase(0, Position + Delimiter.length());
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

vector<string>ConvertFileLinesToVectors(string FileName)
{
	string Line="";
	vector<string>vFileLines;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			vFileLines.push_back(Line);
		}
		MyFile.close();
	}
	return vFileLines;
}

bool AskBeforDeleteLine()
{
	char Ask = 'n';
	cout << "Are you Sure that you want to Delete this Record?(y,n)\n";
	cin >> Ask;
	return(Ask == 'y' ? true : false);
}

void DeleteLineFromFile(vector<string>vFileLines, string Line,string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for(string &S1:vFileLines)
		{
			if (S1 != Line)
			{
				MyFile<<S1<<endl;
			}
		}
		MyFile.close();
	}
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

bool SearchForClient(string AccountNum, stClientData& Client)
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

void SearchForRecordAndDeleteIt(string AccountNumber)
{
	stClientData Client;

	if (SearchForClient(AccountNumber, Client))
	{
		PrintClientData(Client);
		bool Ask =AskBeforDeleteLine();

		if (Ask==true)
		{
			DeleteLineFromFile(ConvertFileLinesToVectors(FileName), ConvertRecordToLine(Client), FileName);
			cout << "\n\nThis Client Already Deleted.\n";
		}
		else
		{
			cout << "\n\nThis Client Still in the File\n";
		}
	}
	else
		cout << "\n\nSorry This Account is not excite";

}

int main()
{
	string AccountNum = ReadAccountNumber();
	SearchForRecordAndDeleteIt(AccountNum);
	system("pause>0");


}
