#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include <ctime>

using namespace std;

typedef struct gameValues {
	string value1; // Число 1го игрока
	string value2; // Число 2го игрока/компьютера
	bool moveFirst; // True - если ход 1го игрока, иначе - false
	int step = 0; // Номер хода
	bool nextStep; // true - если ход обновляется после 1го игрока, иначе false
} GAMEVALUES;

string printDialog(string msg); // Диалоговое окно для запроса загадываемых чисел, возвращает введенное с клавиатуры значение
void printMessage(string msg); // Вывод сообщения информационного характера

void StartGame(bool twoPeople); // Функция запускает игру. twoPeople = true, если игра на двоих, false - если с компьютером
bool correctValue(string value); // Функция возвращает true, если введенное число удовлетворяет правилам игры
string generateValue(int a, int b); // Генерация числа компьютером
void StartNewMove(GAMEVALUES gameValues, bool twoPeople, int min, int max); // Запускает новых ход, gameValues - данные текущей игры, twoPeople - true, если играет два игрока
void printHeader(string player1, string player2, bool moveFirst); // Выводит хэдер
string getResult(string value1, string value2); // Проверяет value1 на совпадение с value2, возвращает строку в формате '<x>б. <y>к.'