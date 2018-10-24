#include "header.h"
void createSelection(HANDLE writeHandle, const int colors[]);
void setHighscoreInformation(HANDLE writeHandle, const int colors[]);
void createKeyHelp(HANDLE writeHandle, const int colors[]);
string getSelectText(int auswahl);
void select(HANDLE writeHandle, const int colors[]);
void createKeyHelpLine(int x, int y, HANDLE writeHandle);
void createCredits(HANDLE writeHandle, const int colors[]);



// Ruft die Funktionen zur Erstellung und Aufgabe des Menüs auf
void createMenu(HANDLE writeHandle, const int colors[]) {

	createTemplateMenu(writeHandle, colors);
	createSelection(writeHandle, colors);
	setHighscoreInformation(writeHandle, colors);
	createKeyHelp(writeHandle, colors);
	select(writeHandle, colors);
}

// Fügt die Auswahlfelder in das Template ein
void createSelection(HANDLE writeHandle, const int colors[]) {

	const int x = 30;
	int y = 9;

	for (int i = 1; i < 5; i++) {
		if (i == 1) {
			SetConsoleTextAttribute(writeHandle, colors[2]);
			cursorToXY(x, y);
			cout << getSelectText(i);
			SetConsoleTextAttribute(writeHandle, colors[0]);
		}

		else {
			cursorToXY(x, y);
			cout << getSelectText(i);
		}
		y = y + 3;
	}
}

// Ändert die Farben der Auswahl und setzt für jede Auswahl einen festen Wert
void select(HANDLE writeHandle, const int colors[]) {
	int auswahl = 1;
	int x = 30;
	int y = 9;


	while (true) {
		if ((GetAsyncKeyState(0x53) != 0 || GetAsyncKeyState(VK_DOWN) != 0) && auswahl < 4) {
			SetConsoleTextAttribute(writeHandle, colors[0]);
			cursorToXY(x, y);
			cout << getSelectText(auswahl++);
			y = y + 3;
			SetConsoleTextAttribute(writeHandle, colors[2]);
			cursorToXY(x, y);
			cout << getSelectText(auswahl);
		}

		else if ((GetAsyncKeyState(0x57) != 0 || GetAsyncKeyState(VK_UP) != 0) && auswahl > 1) {
			SetConsoleTextAttribute(writeHandle, colors[0]);
			cursorToXY(x, y);
			cout << getSelectText(auswahl--);
			y = y - 3;
			SetConsoleTextAttribute(writeHandle, colors[2]);
			cursorToXY(x, y);
			cout << getSelectText(auswahl);
		}

		else if (GetAsyncKeyState(VK_RETURN)) {
			switch (auswahl) {
			case 1: prepareGame(writeHandle, colors);
				break;
			case 2: showScores(writeHandle, colors);
				break;
			case 3:
				createCredits(writeHandle, colors);
				break;
			case 4:
				exit(0);
			}
		}
		system("pause > 0");
	}
}

// Returnt den Auswahltext je nach übergebenem Wert
string getSelectText(int auswahl) {

	const string selection[] = { "--->      START      <---", "--->      SCORES     <---",
		"--->      CREDITS    <---", "--->      EXIT       <---" };

	switch (auswahl) {
	case 1: return selection[0];
		break;
	case 2: return selection[1];
		break;
	case 3: return selection[2];
		break;
	case 4: return selection[3];
		break;
	}
}

// Setzt die Highscoreinformationen
void setHighscoreInformation(HANDLE writeHandle, const int colors[]) {
	int x = 6;
	int y = 9;
	string highscore[] = { "Current", "Highscore"};

	THighscore *Kopf;
	Kopf = new THighscore;
	Kopf->nach = NULL;
	read(Kopf);
	sort(Kopf);

		for (int i = 0; i < 4; i++) {
			if (i == 1 || i == 3) {
				cursorToXY(x, y++);
				SetConsoleTextAttribute(writeHandle, colors[0]);
				if (i == 1){
					cout << highscore[i];
				}
				else{
					cout << Kopf->points;
					cout << " Points";
				}
			}
			else {
				cursorToXY(x, y++);
				SetConsoleTextAttribute(writeHandle, colors[1]);
				if (i == 0){
					cout << highscore[i];
				}
				else{
					cout << Kopf->username;
				}
			}

		}
	}


// Erstellt die KeyHilfe für den Benutzer
void createKeyHelp(HANDLE writeHandle, const int colors[]) {
	int x = 66;
	int y = 8;

	SetConsoleTextAttribute(writeHandle, colors[2]);
	createKeyHelpLine(x--, y++, writeHandle);

	cursorToXY(x, y++);
	cout << ".    Buttons   .";
	cursorToXY(x, y++);
	cout << ".   [^]  [W]   .";
	cursorToXY(x, y);
	cout << ".   [V]  [S]   .";
	createKeyHelpLine(66, 12, writeHandle);
}

// Erstellt die Linie der Umrandung zur KeyHilfe
void createKeyHelpLine(int x, int y, HANDLE writeHandle) {

	cursorToXY(x, y);
	for (int i = 0; i < 14; i++) {
		cout << ".";
	}


}

// Erstellt die Credits Ansicht
void createCredits(HANDLE writeHandle, const int colors[]) {
	char text[60] = { "This Game is developed by ..." };
	system("cls");
	createTemplateMenu(writeHandle, colors);
	cursorToXY(13, 13);
	SetConsoleTextAttribute(writeHandle, colors[2]);
	for (int i = 0; i < 60; i++) {
		cout << text[i];
		Sleep(35);
	}
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
