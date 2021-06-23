// ConsoleApplication1.19.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 16. Спидометр.

#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float currentlySpeed = 0, minSpeed = 0, epsilon = 0.01;
	string text1="\n Скорость машины ", text2, text0, text3=" км/ч\n";
	cout <<text1<<" 0"<<text3;
	do {
		int x=0, y=0, t=0;
		float  maxSpeed = 150, speedChange = 0;
		cout << "\nУкажите изменение скорости машины\n";
		cout << "(Для увеличения скорости + , для уменьшения - )\n";
		cin >> speedChange;
		currentlySpeed += speedChange;
		if (currentlySpeed <= minSpeed + epsilon) {
			currentlySpeed = 0;
			cout << text1 << " 0" << text3;
			break;
		}
		else if (currentlySpeed >= maxSpeed - epsilon) {
			currentlySpeed = 150.;
			y = 150; t = 0;
		}
		else {
		    x = currentlySpeed*10;           //Переменные x и y служат для округления скорости до 0.1 км/ч,
            y =(int) x/10;                  //в случае, если пользователь введёт значение с большей точностью
		    t = x % 10;                    //т.к. такова цена деления спидометра		
		}
			text2 = to_string(y);
		text0 = to_string(t);
		cout << text1 << text2 <<"."<<text0<< text3;
	} while (currentlySpeed > minSpeed + epsilon);
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
