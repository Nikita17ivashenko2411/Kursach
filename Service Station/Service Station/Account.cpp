#include <iostream>
#include <vector>
#include "Account.h"
using namespace std;

extern vector<Account> accountVector;

void Account::add()							//Добавление данных
{
	int temp = 0;
	string tempLogin;
	cout << "Регистрация нового пользователя." << endl;
	setIsAdmin(false);
	do
	{
		temp = 0;
		setLogin();
		tempLogin = getLogin();
		for (int i = 0; i < accountVector.size(); i++)
		{
			if (accountVector[i].getLogin() == tempLogin)
				temp++;
		}
		if (temp != 1)
		{
			cout << "Запись с таким логином уже существует. Попробуйте ещё раз.\n";
		}
	} while (temp != 1);
	setPassword();
	cout << "Регистрация пройдена успешно!" << endl;
	system("pause");
	system("cls");
}
void Account::show()						//Показать данные
{
	if (accountVector.empty())
		cout << "Нет зарегистрированных аккаунтов.";
	else
	{
		cout << "Зарегистрированные аккаунты: ";
		for (int i = 0; i < accountVector.size(); i++)
		{
			cout << accountVector[i].getLogin() << " ";
		}
	}
}
void Account::remove()						//Удаление данных
{
	bool temp = false;
	string tempLogin;
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nКакого пользователя необходимо удалить?\n";
		Account::show();
		cout << "\nВведите логин пользователя: ";
		do
		{
			cin >> tempLogin;
			tempLogin = InputCheck::check(tempLogin);
			if (accountVector.front().getLogin() == tempLogin)
				cout << "Невозможно удалить администратора. Введите нужный логин ещё раз: ";
			if (tempLogin == "Нет")
			{
				temp = true;
				system("pause");
				system("cls");
			}

		} while ((accountVector[0].getLogin() == tempLogin) && (temp == false));

		if (temp == false)
		{
			for (int i = 0; i < accountVector.size(); i++)
			{
				if (accountVector[i].getLogin() == tempLogin)
				{
					accountVector.erase(accountVector.begin() + i);
					temp = true;
					cout << "Учётная запись удалена." << endl;
					system("pause");
					system("cls");
				}
			}
			if (temp == false)
			{
				cout << "Записи с таким логином нет.\n";
				system("pause");
				system("cls");
			}
		}
	} while (temp == false);
}
void Account::find()						//Поиск данных
{
	bool temp = false;
	string tempLogin;
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nДанные какого пользователя необходимо найти?\n";
		Account::show();
		cout << "\nВведите логин пользователя: ";
		cin >> tempLogin;
		tempLogin = InputCheck::check(tempLogin);
		if (tempLogin == "Нет")
			temp = true;
		if (temp == false)
		{
			for (int i = 0; i < accountVector.size(); i++)
			{
				if (accountVector[i].getLogin() == tempLogin)
				{
					if (accountVector[i].getIsAdmin() == 1)
						cout << "Запись предназначена для сотрудников.\n";
					else
						cout << "Запись предназначена для клиента.\n";
					cout << "Пароль от учётной записи: " << accountVector[i].getPassword();
					cout << endl;
					temp = true;
					break;
				}
			}
			if (temp == false)
			{
				cout << "Запись не найдена\n";
				system("pause");
				system("cls");
			}
		}
	} while (temp == false);
}
void Account::change()						//Изменить данные
{
	bool temp = false;
	string tempLogin;
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nДанные какого пользователя необходимо изменить?\n";
		Account::show();
		cout << "\nВведите логин пользователя: ";
		cin >> tempLogin;
		tempLogin = InputCheck::check(tempLogin);
		if (tempLogin == "Нет")
			temp = true;
		if (temp == false)
		{
			for (int i = 0; i < accountVector.size(); i++)
			{
				if (accountVector[i].getLogin() == tempLogin)
				{
					string tempChoice;
					int choice;
					system("cls");
					cout << "\t\t\t\t\t\t1.Изменить логин.\n"
						<< "\t\t\t\t\t\t2.Изменить пароль.\n"
						<< "\t\t\t\t\t\t3.Выход.\n"
						<< "\t\t\t\t\t\tВаш выбор: ";
					cin >> tempChoice;
					tempChoice = InputCheck::numberCheck(tempChoice);
					choice = atoi(tempChoice.c_str());
					switch (choice)
					{
					case 1:
						system("cls");
						cout << "Текущий логин: " << accountVector[i].getLogin() << endl;
						accountVector[i].setLogin();
						break;
					case 2:
						system("cls");
						cout << "Текущий пароль: " << accountVector[i].getPassword() << endl;
						accountVector[i].setPassword();
						break;
					case 3:
						system("cls");
						system("pause");
						break;
					default:
						cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
						system("pause");
						system("cls");
						break;
					}
					temp = true;
					break;
				}
			}
			if (temp == false)
			{
				cout << "Запись не найдена\n";
				system("pause");
				system("cls");
			}
		}
	} while (temp == false);
}

void Account::registrAdmin()
{
	if (accountVector.empty() == 0)
	{
		cout << "Невозможно зарегистрировать нового администратора. Администратор может быть только один.";
	}
	else
	{
		cout << "\t\t\tДобро пожаловать! Требуется пройти регистрацию администратора." << endl;
		Account admin;
		admin.setIsAdmin(true);
		admin.setLogin();
		admin.setPassword();
		accountVector.push_back(admin);
		cout << "Регистрация пройдена успешно!" << endl;
		system("pause");
		system("cls");
	}
}
void Account::setLogin()					//Установить логин для записи
{
	cout << "Логин должен состоять минимум из 6 символов.\nВведите логин: ";
	do
	{
		cin >> login;
		login = InputCheck::check(login);
		if (login.length() < 6) cout << "Ошибка, логин должен состоять минимум из 6 символов.\nВведите логин:";
	} while (login.length() < 6);
}
void Account::setPassword()			//Установить пароль для записи
{
	cout << "Пароль должен состоять минимум из 6 символов.\nВведите пароль: ";
	do
	{
		cin >> password;
		password = InputCheck::check(password);
		if (password.length() < 6) cout << "Ошибка, пароль должен состоять минимум из 6 символов.\nВведите пароль:";
	} while (password.length() < 6);
}
void Account::setIsAdmin(bool isAdminIdentifier)				//Установить указатель, что запись для админа
{
	bool checkIsAdmin = false;
	if (isAdminIdentifier == false)
		isAdmin = isAdminIdentifier;
	else
	{
		for (int i = 0; i < accountVector.size(); i++)
		{
			if (accountVector[i].isAdmin == true) checkIsAdmin = true;
		}
		if (checkIsAdmin == false)
			isAdmin = isAdminIdentifier;
		else cout << "Невозможно добавить больше одного администратора.";
	}
}

bool Account::getIsAdmin()							//Получить метку для записи
{
	return isAdmin;
}
string Account::getLogin()							//Получить логин для записи
{
	return login;
}
string Account::getPassword()						//Получить пароль для записи
{
	return password;
}
ostream& operator<<(ostream& out, const Account& account)
{
	out << account.login << " " << account.password << " " << account.isAdmin << endl;
	return out;
}
istream& operator>>(istream& in, Account& account)
{
	in >> account.login >> account.password >> account.isAdmin;
	return in;
}