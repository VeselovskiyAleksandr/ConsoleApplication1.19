// ConsoleApplication1.19.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 16. Механическое пианино.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    enum musicalNotes {
        DO=1,  RE=2, MI=4, FA=8, SOL=16, LYA=32, CI=64,
    }; 
    string sheetMusic, melody="", note;
    int count = 1;
    int chord[12]; 
    for (int i = 0; i < 12; i++) {
       cout << "\n Введите музыкальный аккорд ";
       cin >> sheetMusic;     
       chord[i] = 0;      
        for (int j = 0; j < 3; j++) {
            note = sheetMusic[j];
          int  sound = stoi(note) - 1; 
          chord[i] |= 1 << sound; 
        }
    }
    for(int i=0;i<12;i++){
        int sound; 
      sound= chord[i];
          if (sound & DO) {
              melody += "Do";
          }
           if (sound & RE) {
              melody += "Re";
          }
           if (sound & MI) {
              melody += "Mi";
          }
          if (sound & FA) {
              melody += "Fa";
          }
           if (sound & SOL) {
              melody += "Sol";
          }
          if (sound & LYA) {
              melody += "Lya";
          }
           if (sound & CI) {
              melody += "Ci";
              sound >> 1;
          }
               melody += " ";          
    }
    cout <<"\n"<< melody<<"\n";
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
