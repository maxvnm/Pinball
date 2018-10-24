#include "header.h"
void hilfszahlen();
void createPointElements(HANDLE writeHandle, const int colors[], int x, int y);



// Erstellt das Spielfeld

void createGameField(HANDLE writeHandle, const int colors[]) {
	system("cls");
	createTemplateField(writeHandle, colors);


	int x = 52;
	int y = 1;
	int x2 = 0;
	int y2 = 0;
	int anzahl = 0;

	// Erstellt die Trennlinie im Spielfeld
	for (int i = 0; i < 45; i++) {
		cursorToXY(x, y++);
		cout << "°";
	}


	// Erstellt die Ecke oben Links
	anzahl = 3;
	x = 1;
	y = 1;
	for (int i = 0; i < 4; i++) {
		cursorToXY(x, y++);
		for (int j = 0; j < anzahl; j++) {
			cout << "°";
		}
		cout << "/";
		anzahl--;
	}

	// Erstellt die Ecke unten Links
	anzahl = 3;
	x = 1;
	y = 45;
	for (int i = 0; i < 4; i++) {
		cursorToXY(x, y--);
		for (int j = 0; j < anzahl; j++) {
			cout << "°";
		}
		cout << "\\";
		anzahl--;
	}


	// Erstellt die Ecke oben Rechts
	anzahl = 3;
	x = 48;
	y = 1;
	for (int i = 0; i < 4; i++) {
		cursorToXY(x++, y++);
		cout << "\\";
		for (int j = 0; j < anzahl; j++) {
			cout << "°";
		}
		anzahl--;
	}


	// Erstellt die Ecke unten Rechts
	anzahl = 3;
	x = 46;
	y = 45;
	for (int i = 0; i < 4; i++) {
		cursorToXY(x++, y--);
		cout << "/";
		for (int j = 0; j < anzahl; j++) {
			cout << "°";
		}
		anzahl--;
	}





	// Setzt den Tunnel



	// leiste rechts
	x = 50;
	y = 45;
	SetConsoleTextAttribute(writeHandle, colors[0]);
	for (int i = 0; i < 38; i++) {
		cursorToXY(x, y--);
		cout << "°";
	}

	x = 48;
	y = 7;
	for (int i = 0; i < 3; i++) {
		cursorToXY(x--, y--);
		cout << "\\\\";
	}

	x = 49;
	y = 8;
	cursorToXY(x, y);
	cout << "\\";


	// leiste oben
	x = 16;
	y = 4;
	for (int i = 0; i < 32; i++) {
		cursorToXY(x++, y);
		cout << "°";
	}

	x = 15;
	y = 5;
	for (int i = 0; i < 3; i++) {
		cursorToXY(x--, y++);
		cout << "//";
	}

	SetConsoleTextAttribute(writeHandle, colors[3]);
	x = 16;
	y = 3;

	for (int i = 0; i < 3; i++) {
		cursorToXY(x, y--);
		cout << "]]";
	}


	SetConsoleTextAttribute(writeHandle, colors[1]);
	x = 18;
	y = 1;
	anzahl = 30;
	for (int i = 0; i < 3; i++) {
		cursorToXY(x, y++);
		for (int j = 0; j < anzahl; j++) {
			cout << "#";
		}
		anzahl++;
	}

	x = 47;
	y = 4;
	anzahl = 4;

	for (int i = 0; i < 4; i++) {
		cursorToXY(x++, y++);
		for (int j = 0; j < anzahl; j++) {
			cout << "#";
		}
		if (i == 1 || i == 2) {
			anzahl--;
		}
	}



	x = 51;
	y = 8;
	for (int i = 0; i < 10; i++) {
		cursorToXY(x, y++);
		cout << "#";
	}

	SetConsoleTextAttribute(writeHandle, colors[3]);
	// ausgang des tunnels nach treffer
	cursorToXY(x, y);
	y = y + 2;
	cout << "/";
	cursorToXY(x, y++);
	cout << "/";


	SetConsoleTextAttribute(writeHandle, colors[1]);
	// eingang des tunnels
	for (int i = 0; i < 5; i++) {
		cursorToXY(x, y++);
		cout << "#";
	}

	x = 29;
	y = 2;
	cursorToXY(x, y);
	cout << "/50/";

	createStartElement(writeHandle, colors, 1);



	SetConsoleTextAttribute(writeHandle, colors[0]);
	// erstellen der unteren spielfeldelemente
	x = 4;
	y = 34;
	x2 = 46;
	y2 = 34;
	for (int i = 0; i < 2; i++) {
		cursorToXY(x, y++);
		cout << "°|";
		cursorToXY(x2, y2++);
		cout << "|°";
	}


	cursorToXY(42, 38);
	cout << "//";
	cursorToXY(8, 38);
	cout << "\\\\";


	for (int i = 0; i < 3; i++) {
		cursorToXY(x++, y++);
		cout << "\\\\";
		cursorToXY(x2--, y2++);
		cout << "//";
	}



	for (int i = 0; i < 10; i++) {
		cursorToXY(x++, y);
		cout << "-";
		cursorToXY(x2--, y);
		cout << "-";
	}


	SetConsoleTextAttribute(writeHandle, colors[0]);
	x = 21;
	y = 26;

	for (int i = 0; i < 9; i++) {
		cursorToXY(x++, y);
		cout << "-";
	}



	SetConsoleTextAttribute(writeHandle, colors[2]);
	// setzt die flipper
	x = 17;
	y = 39;
	x2 = 32;
	y2 = 39;
	for (int i = 0; i < 4; i++) {
		cursorToXY(x, y);
		cout << "\\\\";
		x++;
		y++;
		cursorToXY(x2, y2);
		cout << "//";
		x2--;
		y2++;
	}



	createPointElements(writeHandle, colors, 30, 7);
	createPointElements(writeHandle, colors, 30, 15);
	createPointElements(writeHandle, colors, 20, 11);
	createPointElements(writeHandle, colors, 40, 11);


	//hilfszahlen();

}


// Developer Function to coordinate field
void hilfszahlen() {
	HANDLE writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 47; i++) {
		cursorToXY(85, i);
		cout << i;
	}

	for (int i = 0; i < 84; i++) {
		cursorToXY(i, 49);
		cout << i % 10;
	}


	int x = 10;

	for (int i = 1; i < 9; i++) {

		cursorToXY(x, 48);
		cout << i;
		x = x + 10;
	}
}


void createStartElement(HANDLE writeHandle, const int colors[], int size) {
	SetConsoleTextAttribute(writeHandle, colors[3]);
	// startfeder
	int x = 51;
	int y = 45;
	for (int i = 0; i < size; i++) {
		cursorToXY(x, y--);
		cout << "|";
	}
	cursorToXY(x, y--);
	cout << "^";


	SetConsoleTextAttribute(writeHandle, colors[1]);
	// ball
	cursorToXY(x, y);
	cout << "0";
}


void actionRightFlipper(int *statusRightFlipper, HANDLE writeHandle, bool pressed) {
	int x = 0;
	int y = 0;
	if (pressed && *statusRightFlipper == 0) {

		// Löschen des alten rechten unteren Flippers
		x = 32;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x--, y++);
			cout << "  ";

		}

		// Setzen des Zwischenflippers
		x = 33;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x--, y);
			cout << "-";
		}
		x = 33;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x--, y);
			cout << " ";
		}

		// Setzen des neuen rechten oberen Flippers
		x = 32;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x--, y--);
			cout << "\\\\";
		}
		*statusRightFlipper = 1;
	}

	else if (pressed == false && *statusRightFlipper == 1) {
		// Löschen des alten rechten oberen Flippers
		x = 32;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x--, y--);
			cout << "  ";
		}

		// Setzen des Zwischenflippers
		x = 33;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x--, y);
			cout << "-";
		}
		x = 33;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x--, y);
			cout << " ";
		}



		// Setzen des neuen rechten unteren Flippers
		x = 32;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x--, y++);
			cout << "//";
		}
		*statusRightFlipper = 0;
	}
}


void actionLeftFlipper(int *statusLeftFlipper, HANDLE writeHandle, bool pressed) {
	int x = 0;
	int y = 0;

	if (pressed && *statusLeftFlipper == 0) {

		// Löschen des alten linken unteren Flippers
		x = 17;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x++, y++);
			cout << "  ";
		}

		// Setzen des Zwischenflippers
		x = 17;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x++, y);
			cout << "-";
		}
		x = 17;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x++, y);
			cout << " ";
		}

		// Setzen des neuen linken oberen Flippers
		x = 17;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x++, y--);
			cout << "//";
		}
		*statusLeftFlipper = 1;
	}

	else if (pressed == false && *statusLeftFlipper == 1) {
		// Löschen des alten linken oberen Flippers
		x = 17;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x++, y--);
			cout << "  ";
		}

		// Setzen des Zwischenflippers
		x = 17;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x++, y);
			cout << "-";
		}
		x = 17;
		y = 39;
		for (int i = 0; i < 7; i++) {
			cursorToXY(x++, y);
			cout << " ";
		}

		// Setzen des neuen linken unteren Flippers
		x = 17;
		y = 39;
		for (int i = 0; i < 4; i++) {
			cursorToXY(x++, y++);
			cout << "\\\\";
		}
		*statusLeftFlipper = 0;
	}
}



void createPointElements(HANDLE writeHandle, const int colors[], int x, int y) {
	SetConsoleTextAttribute(writeHandle, colors[2]);

	for (int i = 0; i < 2; i++) {
		cursorToXY(x, y++);
		cout << "/";
		if (i == 1) {
			cout << "10";
		}
		else {
			x--;
		}
		cout << "\\";

	}


	for (int i = 0; i < 2; i++) {
		cursorToXY(x++, y++);
		cout << "\\";
		if (i == 0) {
			cout << "°°";
		}
		cout << "/";
	}

}

// bewegt das Feld in der Mitte
void moveWall(int *x, int y, int position) {

	int a = *x;

	for (int i = 0; i < 9; i++) {
		cursorToXY(a++, y);
		switch (i) {
		case 0: cout << " ";
			break;
		case 8: cout << "  ";
			break;
		default: cout << " ";
			break;

		}

	}


	if (position == 1) {
		(*x)++;
	}
	else if (position == 0) {
		(*x)--;
	}

	int b = *x;

	for (int i = 0; i < 9; i++) {
		cursorToXY(b++, y);
		cout << "-";
	}
	Sleep(35);
}



// schießt den Ball nach oben
void startGame(HANDLE writeHandle, const int colors[]) {
	int x = 51;
	int y = 41;
	SetConsoleTextAttribute(writeHandle, colors[1]);
	for (int i = 0; i < 15; i++) {
		cursorToXY(x, y--);
		cout << " ";
		cursorToXY(x, y);
		cout << "0";
		Sleep(50);
	}
	cursorToXY(x, y);
	cout << " ";

}
