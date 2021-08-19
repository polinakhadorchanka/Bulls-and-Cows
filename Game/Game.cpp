#include "Game.h"
#include "Menu.h"

using namespace std;

// ������� ��������� ����. twoPeople = true, ���� ���� �� �����, false - ���� � �����������
void StartGame(bool twoPeople) {
	GAMEVALUES gameValues; // ������� ���������, � ������� ����� ��������� ������ ����

	// ����������� ����� � 1�� ������
	while (true) {
		gameValues.value1 = printDialog("  ����� 1, ������� �����, ��������� �� 4� ��������������� ���� (0 ��-��� ���� ������): ");
		if (correctValue(gameValues.value1))
			break;
		else {
			system("cls");
			printMessage("�� ����� ������������ ��������!");
		}
	}

	if (twoPeople) { // ���� ���� �� �����, ����������� ����� � 2�� ������
		while (true) {
			gameValues.value2 = printDialog("  ����� 2, ������� �����, ��������� �� 4� ��������������� ���� (0 ��-��� ���� ������): ");
			if (correctValue(gameValues.value1))
				break;
			else {
				system("cls");
				printMessage("�� ����� ������������ ��������!");
			}
		}
	}
	else gameValues.value2 = generateValue(123, 9999); // ����� ����� ���������� ���������

	// ����������, ��� ����� ������
	srand(time(0));
	gameValues.moveFirst = 0 + rand() % (1 - 0 + 1); // 1 - ������ ����� 1� �����, 0 - 2�

	gameValues.nextStep = !gameValues.moveFirst;

	// ��������� ������ ���
	system("cls");
	StartNewMove(gameValues, twoPeople, 123, 9999);
}

// ���������� ���� ��� ������� ������������ �����, ���������� ��������� � ���������� ��������
string printDialog(string msg) {
	int messLine = msg.size() / 69 + 1; // ���������� ���������� �����, � ������� ���������� ���� ���������
	string line(71, '-'), res;
	short pos = 18;
	char key = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m +" << line << "+ \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;

	for (int i = 0; i < messLine; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
		cout << "\x1b[0;37;40m | " << setw(69) << left << msg.substr(i * 69, 69) << " | \x1b[0m" << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                         \x1b[7m +--------+ \x1b[0;37;40m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                         \x1b[7m |   ��   | \x1b[0;37;40m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                         \x1b[7m +--------+ \x1b[0;37;40m  " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m |" << "                                                                       " << "| \x1b[0m" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
	cout << "\x1b[0;37;40m +" << line << "+ \x1b[0m" << endl;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 43, pos - 6 });

	ShowConsoleCursor(true); // �������� ����������� �������
	getline(cin, res); // ������ ������ � ����������
	ShowConsoleCursor(false); // ��������� ����������� �������

	return res;
}

// ����� ��������� ��������������� ���������
void printMessage(string msg) {
	int messLine = msg.size() / 69 + 1; // ���������� ���������� �����, � ������� ���������� ���� ���������
	string line(71, '-');
	short pos = 19;
	char key = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 38, ++pos }); // ���������� ������ � ������ �������
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
	cout << "\x1b[0;37;45m |" << "                                                         \x1b[7m |   ��   | \x1b[0;37;45m  " << "| \x1b[0m" << endl;
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

// ������� ���������� true, ���� ��������� ����� ������������� �������� ����
bool correctValue(string value) {
	if (value.size() != 4) return false;
	else if (!atoi(value.c_str()) || (value[0] != '0' && atoi(value.c_str()) < 1000)) return false;
	else if (value[0] == value[1] || value[0] == value[2] || value[0] == value[3] || value[1] == value[2] || value[1] == value[3] || value[2] == value[3]) return false;
	else return true;
}

// ��������� ����� �����������, ���������� ��� �����
string generateValue(int a, int b) {
	int valueI;
	string valueS = "";

	if (a == b - 1) {
		if (a < 1000)
			valueS = "0" + to_string(a);
	}
	else {
		while (true) {
			valueI = a + rand() % (b - a + 1); // ���������� ��������� �����
			if (valueI < 1000) // ���� ��������������� 3�������� �����, ���������� � ������ 0
				valueS = "0" + to_string(valueI);
			else valueS = to_string(valueI);

			if (correctValue(valueS)) // ���� ��������������� ����� ������������� ��������, �� ������� �� ����� � ���������� ���, ����� ��������� ���������
				break;
		}
	}

	return valueS;
}

// ��������� ����� ���, gameValues - ������ ������� ����, twoPeople - true, ���� ������ ��� ������, ���� ���� � �����������, �� ����������� ������� ���������, ����� ����� ����������
void StartNewMove(GAMEVALUES gameValues, bool twoPeople, int min = 123, int max = 9999) {
	// ������� �����
	if(twoPeople)
		printHeader("����� 1", "����� 2", gameValues.moveFirst);
	else printHeader("����� 1", "���������", gameValues.moveFirst);

	string line(50, ' ');
	short lineNum; // ����� ������ �������, � ������� ����� �������� ����� �� ������� ����
	string value = ""; // ��������, ������� ����� ������� ����� �� ������� ����
	string res = ""; // ��������� 
	lineNum = 4 + gameValues.step * 3;

	if (gameValues.moveFirst) { // ���� ������ ����� 1� �����
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3, lineNum });
		cout << "\x1b[33m�����: \x1b[0m";

		while (true) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 10, lineNum });
			ShowConsoleCursor(true);
			getline(cin, value);
			if (correctValue(value))
				break;
			else {
				// ������� ������ � ������� �� ������, ���� � ���� ������� ��� ���� �����
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 10, lineNum });
				cout << line;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15, lineNum });
				cout << "\x1b[31m������������ ��������!\x1b[0m";
			}
			ShowConsoleCursor(false);
		}
		ShowConsoleCursor(false);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15, lineNum });
		cout << line;

		res = getResult(value, gameValues.value2);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3, lineNum+1 });
		cout << "\x1b[33m" << res << "\x1b[0m";

		if (res == "4 �. 0 �.") {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
			printMessage("����� 1 �������!");
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
		if (twoPeople) { // ���� ������ ��� �������� � ����� 2� �����
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum });
			cout << "\x1b[33m�����: \x1b[0m";

			while (true) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 83, lineNum });
				ShowConsoleCursor(true);
				getline(cin, value);
				if (correctValue(value))
					break;
				else {
					// ������� ������ � ������� �� ������, ���� � ���� ������� ��� ���� �����
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 83, lineNum });
					cout << line;

					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 88, lineNum });
					cout << "\x1b[31m������������ ��������!\x1b[0m";
				}
				ShowConsoleCursor(false);
			}
			ShowConsoleCursor(false);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 88, lineNum });
			cout << line;

			res = getResult(value, gameValues.value1);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum + 1 });
			cout << "\x1b[33m" << res << "\x1b[0m";

			if (res == "4 �. 0 �.") {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				printMessage("����� 2 �������!");
				system("cls");
				Menu(0);
			}
			else {
				if (!gameValues.nextStep) gameValues.step++;
				gameValues.moveFirst = !gameValues.moveFirst;
				StartNewMove(gameValues, twoPeople, min, max);
			}
		}
		else { // ���� ����� ���������
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum });
			cout << "\x1b[33m�����: \x1b[0m";

			value = generateValue(min, max);

			Sleep(500);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 83, lineNum });
			cout << value;

			res = getResult(value, gameValues.value1);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 76, lineNum + 1 });
			cout << "\x1b[33m" << res << "\x1b[0m";

			if (res == "4 �. 0 �.") {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				printMessage("��������� �������!");
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

// ������� �����, moveFirst - true, ���� ����� 1� �����
void printHeader(string player1, string player2, bool moveFirst) {
	string line(146, '-');

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // ����������� ������� � ��������� �������
	cout << " +" << line << "+ " << endl;
	// �������� ������� ������ ������ � �������� �����
	cout << setw(83) << left << (moveFirst ? " | \x1b[32m" + player1 + "\x1b[0m" : " | \x1b[37m" + player1 + "\x1b[0m") << 
		setw(83) << left << (!moveFirst ? "| \x1b[32m" + player2 + "\x1b[0m" : "| \x1b[37m" + player2 + "\x1b[0m") << "| " << endl;
	cout << " +" << line << "+ " << endl;
}

// ��������� value1 �� ���������� � value2, ���������� ������ � ������� '<x>�. <y>�.'
string getResult(string value1, string value2) {
	int bulls = 0, cows = 0;

	// ������ ���-�� �����
	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == value2[i]) bulls++;
	}

	// ������ ���-�� �����
	for (auto el : value1) { 
		for (int i = 0; i < value2.size(); i++)
			if (el == value2[i]) cows++;
	}

	cows -= bulls;

	return to_string(bulls) + " �. " + to_string(cows) + " �.";
}