#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "movimento.h"
//#include "schermo.h"
#include "control.h"
#include "map.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void shift_entity(int positionR, int positionC, char skin){								
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionC, positionR};
	DWORD cose;
	FillConsoleOutputCharacter ( handle, skin ,1, coordinate, &cose);
}
		
void delate_entity(int positionR,int positionC){	
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionC,positionR};
	DWORD cose;
	FillConsoleOutputCharacter ( handle,' ',1, coordinate, &cose);
}

void print_map(char map[][100], int R, int C){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			cout << map[r][c];
		}
		cout << endl;
	}
}

int main(int argc, char** argv) {
	control control_you;
	maps map_level;	
	int rows=0;
	int cols=0;
	int pc=0;
	int pr=0;
	char lvl[50][100];
	map_level.choose_map(lvl);
	map_level.size(lvl, map_level.c, rows, cols);
	map_level.cols=cols;
	map_level.rows=rows;
	control_you.position(lvl, map_level.rows, map_level.cols, map_level.y, pr, pc);
	control_you.pR=pr;
	control_you.pC=pc;
	print_map(lvl, map_level.rows, map_level.cols);
	do{
		control_you.button=get_button();
		lvl[control_you.pR][control_you.pC] = ' ';
		delate_entity(control_you.pR, control_you.pC);
		mov(control_you.pR, control_you.pC, control_you.button);
		control_you.enemy(lvl, map_level.cols, map_level.e);
		control_you.wall(lvl, map_level.cols,map_level.w);
		lvl[control_you.pR][control_you.pC] = map_level.y;
		shift_entity(control_you.pR, control_you.pC, map_level.y);
	}while(3<4);
	return 0;
}
