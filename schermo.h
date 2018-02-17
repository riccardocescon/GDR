#ifndef SCHERMO_H
#define SCHERMO_H
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "control.h"
#include "map.h"
#include "movimento.h"

using namespace std;

void shift_entity(int positionR,int positionC, char skin){								
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionR, positionC};
	DWORD cose;
	FillConsoleOutputCharacter ( handle, skin ,1, coordinate, &cose);
}
		
void delate_entity(int positioR,int positionC){	
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positioR,positionC};
	DWORD cose;
	FillConsoleOutputCharacter ( handle,' ',1, coordinate, &cose);
}

void print_map(char *map, int R, int C){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			cout << map[r*C+c];
		}
		cout << endl;
	}
}

#endif
