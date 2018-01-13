#include <math.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/* Things to do
DONE 1. set up string parsing
DONE 2. set up basic functions
DONE 3. move evaulations to a class or functions
DONE 4. add more complex functions
DONE 4b.change evaluations of the functions into subfunctions using recursion
4c. Make all the evaluation work with each other
5. Made a graphic UI for calculator
*/

//--Declaration of Funcs--
int evaluation(string input);
int complexEval(string input);
void factEval(string input);
double factorial(int number);
double specialSymbol(string input);

//--

int main()
{
	string input;

	cout << "Enter your equation" << endl;
	getline(cin, input);


	if (!isdigit(input[1]) && input[input.length() - 1] == '!')
	{
		factEval(input);
	}
	else
	{
		cout << evaluation(input);
	}

	cout << endl << endl;
	system("Pause");
	return 0;
}

//Function for simple mathematical evaluations
int evaluation(string input)
{
	istringstream iss(input);
	//basic non complex interpretation 
	//e.g. A + B

	string firstNumHolder;
	string secondNumHolder;
	string operation;


	iss >> firstNumHolder;
	iss >> operation;
	getline(iss >> ws, secondNumHolder);

	//firstNum = specialSymbol(firstNumHolder);
	//secondNum = specialSymbol(secondNumHolder);

	//returns number evaluation of a single input
	if (!isdigit(firstNumHolder[0]) && firstNumHolder[0] != 'e' && secondNumHolder.empty())
	{
		return complexEval(firstNumHolder);
	}
	else if (secondNumHolder.empty())
	{
		return specialSymbol(firstNumHolder);
	}

	//Check first for complex evaluations then check for simple evaluations 
	if (!isdigit(firstNumHolder[0]))
	{
		return evaluation(to_string(complexEval(firstNumHolder)) + " " + operation + " " + secondNumHolder);
	}
	else if (operation == "+")
	{
		return evaluation(firstNumHolder) + evaluation(secondNumHolder);
	}
	else if (operation == "-")
	{
		return evaluation(firstNumHolder) - evaluation(secondNumHolder);
	}
	else if (operation == "*")
	{
		if (secondNumHolder.length() > 1)
		{
			return evaluation(to_string(evaluation(firstNumHolder + " " + operation + " " + secondNumHolder[0])) + secondNumHolder.substr(1));
		}
		else
		{
			return evaluation(firstNumHolder) * evaluation(secondNumHolder);
		}
	}
	else if (operation == "/")
	{
		if (secondNumHolder.length() > 1)
		{
			return evaluation(to_string(evaluation(firstNumHolder + " " + operation + " " + secondNumHolder[0])) + secondNumHolder.substr(1));
		}
		else
		{
			return evaluation(firstNumHolder) / evaluation(secondNumHolder);
		}
	}
	else if (operation == "%")
	{
		if (secondNumHolder.length() > 1)
		{
			return evaluation(to_string(evaluation(firstNumHolder + " " + operation + " " + secondNumHolder[0])) + secondNumHolder.substr(1));
		}
		else
		{
			return evaluation(firstNumHolder) % evaluation(secondNumHolder);
		}
	}
	else
	{
		cerr << "Inappropriate operation" << endl;
	}

	return 0;
}

//Function for more complex evaluation like sin, cos, tan, etc
int complexEval(string input)
{
	//Get a substring of the first 3 characters to determine the evaluation needed
	string subInput = input.substr(0, 3);

	int number = input[4] - '0';

	if (subInput == "tan")
	{
		return tan(number);
	}
	else if (subInput == "cos")
	{
		return cos(number);
	}
	else if (subInput == "sin")
	{
		return sin(number);
	}
	else if (subInput == "log")
	{
		return log(number);
	}
	else if (subInput == "EXP")
	{
		return exp(number);
	}
	else if (subInput == "ln(")
	{
		return log(number);
	}
	else
	{
		cerr << "Inappropriate operation" << endl;
	}

	return 0;
}


void factEval(string input)
{
	if (input[1] == '!')
	{
		int number = input[0] - '0';
		cout << factorial(number) << endl;
	}
}

double factorial(int number)
{
	if (number == 1)
	{
		return 1;
	}
	else
	{
		return number * factorial(number - 1);
	}
}

double specialSymbol(string input)
{
	if (input == "e")
	{
		return 2.71828;
	}
	else
	{
		return stoi(input);
	}
}