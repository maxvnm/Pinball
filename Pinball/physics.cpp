#include "header.h"
void one(int **x, int **y);
void two(int **x, int **y);
void three(int **x, int **y);
void fourth(int **x, int **y);
void five(int **x, int **y);
void six(int **x, int **y);
void seven(int **x, int **y);
void eight(int **x, int **y);
void nine(int **x, int **y);
void controlphysics(HANDLE writeHandle, const int colors[], int *x, int *y, int *way, int statusLeftFlipper, int statusRightFlipper, bool *gameRun, int *score, int *bugfixLeft, int *bugfixRight) {


	int tmpx = *x;
	int tmpy = *y;


	char slash = '/';
	char backslash = '\\';
	char wall = '°';
	char wallTwo = '-';
	char wallThree = '|';
	char tunnel = ']';
	char space = ' ';

	TCHAR *nextChar = new TCHAR[1];
	DWORD charnum;

	// zu testende Koordinate wird bestimmt und gespeichert
	switch (*way) {
	case 1:
		tmpy--;
		tmpx--;
		break;
	case 2:
		tmpx--;
		break;
	case 3:
		tmpx--;
		tmpy++;
		break;
	case 4:
		tmpx++;
		tmpy--;
		break;
	case 5:
		tmpx++;
		break;
	case 6:
		tmpx++;
		tmpy++;
		break;
	case 7:
		tmpy--;
		break;
	case 8:
		tmpy++;
		break;
	}


	COORD coord = { tmpx, tmpy };



	// Liest die nächste Koordinate des Balls für die Verarbeitung aus
	ReadConsoleOutputCharacter(writeHandle, nextChar, 1, coord, &charnum);

	if (statusLeftFlipper == 1 && *x == 16 && *y == 38) {
		seven(&x, &y);
		*way = 7;
		return;
	}

	if (statusRightFlipper == 1 && *x == 34 && *y == 38) {
		seven(&x, &y);
		*way = 7;
		return;
	}



	// Abschlag des Balls mit dem rechten Flipper
	if (statusRightFlipper == 1 && *bugfixRight < 3) {
		if (*x >= 28 && *x <= 31 && *y >= 39 && *y <= 42) {
			one(&x, &y);
			*way = 1;
			return;
		}
		else if (*x >= 31 && *x <= 33 && *y >= 36 && *y <= 38) {
			fourth(&x, &y);
			*way = 4;
			return;
		}
	}

	// Abschlag des Balls mit dem linken Flipper
	if (statusLeftFlipper == 1 && *bugfixLeft < 3) {
		if (*x <= 22 && *x >= 19 && *y >= 39 && *y <= 42) {
			fourth(&x, &y);
			*way = 4;
			return;
		}
		else if (*x <= 19 && *x >= 17 && *y >= 36 && *y <= 38) {
			one(&x, &y);
			*way = 1;
			return;
		}

	}




	// Prüft ob der Ball unterhalb der Flipper ist, wenn Ja ist das Spielende erreicht
	if (*y >= 43) {
		*gameRun = false;
		return;
	}

	// Prüft ob der Ball ein Punkteelement getroffen hat
	if (*nextChar == slash || *nextChar == backslash) {
		if (*x >= 18 && *x <= 43 && *y >= 6 && *y <= 19) {
			*score = *score + 10;
		}
	}



	// Physik des Balls, welche auf 8 verschiedene Richtungen mit den Spielzeichen aufbaut
	// Enthält einige Random Zahlen um Ball in manchen Situationen unvorhersehbar zu leiten
	switch (*way) {
	case 1:
		if (*nextChar == space) {
			one(&x, &y);
			*way = 1;
		}
		else if (*nextChar == wall && *x == 1) {
			fourth(&x, &y);
			*way = 4;
		}
		else if (*nextChar == wall || *nextChar == wallTwo) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == slash) {
			fourth(&x, &y);
			*way = 4;
		}
		else if (*nextChar == backslash) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == wallThree) {
			fourth(&x, &y);
			*way = 4;
		}
		break;
	case 2:
		if (*nextChar == space) {
			two(&x, &y);
			*way = 2;
		}
		else if (*nextChar == slash) {
			eight(&x, &y);
			*way = 8;
		}
		else if (*nextChar == backslash) {
			seven(&x, &y);
			*way = 7;
		}
		else if (*nextChar == wall) {
			srand(time(NULL));
			int zahl = rand() % 10;
			if (zahl >= 5) {
				fourth(&x, &y);
				*way = 4;
			}
			else {
				six(&x, &y);
				*way = 6;
			}
		}
		else if (*nextChar == wallThree) {
			five(&x, &y);
			*way = 5;
		}
		break;
	case 3:
		if (*nextChar == space) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == backslash) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == slash) {
			fourth(&x, &y);
			*way = 4;
		}
		else if (*nextChar == wall) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == wallTwo) {
			one(&x, &y);
			*way = 1;
		}
		else if (*nextChar == wallThree) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == '0') {
			six(&x, &y);
			*way = 6;
		}
		break;
	case 4:
		if (*nextChar == space) {
			fourth(&x, &y);
			*way = 4;
		}
		else if (*nextChar == slash) {
			seven(&x, &y);
			*way = 7;
		}
		else if (*nextChar == backslash) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == wall && (*x == 49 || *y == 34 || *y == 35)) {
			one(&x, &y);
			*way = 1;
		}
		else if (*nextChar == wall || *nextChar == wallThree) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == wallTwo) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == tunnel) {
			nine(&x, &y);
			*way = 3;
			*score = *score + 50;
		}
		break;
	case 5:
		if (*nextChar == space) {
			five(&x, &y);
			*way = 5;
		}
		else if (*nextChar == slash) {
			seven(&x, &y);
			*way = 7;
		}
		else if (*nextChar == backslash) {
			eight(&x, &y);
			*way = 8;
		}
		else if (*nextChar == wall) {
			two(&x, &y);
			*way = 2;
		}
		else if (*nextChar == tunnel) {
			nine(&x, &y);
			*way = 3;
			*score = *score + 50;
		}
		break;
	case 6:
		if (*nextChar == space) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == slash) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == backslash) {
			seven(&x, &y);
			*way = 7;
		}
		else if (*nextChar == wall) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == wallTwo) {
			fourth(&x, &y);
			*way = 4;
		}
		else if (*nextChar == wallThree) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == tunnel) {
			nine(&x, &y);
			*way = 3;
			*score = *score + 50;
		}
		else if (*nextChar == '1') {
			one(&x, &y);
			*way = 1;
		}
		break;
	case 7:
		if (*nextChar == space) {
			seven(&x, &y);
			*way = 7;
		}
		else if (*nextChar == slash) {
			fourth(&x, &y);
			*way = 4;
		}
		else if (*nextChar == backslash) {
			one(&x, &y);
			*way = 1;
		}
		else if (*nextChar == wall) {
			eight(&x, &y);
			*way = 8;
		}
		else if (*nextChar == wallTwo) {
			srand(time(NULL));
			int zahl = rand() % 10;
			if (zahl >= 5) {
				six(&x, &y);
				*way = 6;
			}
			else {
				three(&x, &y);
				*way = 3;
			}
		}
		break;
	case 8:
		if (*nextChar == space) {
			eight(&x, &y);
			*way = 8;
		}
		else if (*nextChar == slash) {
			three(&x, &y);
			*way = 3;
		}
		else if (*nextChar == backslash) {
			six(&x, &y);
			*way = 6;
		}
		else if (*nextChar == wallThree || *nextChar == wall) {
			srand(time(NULL));
			int zahl = rand() % 10;
			if (zahl >= 5) {
				one(&x, &y);
				*way = 1;
			}
			else {
				fourth(&x, &y);
				*way = 4;
			}
		}
		else if (*nextChar == wallTwo) {
			if (*x > 25) {
				one(&x, &y);
				*way = 1;
			}
			else {
				fourth(&x, &y);
				*way = 4;
			}
		}
	}
}




// links oben -> way 1
void one(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx--, tmpy--);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

// links mitte -> way 2
void two(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx--, tmpy);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

// links unten -> way 3
void three(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx--, tmpy++);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

// rechts oben -> way 4
void fourth(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx++, tmpy--);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

// rechts mitte -> way 5
void five(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx++, tmpy);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

// rechts unten -> way 6
void six(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx++, tmpy++);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;

}

// hoch -> way 7
void seven(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx, tmpy--);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

// runter -> way 8
void eight(int **x, int **y) {
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx, tmpy++);
	cout << " ";
	cursorToXY(tmpx, tmpy);
	cout << "0";
	**x = tmpx;
	**y = tmpy;
}

void nine(int **x, int **y) {
	// tunnel -> noch zu implementieren
	int tmpx = **x;
	int tmpy = **y;
	cursorToXY(tmpx, tmpy);
	cout << " ";
	tmpx = 49;
	tmpy = 20;
	cursorToXY(tmpx, tmpy);
	**x = tmpx;
	**y = tmpy;
	cout << "0";
}
