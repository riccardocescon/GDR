#ifndef MOVIMENTO_H
#define MOVIMENTO_H
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "schermo.h"
#include "control.h"
#include "map.h"

using namespace std;

char get_button(){
	kbhit();
	char button = getch();
	if (button < 97){
		button=button+32;
	}
	return button;
}
		
void mov(int& pR, int& pC, char button){
	switch(button){
		case 'w':
			pR--;
			break;
		case 's':
			pR++;
			break;
		case 'a':
			pC--;
			break;
		case 'd':
			pC++;
			break;
	}
}

#endif
