// ConsoleApplication1.19.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 16. Механическое пианино.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    enum musicalNotes {
        DO,  RE, MI, FA, SOL, LYA, CI,
    };
    string sheetMusic, melody="", note;
    int noteNumber, count = 0;
    cout << "\n Введите музыкальную мелодию ";
    cin >> sheetMusic;
    for (int i = 0;i< sheetMusic.size();i++) {
        note = sheetMusic[i];
        noteNumber = stoi(note);
        switch (noteNumber) {
        case 1:
            melody += "Do";
            break;
        case 2:
            melody += "Re";
            break;
        case 3:
            melody += "Mi";
            break;
        case 4:
            melody += "Fa";
            break;
        case 5:
            melody += "Sol";
            break;
        case 6:
            melody += "Lya";
            break;
        case 7:
            melody += "Ci";
            break;
        default:
            cout << "\nОшибка. Введите правильно ноты. ";
   }
        count++;
        if (count % 3 == 0) {
            melody += " ";
        }
    }
    cout <<"\n"<< melody;
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
