#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("MODE CON: COLS=150 LINES=50"); // Задаем размер окна (после запуска менять размер консоли не рекомендуется)
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { 150, 9999 }); // Полосы прокрутки
	ShowConsoleCursor(false); // Скрываем отображение курсора

	Menu(0);
}
