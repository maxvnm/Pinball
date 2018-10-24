#include "header.h"
void createLine(HANDLE writeHandle, const int colors[], int laenge);
void createSign(HANDLE writeHandle, const int colors[]);
void createSpace(HANDLE writeHandle, const int colors[], int laenge);
void createFieldLine(HANDLE writeHandle);


// Erstellt das Template für das Menü
void createTemplateMenu(HANDLE writeHandle, const int colors[]) {

	const int laenge = 85;

	createLine(writeHandle, colors, laenge);
	createSign(writeHandle, colors);
	createLine(writeHandle, colors, laenge);
	createSpace(writeHandle, colors, laenge);
	createLine(writeHandle, colors, laenge);

}

//Erstellt die Linie des Menüs mit der Länge des übergebenen Integers
void createLine(HANDLE writeHandle, const int colors[], int laenge) {
	cout << " ";
	SetConsoleTextAttribute(writeHandle, colors[0]);

	for (int i = 0; i < laenge; i++) {
		if (i % 5 == 0) {
			SetConsoleTextAttribute(writeHandle, colors[1]);
			cout << ".";
			SetConsoleTextAttribute(writeHandle, colors[0]);
		}

		else {
			cout << ".";
		}
	}

	cout << endl;
}

// Erstellt das Pinball Sign mit Rand
void createSign(HANDLE writeHandle, const int colors[]) {
	SetConsoleTextAttribute(writeHandle, colors[1]);
	cout << ".          ______    __   __   __   ______        ___       __       __               ." << endl;
	SetConsoleTextAttribute(writeHandle, colors[0]);
	cout << ".         |   _  \\  |  | |  \\ |  | |   _  \\      /   \\     |  |     |  |              ." << endl;
	SetConsoleTextAttribute(writeHandle, colors[1]);
	cout << ".         |  |_)  | |  | |   \\|  | |  |_)  |    /  ^  \\    |  |     |  |              ." << endl;
	SetConsoleTextAttribute(writeHandle, colors[0]);
	cout << ".         |   ___/  |  | |  . `  | |   _  <    /  /_\\  \\   |  |     |  |              ." << endl;
	SetConsoleTextAttribute(writeHandle, colors[1]);
	cout << ".         |  |      |  | |  |\\   | |  |_)  |  /  _____  \\  |  `----.|  `----.         ." << endl;
	SetConsoleTextAttribute(writeHandle, colors[0]);
	cout << ".         | _|      |__| |__| \\__| |______/  /__/     \\__\\ |_______||_______|         ." << endl;
}

// Erstellt den Platzhalter des Menüs, welcher später befüllt werden kann
void createSpace(HANDLE writeHandle, const int colors[], int laenge) {
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 0) {
			SetConsoleTextAttribute(writeHandle, colors[0]);
		}
		else {
			SetConsoleTextAttribute(writeHandle, colors[1]);
		}
		cout << ".";
		for (int j = 0; j < laenge; j++) {
			cout << " ";
		}
		cout << "." << endl;
	}
}


// Erstellt das Template für die Instruktion und das Spiel
void createTemplateField(HANDLE writeHandle, const int colors[]) {

	system("cls");

	SetConsoleTextAttribute(writeHandle, colors[0]);
	createFieldLine(writeHandle);

	for (int i = 0; i < 45; i++) {
		cout << "°";
		for (int j = 0; j < 82; j++) {
			cout << " ";
		}
		cout << "°" << endl;
	}
	createFieldLine(writeHandle);
}

// Erstellt den oberen und unteren Rand des Feldes für die Instruktion und das Spiel
void createFieldLine(HANDLE writeHandle) {
	for (int i = 0; i < 84; i++) {
		cout << "°";
	}
	cout << endl;
}
