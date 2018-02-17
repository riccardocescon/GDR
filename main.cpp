#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "movimento.h"
#include "schermo.h"
#include "control.h"
#include "map.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char w = 189; //wall
	char e = 122; //entity
	char y = 206; //you
	char s = ' '; //space
	char c = 188; //corner
	control control_you;
	maps map_level;
	char lvl1[200]={w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, c,
				   	   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, e, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, w,
					   w, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, y, w,
					   c, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w};	
	
	map_level.size(*lvl1, c);
	cin >> y;
	control_you.position(*lvl1, map_level.rows, map_level.cols, y);
	print_map(*lvl1, map_level.rows, map_level.cols);
	do{
		control_you.button=get_button();
		lvl1[control_you.pR][control_you.pC] = ' ';
		mov(control_you.pR, control_you.pC, control_you.button);
		control_you.enemy(*lvl1, map_level.cols);
		control_you.wall(*lvl1, map_level.cols, w);
		lvl1[control_you.pR][control_you.pC] = y;
		delate_entity(control_you.pR, control_you.pC);
		shift_entity(control_you.pR, control_you.pC, y);
	}while(3<4);
	return 0;
}
