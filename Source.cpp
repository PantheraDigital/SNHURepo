#include <Python.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "PythonWrapper.h"
#include "InputHelper.h"

using namespace std;


int main()
{
	int userNum = 0;
	do
	{
		cout << "1. Show frequency of all items\n2. Find frequency of item\n3. Create histogram\n4. Quit" << endl;
		cout << "Enter Selection: ";

		userNum = GetIntInput(1, 4);
		cout << endl;

		switch (userNum)
		{
		case 1:
			//all items and frequency of the day
			CallProcedure("OutputAllItems");
			break;

		case 2:
		{
			//number of purchases for a specific item
			string item = "";

			cout << "Enter item name to search for: ";
			item = GetStringInput();
			callIntFunc("ItemOccurrence", item);
			break;
		}
		case 3:
		{
			//text based histogram of items purchased in a day
			// + representation of the number of times each item was purchased

			//create file to read
			CallProcedure("ItemHistogram");

			//read file from python function 
			ifstream inFile;
			inFile.open("frequency.dat");

			//process data and create graph
			if (inFile)
			{
				string item;
				int num;
				while (inFile >> item >> num)
				{
					cout << right << setw(20) << item << "-" << setw(3) << num << ": ";
					cout << string(num, '#') << endl;
				}
			}
			else
				cout << "File not found" << endl;
			
			inFile.close();
			break;
		}
		default:
			break;
		}

		cout << endl;
	} while (userNum != 4);

}