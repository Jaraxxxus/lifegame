#include <iostream>
#include <windows.h>



/* Размер игрового поля */
#define WORLD_H 10
#define WORLD_W 10
/*
#ifndef __CSCREEN_H__
#define __CSCREEN_H__
*/
using namespace std;



class konvey {
    

public:
    unsigned is_live : 1;
    char wrd[WORLD_W][WORLD_H];
    char old_wrd[WORLD_W][WORLD_H];
 //   konvey();
 //   konvey~();

//private:
  /*  void clr_world();
    unsigned int get_live_count();
    void read_point_neighbors(unsigned int nb[][2], unsigned int x, unsigned int y);
    unsigned int count_live_neighbors(char* world, unsigned int x, unsigned int y);
    void copy_world();
    int cmp_world();
    void print_world();*/








/*
 * Очистка поля
 */

void clr_world(){  
    unsigned int i, j;
    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
            wrd[i][j] = '.';
            old_wrd[i][j] = '.';
        }
        }
    }

/*
 * Количество живых клеток на игровом поле
*/
unsigned int get_live_count(){
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

/*
 * Получение координат соседей точки 
*/
void read_point_neighbors(signed int nb[][2], unsigned int x, unsigned int y)
{
    int i, j;
    unsigned int k = 0;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }                     
            if (i < 0)  nb[k][0] = WORLD_H - 1;
            else if (j < 0)  nb[k][1] = WORLD_H-1;
            else if (i > 9)  nb[k][0] = 0;
            else if (j > 9)  nb[k][1] = 0;
            else {
                nb[k][0] = i;
                nb[k][1] = j;
            }
            k++;
        }
    }
}

/*
 * Количество живых соседей у клетки с координатами x, y
 */
unsigned int count_live_neighbors(char* world, unsigned int x, unsigned int y)
{
    unsigned int count = 0;
    unsigned int i;
    unsigned int nb[8][2];
    unsigned int _x, _y;

    read_point_neighbors(nb, x, y);

    for (i = 0; i < 8; i++) {
        _x = nb[i][0];
        _y = nb[i][1];


        if (wrd[_x][_y] == '*') {
            count++;
        }
    }

    return count;
}

/*
 * Сгенерировать следующее поколение игрового мира
 */
void next_generation(){
    unsigned int i, j;
    unsigned int live_nb;
    

    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
            ptr = old_wrd;
            live_nb = count_live_neighbors(old_wrd, i, j);

            if (ptr[i][j] == '.') {
                if (live_nb == 3) {
                    wrd[i][j]=='*';
                }
            }
            else {
                if (live_nb < 2 || live_nb > 3) {
                    wrd[i][j] = '.';
                }
            }
        }
    }
   
}


/*
 * Копирование игрового мира. Используется для сохранения предыдущего поколения
*/
void copy_world(){
    char(*ptr)[WORLD_H] = old_wrd;

    **old_wrd = **wrd;
    **wrd = **ptr;
}

/*
 * Сравнение игровых миров текущего и предыдущего поколения
 */
int cmp_world() {
    unsigned int i, j;
    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {
            if (wrd[i][j] != old_wrd[i][j]) {
                return -1;
            }
        }
    }
    return 0;
}


/*
 * Вывести на экран игровое поле
*/
void print_world(){
    unsigned int i, j;
    for (i = 0; i < WORLD_W; i++) {
        for (j = 0; j < WORLD_H; j++) {

            cout << wrd[i][j];
        }
        cout << "\n";
    }
      
}



void set_pos(unsigned int x, unsigned int y) {
    if (x < 0 || x > 9) x = 0;
    if (y < 0 || y > 9) y = 0;
    wrd[x][y] = '*';
    //old_wrd[x][y] = '*';
}


};



















int main() {
int x, y, j;
konvey The_wrd;
unsigned int live_points = -1;
bool is_optimal = false;
The_wrd.clr_world();
for (j = 0; j < WORLD_H - 5; j++) {

    cout << " ener XY";
    cin >> x;
    cin >> y;
    The_wrd.set_pos(x, y);
}

do {
    The_wrd.print_world();

    The_wrd.next_generation();

    is_optimal = The_wrd.cmp_world() == 0;
    live_points = The_wrd.get_live_count();

    if (is_optimal) {
        cout << "Optimal configuration detected" << endl;
    }

    if (live_points == 0) {
        cout << "All points died" << endl;
    }
    system("pause");
    The_wrd.copy_world();
} while (live_points != 0 && !is_optimal);

return 0;
}