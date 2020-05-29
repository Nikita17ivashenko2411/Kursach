#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#pragma warning(disable: 4996)

using namespace std;

class Authorization {
	string login, password;
public:
	Authorization() { login = password = ""; }
	bool authorization(SOCKET S, Authorization* autho, string pathFile)
	{
		ofstream theFileIsNotCreated;
		fstream theFileIsCreated;
		theFileIsCreated.open(pathFile);
		if (theFileIsCreated.is_open()) {
			autho = new Authorization[1000];
			int count = 0, position = 0;
			while (!theFileIsCreated.eof()) {
				theFileIsCreated >> autho[count].login;
				theFileIsCreated >> autho[count].password;
				count++;
			}
			char log[256], pass[256];
			for (int i = 0; i < 256; i++) {
				log[i] = '\0';
				pass[i] = '\0';
			}
			recv(S, log, sizeof(log), 0);
			recv(S, pass, sizeof(log), 0);
			string log1 = (string)log;
			string pass1 = (string)pass;
			for (int i = 0; i < count - 1; i++) {
				if (log1 == autho[i].login && pass1 == autho[i].password) {
					position = i;
					break;
				}
			}
			if (autho[position].login == log1 && autho[position].password == pass1) {
				return true;
			}
			else {
				return false;
			}
			delete[] autho;
		}
		else {
			theFileIsNotCreated.open(pathFile);
			cout << "Ошибка создания файла!" << endl;
			theFileIsNotCreated.close();
			return false;
		}
		theFileIsCreated.close();
	}
};

Authorization adminValue, * adminPtr, userValue, * userPtr;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(TEXT("СЕРВЕР"));
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		cout << "Ошибка. Выход из программы!" << endl;
		exit(1);
	}
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	if (newConnection == 0)
		cout << "Ошибка в подключении!" << endl;
	else {
		char msg[256];
		for (int i = 0; i < 256; i++) {
			msg[i] = '\0';
		}
		cout << "Клиент подключен!" << endl;
		while (recv(newConnection, msg, sizeof(msg), 0)) {
			switch (atoi(msg))
			{
			case 1: {
				if (adminValue.authorization(newConnection, adminPtr, "admin.txt") == true) {
					char newMSG[] = "true";
					send(newConnection, newMSG, sizeof(newMSG), 0);
				}
				else {
					char newMSG[] = "false";
					send(newConnection, newMSG, sizeof(newMSG), 0);
				}
				break;
			}
			case 2: {
				if (userValue.authorization(newConnection, userPtr, "user.txt") == true) {
					char newMSG[] = "true";
					send(newConnection, newMSG, sizeof(newMSG), 0);
				}
				else {
					char newMSG[] = "false";
					send(newConnection, newMSG, sizeof(newMSG), 0);
				}
				break;
			}
			default:
				break;
			}
		}

	}
	system("pause");
	return 0;
}