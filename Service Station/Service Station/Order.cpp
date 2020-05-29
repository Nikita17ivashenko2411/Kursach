#include <iostream>
#include <vector>
#include <iomanip>
#include "Order.h"
#include "Client.h"
using namespace std;

extern vector<Order> orderVector;

void Order::add()									//Добавление данных о заказе
{
	cout << "Добавление данных о заказе..." << endl;
	string choice;
	int tempChoice;
	setVIN();
	do
	{
		cout << "Необходимо ввести число из списка.\n 1.Пассажирские городские перевозки.\n 2.Пассажирские междугородние перевозки.\n 3.Пассажирские международные перевозки.\n 4.Грузовые междугородние перевозки.\n 5.Грузовые международные перевозки.\nВведите тип перевозки: ";
		cin >> choice;
		choice = InputCheck::numberCheck(choice);
		tempChoice = atoi(choice.c_str());
	} while ((tempChoice < 1) || (tempChoice > 5));
	switch (tempChoice)
	{
	case 1:
		setRepairType(urbainTransporationofPassengers);
		break;
	case 2:
		setRepairType(longdistanceTransopationofPassengers);
		break;
	case 3:
		setRepairType(internationalTransporationofPassengers);
		break;
	case 4:
		setRepairType(longdistanceFreight);
		break;
	case 5:
		setRepairType(internationalFreight);
		break;
	}
	setStatus(Waiting);
	cout << "Регистрация пройдена успешно!" << endl;
	system("pause");
	system("cls");
}
void Order::show()									//Показать данные о всех заказах
{
	if (orderVector.empty())
		cout << "Данные о заказах ещё не добавлены. Попробуйте позже";
	else
	{
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "|   VIN  |Стоимость поездки|        Тип перевозки                 |     Статус      |" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < orderVector.size(); i++)
		{
			cout << "|" << setw(8) << orderVector[i].getVIN() << "|" << setw(17) << orderVector[i].getPrice() << "|" << setw(32);
			switch (orderVector[i].getTransporationType())
			{
			case urbainTransporationofPassengers:
				cout << "Пассажирская городская перевозка      |";
				break;
			case longdistanceTransopationofPassengers:
				cout << "Пассажирская межрегиональная перевозка|";
				break;
			case internationalTransporationofPassengers:
				cout << "Пассажирская международная перевозка  |";
				break;
			case longdistanceFreight:
				cout << "Межрегиональные перевозки грузов      |";
				break;
			case internationalFreight:
				cout << "Международные перевозки грузов        |";
				break;
			}
			cout << setw(18);
			switch (orderVector[i].getStatus())
			{
			case Waiting:
				cout << "Ожидание|" << endl;
				break;
			case Inroad:
				cout << "Находится в пути|" << endl;
				break;
			case Ready:
				cout << "Готово|" << endl;
				break;
			}
			cout << "-------------------------------------------------------------------------------------" << endl;
		}
	}
}
void Order::remove()								//Удалить данные о заказе
{
	bool temp = false;
	string tempVIN;
	if (orderVector.empty())
	{
		cout << "Данные о МТС ещё не добавлены. Попробуйте позже";
		temp = true;
	}
	else
	{
		cout << "Данные ТС: " << endl;
		for (int i = 0; i < orderVector.size(); i++)
		{
			cout << orderVector[i].getVIN() << endl;
		}
	}
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nДанные какого МТС необходимо удалить?\n";
		cout << "Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		if (tempVIN == "Нет")
			temp = true;
		if (temp == false)
		{
			for (int i = 0; i < orderVector.size(); i++)
			{
				if (orderVector[i].getVIN() == tempVIN)
				{
					orderVector.erase(orderVector.begin() + i);
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
void Order::find()									//Поиск данных о заказе
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
			cout << "Данные МТС: " << endl;
			for (int i = 0; i < orderVector.size(); i++)
			{
				cout << orderVector[i].getVIN() << endl;
			}
		}
		cout << "Введите VIN МТС, данные которого необходмо показать. Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		for (int i = 0; i < orderVector.size(); i++)
		{
			if (orderVector[i].getVIN() == tempVIN)
			{
				cout << "------------------------------------------------------------------------------" << endl;
				cout << "|   VIN  |Стоимость поездки|        Тип перевозки          |     Статус      |" << endl;
				cout << "------------------------------------------------------------------------------" << endl;
				cout << "|" << setw(8) << orderVector[i].getVIN() << "|" << setw(17) << orderVector[i].getPrice() << "|" << setw(32);
				switch (orderVector[i].getTransporationType())
				{
				case urbainTransporationofPassengers:
					cout << "Пассажирская городская перевозка|";
					break;
				case longdistanceTransopationofPassengers:
					cout << "Пассажирская межрегиональная перевозка|";
					break;
				case internationalTransporationofPassengers:
					cout << "Пассажирская международная перевозка|";
					break;
				case longdistanceFreight:
					cout << "Межрегиональные перевозки грузов|";
					break;
				case internationalFreight:
					cout << "Международные перевозки грузов|";
					break;
				}
				cout << setw(18);
				switch (orderVector[i].getStatus())
				{
				case Waiting:
					cout << "Ожидание|" << endl;
					break;
				case Inroad:
					cout << "Находится в пути|" << endl;
					break;
				case Ready:
					cout << "Готово|" << endl;
					break;
				}
				cout << "------------------------------------------------------------------------------" << endl;
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
void Order::change()								//Изменить данные о заказе
{
	bool temp = false;
	string tempVIN;
	if (orderVector.empty())
	{
		cout << "Данные о МТС ещё не добавлены. Попробуйте позже";
		system("pause");
		temp = true;
	}
	else
	{
		cout << "Данные МТС: " << endl;
		for (int i = 0; i < orderVector.size(); i++)
		{
			cout << orderVector[i].getVIN() << endl;
		}
	}
	do
	{
		cout << "Чтобы выйти в меню напишите 'Нет'.\nДанные какого МТС необходимо изменить?\n";
		cout << "Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		if (tempVIN == "Нет")
			temp = true;
		if (temp == false)
		{
			for (int i = 0; i < orderVector.size(); i++)
			{
				if (orderVector[i].getVIN() == tempVIN)
				{
					orderVector[i].add();
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

void Order::setVIN()								//Ввести VIN МТС
{
	bool flag;
	string tempVIN;
	do
	{
		flag = false;
		cout << "VIN МTC должен состоять из 8 символов (буквы и цифры). Введите VIN МТС: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		for (int i = 0; i < orderVector.size(); i++)
		{
			if (orderVector[i].getVIN() == tempVIN)
			{
				flag = true;
				cout << "Заказ для МТС с таким VIN уже зарегистрирован. Попробуйте ещё раз." << endl;
			}
		}
		VIN = tempVIN;
	} while ((VIN.length() != 8) || (flag == true));
}
void Order::setRepairType(RepairType type)			//Ввести тип перевозки
{
	this->transporation = type;
}
void Order::setStatus(Status selectedStatus)		//Ввести статус перевозки
{
	this->status = selectedStatus;
}
void Order::nextStatus(int choice)
{
	bool flag = false;
	if (orderVector[choice].getStatus() == 1)
	{
		cout << "Статус заказа изменён на 'Находится в пути'" << endl;
		orderVector[choice].setStatus(Inroad);
		flag = true;
	}
	if ((orderVector[choice].getStatus() == 2) && (flag == false))
	{
		string tempPrice;
		cout << "Статус заказа изменён на 'Готово', необходимо ввести стоимость перевозки: ";
		cin >> tempPrice;
		price = atoi(InputCheck::numberCheck(tempPrice).c_str());
		orderVector[choice].setStatus(Ready);
		flag = true;
	}
	if ((orderVector[choice].getStatus() == 3) && (flag == false))
	{
		cout << "Статус данного заказа 'Готово', необходимо оплатить заказ.";
	}
}
string Order::getVIN()								//Получить VIN МТС
{
	return VIN;
}
Order::RepairType Order::getTransporationType()					//Пoлучить тип перевозки
{
	return transporation;
}
Order::Status Order::getStatus()							//Получить статус ремонта
{
	return status;
}
int Order::getPrice()
{
	return price;
}
ostream& operator<<(ostream& out, Order& order)
{
	out << order.VIN << " "	<< order.transporation << " " << order.status << " " << order.price << " " << endl;
	return out;
}
istream& operator>>(istream& in, Order& order)
{
	string buf;
	int value;
	in >> order.VIN;
	in >> value; 
	order.transporation = (Order::RepairType)value;
	in >> value; 
	order.status = (Order::Status)value;
	in >> order.price;
	return in;
}
