#ifndef CONTROL_H
#define CONTROL_H
#include "movimento.h"
#include "schermo.h"
#include "map.h"

using namespace std;

class control{
	public:
		int pR;
		int pC;
		char button;
		void back();
		void enemy(char arr[][100], int C);
		void wall(char arr[][100], int C, char wall);
		void position(char lvl[][100], int& R, int& C, char entity);
	protected:

};

void control::back (){
	switch(button){
		case 'w':
			pR++;
			break;
		case 's':
			pR--;
			break;
		case 'a':
			pC++;
			break;
		case 'd':
			pC--;
			break;
	}
}
	
void control::enemy (char arr[][100], int C){
   	if (arr[pR][pC] =='1' || arr[pR][pC]=='2'){
		back();
	}
}

void control::wall (char arr[][100], int C, char wall){						   
	if (arr[pR][pC]==wall){
		back();
	}
}

void control::position (char lvl[][100], int& R, int& C, char entity){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			if (lvl[r][c]==entity){
				pR = r;
				pC = c;
			}
		}
	}
}

#endif
