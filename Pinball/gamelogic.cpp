#include "header.h"


// Bereitet das Spiel vor und ruft die einzelnen Funktionen während des Spiels auf
void prepareGame(HANDLE writeHandle, const int colors[]) {

	string username = createUsername(writeHandle, colors);
	writeUsername(username);
	createTemplateField(writeHandle, colors);
	createInstruction(writeHandle, colors, username);
	int score = 0;


	// 3 Schleifendurchläufe für jeweils 3 Runden Pinball
	for (int i = 3; i > 0; i--) {
		system("cls");
		createGameField(writeHandle, colors);
		createInformationField(writeHandle, colors, i);
		int statusRightFlipper = 0;
		int statusLeftFlipper = 0;
		int x = 21;
		const int y = 26;
		int position = 1;
		int bugfixLeft = 0;
		int bugfixRight = 0;

		int ballx = 15;
		int bally = 2;
		bool gameRun = true;

		while (true) {
			if (GetAsyncKeyState(VK_TAB) != 0) {
				createStartElement(writeHandle, colors, 3);
				startGame(writeHandle, colors);
				break;

			}
			else {
				system("pause > 0");
			}


		}

		Sleep(800);
		srand(time(NULL));


		// Zufällige Richtung
		int way;

		int zahl = rand() % 5;
		if (zahl < 10) {
			way = 1;
		}
		else {
			way = 3;
		}


		cursorToXY(ballx, bally);
		cout << "0";

		// Solange gameRun true ist wird das Spiel fortgesetzt
		while (gameRun) {
			SetConsoleTextAttribute(writeHandle, colors[1]);
			controlphysics(writeHandle, colors, &ballx, &bally, &way, statusLeftFlipper, statusRightFlipper, &gameRun, &score, &bugfixLeft, &bugfixRight);
			SetConsoleTextAttribute(writeHandle, colors[2]);
			if (GetAsyncKeyState(0x41) != 0 || GetAsyncKeyState(VK_LEFT) != 0) {
				actionLeftFlipper(&statusLeftFlipper, writeHandle, true);
				bugfixLeft++;

			}

			else {
				actionLeftFlipper(&statusLeftFlipper, writeHandle, false);
				bugfixLeft = 0;
			}

			if (GetAsyncKeyState(0x44) != 0 || GetAsyncKeyState(VK_RIGHT) != 0) {
				actionRightFlipper(&statusRightFlipper, writeHandle, true);
				bugfixRight++;
			}

			else {
				actionRightFlipper(&statusRightFlipper, writeHandle, false);
				bugfixRight = 0;
			}

			if (x == 40) {
				position = 0;
			}
			else if (x == 1) {
				position = 1;
			}
			SetConsoleTextAttribute(writeHandle, colors[0]);
			moveWall(&x, y, position);
			printScore(writeHandle, colors, score);
		}
	}

	system("pause > 0");

	writePoints(to_string(score));
	THighscore *Kopf;
	Kopf = new THighscore;
	Kopf->nach = NULL;
	read(Kopf);
	update(Kopf, readUsername());
	write(Kopf);

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) != 0) {
			system("cls");
			createMenu(writeHandle, colors);
		}
		else {
			system("pause > 0");
		}
	}
}
