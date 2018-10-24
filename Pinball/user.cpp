#include "header.h"

// Erstellt die Abfrage und Eingabe des Benutzernamens und ruft anschlieﬂend die Spielanleitung auf
string createUsername(HANDLE writeHandle, const int colors[]) {

	string username;

	system("cls");
	createTemplateMenu(writeHandle, colors);

	cursorToXY(30, 12);
	SetConsoleTextAttribute(writeHandle, colors[1]);
	cout << "Please enter your Username:";
	cursorToXY(30, 14);
	visibleCursor(writeHandle, true);
	SetConsoleTextAttribute(writeHandle, colors[2]);

	cin >> username;
	visibleCursor(writeHandle, false);

	return username;
}
