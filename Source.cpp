#include <math.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/* Things to do
1. set up string parsing
2. set up basic functions
3. move evaulations to a class or functions
4. add more complex functions
4b.change evaluations of the functions into subfunctions using recursion
5. Made a graphic UI for calculator
*/

//--Declaration of Funcs--
void evaluation(string input);
void complexEval(string input);
void factEval(string input);
int factorial(int number);

//--

int main()
{
	string input;

	cout << "Enter your equation" << endl;
	getline(cin, input);

	if (!isdigit(input[0]))
	{
		complexEval(input);
	}
	else if (!isdigit(input[1]))
	{
		factEval(input);
	}
	else
	{
		evaluation(input);
	}

	cout << endl << endl;
	system("Pause");
	return 0;
}

//Function for simple mathematical evaluations
void evaluation(string input)
{
	istringstream iss(input);
	//basic non complex interpretation 
	//e.g. A + B

	int firstNum;
	int secondNum;
	string operation;


	iss >> firstNum;
	iss >> operation;
	iss >> secondNum;

	if (operation == "+")
	{
		cout << firstNum + secondNum;
	}
	else if (operation == "-")
	{
		cout << firstNum - secondNum;
	}
	else if (operation == "*")
	{
		cout << firstNum * secondNum;
	}
	else if (operation == "/")
	{
		cout << firstNum / secondNum;
	}
	else if (operation == "%")
	{
		cout << firstNum % secondNum;
	}
	else
	{
		cerr << "Inappropriate operation" << endl;
	}
}

//Function for more complex evaluation like sin, cos, tan, etc
void complexEval(string input)
{
	//Get a substring of the first 3 characters to determine the evaluation needed
	string subInput = input.substr(0, 3);

	int number = input[4] - '0';

	if (subInput == "tan")
	{
		cout << tan(number) << endl;
	}
	else if (subInput == "cos")
	{
		cout << cos(number) << endl;
	}
	else if (subInput == "sin")
	{
		cout << sin(number) << endl;
	}
	else if (subInput == "log")
	{
		cout << log(number) << endl;
	}
	else if (subInput == "EXP")
	{
		cout << exp(number) << endl;
	}
	else if (subInput == "ln(")
	{
		cout << log(number) << endl;
	}
	else
	{
		cerr << "Inappropriate operation" << endl;
	}
}


void factEval(string input)
{
	if (input[1] == '!')
	{
		int number = input[0] - '0';
		cout << factorial(number) << endl;
	}
}

int factorial(int number)
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

