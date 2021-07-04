// ConsoleApplication1.19.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 16. Калькулятор.

#include <iostream>
#include <locale.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string mathAction;
	double  result, result1, result2;
	char actionSign;
	cout << "\nВведите математическое действие с двумя числами\n";
	cin >> mathAction;
	stringstream actionString (mathAction);
	actionString >> result1>> actionSign >> result2;
	if (actionSign == '+') {
		result = result1 + result2;
	}
	else if (actionSign == '-') {
		result = result1 - result2;
	}
	else if (actionSign == '*') {
		result = result1 * result2;
	}
	else if (actionSign == '/') {
		result = result1 / result2;
	}
    else {
		cout << "\nУкажите правильно действие.";
	}
	cout << "\nРезультат операции: " << result;
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
