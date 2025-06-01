#include <iostream>
#include<cstdlib>
using namespace std;

enum enOperationType {Add=1,Sub=2,Multi=3,Dev=4,OpMix=5};

enum enLevel {Easy=1,Medium=2,Hard=3,Mix=4};

struct stQuestion
{
	short FirstNum = 0;
	short SecondNum = 0;
	enOperationType OperationType;
	enLevel Level;
	short CorrectAns;
	short UserAns;
};

struct stGameVariables
{
	stQuestion QuestionList[100];
	enOperationType OperationType;
	enLevel Level;
	short NumberOfQuestions=0;
	short CorrectAns=0;
	short WrongAns = 0;
	bool IsPass = false;
};

short ReadNumOfQuestion()
{
	short Num = 0;
	do
	{
		cout << "Please enter Number of Questions ?(From 1 to 10 )\n";
		cin >> Num;
	} while (Num < 1 || Num>10);
	return Num;
}

int RandomNum(int From, int To)
{
	int Num = 0;
	Num = rand() % (To - From + 1) + From;
	return Num;
}

int ReadPositiveNum(string Ask)
{
	int Num = 0;
		do
		{
			cout << Ask << endl;
			cin >> Ask;
		} while (Num <= 0);
		return Num;
}

enOperationType ChooseOperationType()
{
	short Num = 0;
	do{
		cout << "Please enter Operation Type ? [1]:Add [2]:Sub [3]:Multi [4]:Dev [5]:Mix\n";
		cin >> Num;
	} while (Num < 1 || Num> 5 );
	return (enOperationType) Num;
}

enLevel ChooseLevel()
{
	short Num = 0;
	do {
		cout << "Please enter Level of Questions ? [1]:Easy [2]:Medium [3]:Hard [4]:Mix \n";
		cin >> Num;
	} while (Num < 1 || Num>4);
	return (enLevel) Num;
}

void IsPass(stGameVariables Info)
{
	if (Info.CorrectAns >= Info.WrongAns)
	{
		cout << "congratulation,You Passed the Quiz :-) \n";
	}
	else
	{
		cout << "Sorry,You Failed at the Quiz :-( \n";
	}
}

char OP(enOperationType OperationType, int Num)
{
	char OP;
	if (OperationType == enOperationType::Add)
		return OP = '+';
	else if (OperationType == enOperationType::Dev)
		return OP = '/';
	else if (OperationType == enOperationType::Multi)
		return OP = '*';
	else if (OperationType == enOperationType::Sub)
		return OP = '-';
}

short ReadUserAnswer()
{
	short Num;
	cin >> Num;
	return Num;
}

short Calculator(int Num1, int Num2, enOperationType OP)
{
	if (OP == enOperationType::Add)
		return (Num1 + Num2);
	else if (OP == enOperationType::Sub)
		return (Num1 - Num2);
	else if (OP == enOperationType::Multi)
		return (Num1 * Num2);
	else 
		return (Num1 / Num2);
}

void ResetScreen()
{
	system("color 0f");
	system("cls");
}

enOperationType GetRandomOperationType()
{
    int Op = RandomNum(1, 4);
    return (enOperationType)Op;
}

stQuestion GenerateOneQuestion(enOperationType OperationType , enLevel Level)
{
	stQuestion Question;
	if (Level == enLevel::Mix)
	{
		Level = (enLevel)RandomNum(1, 3);
	}
	if (OperationType == enOperationType::OpMix)
	{
		OperationType = GetRandomOperationType();
	}
	Question.OperationType = OperationType;
	switch (Level)
	{
	case enLevel::Easy:
		Question.FirstNum = RandomNum(1, 10);
		Question.SecondNum = RandomNum(1, 10);
		Question.CorrectAns = Calculator(Question.FirstNum, Question.SecondNum, Question.OperationType);
		Question.Level = Level;
		return Question;
	case enLevel::Medium:
		Question.FirstNum = RandomNum(20, 50);
		Question.SecondNum = RandomNum(20, 50);
		Question.CorrectAns = Calculator(Question.FirstNum, Question.SecondNum, Question.OperationType);
		Question.Level = Level;
		return Question;
	case enLevel::Hard:
		Question.FirstNum = RandomNum(50, 10);
		Question.SecondNum = RandomNum(50, 10);
		Question.CorrectAns = Calculator(Question.FirstNum, Question.SecondNum, Question.OperationType);
		Question.Level = Level;
		return Question;
	}
	return Question;
}

void IsAnsCorrect(stGameVariables& Info, short QuestionNumber)
{
	if (Info.QuestionList[QuestionNumber].CorrectAns == Info.QuestionList[QuestionNumber].UserAns)
	{
		Info.CorrectAns++;
		cout << "	Right Answer :-)" << endl;
		system("color 2f");
	}
	else
	{
		Info.WrongAns++;
		cout << "	Wrong Answer :-(" << endl;
		cout << "The Correct Answer is : " << Info.QuestionList->CorrectAns << endl;
		system("color 4f");
		cout << "\a";
	}
}

string PrintLevel(enLevel HardLevel)
{
	string Level[4] = { "Easy ", "Medium" , "Hard" , "Mix" };
	if (HardLevel == enLevel::Easy)
		return Level[0];
	else if (HardLevel == enLevel::Medium)
		return Level[1];
	else if (HardLevel == enLevel::Medium)
		return Level[2];
	else
		return Level[3];
}

string PrintOP(enOperationType OperationType)
{
	string OP[5] = { "Add" , "Sub" , "Multi" , "Dev" , "Mix" };
	if (OperationType == enOperationType::Add)
		return OP[0];
	else if (OperationType == enOperationType::Sub)
		return OP[1];
	else if (OperationType == enOperationType::Multi)
		return OP[2];
	else if (OperationType == enOperationType::Dev)
		return OP[3];
	else
		return OP[4];
}

void FillQuizQuestion(stGameVariables &Quiz)
{
	for (int i = 0; i < Quiz.NumberOfQuestions; i++)
	{
		Quiz.QuestionList[i] = GenerateOneQuestion(Quiz.OperationType, Quiz.Level);
	}
}

void Questions(stGameVariables &Quiz, short QuestionNumber)
{	
		cout << "Question[" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]" << endl;
		cout << Quiz.QuestionList[QuestionNumber].FirstNum << " " << OP( Quiz.QuestionList[QuestionNumber].OperationType, QuestionNumber) << " " << Quiz.QuestionList[QuestionNumber].SecondNum;
		cout << endl << "_________________________" << endl;
		Quiz.QuestionList[QuestionNumber].UserAns = ReadUserAnswer();
		IsAnsCorrect(Quiz, QuestionNumber);
		cout << endl;
}

void PrintQuestions(stGameVariables& Quiz)
{
	for (int i = 0; i < Quiz.NumberOfQuestions; i++)
	{
		Questions(Quiz, i);
	}
}

void GenerateAndPrintQuizQuestions()
{
	stGameVariables Quiz;
	Quiz.NumberOfQuestions = ReadNumOfQuestion();
	Quiz.OperationType = ChooseOperationType();
	Quiz.Level = ChooseLevel();
	FillQuizQuestion(Quiz);
	PrintQuestions(Quiz);
	IsPass(Quiz);
	cout << "\n\n___________Quiz Info________\n\n";
	cout << "Number Of Questions : " << Quiz.NumberOfQuestions << endl;
	cout << "Level : " << PrintLevel(Quiz.Level) << endl;
	cout << "Operation Type : " << PrintOP(Quiz.OperationType)<<endl;
	cout << "Number of Correct Questions : " << Quiz.CorrectAns << endl;
	cout << "Number of Wrong Questions : " << Quiz.WrongAns << endl;
}

void StartTheGame()
{
	char PlayAgain = 'y';
	do
	{
		ResetScreen();
		GenerateAndPrintQuizQuestions();
		cout << "Do you want to play again ?[y]:Yes , [N]:No \n";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartTheGame();
	return 0;
}

