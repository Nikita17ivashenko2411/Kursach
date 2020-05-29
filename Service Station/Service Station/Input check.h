#pragma once
#pragma once
#include <string>
using namespace std;

class InputCheck
{
public:
	template<typename T> static T check(T data)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Неверный ввод данных. Попробуйте ещё раз: ";
			cin >> data;
		}
		return data;
	}
	static string stringCheck(string data);			//Проверка (не пускает, если есть что-либо, кроме букв)
	static string numberCheck(string data);			//Проверка (не пускает, если есть что-либо, кроме цифр)
	static string stringNumberCheck(string data);	//Проверка (не пускает, если есть что-либо, кроме цифр и букв)
};