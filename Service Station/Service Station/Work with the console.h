#pragma once

bool logInAsAdmin();				//Авторизироваться как администратор
int logInAsUser();					//Авторизироваться как пользователь

void createFileWithData();			//Создание файлов для зарписи данных
void getDataFromFile();				//Запись данных из файла
void saveDataToFile();				//Запись данных в файл

int mainMenu();						//Выбор действия в главном меню приложения

int serviceTeamMenuText();			//Выбор действия в меню сотрудника СТО
void serviceTeamMenu();				//Меню для сотрудников СТО

int workWithOrderMenuText();		//Выбор действия в меню работы с заказами
void workWithOrderMenu();			//Меню для работы с заказами

int workWithClientDataMenuText();	//Выбор действия в меню для работы с клиентами
void workWithClientDataMenu();		//Меню для работы с клиентами

int clientMenuText();				//Выбор действия в меню клиента
void clientMenu(int choice);		//Меню для клиента

void changeInformation();			//Изменить информацию в классах
void findInformation();				//Поиск информации в классах
void removeInformation();			//Удалить информацию

void showAllAccountDetails(int choice);	//Показать все данные заказа для клиента
void showStatusInformation(int choice); //Показать данные о статусе выполнения заказа