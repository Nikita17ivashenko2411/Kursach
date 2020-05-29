#include <iostream>
#include <iomanip>
#include <vector>
#include "Client.h"
using namespace std;

extern vector<Client> clientVector;

void Client::add()									//Добавление данных о водителе
{
	cout << "Добавление данных о водителе..." << endl;
	setSurname();
	setName();
	setPatronymic();
	setEmail();
	setPhoneNumber();
	setVIN();
	cout << "Регистрация пройдена успешно!" << endl;
	system("pause");
	system("cls");
}
void Client::show()									//Показать данные о водителе
{
	if (clientVector.empty())
		cout << "Данные о водителе ещё не добавлены. Попробуйте позже";
	else
	{
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|   VIN  |      Фамилия       |      Имя      |      Отчество      |                Email              |Номер телефон|" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < clientVector.size(); i++)
		{
			cout << "|" << setw(8) << clientVector[i].getVIN() << "|" << setw(20) << clientVector[i].getSurname() << "|" << setw(15) << clientVector[i].getName() << "|" << setw(20) << clientVector[i].getPatronymic();
			cout << "|" << setw(35) << clientVector[i].getEmail() << "|375" << setw(9) << clientVector[i].getPhoneNumber() << " |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
}
void Client::remove()								//Удалить данные о водителе
{
	bool temp = false;
	string tempVIN;
	if (clientVector.empty())
	{
		cout << "Данные о клиентах ещё не добавлены. Попробуйте позже";
		temp = true;
	}
	else
	{
		cout << "Данные клиентов: " << endl;
		for (int i = 0; i < clientVector.size(); i++)
		{
			cout << clientVector[i].getSurname() << "(" << clientVector[i].getVIN() << ")" << endl;
		}
	}
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nДанные какого клиента необходимо удалить?\n";
		cout << "Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		if (tempVIN == "Нет")
			temp = true;
		if (temp == false)
		{
			for (int i = 0; i < clientVector.size(); i++)
			{
				if (clientVector[i].getVIN() == tempVIN)
				{
					clientVector.erase(clientVector.begin() + i);
					temp = true;
					cout << "Запись удалена." << endl;
				}
			}
			if (temp == false)
			{
				cout << "Записи с таким VIN нет.\n";
				system("pause");
				system("cls");
			}
		}
	} while (temp == false);
}
void Client::find()									//Поиск данных о водителе
{
	string tempVIN;
	bool flag = false;
	do
	{
		if (clientVector.empty())
		{
			cout << "Данные о клиентах ещё не добавлены. Попробуйте позже";
			flag = true;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "Данные клиентов: " << endl;
			for (int i = 0; i < clientVector.size(); i++)
			{
				cout << clientVector[i].getSurname() << "(" << clientVector[i].getVIN() << ")" << endl;
			}
		}
		cout << "Введите VIN ТС, данные владельца которого необходмо показать. Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		for (int i = 0; i < clientVector.size(); i++)
		{
			if (clientVector[i].getVIN() == tempVIN)
			{
				cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "|   VIN  |      Фамилия       |      Имя      |      Отчество      |                Email              |Номер телефон|" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "|" << setw(8) << clientVector[i].getVIN() << "|" << setw(20) << clientVector[i].getSurname() << "|" << setw(15) << clientVector[i].getName() << "|" << setw(20) << clientVector[i].getPatronymic();
				cout << "|" << setw(35) << clientVector[i].getEmail() << "|375" << setw(9) << clientVector[i].getPhoneNumber() << " |" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Совпадений не найдено." << endl;
			system("pause");
			system("cls");
		}

	} while (flag == false);
}
void Client::change()								//Изменить данные о водителе
{
	bool temp = false;
	string tempVIN;
	if (clientVector.empty())
	{
		cout << "Данные о водителе ещё не добавлены. Попробуйте позже";
		temp = true;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Данные клиентов: " << endl;
		for (int i = 0; i < clientVector.size(); i++)
		{
			cout << clientVector[i].getSurname() << "(" << clientVector[i].getVIN() << ")" << endl;
		}
	}
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nДанные какого водителя необходимо изменить?\n";
		cout << "Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		if (tempVIN == "Нет")
			temp = true;
		if (temp == false)
		{
			for (int i = 0; i < clientVector.size(); i++)
			{
				if (clientVector[i].getVIN() == tempVIN)
				{
					clientVector[i].add();
					temp = true;
				}
			}
			if (temp == false)
			{
				cout << "Записи с таким VIN нет.\n";
				system("pause");
				system("cls");
			}
		}
	} while (temp == false);
}

void Client::setSurname()							//Ввести фамилию
{
	cout << "Введите фамилию: ";
	cin >> surname;
	surname = InputCheck::stringCheck(surname);
}
void Client::setName()								//Ввести имя
{
	cout << "Введите имя: ";
	cin >> name;
	name = InputCheck::stringCheck(name);
}
void Client::setPatronymic()						//Ввести отчество
{
	cout << "Введите отчество: ";
	cin >> patronymic;
	patronymic = InputCheck::stringCheck(patronymic);
}
void Client::setEmail()								//Ввести адрес эл. почты
{
	cout << "Введите email: ";
	cin >> email;
	email = InputCheck::check(email);
}
void Client::setPhoneNumber()						//Ввести номер мобильного телефона
{
	string tempPhoneNumber;
	cout << "Введите номер мобильного телефона в формате 375YYXXXXXXX: 375";
	cin >> tempPhoneNumber;
	tempPhoneNumber = InputCheck::numberCheck(tempPhoneNumber);
	phoneNumber = atoi(tempPhoneNumber.c_str());
}
void Client::setVIN()								//Ввести VIN МТС
{
	bool flag;
	string tempVIN;
	do
	{
		flag = false;
		cout << "VIN TC должен состоять из 8 символов (буквы и цифры). Введите VIN ТС: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		VIN = tempVIN;
	} while ((VIN.length() != 8) || (flag == true));
}

string Client::getSurname()							//Получить фамилию
{
	return surname;
}
string Client::getName()							//Получить имя
{
	return name;
}
string Client::getPatronymic()						//Получить отчество
{
	return patronymic;
}
string Client::getEmail()							//Получить адрес эл. почты
{
	return email;
}
int Client::getPhoneNumber()						//Получить номер мобильного телефона
{
	return phoneNumber;
}
string Client::getVIN()								//Получить VIN ТС
{
	return VIN;
}

ostream& operator<<(std::ostream& out, const Client& client)
{
	out << client.surname << " " << client.name << " " << client.patronymic << " "
		<< client.email << " " << client.phoneNumber << " " << client.VIN << " " << endl;
	return out;
}
istream& operator>>(std::istream& in, Client& client)
{
	in >> client.surname >> client.name >> client.patronymic >> client.email >> client.phoneNumber >> client.VIN;
	return in;
}