#include "header.h"

void showScores(HANDLE writeHandle, const int colors[]) {
	system("cls");
	createTemplateMenu(writeHandle, colors);

	THighscore *Kopf;
	Kopf = new THighscore;
	Kopf->nach = NULL;
	read(Kopf);
	sort(Kopf);

	cursorToXY(21, 8);
	cout << "Username:";
	cursorToXY(59, 8);
	cout << "Points:" << endl;

	createLine(writeHandle, colors, 85);
	SetConsoleTextAttribute(writeHandle, colors[1]);

	int counter = count(Kopf);
	THighscore *Laeufer = Kopf;
	int y = 9;
	if (counter >= 10) {
		for (int i = 0; i < 10; i++) {
			y++;

			if (i % 2 == 0) {
				SetConsoleTextAttribute(writeHandle, colors[1]);
			}
			else {
				SetConsoleTextAttribute(writeHandle, colors[0]);
			}
			cursorToXY(2, y);
			cout << i + 1;
			cursorToXY(21, y);
			cout << Laeufer->username;
			cursorToXY(44, y);
			cout << ".";
			cursorToXY(59, y);
			cout << Laeufer->points;
			Laeufer = Laeufer->nach;
		}
	}
	else {
		for (int i = 0; i < counter; i++) {
			y++;

			if (i % 2 == 0) {
				SetConsoleTextAttribute(writeHandle, colors[1]);
			}
			else {
				SetConsoleTextAttribute(writeHandle, colors[0]);
			}
			cursorToXY(2, y);
			cout << i + 1;
			cursorToXY(21, y);
			cout << Laeufer->username;
			cursorToXY(44, y);
			cout << ".";
			cursorToXY(59, y);
			cout << Laeufer->points;
			Laeufer = Laeufer->nach;
		}
	}

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) != 0) {
			system("cls");
			createMenu(writeHandle, colors);
		}
		else {
			system("pause> 0");
		}
	}
}
