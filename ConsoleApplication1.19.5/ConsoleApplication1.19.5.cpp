// ConsoleApplication1.19.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 16. Умный дом.

#include <iostream>
#include <locale.h>
#include <sstream>
#include <cstdio>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	enum home{
		POWER_SUPPLY=1, OUTLET, INDOOR_LIGHT, OUTDOOR_LIGHT, HOME_HEATING, WATER_HEATING, AIR_CONDITIONER
	};
	string sourceDatasee, time = "", strTempOut="", strTempIn="", strMoveOut="", strLight="";
	int tempIn, tempOut, colorTemp=5000, timeCount=0, dayCount=0, strCount=0;
	int statePower = 0, stateOutlet = 0, stateInDoorLight = 0, stateOutDoorLight = 0;
	int stateHomeHeating = 0, stateWaterHeating=0, stateCond=0;
	statePower |= POWER_SUPPLY;
		stateOutlet |= OUTLET;
	bool movementOut, light;
	while (dayCount < 2) {
		if (statePower & POWER_SUPPLY) {
			if (timeCount < 10) {
				time += "0";
			}
			time += to_string(timeCount);
			time += ":00";
			cout << "\nВремя: " << time << "\n Введите исходные данные.\n";
			getline(cin, sourceDatasee);
			for (int i = 0; i < sourceDatasee.size(); i++) {
				if (sourceDatasee[i] == ' ') {
					strCount++;
				}
				else if (strCount == 0) {
					strTempOut += sourceDatasee[i];
				}
				else if (strCount == 1) {
					strTempIn += sourceDatasee[i];
				}
				else if (strCount == 2) {
					strMoveOut += sourceDatasee[i];
				}
				else if (strCount == 3) {
					strLight += sourceDatasee[i];
				}
			}
			tempOut = stoi(strTempOut);
			tempIn = stoi(strTempIn);
			if (strMoveOut == "yes") {
				movementOut = true;
			}
			else if(strMoveOut == "no"){
				movementOut = false;
			}
			else {
				cout << "\nВведите правильно данные.";
				break;
			}
			if (strLight == "on") {
				light = true;
			}
			else if (strLight == "off") {
				light = false;
			}
			else {
				cout << "\nВведите правильно данные.";
				break;
			}
			if ((light==true) && (!(stateInDoorLight & INDOOR_LIGHT))) {
				stateInDoorLight |= INDOOR_LIGHT;
				cout << "\nСвет в доме включен.";
			}
			else if ((light!=true) && (stateInDoorLight & INDOOR_LIGHT)) {
				stateInDoorLight &=~INDOOR_LIGHT;
				cout << "\nСвет в доме выключен.";
			}
			if (tempOut < 0 && (!(stateWaterHeating & WATER_HEATING))) {
				stateWaterHeating |= WATER_HEATING;
				cout << "\nОтопление водопровода включено. ";
			}
			else if ((tempOut > 5) && (stateWaterHeating & WATER_HEATING)) {
				stateWaterHeating &=~WATER_HEATING;
				cout << "\nОтопление водопровода выключено. ";
			}
			if (((timeCount < 5 || timeCount>16) && movementOut==true) && (!(stateOutDoorLight & OUTDOOR_LIGHT))) {
				stateOutDoorLight |= OUTDOOR_LIGHT;
				cout << "\nНаружное освещение включено. ";
			}
			else if (((timeCount < 5 || timeCount>16) && movementOut!=true) && (stateOutDoorLight & OUTDOOR_LIGHT)) {
				stateOutDoorLight &= ~OUTDOOR_LIGHT;
				cout << "\nНаружное освещение выключено. ";
			}
			else if ((timeCount > 5 && timeCount < 16) && (stateOutDoorLight & OUTDOOR_LIGHT)) {
				stateOutDoorLight &=~ OUTDOOR_LIGHT;
				cout << "\nНаружное освещение выключено. ";
			}
			if (tempIn < 22 && (!( stateHomeHeating & HOME_HEATING))) {
				stateHomeHeating |= HOME_HEATING;
				cout << "\nОтопление в доме включено.";
			}
			else if (tempIn >= 25 && (stateHomeHeating & HOME_HEATING)) {
				stateHomeHeating &= ~HOME_HEATING;
				cout << "\nОтопление в доме выключено.";
			}
			if (stateOutlet & OUTLET) {
				if (tempIn >= 30 && (!(stateCond & AIR_CONDITIONER))) {
					stateCond |= AIR_CONDITIONER;
					cout << "\nКондиционер включен.";
				}
				else if (tempIn <= 25 && (stateCond & AIR_CONDITIONER)) {
					stateCond &= ~AIR_CONDITIONER;
					cout << "\nКондиционер выключен.";
				}
			}
			if (stateInDoorLight & INDOOR_LIGHT) {
				if (timeCount >= 16 && timeCount <= 20) {
					colorTemp = 5000 - (5000 - 2700) * (timeCount - 16) / 4;
					cout << "\nЦветовая температура в доме " << colorTemp;
				}
				else if (timeCount == 0 || timeCount == 24) {
					colorTemp = 5000;
				}
			}
			timeCount++;
			if (timeCount == 24) {
				timeCount = 0;
				dayCount++;
			}
			strCount = 0;
			time = ""; strTempOut = ""; strTempIn = ""; strMoveOut = ""; strLight = "";
		}
		else {
			cout << "\nВ доме отключено электропитание.";
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
