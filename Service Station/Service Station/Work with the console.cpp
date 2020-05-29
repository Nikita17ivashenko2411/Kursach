#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <iomanip>

#include "Abstract.h"
#include "Account.h"
#include "Car.h"
#include "Client.h"
#include "Order.h"
#include "Input check.h"
#include "Work with the console.h"
using namespace std;

extern vector<Account> accountVector;
extern vector<Car> carVector;
extern vector<Client> clientVector;
extern vector<Order> orderVector;

int methods() /*Реализация метода парных сравнений*/
{
	setlocale(LC_ALL, "Russian");


	float** matrix = NULL;
	// int height = 0;
	 //int width = 0;

	// cout << " Введите размер матрицы (высота,ширина) :\n>";
	 //cin >> height >> width;

	matrix = new float* [3];
	for (int i = 0; i < 4; i++)
		matrix[i] = new float[3];

	cout << "\nВведите оценки экспертов: \n\n";
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) { cout << "Закупка дешевого топлива" << endl; };
		if (i == 1) { cout << "Повышение стоимости проездных билетов" << endl; };
		if (i == 2) { cout << "Повышение квалификации сотрудников компании"<<endl;
		};
		if (i == 3) { cout << "Закупка новых, дорогостоящих автобусов Mercedes-Benz O 405 N"<< endl;
		};

		for (int j = 0; j < 4; j++)
		{
			float temp;
			cin >> temp;

			if (temp >= 0.f && temp <= 1.f) //negative?
				matrix[i][j] = temp;
			else
			{
				cout << "\nНеккоректные оценки " << endl;
				--j;
			}
			
		}
	}
	cout << "\nИсходные оценки экспертов: \n\n";
	cout << fixed << "    Z1-Z2           Z1-Z3           Z2-Z3\n";
	for (int i = 0; i < 4; i++)
	{
		//int last = width - 1;
		for (int j = 0; j < 4; j++)
		{
			cout << fixed << matrix[i][j] << " " << "\t";
		}
		cout << "\n\n";
	}

	//производим подсчет суммы по строкам
	float Sum[6];
	for (int j = 0; j < 4; j++)
		Sum[j] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << " ";
			Sum[i] += matrix[i][j];
		}
		cout << "Сумма строк = " << Sum[i] << endl;
	}


	/* float f[3];
   // f[0] = Sum[0] + Sum[2];
	 //f[1] = Sum[1] + Sum[4];
	 //f[2] = Sum[3] + Sum[5];*/
	float Sumf = 0.f;
	/*//  for (int i = 0; i < 4; i++)
	  //{
		  //cout << f[i] << "" << endl;
		//  Sumf += f[i];
	  //}*/
	Sumf = Sum[0] + Sum[1] + Sum[2] + Sum[3];

	/* for (int i = 0; i < 4; i++)
	 {
		 cout << "f[" << i << "] = " << f[i] << endl;
	 }*/
	float w[4];
	for (int i = 0; i < 4; i++)
	{
		/*w[i] = Sum[i] / Sumf;
		cout << w[i] << endl;*/
		w[i] = Sum[i] / Sumf;
		cout << "Исковые веса целей " << w[i] << endl;
	}
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i - 1; j++) {
			if (w[j] < w[j + 1]) {

				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
			}
		}
	}
	cout << "Наиболее выгодным решением будет являться " << w[0] << " - Закупка дешевого топлива"<< endl;


	system("pause");
	return 0;
}
bool logInAsAdmin()				//Авторизироваться как администратор
{

	
	bool checkEnter = false, checkLogin = false, checkPassword = false;
	string tempLogin, tempPassword;
	cout << "\t\t\t\t\tВы пытаетесь авторизироваться как Администратор.\n";
	for (int i = 0; i < accountVector.size(); i++)
	{
		if (accountVector[i].getIsAdmin() == true)
		{
			cout << "Введите логин: ";
			cin >> tempLogin;
			tempLogin = InputCheck::check(tempLogin);
			if (accountVector[i].getLogin() == tempLogin)
				checkLogin = true;
			cout << "Введите пароль: ";
			while (true)
			{
				char c;
				if (!(c = _getch()))
					c = _getch();

				if (c == 13)
				{
					cout << endl;
					break;
				}

				if (c == 8)
				{
					if (tempPassword.length())
					{
						tempPassword.pop_back();
					}
					system("cls");

					for (int i = 0; i < tempPassword.length(); i++)
					{
						_putch('*');
					}
				}
				else
				{
					tempPassword += c;
					_putch('*');
				}
			}
			tempPassword = InputCheck::check(tempPassword);
			if (accountVector[i].getPassword() == tempPassword)
				checkPassword = true;
		}
	}

	if ((checkLogin == true) && (checkPassword == true))
		checkEnter = true;
	if (checkEnter == true)
	{
		system("cls");
		return true;
	}
	else
	{
		cout << "\t\t\t\t\tАвторизация прекращена! Неверный логин или пароль.\n\t\t\t\t\t";
		system("pause");
		system("cls");
		return false;
	}
	
}

int logInAsUser()					//Авторизироваться как пользователь
{
	bool checkEnter = false, checkLogin = false, checkPassword = false;
	int accountNumber = -1;
	string tempLogin, tempPassword;
	cout << "\t\t\t\t\tВы пытаетесь авторизироваться как клиент.\n";

	cout << "Введите логин: ";
	cin >> tempLogin;
	tempLogin = InputCheck::check(tempLogin);

	cout << "Введите пароль: ";
	while (true)
	{
		char c;
		if (!(c = _getch()))
			c = _getch();

		if (c == 13)
		{
			cout << endl;
			break;
		}

		if (c == 8)
		{
			if (tempPassword.length())
			{
				tempPassword.pop_back();
			}
			system("cls");

			for (int i = 0; i < tempPassword.length(); i++)
			{
				_putch('*');
			}
		}
		else
		{
			tempPassword += c;
			_putch('*');
		}
	}
	tempPassword = InputCheck::check(tempPassword);

	for (int i = 0; i < accountVector.size(); i++)
	{
		if (accountVector[i].getIsAdmin() == false)
		{
			if ((accountVector[i].getLogin() == tempLogin) && (accountVector[i].getPassword() == tempPassword))
			{
				accountNumber = i;
				checkEnter = true;
				system("cls");
				return accountNumber;	
			}
		}
	}

	if (checkEnter == true)
	{
		system("cls");
		return accountNumber;
	}
	else
	{
		cout << "\t\t\t\t\tАвторизация прекращена! Неверный логин или пароль.\n\t\t\t\t\t";
		system("pause");
		system("cls");
		return accountNumber;
	}
}

void createFileWithData()
{
	ifstream accountFile("Accounts.txt");
	if (!accountFile.is_open())
	{
		ofstream accountFile("Accounts.txt");
	}
	accountFile.close();

	ifstream carFile("Cars.txt");
	if (!carFile.is_open())
	{
		ofstream carFile("Cars.txt");
	}
	carFile.close();

	ifstream clientFile("Clients.txt");
	if (!clientFile.is_open())
	{
		ofstream clientFile("Clients.txt");
	}
	clientFile.close();

	ifstream orderFile("Order.txt");
	if (!orderFile.is_open())
	{
		ofstream orderFile("Order.txt");
	}
	orderFile.close();
}
void getDataFromFile()
{
	ifstream accountFile("Accounts.txt");
	Account account;
	while (true)
	{
		accountFile >> account;
		if (accountFile.eof())
		{
			break;
		}
		accountVector.push_back(account);
	}
	accountFile.close();


	ifstream carFile("Cars.txt");
	Car car;
	while (true)
	{
		carFile >> car;
		if (carFile.eof())
		{
			break;
		}
		carVector.push_back(car);
	}
	carFile.close();

	ifstream clientFile("Clients.txt");
	Client client;
	while (true)
	{
		clientFile >> client;
		if (clientFile.eof())
		{
			break;
		}
		clientVector.push_back(client);
	}
	clientFile.close();

	ifstream orderFile("Order.txt");
	Order order;
	while (true)
	{
		orderFile >> order;
		if (orderFile.eof())
		{
			break;
		}
		orderVector.push_back(order);
	}
	orderFile.close();

}
void saveDataToFile()
{

	ofstream accountFile("Accounts.txt", ios::trunc);
	for (int i = 0; i < accountVector.size(); i++)
	{
		accountFile << accountVector[i];
	}
	accountFile.close();

	ofstream carFile("Cars.txt", ios::trunc);
	for (int i = 0; i < carVector.size(); i++)
	{
		carFile << carVector[i];
	}
	carFile.close();

	ofstream clientFile("Clients.txt", ios::trunc);
	for (int i = 0; i < clientVector.size(); i++)
	{
		clientFile << clientVector[i];
	}
	clientFile.close();

	ofstream orderFile("Order.txt", ios::trunc);
	for (int i = 0; i < orderVector.size(); i++)
	{
		orderFile << orderVector[i];
	}
	orderFile.close();
}

int mainMenu()							//Выбор действия в главном меню приложения
{
	string choice;
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t1.Администратор.\n"
		<< "\n\n\n\n\n\n\t\t\t\t\t\t2.Клиент.\n"
		<< "\n\n\n\n\n\n\t\t\t\t\t\t3.Выход.\n"
		<< "\n\n\n\n\n\n\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	return atoi(choice.c_str());
}

int serviceTeamMenuText()				//Выбор действия в меню администратора
{
	string choice;
	cout << "\t\t\t\t\t\t1.Работа с заказами.\n"
		<< "\t\t\t\t\t\t2.Работа с пользователями.\n"
		<< "\t\t\t\t\t\t3.Реализация метода парных сравнений.\n"
		<< "\t\t\t\t\t\t4.Выход в главное меню.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	return atoi(choice.c_str());
}
void serviceTeamMenu()			//Меню для администратора
{
	bool status = true;
	do
	{
		switch (serviceTeamMenuText())
		{
		case 1:
			system("cls");
			workWithOrderMenu();
			system("cls");
			break;
		case 2:
			system("cls");
			workWithClientDataMenu();
			system("cls");
			break;
		case 3:
			system("cls");
			methods();
			system("cls");
			break;
		case 4:
			status = false;
			system("cls");
			break;
		default:
			cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (status == true);
}

int workWithOrderMenuText()			//Выбор действия в меню работы с заказами
{
	string choice;
	cout << "\t\t\t\t\t\t1.Добавление заказа.\n"
		<< "\t\t\t\t\t\t2.Редактирование заказа.\n"
		<< "\t\t\t\t\t\t3.Поиск заказа.\n"
		<< "\t\t\t\t\t\t4.Сортировка заказов.\n"
		<< "\t\t\t\t\t\t5.Удаление заказа.\n"
		<< "\t\t\t\t\t\t6.Просмотр всех заказов.\n"
		<< "\t\t\t\t\t\t7.Осуществить перевозку.\n"
		<< "\t\t\t\t\t\t8.Выход.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	return atoi(choice.c_str());
}
void workWithOrderMenu()
{
	bool status = true;
	do
	{
		switch (workWithOrderMenuText())
		{
		case 1:
		{
			system("cls");
			Account user;
			accountVector.push_back(user);
			accountVector.back().add();
			Client client;
			clientVector.push_back(client);
			clientVector.back().add();
			Car car;
			carVector.push_back(car);
			carVector.back().add();
			Order order;
			orderVector.push_back(order);
			orderVector.back().add();
			break;
		}
		case 2:
			system("cls");
			if (carVector.empty())
			{
				cout << "\t\t\tДля работы с этой функцией необходимо добавить данные о ТС." << endl;
				system("pause");
			}
			else
				changeInformation();
			system("cls");
			break;
		case 3:
			system("cls");
			if (carVector.empty())
			{
				cout << "\t\t\tДля работы с этой функцией необходимо добавить данные о ТС." << endl;
			}
			else
				findInformation();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Данная функция находится в разработке, спасибо, что проявили интерес!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
		{
			system("cls");
			if (carVector.empty())
			{
				cout << "\t\t\tДля работы с этой функцией необходимо добавить данные о ТС." << endl;
			}
			else
				removeInformation();
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			if (carVector.empty())
			{
				cout << "\t\t\tДля работы с этой функцией необходимо добавить данные о ТС." << endl;
			}
			else
				clientVector.front().show();
				carVector.front().show();
				orderVector.front().show();
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			system("cls");
			if (orderVector.empty())
			{
				cout << "\t\t\tДля работы с этой функцией необходимо добавить данные о MТС." << endl;
			}
			else
			{
				string tempVIN;
				bool flag = false;
				do
				{
					if (orderVector.empty())
					{
						cout << "Данные о МТС ещё не добавлены. Попробуйте позже";
						flag = true;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Данные ТС: " << endl;
						for (int i = 0; i < orderVector.size(); i++)
						{
							cout << orderVector[i].getVIN() << endl;
						}
					}
					cout << "Введите VIN MТС, для которого необходимо изменить статус выполнения заказа. Введите VIN: ";
					cin >> tempVIN;
					tempVIN = InputCheck::stringNumberCheck(tempVIN);
					for (int i = 0; i < orderVector.size(); i++)
					{
						if (orderVector[i].getVIN() == tempVIN)
							orderVector[i].nextStatus(i);
						flag = true;
					}
					if (flag == false)
					{
						cout << "Совпадений не найдено." << endl;

						system("pause");
						system("cls");
					}

				} while (flag == false);
			}
				
			system("pause");
			system("cls");
			break;
		}
		case 8:
			status = false;
			system("cls");
			break;
		default:
			cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (status == true);
}

int workWithClientDataMenuText()
{
	string choice;
	cout << "\t\t\t\t\t\t1.Добавить пользователя.\n"
		<< "\t\t\t\t\t\t2.Удалить пользователя.\n"
		<< "\t\t\t\t\t\t3.Показать всех пользователей.\n"
		<< "\t\t\t\t\t\t4.Поиск пользователя.\n"
		<< "\t\t\t\t\t\t5.Редактировать данные пользователя.\n"
		<< "\t\t\t\t\t\t6.Выход.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	return atoi(choice.c_str());
}
void workWithClientDataMenu()
{
	bool status = true;
	do
	{
		switch (workWithClientDataMenuText())
		{
		case 1:
		{
			system("cls");
			Account user;
			accountVector.push_back(user);
			accountVector.back().add();
			break;
		}
		case 2:
		{
			system("cls");
			accountVector.front().remove();
			break;
		}
		case 3:
		{
			system("cls");
			accountVector.front().show();
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			accountVector.front().find();
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			accountVector.front().change();
			system("pause");
			system("cls");
			break;
		}
		case 6:
			status = false;
			system("cls");
			break;
		default:
			cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (status == true);
}

int clientMenuText()			//Выбор действия в меню клиента
{
	string choice;
	cout << "\t\t\t\t\t\t1.Просмотр всех данных заказа.\n"
		<< "\t\t\t\t\t\t2.Просмотр состояния заказа.\n"
		<< "\t\t\t\t\t\t3.Просмотреть список оказываемых услуг.\n"
		<< "\t\t\t\t\t\t4.Выход в главное меню.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	return atoi(choice.c_str());
}
void clientMenu(int choice)				//Меню для клиента
{
	bool status = true;
	
	do
	{
		switch (clientMenuText())
		{
		case 1:
			system("cls");
			//showAllAccountDetails(choice);
			clientVector.front().show();
			carVector.front().show();
			
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			//showStatusInformation(choice);
			orderVector.front().show();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "\t\t\t\t\t\tСписок оказываемых услуг:\n\t\t\t\t\t\t1.Пассажирские городские перевозки.\n\t\t\t\t\t\t2.Пассажирские междугородние перевозки.";
			cout << "\n\t\t\t\t\t\t3.Пассажирские международные перевозки.\n\t\t\t\t\t\t4.Междугородние перевозки грузов.";
			cout << "\n\t\t\t\t\t\t5.Международные перевозки грузов" << endl;
			cout << "\t\t\t\t\t";
			system("pause");
			system("cls");
			break;
		case 4:
			status = false;
			system("cls");
			break;
		default:
			cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (status == true);
}

void changeInformation()
{
	string choice;
	int tempChoice;
	cout << "\t\t\t\t\t\t1.Изменить данные о МTC.\n"
		<< "\t\t\t\t\t\t2.Изменить данные о клиенте.\n"
		<< "\t\t\t\t\t\t3.Изменить данные о заказе.\n"
		<< "\t\t\t\t\t\t4.Отменить изменения.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	tempChoice = atoi(choice.c_str());
	switch (tempChoice)
	{
	case 1:
		system("cls");
		carVector.front().change();
		break;
	case 2:
		system("cls");
		clientVector.front().change();
		break;
	case 3:
		system("cls");
		orderVector.front().change();
		break;
	case 4:
		break;
	default:
		cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
		system("pause");
		system("cls");
		break;
	}	
}
void findInformation()				//Поиск информации в классах
{
	string choice;
	int tempChoice;
	cout << "\t\t\t\t\t\t1.Поиск данных о МTC.\n"
		<< "\t\t\t\t\t\t2.Поиск данных о клиенте.\n"
		<< "\t\t\t\t\t\t3.Поиск данных о заказе.\n"
		<< "\t\t\t\t\t\t4.Отменить поиск.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	tempChoice = atoi(choice.c_str());
	switch (tempChoice)
	{
	case 1:
		system("cls");
		carVector.front().find();
		break;
	case 2:
		system("cls");
		clientVector.front().find();
		break;
	case 3:
		system("cls");
		orderVector.front().find();
		break;
	case 4:
		break;
	default:
		cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
		system("pause");
		system("cls");
		break;
	}
}
void removeInformation()			//Удалить информацию
{
	string choice;
	int tempChoice;
	cout << "\t\t\t\t\t\t1.Удалить данные о МTC.\n"
		<< "\t\t\t\t\t\t2.Удалить данные о клиенте.\n"
		<< "\t\t\t\t\t\t3.Удалить данные о заказе.\n"
		<< "\t\t\t\t\t\t4.Отменить удаление.\n"
		<< "\t\t\t\t\t\tВаш выбор: ";
	cin >> choice;
	choice = InputCheck::numberCheck(choice);
	tempChoice = atoi(choice.c_str());
	switch (tempChoice)
	{
	case 1:
		system("cls");
		carVector.front().remove();
		break;
	case 2:
		system("cls");
		clientVector.front().remove();
		break;
	case 3:
		system("cls");
		orderVector.front().remove();
		break;
	case 4:
		break;
	default:
		cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
		system("pause");
		system("cls");
		break;
	}
}

void showAllAccountDetails(int choice)
{
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	cout << "|   VIN  |     Марка МТС    |    Модель МТС    | Пробег |Год выпуска|   Цвет кузова  |    Вид топлива    |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(8) << carVector[choice].getVIN() << "|" << setw(18) << carVector[choice].getBrand() << "|" << setw(18) << carVector[choice].getModel() << "|" << setw(8) << carVector[choice].getMileage();
	cout << "|" << setw(11) << carVector[choice].getProductionYear() << "|" << setw(16) << carVector[choice].getBodyColor() << "|" << setw(20);
	switch (carVector[choice].getFuelUsed())
	{
	case Car::Gasoline:
		cout << "Бензин|" << endl;
		break;
	case Car::Diesel:
		cout << "Дизельное топливо|" << endl;
		break;
	case Car::Gas:
		cout << "Газ|" << endl;
		break;
	case Car::Electricity:
		cout << "Электричество|" << endl;
		break;
	}
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|   VIN  |      Фамилия       |      Имя      |      Отчество      |                Email              |Номер телефон|" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(8) << clientVector[choice].getVIN() << "|" << setw(20) << clientVector[choice].getSurname() << "|" << setw(15) << clientVector[choice].getName() << "|" << setw(20) << clientVector[choice].getPatronymic();
	cout << "|" << setw(35) << clientVector[choice].getEmail() << "|375" << setw(9) << clientVector[choice].getPhoneNumber() << " |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|   VIN  |Стоимость поездки|        Тип перевозки          |     Статус      |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(8) << orderVector[choice].getVIN() << "|" << setw(17) << orderVector[choice].getPrice() << "|" << setw(32);
	switch (orderVector[choice].getTransporationType())
	{
	case Order::urbainTransporationofPassengers:
		cout << "Пассажирские городские перевозки|";
		break;
	case Order::longdistanceTransopationofPassengers:
		cout << "Пассажирские междугородние перевозки|";
		break;
	case Order::internationalTransporationofPassengers:
		cout << "Пассажирские международные перевозки|";
		break;
	case Order::longdistanceFreight:
		cout << "Междугородние перевозки грузов|";
		break;
	case Order::internationalFreight:
		cout << "Международные перевозки грузов|";
		break;
	}
	cout << setw(18);
	switch (orderVector[choice].getStatus())
	{
	case Order::Waiting:
		cout << "Ожидание|" << endl;
		break;
	case Order::Inroad:
		cout << "Находится в пути |" << endl;
		break;
	case Order::Ready:
		cout << "Готово|" << endl;
		break;
	}
	cout << "------------------------------------------------------------------------------" << endl;

}
void showStatusInformation(int choice)
{
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|   VIN  |Стоимость поездки|        Тип перевозки         |     Статус      |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(8) << orderVector[choice].getVIN() << "|" << setw(17) << orderVector[choice].getPrice() << "|" << setw(32);
	switch (orderVector[choice].getTransporationType())
	{
	case Order::urbainTransporationofPassengers:
		cout << "Пассажирские городские перевозки|";
		break;
	case Order::longdistanceTransopationofPassengers:
		cout << "Пассажирские междугородние перевозки|";
		break;
	case Order::internationalTransporationofPassengers:
		cout << "Пассажирские международные перевозки|";
		break;
	case Order::longdistanceFreight:
		cout << "Междугородние перевозки грузов|";
		break;
	case Order::internationalFreight:
		cout << "Международные перевозки грузов|";
		break;
	}
	cout << setw(18);
	switch (orderVector[choice].getStatus())
	{
	case Order::Waiting:
		cout << "Ожидание|" << endl;
		break;
	case Order::Inroad:
		cout << "Находится в пути |" << endl;
		break;
	case Order::Ready:
		cout << "Готово|" << endl;
		break;
	}
	cout << "------------------------------------------------------------------------------" << endl;
}