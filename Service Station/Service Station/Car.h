#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Abstract.h"
#include "Input check.h"
#include "Work with the console.h"
using namespace std;

class Car : Abstract
{
private:
	string brand;				//Марка
	string model;				//Модель
	int productionYear;			//Год выпуска
	int mileage;				//Пробег						
	string VIN;					//VIN
	string bodyColor;			//Цвет кузова
	
	friend std::ostream& operator<<(std::ostream& out, const Car& car);
	friend std::istream& operator>>(std::istream& in, Car& car);
public:
	enum FuelUsed				//Тип топлива
	{
		Gasoline = 1,
		Diesel,
		Gas,
		Electricity
	} fuelType;

	void add() override;						//Добавление данных о ТС
	void show() override;						//Показать данные о всех ТС
	void remove() override;						//Удалить данные о ТС
	void find() override;						//Поиск данных о ТС
	void change() override;						//Изменить данные о ТС

	void setBrand();							//Ввести марку ТС
	void setModel();							//Ввести модель ТС
	void setProductionYear();					//Ввести год выпуска ТС
	void setMileage();							//Ввести пробег ТС
	void setVIN();								//Ввести VIN ТС
	void setBodyColor();						//Ввести цвет кузова ТС
	void setFuelUsed(FuelUsed fuel);			//Ввести тип используемого топлива ТС

	string getBrand();							//Получить марку ТС
	string getModel();							//Получить модель ТС
	int getProductionYear();					//Получить год выпуска ТС
	int getMileage();							//Получить пробег ТС
	string getVIN();							//Получить VIN ТС
	string getBodyColor();						//Получить цвет кузова ТС
	FuelUsed getFuelUsed();						//Получить тип используемого топлива ТС
};