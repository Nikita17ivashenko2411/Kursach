#pragma once
#include <fstream>
#include "Abstract.h"
#include "Input check.h"
using namespace std;

class Account : public Abstract
{
private:
	string login;								//логин учетной записи
	string password;							//пароль учетонй записи
	bool isAdmin = false;						//Проверка (запись - админ?)
	friend ostream& operator<<(ostream& out, const Account& account);
	friend istream& operator>>(istream& in, Account& account);
	
	void setLogin();							//Установить логин для записи
	void setPassword();							//Установить пароль для записи
	void setIsAdmin(bool isAdminIdentifier);	//Установить flag, что запись для админа
public:
	void add() override;						//Добавление данных
	void show() override;						//Показать данные
	void remove() override;						//Удалить данные
	void find() override;						//Поиск данных
	void change() override;						//Изменить данные

	static void registrAdmin();					//Зарегистрировать админа
	 
	bool getIsAdmin();							//Получить метку для записи
	string getLogin();							//Получить логин для записи
	string getPassword();						//Получить пароль для записи
};