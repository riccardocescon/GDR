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
		void enemy(char arr[][100], int C, char e);
		void wall(char arr[][100], int C, char wall);
		void position(char lvl[][100], int& R, int& C, char entity, int& px, int& py);
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
	
void control::enemy (char arr[][100], int C, char e){
   	if (arr[pR][pC] == e){
		back();
	}
}

void control::wall (char arr[][100], int C, char wall){						   
	if (arr[pR][pC]==wall){
		back();
	}
}

void control::position (char lvl[][100], int& R, int& C, char entity, int& px, int& py){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			if (lvl[r][c]==entity){
				px = r;
				py = c;
			}
		}
	}
}

#endif
