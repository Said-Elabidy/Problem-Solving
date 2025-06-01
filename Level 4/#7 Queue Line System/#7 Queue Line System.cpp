#include <iostream>
#include "clsQueueLine.h"

using namespace std;


int main()
{
	clsQueueLine PayBills("A0", 10);

	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();

	PayBills.PrintInfo();

	PayBills.PrintTicketsLineRTL();
	PayBills.PrintTicketsLineLTR();

	PayBills.PrintAllTickets();

	PayBills.ServeNextClient();

	cout << "\n\n After Serve One Cleint :\n\n\n";
	PayBills.PrintInfo();
	PayBills.PrintAllTickets();


	system("pause>0");


}
