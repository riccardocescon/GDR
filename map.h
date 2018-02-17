#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "movimento.h"
#include "schermo.h"
#include "control.h"

using namespace std;

class maps{
	
	public:
		
		int rows;
		int cols;
		
	void size(char lvl[][100], char corner, int& R, int& C){
            for(int c=0; lvl[0][c] != corner; c++){
    		  C=c+2;
    	    }
    	   for (int r=0; lvl[r][0] != corner; r++){
    		  R=r+2;
    	   }
        }
		
	private:
		
};

#endif
