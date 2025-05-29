#include <iostream>
#include <cctype>
#include<vector>
#include <string>
using namespace std;

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	string AccountBalance = "";
};

stClientData ClinentData(stClientData Data)
{
	cout << "Please enter your Account Number?";
	getline(cin, Data.AccountNumber);

	cout << "\nPlease enter your Pin Code?";
	getline(cin, Data.PinCode);

	cout << "\nPlease enter your Name?";
	getline(cin, Data.Name);
	cout << "\nPlease enter your Pin Code?";
	getline(cin, Data.PinCode);

	cout << "\nPlease enter your Phone?";
	getline(cin, Data.Phone);

	cout << "\nPlease enter your Account Balance?";
	getline(cin, Data.AccountBalance);

	return Data;
}

vector<string>VectorOfClientData(stClientData ClientData)
{
	vector<string>vData;
	vData.push_back(ClientData.AccountNumber);
	vData.push_back(ClientData.PinCode);
	vData.push_back(ClientData.Name);
	vData.push_back(ClientData.Phone);
	vData.push_back(ClientData.AccountBalance);

	return vData;
}

string JoinString(vector<string>vString, string Delimeter)
{
	string S1 = "";
	for (string& S2 : vString)
	{
		S1 = S1+S2 + Delimeter;
	}
	S1 = S1.substr(0, S1.length() - Delimeter.length());
	return S1;
}


int main()
{
	stClientData Data;
	string ClientRecord = JoinString(VectorOfClientData(ClinentData(Data)), "#//#");

	cout << "Client Record For saveing is : \n";
	cout << ClientRecord << endl;

	system("pause>0");


}

