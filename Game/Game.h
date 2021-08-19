#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include <ctime>

using namespace std;

typedef struct gameValues {
	string value1; // ����� 1�� ������
	string value2; // ����� 2�� ������/����������
	bool moveFirst; // True - ���� ��� 1�� ������, ����� - false
	int step = 0; // ����� ����
	bool nextStep; // true - ���� ��� ����������� ����� 1�� ������, ����� false
} GAMEVALUES;

string printDialog(string msg); // ���������� ���� ��� ������� ������������ �����, ���������� ��������� � ���������� ��������
void printMessage(string msg); // ����� ��������� ��������������� ���������

void StartGame(bool twoPeople); // ������� ��������� ����. twoPeople = true, ���� ���� �� �����, false - ���� � �����������
bool correctValue(string value); // ������� ���������� true, ���� ��������� ����� ������������� �������� ����
string generateValue(int a, int b); // ��������� ����� �����������
void StartNewMove(GAMEVALUES gameValues, bool twoPeople, int min, int max); // ��������� ����� ���, gameValues - ������ ������� ����, twoPeople - true, ���� ������ ��� ������
void printHeader(string player1, string player2, bool moveFirst); // ������� �����
string getResult(string value1, string value2); // ��������� value1 �� ���������� � value2, ���������� ������ � ������� '<x>�. <y>�.'