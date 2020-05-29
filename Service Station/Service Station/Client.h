#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Abstract.h"
#include "Account.h"
#include "Input check.h"
#include "Work with the console.h"
using namespace std;

class Client : protected Account
{
private:
	string surname;
	string name;
	string patronymic;
	string email;
	int phoneNumber;
	string VIN;
	friend std::ostream& operator<<(std::ostream& out, const Client& client);
	friend std::istream& operator>>(std::istream& in, Client& client);
public:
	void add() override;						//Добавление данных о клиенте
	void show() override;						//Показать данные о клиенте
	void remove() override;						//Удалить данные о клиенте
	void find() override;						//Поиск данных о клиенте
	void change() override;						//Изменить данные о клиенте

	void setSurname();							//Ввести фамилию
	void setName();								//Ввести имя
	void setPatronymic();						//Ввести отчество
	void setEmail();							//Ввести адрес эл. почты
	void setPhoneNumber();						//Ввести номер мобильного телефона
	void setVIN();								//Ввести VIN ТС

	string getSurname();						//Получить фамилию
	string getName();							//Получить имя
	string getPatronymic();						//Получить отчество
	string getEmail();							//Получить адрес эл. почты
	int getPhoneNumber();						//Получить номер мобильного телефона
	string getVIN();							//Получить VIN ТС
};