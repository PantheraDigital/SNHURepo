#pragma once

#include <iostream>
#include <string>

using namespace std;


int GetIntInput(int t_min, int t_max)
{
	int result;
	cin >> result;

	while (cin.fail() || result > t_max || result < t_min)
	{
		cin.clear();
		cin.ignore(256, '\n');

		cout << "Invalid input. ";
		if (result > t_max)
			cout << "Must be less than " << t_max << endl;
		else if (result < t_min)
			cout << "Must be greater than " << t_min << endl;
		else
			cout << "Try an Integer." << endl;

		cin >> result;
	}

	return result;
}
int GetIntInput()
{
	int result;
	cin >> result;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');

		cout << "Invalid input. Try an Integer." << endl;

		cin >> result;
	}

	return result;
}

string GetStringInput()
{
	string result;
	cin >> result;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');

		cout << "Invalid input. Must be a word." << endl;

		cin >> result;
	}

	return result;
}