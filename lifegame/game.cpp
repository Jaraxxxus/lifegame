#include <iostream>
#include <conio.h>
#include <cstring>

#include "CScreen.h"
#include "CComand.h"
//#include "konvey.h"


//void play(CScreen screen);
using namespace std;

int main() {


    // setlocale(LC_ALL, "Russian");

    try {
        CScreen screen;
        screen.cursor_show(false);
        screen.text_attr((WORD)0x0a);
        screen.cls();

        Command cmd;
        cmd.playGame(screen);


    }
    catch (CSScreenException& ex) {
        cerr << "*** " << ex.what() << endl;
    }

    return 0;
}
