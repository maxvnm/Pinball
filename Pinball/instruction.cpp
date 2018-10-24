#include "header.h"

void createInstruction(HANDLE writeHandle, const int colors[], string username) {

	cursorToXY(20, 3);
	SetConsoleTextAttribute(writeHandle, colors[1]);
	cout << "Here are your Instructions ";
	SetConsoleTextAttribute(writeHandle, colors[2]);
	cout << username << ",";
	SetConsoleTextAttribute(writeHandle, colors[1]);


	int y = 7;
	int x = 4;
	cursorToXY(x, y++);
	cout << "in this short instruction I will explain you the basics of pinball and the " << endl;
	cursorToXY(x, y++);
	cout << "game controls." << endl;
	y++;
	cursorToXY(x, y++);
	cout << "Pinball is an oldschool arcade game.";
	cursorToXY(x, y++);
	cout << "The first pinball machine was published 1947 with the name \"Humpty Dumpty\" ";
	cursorToXY(x, y++);
	cout << "and is very different to the machines today." << endl;
	y++;
	cursorToXY(x, y++);
	cout << "But what is the goal in pinball?" << endl;
	cursorToXY(x, y++);
	cout << "First of all you have three balls. With these";
	cursorToXY(x, y++);
	cout << "three balls you need to score as much points as you can." << endl;
	cursorToXY(x, y++);
	cout << "You can get points by hitting the bouncers (10 Pts.) or going through ";
	cursorToXY(x, y++);
	cout << "the tunnel (50 Pts.)." << endl;
	cursorToXY(x, y++);
	cout << "But watch out and kick the ball with your kickers up into the air again";
	cursorToXY(x, y++);
	cout << "before they hit the ground. If one ball hits the ground you will loose this";
	cursorToXY(x, y++);
	cout << "ball and the game starts again with ball number two or three." << endl;
	y++;
	cursorToXY(x, y++);
	cout << "Let's learn some game controls: " << endl;
	cursorToXY(x, y++);
	cout << "You can move your kickers by pressing the \"A\",\"D\" or ";
	cursorToXY(x, y++);
	cout << "the left and right arrow keys." << endl;
	cursorToXY(x, y++);
	cout << "You can start the game by hitting the \"TAB\" button once." << endl;
	y++;
	cursorToXY(x, y++);
	cout << "Enjoy your game and beat them all!" << endl;

	x = 4;
	y = 35;
	cursorToXY(x, y++);
	SetConsoleTextAttribute(writeHandle, colors[2]);
	cout << "Please remember that this is an alpha version containing bugs.";
	cursorToXY(x, y++);
	cout << "Press a key to start the game. Good Luck!";
	system("pause > 0");
}
