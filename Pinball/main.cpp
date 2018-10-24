#include "header.h"


// 2065 Zeilen
int main() {

	//typedef auf void
	HANDLE writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	int CYAN = 11;
	int MAGENTA = 13;
	int WHITE = 15;
	int RED = 12;
	int GELB = 14;

	const int colors[5] = { CYAN, WHITE, MAGENTA, RED, GELB };

	SetConsoleTitle(TEXT("Pinball Version 1.0"));
	visibleCursor(writeHandle, false);
	createMenu(writeHandle, colors);
	return 0;
}
