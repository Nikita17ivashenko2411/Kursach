#include <iostream>
#include <vector>
#include <iomanip>
#include "Account.h"
#include "Car.h"
using namespace std;

extern vector<Car> carVector;

void Car::add()									//Добавление данных о ТС
{
	cout << "Добавление данных об МТС" << endl;
	setBrand();
	setModel();
	setProductionYear();
	setMileage();
	setVIN();
	setBodyColor();
	string choice;
	int tempChoice;
	do
	{
		cout << "Необходимо ввести число из списка.\n 1.Бензин.\n 2.Дизельное топливо.\n 3.Газ.\n 4.Электричество.\nВведите тип топлива: ";
		cin >> choice;
		choice = InputCheck::numberCheck(choice);
		tempChoice = atoi(choice.c_str());
	} while ((tempChoice < 1) || (tempChoice > 4));
	switch (tempChoice)
	{
	case 1:
		setFuelUsed(Gasoline);
		break;
	case 2:
		setFuelUsed(Diesel);
		break;
	case 3:
		setFuelUsed(Gas);
		break;
	case 4:
		setFuelUsed(Electricity);
		break;
	}
	cout << "Регистрация пройдена успешно!" << endl;
	system("pause");
	system("cls");
}
void Car::show()									//Показать данные о ТС
{
	if (carVector.empty())
		cout << "Данные о ТС ещё не добавлены. Попробуйте позже";
	else
	{
		cout << "----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|   VIN  |     Марка ТС     |    Модель ТС     | Пробег |Год выпуска|   Цвет кузова  |    Вид топлива    |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < carVector.size(); i++)
		{			
			cout << "|" << setw(8) << carVector[i].getVIN() << "|" << setw(18) << carVector[i].getBrand() << "|" << setw(18) << carVector[i].getModel() << "|" << setw(8) << carVector[i].getMileage();
			cout << "|" << setw(11) << carVector[i].getProductionYear() << "|" << setw(16) << carVector[i].getBodyColor() << "|" << setw(20);
			switch (carVector[i].getFuelUsed())
			{
			case Gasoline:
				cout << "Бензин|" << endl;
				break;
			case Diesel:
				cout << "Дизельное топливо|" << endl;
				break;
			case Gas:
				cout << "Газ|" << endl;
				break;
			case Electricity:
				cout << "Электричество|" << endl;
				break;
			}
			cout << "----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
}
void Car::remove()								//Удалить данные о ТС
{
	bool temp = false;
	string tempVIN;
	if (carVector.empty())
	{
		cout << "Данные о ТС ещё не добавлены. Попробуйте позже";
		temp = true;
	}
	else
	{
		cout << "Данные ТС: " << endl;
		for (int i = 0; i < carVector.size(); i++)
		{
			cout << carVector[i].getVIN() << endl;
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
			for (int i = 0; i < carVector.size(); i++)
			{
				if (carVector[i].getVIN() == tempVIN)
				{
					carVector.erase(carVector.begin() + i);
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
void Car::find()									//Поиск данных о МТС
{
	string tempVIN;
	bool flag = false;
	do
	{
		if (carVector.empty())
		{
			cout << "Данные о МТС ещё не добавлены. Попробуйте позже";
			flag = true;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "Данные МТС: " << endl;
			for (int i = 0; i < carVector.size(); i++)
			{
				cout << carVector[i].getVIN() << endl;
			}
		}
		cout << "Введите VIN МТС, данные которого необходмо показать. Введите VIN: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		for (int i = 0; i < carVector.size(); i++)
		{
			if (carVector[i].getVIN() == tempVIN)
			{
				cout << "----------------------------------------------------------------------------------------------------------" << endl;
				cout << "|   VIN  |     Марка ТС     |    Модель ТС     | Пробег |Год выпуска|   Цвет кузова  |    Вид топлива    |" << endl;
				cout << "----------------------------------------------------------------------------------------------------------" << endl;
				cout << "|" << setw(8) << carVector[i].getVIN() << "|" << setw(18) << carVector[i].getBrand() << "|" << setw(18) << carVector[i].getModel() << "|" << setw(8) << carVector[i].getMileage();
				cout << "|" << setw(11) << carVector[i].getProductionYear() << "|" << setw(16) << carVector[i].getBodyColor() << "|" << setw(20);
				switch (carVector[i].getFuelUsed())
				{
				case Gasoline:
					cout << "Бензин|" << endl;
					break;
				case Diesel:
					cout << "Дизельное топливо|" << endl;
					break;
				case Gas:
					cout << "Газ|" << endl;
					break;
				case Electricity:
					cout << "Электричество|" << endl;
					break;
				}
				cout << "----------------------------------------------------------------------------------------------------------" << endl;
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
void Car::change()								//Изменить данные о ТС
{
	bool temp = false;
	string tempVIN;
	if (carVector.empty())
	{
		cout << "Данные о МТС ещё не добавлены. Попробуйте позже";
		system("pause");
		temp = true;
	}
	else
	{
		cout << "Данные МТС: " << endl;
		for (int i = 0; i < carVector.size(); i++)
		{
			cout << carVector[i].getVIN() << endl;
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
			for (int i = 0; i < carVector.size(); i++)
			{
				if (carVector[i].getVIN() == tempVIN)
				{
					carVector[i].add();
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

void Car::setBrand()								//Ввести марку МТС
{
	cout << "Марку МТС вводить без пробелов. Введите марку МТС: ";
	cin >> brand;
	brand = InputCheck::stringCheck(brand);
}
void Car::setModel()								//Ввести модель МТС
{
	cout << "Модель МТС вводить без пробелов. Введите модель МТС: ";
	cin >> model;
	model = InputCheck::stringNumberCheck(model);
}
void Car::setProductionYear()					//Ввести год выпуска МТС
{
	string tempProductionYear;
	do
	{
		cout << "Введите год выпуска МТС: ";
		cin >> tempProductionYear;
		tempProductionYear = InputCheck::numberCheck(tempProductionYear);
		productionYear = atoi(tempProductionYear.c_str());
		if ((productionYear < 1900) || (productionYear > 2019))
		{
			cout << "Неверный ввод, попробуйте ещё раз." << endl;
		}
	} while ((productionYear < 1980) || (productionYear > 2020));
}
void Car::setMileage()							//Ввести пробег МТС
{
	string tempMileage;
	do
	{
		cout << "Введите пробег МТС: ";
		cin >> tempMileage;
		tempMileage = InputCheck::numberCheck(tempMileage);
		mileage = atoi(tempMileage.c_str());
		if ((mileage < 0) || (mileage > 1000000))
		{
			cout << "Неверный ввод, попробуйте ещё раз." << endl;
			system("pause");
		}
	} while ((mileage < 0) || (mileage > 1000000));
}
void Car::setFuelUsed(FuelUsed fuel)							//Ввести тип используемого топлива МТС
{
	this->fuelType = fuel;
}
void Car::setVIN()								//Ввести VIN ТС
{
	bool flag;
	string tempVIN;
	do
	{
		flag = false;
		cout << "VIN МTC должен состоять из 8 символов (буквы и цифры). Введите VIN МТС: ";
		cin >> tempVIN;
		tempVIN = InputCheck::stringNumberCheck(tempVIN);
		for (int i = 0; i < carVector.size(); i++)
		{
			if (carVector[i].getVIN() == tempVIN)
			{
				flag = true;
				cout << "МТС с таким VIN уже зарегистрирована. Попробуйте ещё раз." << endl;
			}
		}
		VIN = tempVIN;
	} while ((VIN.length() != 8) || (flag == true));
}
void Car::setBodyColor()							//Ввести цвет кузова МТС
{
	cout << "Введите цвет ТС: ";
	cin >> bodyColor;
	bodyColor = InputCheck::stringCheck(bodyColor);
}

string Car::getBrand()							//Получить марку МТС
{
	return brand;
}
string Car::getModel()							//Получить модель МТС
{
	return model;
}
int Car::getProductionYear()						//Получить год выпуска МТС
{
	return productionYear;
}
int Car::getMileage()							//Получить пробег МТС
{
	return mileage;
}
Car::FuelUsed Car::getFuelUsed()						//Получить тип используемого топлива МТС
{
	return fuelType;
}
string Car::getVIN()								//Получить VIN МТС
{
	return VIN;
}
string Car::getBodyColor()						//Получить цвет кузова МТС
{
	return bodyColor;
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
	out << car.brand << " " << car.model << " " << car.productionYear << " " << car.mileage << " " << car.fuelType << " " << car.VIN << " " << car.bodyColor << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Car& car)
{
	int value;
	in >> car.brand >> car.model >> car.productionYear >> car.mileage >> value >> car.VIN >> car.bodyColor;
	car.fuelType = (Car::FuelUsed)value;
	return in;
}