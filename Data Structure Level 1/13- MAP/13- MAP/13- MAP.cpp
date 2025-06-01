#include <iostream>
#include<map>
using namespace std;


int main()
{
	map <string, int > StudentsGrade;

	StudentsGrade["Ali"] = 81;
	StudentsGrade["Gamal"] = 87;
	StudentsGrade["Said"] = 98;


	cout << "Printing Students Names and Grades :-\n\n";
	for (auto& Grade : StudentsGrade)
	{
		cout << "Student Name : " << Grade.first << ", Grade : " << Grade.second << endl;
	}

	cout << "\n\nSearch for Gamal Grade :-" << endl;

	if (StudentsGrade.find("Gamal") != StudentsGrade.end())
	{
		cout << "Student Name : Gamal " << ", Grade : " << StudentsGrade["Gamal"] << endl;
	}
	else
		cout << "Student not Found :-(\n\n";

	cout << "\n\nSearch for Omar Grade :-" << endl;

	if (StudentsGrade.find("Omar") != StudentsGrade.end())
	{
		cout << "Student Name : Omar " << ", Grade : " << StudentsGrade["Omar"] << endl;
	}
	else
		cout << "Student not Found :-(\n\n";

	system("pause>0");
}

