#include "Menu.h"
#include "Game.h"

using namespace std;

// Функция выводит меню игры. activeItem - активный элемент
void Menu(int activeItem = 0) {
	char key = 0;

	// Выводим название игры псевдографикой (о цветовом оформлении https://habr.com/ru/post/94647/)
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m ____        _ _                   _____                           \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m|  _ \\      | | |      \x1b[33m  ___      \x1b[32m/ ____|                          \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "\x1b[32m ______   | |_) |_   _| | |___    \x1b[33m( _ )    \x1b[32m| |     _____      _____   ______ \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "\x1b[32m|______|  |  _ <| | | | | / __|   \x1b[33m/ _ \\/\\  \x1b[32m| |    / _ \\ \\ /\\ / / __| |______|\x1b[0m" << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m| |_) | |_| | | \\__ \\ \x1b[33m | (_>  <  \x1b[32m| |___| (_) \\ V  V /\\__ \\         \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m|____/ \\__,_|_|_|___/  \x1b[33m \\___/\\/ \x1b[32m  \\_____\\___/ \\_/\\_/ |___/         \x1b[0m" << endl;

	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t    " << "  +------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t    " << (activeItem == 0 ? "\x1b[32m>>>\x1b[0m" : "  -") << " игра на двоих                                        -" << endl;
	cout << "\t\t\t\t\t    " << "  +------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t    " << (activeItem == 1 ? "\x1b[32m>>>\x1b[0m" : "  -") << " игра против компьютера                               -" << endl;
	cout << "\t\t\t\t\t    " << "  +------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t    " << (activeItem == 2 ? "\x1b[32m>>>\x1b[0m" : "  -") << " правила игры                                         -" << endl;
	cout << "\t\t\t\t\t    " << "  +------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t    " << (activeItem == 3 ? "\x1b[32m>>>\x1b[0m" : "  -") << " выход                                                -" << endl;
	cout << "\t\t\t\t\t    " << "  +------------------------------------------------------+" << endl;

	while (key != 80 && key != 72 && key != 13)
	{
		key = _getch();

		switch (key) {
		case 80: // При нажатии стрелки вниз
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // Перемещение курсора в начальную позицию
			if (activeItem == 3) Menu(0); // Если указатель был на последней строке, то перенести курсор на 1ую строку
			else Menu(++activeItem); // Иначе перенести курсор на строку ниже
			break;

		case 72: // При нажтиии стрелки вверх (по аналогии с кодом выше)
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
			if (activeItem == 0) Menu(3);
			else Menu(--activeItem);
			break;
		case 13: // При нажатии кнопку Enter
			switch (activeItem) {
			case 0:
				system("cls"); // Очищаем консоль
				StartGame(true);
				break;
			case 1:
				system("cls"); // Очищаем консоль
				StartGame(false);
				break;
			case 2:
				system("cls"); // Очищаем консоль
				Rules(); // Рисуем правила
				break;
			case 3:
				exit(0);
				break;
			}
			break;
		}
	}
}

// Функция выводит правила игры. Чтобы вернуться назад в меню - нажать ESC
void Rules() {
	char key = 0;

	// Выводим название игры псевдографикой (о цветовом оформлении https://habr.com/ru/post/94647/)
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m ____        _ _                   _____                           \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m|  _ \\      | | |      \x1b[33m  ___      \x1b[32m/ ____|                          \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "\x1b[32m ______   | |_) |_   _| | |___    \x1b[33m( _ )    \x1b[32m| |     _____      _____   ______ \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "\x1b[32m|______|  |  _ <| | | | | / __|   \x1b[33m/ _ \\/\\  \x1b[32m| |    / _ \\ \\ /\\ / / __| |______|\x1b[0m" << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m| |_) | |_| | | \\__ \\ \x1b[33m | (_>  <  \x1b[32m| |___| (_) \\ V  V /\\__ \\         \x1b[0m" << endl;
	cout << "\t\t\t\t   " << "          \x1b[32m|____/ \\__,_|_|_|___/  \x1b[33m \\___/\\/ \x1b[32m  \\_____\\___/ \\_/\\_/ |___/         \x1b[0m" << endl;
	
	cout << "\t\t\t\t\t\t\t   " << "             _           " << endl;
	cout << "\t\t\t\t\t\t\t   " << "  _ __ _   _| | ___  ___ " << endl;
	cout << "\t\t\t\t\t\t\t   " << " | '__| | | | |/ _ \\/ __|" << endl;
	cout << "\t\t\t\t\t\t\t   " << " | |  | |_| | |  __/\\__ \\" << endl;
	cout << "\t\t\t\t\t\t\t   " << " |_|   \\__,_|_|\\___||___/" << endl;

	cout << endl << endl;
	cout << "\t\t\t\t   " << "В классическом варианте игра рассчитана на двух игроков. Каждый из игроков за-" << endl;
	cout << "\t\t\t\t   " << "думывает и записывает тайное 4-значное число с неповторяющимися цифрами. Игро-" << endl;
	cout << "\t\t\t\t   " << "ки делают ходы по очереди, чтобы узнать цифры  соперника и их порядок." << endl << endl;

	cout << "\t\t\t\t   " << "Каждый ход состоит из четырёх цифр, 0 может стоять на первом месте. В ответ на" << endl;
	cout << "\t\t\t\t   " << "ход показывается число отгаданных цифр, стоящих на своих местах (число быков) " << endl;
	cout << "\t\t\t\t   " << "и число отгаданных цифр, стоящих не на своих местах (число коров)." << endl << endl;

	cout << "\t\t\t\t   " << "Побеждает игрок, первый угадавший число соперника." << endl;

	// Перемещение курсора в заданную позицию
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 117, 48 });
	cout << "\x1b[33mESC - вернуться в главное меню\x1b[0m";
                         

	while (key != 27)
	{
		key = _getch();

		switch (key) {
		case 27: // При нажатии ESC
			system("cls"); // Очищаем консоль
			Menu(0); // Рисуем меню
			break;
		}
	}
}