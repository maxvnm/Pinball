#ifndef header_h
#define header_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <thread>
#include <fstream>
#include <stdlib.h>
using namespace std;
void visibleCursor(HANDLE writeHandle, bool value);
void createMenu(HANDLE writeHandle, const int colors[]);
void createTemplateMenu(HANDLE writeHandle, const int colors[]);
void cursorToXY(int x, int y);
void prepareGame(HANDLE writeHandle, const int colors[]);
string createUsername(HANDLE writeHandle, const int colors[]);
void createTemplateField(HANDLE writeHandle, const int colors[]);
void createInstruction(HANDLE writeHandle, const int colors[], string username);
void createGameField(HANDLE writeHandle, const int colors[]);
void createInformationField(HANDLE writeHandle, const int colors[], int anzahlBaelle);
void createStartElement(HANDLE writeHandle, const int colors[], int size);
void actionLeftFlipper(int *statusLeftFlipper, HANDLE writeHandle, bool pressed);
void actionRightFlipper(int *statusRightFlipper, HANDLE writeHandle, bool pressed);
void startGame(HANDLE writeHandle, const int colors[]);
void controlphysics(HANDLE writeHandle, const int colors[], int *x, int *y, int *way, int statusRightFlipper, int statusLeftFlipper, bool *gameRun, int *score, int *bugfixLeft, int *bugfixRight);
void printScore(HANDLE writeHandle, const int colors[], int score);
void moveWall(int *x, int y, int position);
void showScores(HANDLE writeHandle, const int colors[]);
void createLine(HANDLE writeHandle, const int colors[], int laenge);

struct THighscore {
	char username[20+1];
	char points[6+1];
	THighscore *nach;
};
void sort(THighscore *Kopf);
void write(THighscore *Kopf);
void read(THighscore *Kopf);
void add(THighscore *Kopf);
void getData(THighscore *Speicher);
void update(THighscore *Kopf, char username[]);
int getPlayer(THighscore *Kopf, char username[]);
int count(THighscore *Kopf);
void writeUsername(string username);
char * readUsername();
void writePoints(string points);
char * readPoints();
#endif
