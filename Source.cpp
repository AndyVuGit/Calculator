#include <math.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/* Things to do
1. set up string parsing
2. set up basic functions
3. move functions to a class
4. add more complex functions
5. Made a graphic UI for calculator
*/


int main()
{
	string input;


	//1 + 2
	cout << "Enter your equation" << endl;
	getline(cin, input);

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
	else
	{
		cerr << "Inappropriate operation" << endl;
	}


	cout << endl << endl;
	system("Pause");
	return 0;
}
