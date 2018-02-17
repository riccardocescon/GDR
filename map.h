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
		void size(char* lvl[], char corner){
            for(int c=0; **lvl[c] != corner; c++){
    		  cols=c;
    	    }
    	   for (int r=0; *lvl[r * cols + 1] != corner; r++){
    		  cols=r;
    	   }
        }
		
	private:
		
};

#endif
