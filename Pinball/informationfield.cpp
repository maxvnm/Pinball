#include "header.h"
void createBall(HANDLE writeHandle, const int colors[], int anzahl);
void createScoreLine(HANDLE writeHandle, int x, int y);

void createInformationField(HANDLE writeHandle, const int colors[], int anzahlBaelle) {
	int x = 53;
	int y = 20;

	SetConsoleTextAttribute(writeHandle, colors[0]);
	// Erstellt die Trennlinien
	for (int i = 0; i < 30; i++) {
		cursorToXY(x++, y);
		cout << "°";
	}

	x = 53;
	y = 25;

	for (int i = 0; i < 30; i++) {
		cursorToXY(x++, y);
		cout << "°";
	}

	x = 56;
	y = 27;
	cursorToXY(x, y++);
	cout << "  ___   _   _    _    ";
	cursorToXY(x, y++);
	cout << " | _ ) /_\\ | |  | |   ";
	cursorToXY(x, y++);
	cout << " | _ \\/ _ \\| |__| |__";
	cursorToXY(x, y++);
	cout << " |___/_/ \\_\\____|____|";

	createBall(writeHandle, colors, anzahlBaelle);




	SetConsoleTextAttribute(writeHandle, colors[0]);
	x = 55;
	y = 37;
	createScoreLine(writeHandle, x, y);

	// Erstellt den Startscore
	SetConsoleTextAttribute(writeHandle, colors[1]);
	x = 59;
	y = 43;
	cursorToXY(x, y++);
	for (int i = 0; i < 17; i++) {
		cout << "-";
	}




	SetConsoleTextAttribute(writeHandle, colors[0]);
	// Erstellt den aktuellen Highscore
	x = 55;
	y = 2;
	cursorToXY(x, y++);
	cout << "  _  _ ___ ___ _  _       ";
	cursorToXY(x, y++);
	cout << " | || |_ _/ __| || |  ___ ";
	cursorToXY(x, y++);
	cout << " | __ || | (_ | __ | |___|";
	cursorToXY(x, y++);
	cout << " |_||_|___\\___|_||_|      ";

	x = 55;
	y = 6;
	createScoreLine(writeHandle, x, y);

	x = 55;
	y = 12;

	//Liste initialisierung für Ausgabe von Current Highscore und eigenen Score
	THighscore *Kopf;
	Kopf = new THighscore;
	Kopf->nach = NULL;
	read(Kopf);
	sort(Kopf);

	SetConsoleTextAttribute(writeHandle, colors[1]);
	cursorToXY(x, y++);
	cout << "Current Highscore";
	cursorToXY(x, y++);
	cout << Kopf->username;
	cout << " ";
	cout << Kopf->points;
	cout << " Points";

	y = 15;
	cursorToXY(x, y++);
	cout << "Your current Highscore";

	//checkt ob der Spieler schon existiert
	char username[20+1];
	strcpy_s(username,readUsername());
	int position = getPlayer(Kopf, username);
	if (position != 0){
		THighscore *Laeufer = Kopf;
		for (int i = 0; i < position; i++){
			Laeufer = Laeufer->nach;
		}
		cursorToXY(x, y++);
		cout << Laeufer->points;
		cout << " Points";
	} else{
		cursorToXY(x, y++);
		cout << "You have no Highscore yet";
	}


	// Erstellt den Startspielstatus
	SetConsoleTextAttribute(writeHandle, colors[2]);
	x = 65;
	y = 22;
	cursorToXY(x, y);
	cout << "READY";
}


// Erstellt die Bälle der Informationsleiste
void createBall(HANDLE writeHandle, const int colors[], int anzahl) {

	int x = 58;
	int y = 31;

	SetConsoleTextAttribute(writeHandle, colors[1]);

	for (int i = 0; i < anzahl; i++) {
		cursorToXY(x--, y++);
		cout << "---";
		cursorToXY(x, y++);
		cout << "/   \\";
		cursorToXY(x++, y++);
		cout << "\\   /";
		cursorToXY(x, y);
		cout << "---";

		x = x + 7;
		y = y - 3;
	}
}

// Gibt den Score in der Informationsleiste aus
void printScore(HANDLE writeHandle, const int colors[], int score) {
	SetConsoleTextAttribute(writeHandle, colors[4]);
	int x = 67;
	int y = 42;
	cursorToXY(x, y);
	cout << score;
}

// Erstellt die ScoreLinie
void createScoreLine(HANDLE writeHandle, int x, int y) {
	cursorToXY(x, y++);
	cout << "  ___  ___ ___  ___ ___ ";
	cursorToXY(x, y++);
	cout << " / __|/ __/ _ \\| _ \\ __|";
	cursorToXY(x, y++);
	cout << " \\__ \\ (_| (_) |   / _| ";
	cursorToXY(x, y++);
	cout << " |___/\\___\\___/|_|_\\___|";
}
