#include <stdio.h>
#include <conio.h>
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <locale.h>
#include <windows.h>
#include <wchar.h> 
#include <stdbool.h>
#pragma warning(disable:4996)
// use wchar_t instead of char (for the special characters)
// use wprintf instead of printf (when printing special characters)
// and lastly make sure to set the stdout mode to u16 before using wprintf, and txt for printf (it might crash otherwise)

#define settxt _setmode(_fileno(stdout), _O_TEXT)
#define setu16 _setmode(_fileno(stdout), _O_U16TEXT)
#define sleep(x) Sleep(1 * (x))
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
    int x = 0, y = 0;
    char dir = 'd';
    while (1) {
        if (_kbihit()) {
            char c = _getch;
            if (c == 'w' || c == 's' || c == 'a' || c == 'd')
                dir = c;
            gotoxy(x, y);
            wprintf(L" ");
            if (dir == 'w') y--;
            if (dir == 's') y++;
            if (dir == 'd') x++;
            if (dir == 'a') x--;
            gotoxy(x, y);
            wprintf(L"■");

            sleep(200);

        }













    }




















    return 0;
}
