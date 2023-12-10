#include<iostream>
using namespace std;

int stack_arr[5];
int first = -1;

int isFull()
{
	if (first == stack_arr[5] - 1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if (first == -1)
		return 1;
	else
		return 0;
}

void push(int data)
{
	int i;

	if (isFull())
	{
		cout << " Stack overflow !" << endl;
		exit(1);
	}
	first += 1;
	for  (i = first ; i>0 ; i--)
	{
		stack_arr[i] = stack_arr[i - 1];
	}
	stack_arr[0] = data;
}

int pop()
{
	int i, val;
	val = stack_arr[0];

	if (isEmpty())
	{
		cout << " Stack underflow !" << endl;
		exit(1);
	}
	for (i = 0; i < first; i++)
	{
		stack_arr[i] = stack_arr[i + 1];
	}
	first -= 1;
	return val;
}

int peek()
{
	if (isEmpty())
	{
		cout << " Stack underflow !" << endl;
		exit(1);
	}
	return stack_arr[0];
}

void print()
{
	int i;
	if (first == -1)
	{
		cout << "Stack underflow ! " << endl;
		exit(1);
	}
	for (i = 0; i <= first; i++)
	{
		cout << stack_arr[i] << endl;
	}
}

int main()
{
	int choice, data;
	while (1)
	{
		cout << endl;
		cout << " 1-  PUSH " << endl << endl;
		cout << " 2-  POP " << endl << endl;
		cout << " 3-  Print the TOP element " << endl << endl;
		cout << " 4-  Print all the element of the Stack " << endl << endl;
		cout << " 5-  Quit " << endl << endl;

		cout << "Pls! Enter your Choice :    ";
		cin >> choice;
		
			switch (choice)
			{
			case 1:
				cout << "Enter the element you push : ";
				cin >> data;
				break;

			case 2:
				data = pop();
				cout << "Deleted the element is : " << data;
				break;
			case 3:
				cout << "The top most element is : " << peek() << endl;
				break;
			case 4:
				print();
				break;
			case 5:
				exit(1);
			default:
				cout << "  WRONG CHOICE ! " << endl;
			}
			continue;
	}

	return 0;
}