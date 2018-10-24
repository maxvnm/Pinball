#include "header.h"

// Setzt den Cursor an eine bestimmte Stelle
void cursorToXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Macht den Cursor in der Konsole unsichtbar
void visibleCursor(HANDLE writeHandle, bool value) {
	CONSOLE_CURSOR_INFO info;
	info.bVisible = value;
	info.dwSize = 100;
	SetConsoleCursorInfo(writeHandle, &info);
}

void setConsoleSize(HANDLE writeHandle, int hight, int width) {

	// Definiert die Koordinaten der oberen linken und unteren rechten Ecke eines Rechtecks
	SMALL_RECT size;
	//Definiert die Koordinaten einer Zeichenzelle in einem Konsolenbildschirmpuffer
	COORD coordsize;

	size.Left = 0;
	size.Top = 0;

	size.Right = width;
	size.Bottom = hight;

	coordsize.X = width + 1;
	coordsize.Y = hight + 1;

	// TRUE setzt die Konsole absolut von der Koordinate 0 / 0
	SetConsoleWindowInfo(writeHandle, TRUE, &size);
	SetConsoleScreenBufferSize(writeHandle, coordsize);
}

