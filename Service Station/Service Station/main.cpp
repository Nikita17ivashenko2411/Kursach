#include <iostream>
#include <vector>
#include <Windows.h>
#include "Abstract.h"
#include "Account.h"
#include "Car.h"
#include "Client.h"
#include "Order.h"
#include "Input check.h"
#include "Work with the console.h"
using namespace std;
#pragma comment(lib, "ws2_32.lib")
vector<Account> accountVector;
vector<Car> carVector;
vector<Client> clientVector;
vector<Order> orderVector;
int temp;

    
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(TEXT("АВТОМАТИЗИРОВАННАЯ СИСТЕМА УЧЁТА ФУНКЦИОНИРОВАНИЯ АВТОПАРКА"));
	system("color F0");
	createFileWithData();
	getDataFromFile();

	if (accountVector.empty())
		Account::registrAdmin();
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        cout << "Ошибка WSAStartup!" << endl;
        return 1;
    }
    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;
    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        cout << "Отсутствует соединение с сервером!" << endl;
        return 1;
    }
	do
	{
		switch (mainMenu())
		{
		case 1:
			system("cls");
			if (logInAsAdmin() == true)
				serviceTeamMenu();
			break;
		case 2:
			system("cls");
			temp = logInAsUser();
			if (temp != -1) 
				clientMenu(temp-1);
			break;
		case 3:
			system("cls");
			
			saveDataToFile();
			system("pause");
			return 0;
		default:
			cout << "\t\t\t\tНеверный выбор. Пожалуйста, сделайте правильный выбор." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (true);
}

