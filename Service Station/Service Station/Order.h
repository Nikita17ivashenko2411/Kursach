#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Abstract.h"
#include "Input check.h"
#include "Work with the console.h"
using namespace std;

class Order : Abstract
{
private:
	string VIN;					//VIN
	int price = 0;				//Стоимость
	
	friend ostream& operator<<(ostream& out, Order& order);
	friend istream& operator>>(istream& in, Order& order);
public:
	enum RepairType				//Тип ремонта
	{
		urbainTransporationofPassengers = 1,
		longdistanceTransopationofPassengers,
		internationalTransporationofPassengers,
		longdistanceFreight,
		internationalFreight
	}transporation;
	enum Status					//Статус заказа
	{
		Waiting = 1,
		Inroad,
		Ready
	}status;
	void add() override;						//Добавление данных о заказе
	void show() override;						//Показать данные о всех заказах
	void remove() override;						//Удалить данные о заказе
	void find() override;						//Поиск данных о заказе
	void change() override;						//Изменить данные о заказе
	

	void setVIN();								//Ввести VIN ТС
	void setRepairType(RepairType type);		//Ввести тип ремонта
	void setStatus(Status selectedStatus);		//Ввести статус ремонта
	void nextStatus(int choice);				//Выполнение ремонта

	string getVIN();							//Получить VIN ТС
	RepairType getTransporationType();					//Пoлучить тип ремонта
	Status getStatus();							//Получить статус ремонта
	int getPrice();								//Получить стоимость ремонта
};