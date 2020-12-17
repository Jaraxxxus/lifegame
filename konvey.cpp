#include <iostream>
#include <fstream>
#include <windows.h>
#include "konvey.h"



#define WORLD_H 10
#define WORLD_W 10
/*
#ifndef __CSCREEN_H__
#define __CSCREEN_H__
*/
using namespace std;



void konvey::clr_world(){  
    unsigned int i, j;
    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
            wrd[i][j] = '.';
            old_wrd[i][j] = '.';
        }
        }
     step = 0;   
    }

konvey::konvey(){

wrd     = new char*[WORLD_W];
old_wrd = new char*[WORLD_W];	
for(unsigned int i = 0; i < WORLD_H; i++){
        wrd[i]     = new char[WORLD_H];
        old_wrd[i] = new char[WORLD_H];
        
    }
step = 0;    
}

konvey::~konvey() {
    for (unsigned int i = 0; i < WORLD_H; i++){
        delete [] wrd[i];
        delete [] old_wrd[i];
    }
    delete [] wrd;
    delete [] old_wrd;
}


unsigned int konvey::get_live_count(){
    unsigned int count = 0;
    unsigned i, j;
    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
            if (wrd[i][j] == '*') {
                count++;
            }
        }
    }
    return count;
}


void konvey::read_point_neighbors(unsigned int nb[][2], int x, int y)
{
    int i =0, j = 0;
    signed int k = 0;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }  
			int i1 =i%10;
			int j1 =j%10;
			if (i1< 0) i1= WORLD_H +i1;
			if (j1< 0) j1= WORLD_W +j1;     
            nb[k][0] = i1;
            nb[k][1] = j1;
            k++;
        }
    }
}


unsigned int konvey::count_live_neighbors(unsigned int x, unsigned int y)
{
    unsigned int count = 0;
    unsigned int i;
    unsigned int nb[8][2];
    unsigned int _x, _y;

    read_point_neighbors(nb, x, y);
		 
    for (i = 0; i < 8; i++) {
        _x = nb[i][0];
        _y = nb[i][1];
        if (get_world(_x,_y) == '*') {
            count++;
        }
    }
    return count;
}


void konvey::next_generation(){
    unsigned int i, j;
    unsigned int live_nb;


    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
            live_nb = count_live_neighbors(i, j);
			if (live_nb == 3) {
               old_wrd[i][j]='*';                  
            }
            
            else {
                if (live_nb < 2 || live_nb > 3) {
                    old_wrd[i][j] = '.';          
                }
                else if (live_nb == 2)
				 old_wrd[i][j] = wrd[i][j];
            }
	
        }
    }

}


void konvey::swap_world(){
    char** ptr = wrd;
	wrd = old_wrd;
    old_wrd = ptr;
}

int konvey::cmp_world() {
    unsigned int i, j;
    //char cWrd, cOldWrd;
    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
          //  cWrd = get_world(i, j);
          //  cOldWrd = get_old(i, j);
          //  if (cWrd != cOldWrd){
            if (wrd[i][j] != old_wrd[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}


char konvey::get_world(unsigned int x, unsigned int y){
        if ((x < 0 || x > 9) & (y < 0 || y > 9))
          return '1';
        return wrd[x][y];
      
}
char konvey::get_old(unsigned int x, unsigned int y) {
    if ((x < 0 || x > 9) & (y < 0 || y > 9))
        return '1';
    return old_wrd[x][y];

}
char* konvey::get_world_str(unsigned int x){
        if (x < 0 || x > 9)
          return NULL;
        return wrd[x];
      
}

void konvey::set_pos(unsigned int x, unsigned int y){ 
     if (x < 0  || x > 9) x=0;
     if (y < 0  || y > 9) y=0;
	 wrd[x][y] = '*';
	  if (step == 0)
        old_wrd[x][y] = '*';
}

void konvey::set_dot(unsigned int x, unsigned int y){ 
     if (x < 0  || x > 9) x=0;
     if (y < 0  || y > 9) y=0;
	   wrd[x][y] = '.';
}

int konvey::get_step(){       
        return step;
}
void konvey::set_step(int st) {
        step = st;
}
