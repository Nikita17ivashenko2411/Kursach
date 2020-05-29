#include <string>
#include <iostream>
#include "Input check.h"
using namespace std;

string InputCheck::stringCheck(string data)
{
	bool check = false;
	while (!check)
	{
		while (data == "")
		{
			cout << "Неверный ввод данных. Попробуйте ещё раз: ";
			cin >> data;
		}
		check = true;
		int lineLength = data.length();
		for (int i = 0; i < lineLength; i++)
		{
			if (!((data.at(i) >= 'А' && data.at(i) <= 'я') || (data.at(i) >= 'A' && data.at(i) <= 'z') || data.at(i) == 'ё' || data.at(i) == 'Ё'))
			{
				check = false;
				cout << "Неверный ввод данных. Попробуйте ещё раз: ";
				cin >> data;
				break;
			}
		}
	}
	return string(data);
}
string InputCheck::numberCheck(string data)
{
	bool check = false;
	while (!check)
	{
		while (data == "")
		{
			cout << "Неверный ввод данных. Попробуйте ещё раз: ";
			cin >> data;
		}
		check = true;
		int lineLength = data.length();
		for (int i = 0; i < lineLength; i++)
		{
			if (!(data.at(i) >= '0' && data.at(i) <= '9'))
			{
				check = false;
				cout << "Неверный ввод данных. Попробуйте ещё раз: ";
				cin >> data;
				break;
			}
		}
	}
	return string(data);
}
string InputCheck::stringNumberCheck(string data)
{
	bool check = false;
	while (!check)
	{
		while (data == "")
		{
			cout << "Неверный ввод данных. Попробуйте ещё раз: ";
			cin >> data;
		}
		check = true;
		int lineLength = data.length();
		for (int i = 0; i < lineLength; i++)
		{
			if (!((data.at(i) >= 'А' && data.at(i) <= 'я') || (data.at(i) >= 'A' && data.at(i) <= 'z') || (data.at(i) >= '0' && data.at(i) <= '9') || data.at(i) == 'ё' || data.at(i) == 'Ё'))
			{
				check = false;
				cout << "Неверный ввод данных. Попробуйте ещё раз: ";
				cin >> data;
				break;
			}
		}
	}
	return string(data);
}
