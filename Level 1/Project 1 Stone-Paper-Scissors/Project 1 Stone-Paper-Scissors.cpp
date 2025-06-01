#include <iostream>
using namespace std;
enum enGameChoices { Stone = 1, Paper = 2, Scissor = 3 };

enum enRoundResualts { PlayerWin = 1, ComputerWin = 2, Draw = 3 };

int ReadPositiveNumber()
{
	int Num = 0;
	do
	{
		cout << "How Many Rounds 1 To 10 ?\n";
		cin >> Num;
		cout << endl; 
	} while (Num < 1 || Num > 10);
		return Num;
}

int RandomNum(int From , int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

enGameChoices ReadPlayerChoice()
{
	int PlayersChoice = 0;
	do
	{
		cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissor. ?\n";
		cin >> PlayersChoice;
	} while (PlayersChoice > 3 || PlayersChoice < 1);
	return enGameChoices(PlayersChoice);
}

enGameChoices ComputerChoice()
{
	int Num = RandomNum(1, 3);
	return enGameChoices(Num);
}

enRoundResualts RoundResualtCases(enGameChoices Player , enGameChoices Computer)
{
	enRoundResualts RoundResualt;

	 if (Player == enGameChoices::Paper && Computer == enGameChoices::Stone)
		return RoundResualt=enRoundResualts::PlayerWin;
	else if (Player == enGameChoices::Stone && Computer == enGameChoices::Scissor)
		return RoundResualt = enRoundResualts::PlayerWin;
	else if (Player == enGameChoices::Scissor && Computer == enGameChoices::Paper)
		return RoundResualt = enRoundResualts::PlayerWin;
	else if (Computer == enGameChoices::Paper && Player == enGameChoices::Stone)
		return RoundResualt = enRoundResualts::ComputerWin;
	else if (Computer == enGameChoices::Stone && Player == enGameChoices::Scissor)
		return RoundResualt = enRoundResualts::ComputerWin;
	else if (Computer == enGameChoices::Scissor && Player == enGameChoices::Paper)
		return RoundResualt = enRoundResualts::ComputerWin;
	else 
		 return RoundResualt = enRoundResualts::Draw;
}

string ReplaceChoiceToWord(enGameChoices Choice)
{
	string ChoiceResualt = "";
	if (Choice == enGameChoices::Paper)
		return ChoiceResualt = "Paper.";
	else if (Choice == enGameChoices::Stone)
		return ChoiceResualt = "Stone.";
	else 
		return ChoiceResualt = "Scissor.";
}

string RoundWinner(enRoundResualts Result)
{
	string Winner = "";
	if (Result == enRoundResualts::ComputerWin)
		return Winner = "Computer";
	else if (Result == enRoundResualts::PlayerWin)
		return Winner = "Player";
	else
		return Winner = "No Winner";
}

enRoundResualts OneRound()
{
	enGameChoices PlayerChoice = ReadPlayerChoice();
	enGameChoices Computer = ComputerChoice();
	enRoundResualts RoundResualt = RoundResualtCases(PlayerChoice, Computer);
	string Player = ReplaceChoiceToWord(PlayerChoice);
	string ComputerChoice = ReplaceChoiceToWord(Computer);
	string Winner = RoundWinner(RoundResualt);
	if (RoundResualt == enRoundResualts::ComputerWin)
	{
		cout << system("Color 4f");
		cout << "\a";
		cout << "Player Choice : " << Player << endl;
		cout << "Computer Choice : " << ComputerChoice << endl;
		cout << "Round Winner : " << Winner <<endl;

		return enRoundResualts::ComputerWin;
	}
	else if (RoundResualt == enRoundResualts::PlayerWin)
	{
		cout << system("Color 2f");
		cout << "Player Choice : " << Player << endl;
		cout << "Computer Choice : " << ComputerChoice << endl;
		cout << "Round Winner : " << Winner<< endl;
		return enRoundResualts::PlayerWin;

	}
	else
	{
		cout << system("Color 6f");
		cout << "Player Choice : " << Player << endl;
		cout << "Computer Choice : " << ComputerChoice << endl;
		cout << "Round Winner : "<< Winner << endl;
		return enRoundResualts::Draw;

	}
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void Game()
{
	int ComputerWin = 0, Playerwin = 0, Draw = 0;
	char Ask =0;
	do
	{
		ResetScreen();
		int Num = ReadPositiveNumber();

		for (int i = 1; i <= Num; i++)
		{
			cout << "Round " << i << " Begins : \n\n";
			cout << "____________Round [" << i <<"]____________\n" << endl;
			enRoundResualts Round = OneRound();
			if (Round == enRoundResualts::ComputerWin)
			{
				ComputerWin = ComputerWin + 1;
			}
			else if (Round == enRoundResualts::PlayerWin)
			{
				Playerwin = Playerwin + 1;
			}
			else if (Round == enRoundResualts::Draw)
			{
				Draw = Draw + 1;
			}
		}
		cout << "_________________Game Over_________________\n\n";
		cout << "_________________Final Result_________________\n\n";
		cout << "Total Win : " << Playerwin << endl;
		cout << "Total Loose : " << ComputerWin << endl;
		cout << "Total Draws : " << Draw << endl << endl;
		cout << "Do You Want to Play again ? [y]:For Yes , [n]:For No" << endl;
		cin >> Ask;
	} while (Ask == 'y'||Ask=='Y');
}

int main()
{
	srand((unsigned)time(NULL));

	Game();

	system("pause>0");
	return 0;

}

