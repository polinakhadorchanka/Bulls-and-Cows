#include "Game.h"
#include "Menu.h"

using namespace std;

// Функция запускает игру. twoPeople = true, если игра на двоих, false - если с компьютером
void StartGame(bool twoPeople) {
	GAMEVALUES gameValues; // Создаем структуру, в которой будут храниться данные игры

	// Запрашиваем число у 1го игрока
	while (true) {
		gameValues.value1 = printDialog("  Игрок 1, введите число, состоящее из 4х неповторяющихся цифр (0 мо-жет быть первым): ");
		if (correctValue(gameValues.value1))
			break;
		else {
			system("cls");
			printMessage("Вы ввели недопустимое значение!");
		}
	}

	if (twoPeople) { // Если игра на двоих, запрашиваем число у 2го игрока
		while (true) {
			gameValues.value2 = printDialog("  Игрок 2, введите число, состоящее из 4х неповторяющихся цифр (0 мо-жет быть первым): ");
			if (correctValue(gameValues.value1))
				break;
			else {
				system("cls");
				printMessage("Вы ввели недопустимое значение!");
			}
		}
	}
	else gameValues.value2 = generateValue(123, 9999); // Иначе число генерирует компьютер

	// Определяем, кто ходит первым
	srand(time(0));
	gameValues.moveFirst = 0 + rand() % (1 - 0 + 1); // 1 - первым ходит 1й игрок, 0 - 2й

	gameValues.nextStep = !gameValues.moveFirst;

	// Запускаем первых ход
	system("cls");
	StartNewMove(gameValues, twoPeople, 123, 9999);
}

// Диалоговое окно для запроса загадываемых чисел, возвращает введенное с клавиатуры значение
string printDialog(string msg) {
	int messLine = msg.size() / 69 + 1; // Определяем количество строк, в которое поместится наше сообщение
	string line(71, '-'), res;
	short pos = 18;
	char key = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m +" << line << "+ \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;

	for (int i = 0; i < messLine; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
		cout << "\x1b[0;37;40m | " << setw(69) << left << msg.substr(i * 69, 69) << " | \x1b[0m" << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                         \x1b[7m +--------+ \x1b[0;37;40m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                         \x1b[7m |   ОК   | \x1b[0;37;40m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                         \x1b[7m +--------+ \x1b[0;37;40m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;40m +" << line << "+ \x1b[0m" << endl;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 43, pos - 6 });

	ShowConsoleCursor(true); // Включаем отображение курсора
	getline(cin, res); // Вводим строку с клавиатуры
	ShowConsoleCursor(false); // Отключаем отображение курсора

	return res;
}

// Вывод сообщения информационного характера
void printMessage(string msg) {
	int messLine = msg.size() / 69 + 1; // Определяем количество строк, в которое поместится наше сообщение
	string line(71, '-');
	short pos = 19;
	char key = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // Перемещаем курсор в нужную позицию
	cout << "\x1b[0;37;45m +" << line << "+ \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m |" << "                                                                       " << "| \x1b[0m" << endl;

	for (int i = 0; i < messLine; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
		cout << "\x1b[0;37;45m | " << setw(69) << left << msg.substr(i * 69, 69) << " | \x1b[0m" << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m |" << "                                                         \x1b[7m +--------+ \x1b[0;37;45m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m |" << "                                                         \x1b[7m |   ОК   | \x1b[0;37;45m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m |" << "                                                         \x1b[7m +--------+ \x1b[0;37;45m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); 
	cout << "\x1b[0;37;45m +" << line << "+ \x1b[0m" << endl;

	while (key != 13)
	{
		key = _getch();
	}
}

// Функция возвращает true, если введенное число удовлетворяет правилам игры
bool correctValue(string value) {
	if (value.size() != 4) return false;
	else if (!atoi(value.c_str()) || (value[0] != '0' && atoi(value.c_str()) < 1000)) return false;
	else if (value[0] == value[1] || value[0] == value[2] || value[0] == value[3] || value[1] == value[2] || value[1] == value[3] || value[2] == value[3]) return false;
	else return true;
}

// Генерация числа компьютером, возвращает это число
string generateValue(int a, int b) {
	int valueI;
	string valueS = "";

	if (a == b - 1) {
		if (a < 1000)
			valueS = "0" + to_string(a);
	}
	else {
		while (true) {
			valueI = a + rand() % (b - a + 1); // Генерируем случайное число
			if (valueI < 1000) // Если сгенерировалось 3хзначное число, дописываем в начало 0
				valueS = "0" + to_string(valueI);
			else valueS = to_string(valueI);

			if (correctValue(valueS)) // Если сгенерированное число удовлетворяет правилам, то выходим из цикла и возвращаем его, иначе повторяем генерацию
				break;
		}
	}

	return valueS;
}

// Запускает новых ход, gameValues - данные текущей игры, twoPeople - true, если играет два игрока, если игра с компьютером, то указываются границы диапазона, иначе можно пропускать
void StartNewMove(GAMEVALUES gameValues, bool twoPeople, int min = 123, int max = 9999) {
	// Выведем хэдер
	if(twoPeople)
		printHeader("Игрок 1", "Игрок 2", gameValues.moveFirst);
	else printHeader("Игрок 1", "Компьютер", gameValues.moveFirst);

	string line(50, ' ');
	short lineNum; // Номер строки консоли, в которой будем выводить текст на текущем ходе
	string value = ""; // Значение, которое будет вводить игрок на текущем ходу
	string res = ""; // Результат 
	lineNum = 4 + gameValues.step * 3;

	if (gameValues.moveFirst) { // Если сейчас ходит 1й игрок
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3, lineNum });
		cout << "\x1b[33mЧисло: \x1b[0m";

		while (true) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 10, lineNum });
			ShowConsoleCursor(true);
			getline(cin, value);
			if (correctValue(value))
				break;
			else {
				// Стираем строку в консоли на случай, если в этой позиции уже есть текст
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 10, lineNum });
				cout << line;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15, lineNum });
				cout << "\x1b[31mНедопустимое значение!\x1b[0m";
			}
			ShowConsoleCursor(false);
		}
		ShowConsoleCursor(false);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15, lineNum });
		cout << line;

		res = getResult(value, gameValues.value2);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3, lineNum+1 });
		cout << "\x1b[33m" << res << "\x1b[0m";

		if (res == "4 б. 0 к.") {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
			printMessage("Игрок 1 победил!");
			system("cls");
			Menu(0);
		}
		else {
			if (gameValues.nextStep) gameValues.step++;
			gameValues.moveFirst = !gameValues.moveFirst;
			StartNewMove(gameValues, twoPeople, min, max);
		}
	}
	else {
		if (twoPeople) { // Если играют два человека и ходит 2й игрок
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum });
			cout << "\x1b[33mЧисло: \x1b[0m";

			while (true) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 83, lineNum });
				ShowConsoleCursor(true);
				getline(cin, value);
				if (correctValue(value))
					break;
				else {
					// Стираем строку в консоли на случай, если в этой позиции уже есть текст
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 83, lineNum });
					cout << line;

					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 88, lineNum });
					cout << "\x1b[31mНедопустимое значение!\x1b[0m";
				}
				ShowConsoleCursor(false);
			}
			ShowConsoleCursor(false);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 88, lineNum });
			cout << line;

			res = getResult(value, gameValues.value1);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum + 1 });
			cout << "\x1b[33m" << res << "\x1b[0m";

			if (res == "4 б. 0 к.") {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				printMessage("Игрок 2 победил!");
				system("cls");
				Menu(0);
			}
			else {
				if (!gameValues.nextStep) gameValues.step++;
				gameValues.moveFirst = !gameValues.moveFirst;
				StartNewMove(gameValues, twoPeople, min, max);
			}
		}
		else { // Если ходит компьютер
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum });
			cout << "\x1b[33mЧисло: \x1b[0m";

			value = generateValue(min, max);

			Sleep(500);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 83, lineNum });
			cout << value;

			res = getResult(value, gameValues.value1);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum + 1 });
			cout << "\x1b[33m" << res << "\x1b[0m";

			if (res == "4 б. 0 к.") {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				printMessage("Компьютер победил!");
				system("cls");
				Menu(0);
			}
			else {
				if (!gameValues.nextStep) gameValues.step++;

				gameValues.moveFirst = !gameValues.moveFirst;

				int mid = (min + max) / 2;
				if (atoi(value.c_str()) < mid) {
					if (atoi(gameValues.value1.c_str()) > atoi(value.c_str()))
						min = atoi(value.c_str());
					else max = mid;
				}
				else {
					if (atoi(gameValues.value1.c_str()) < atoi(value.c_str()))
						max = atoi(value.c_str());
					else min = mid;
				}

				StartNewMove(gameValues, twoPeople, min, max);
			}
		}
	}
}

// Выводит хэдер, moveFirst - true, если ходит 1й игрок
void printHeader(string player1, string player2, bool moveFirst) {
	string line(146, '-');

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // Перемещение курсора в начальную позицию
	cout << " +" << line << "+ " << endl;
	// Выделяем зеленым цветом игрока с активным ходом
	cout << setw(83) << left << (moveFirst ? " | \x1b[32m" + player1 + "\x1b[0m" : " | \x1b[37m" + player1 + "\x1b[0m") << 
		setw(83) << left << (!moveFirst ? "| \x1b[32m" + player2 + "\x1b[0m" : "| \x1b[37m" + player2 + "\x1b[0m") << "| " << endl;
	cout << " +" << line << "+ " << endl;
}

// Проверяет value1 на совпадение с value2, возвращает строку в формате '<x>б. <y>к.'
string getResult(string value1, string value2) {
	int bulls = 0, cows = 0;

	// Узнаем кол-во быков
	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == value2[i]) bulls++;
	}

	// Узнаем кол-во коров
	for (auto el : value1) { 
		for (int i = 0; i < value2.size(); i++)
			if (el == value2[i]) cows++;
	}

	cows -= bulls;

	return to_string(bulls) + " б. " + to_string(cows) + " к.";
}