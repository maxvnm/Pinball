#include "header.h"
int mapper(char arr[]);
char * mapperString2Array(string date);

//new player
void add(THighscore *Kopf) {

	THighscore *Laeufer = Kopf;

	while (Laeufer->nach != NULL) {
		Laeufer = Laeufer->nach;
	}
	Laeufer->nach = new THighscore;
	Laeufer = Laeufer->nach;
	getData(Laeufer);
	Laeufer->nach = NULL;

}

//get data of new player
void getData(THighscore *Speicher) {
	//Name
	strcpy_s(Speicher->username, readUsername());

	//Points
	strcpy_s(Speicher->points, readPoints());
}

// add a new player if necessary
void update(THighscore *Kopf, char username[]) {
	THighscore *Laeufer = Kopf;
	int position = getPlayer(Kopf, username);

	if (position != 0){
		for (int i = 0; i < position; i++){
			Laeufer = Laeufer->nach;
		}

		strcpy_s(Laeufer->points, readPoints());
	}
	else{
		add(Kopf);
	}
}

//get players list position
int getPlayer(THighscore *Kopf, char username[]) {
	int counter = 0;
	THighscore *Laeufer = Kopf;
	while (Laeufer != NULL) {
		if (strcmp(Laeufer->username, username) == 0) {
			return counter;
		}
		else {
			Laeufer = Laeufer->nach;
			counter++;
		}
	}
	return 0;
}

//sort list by points
void sort(THighscore *Kopf) {
	THighscore *Laeufer = Kopf;

	char tmpUsername[20 + 1];
	char tmpPoints[6 + 1];

	for (int i = 0; i < count(Kopf); i++) {
		while (Laeufer->nach != NULL) {
			if (mapper(Laeufer->points) < mapper(Laeufer->nach->points)) {
				//save data
				strcpy_s(tmpUsername, Laeufer->username);
				strcpy_s(tmpPoints, Laeufer->points);

				//Swap data
				strcpy_s(Laeufer->username, Laeufer->nach->username);
				strcpy_s(Laeufer->points, Laeufer->nach->points);

				strcpy_s(Laeufer->nach->username, tmpUsername);
				strcpy_s(Laeufer->nach->points, tmpPoints);
			}
			Laeufer = Laeufer->nach;
		}
		Laeufer = Kopf;
	}
}

int mapper(char arr[]){
	string test = arr;
	return stoi(test);
}

//counts total list elements
int count(THighscore *Kopf) {
	THighscore *Laeufer = Kopf;
	int counter = 1;
	while (Laeufer != NULL) {
		Laeufer = Laeufer->nach;
		counter++;
	}
	return counter - 1;
}

//save list in txt
void write(THighscore *Kopf) {
	ofstream Write;
	Write.open("Highscore.txt", ios::out);
	THighscore *Laeufer = Kopf;

	while (Laeufer != NULL) {
		if (Write) {
			if (Laeufer->nach == NULL) {
				Write << Laeufer->username << ";" << Laeufer->points;
			}
			else {
				Write << Laeufer->username << ";" << Laeufer->points << "\n";
			}
		}
		Laeufer = Laeufer->nach;
	}
	Write.close();
}

//get list out of txt
void read(THighscore *Kopf) {
	THighscore *Laeufer = Kopf;
	ifstream Read;
	int i = 0;

	Read.open("Highscore.txt", ios::in);

	if (Read) {
		while (!Read.eof()) {
			if (i == 0) {
				Read.getline(Kopf->username, 20 + 1, ';');
				Read.getline(Kopf->points, 6 + 1);
			}
			else {
				while (Laeufer->nach != NULL) {
					Laeufer = Laeufer->nach;
				}

				Laeufer->nach = new THighscore;
				Laeufer = Laeufer->nach;

				Read.getline(Laeufer->username, 20 + 1, ';');
				Read.getline(Laeufer->points, 6 + 1);

				Laeufer->nach = NULL;
			}
			i++;
		}
		Read.close();
	}

}

//save username in txt
void writeUsername(string username) {
	ofstream Write;
	Write.open("Username.txt", ios::out);
	if (Write) {
		Write << username;
	}
	Write.close();
}

//get username out of txt
char * readUsername() {
	char username[20 + 1];
	ifstream Read;
	Read.open("Username.txt", ios::in);
	if (Read) {
		while (!Read.eof()) {
			Read.getline(username, 20 + 1);
		}
		Read.close();
	}
	return username;
}

//save points in txt
void writePoints(string points) {
	ofstream Write;
	Write.open("Points.txt", ios::out);
	if (Write) {
		Write << points;
	}
	Write.close();
}

//get points out of txt
char * readPoints() {
	char points[6 + 1];
	ifstream Read;
	Read.open("Points.txt", ios::in);
	if (Read) {
		while (!Read.eof()) {
			Read.getline(points, 6 + 1);
		}
		Read.close();
	}
	return points;
}
