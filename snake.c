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
#include "map2.h"
#include "map1.h"
#include <windows.h>
#pragma warning(disable:4996)
// use wchar_t instead of char (for the special characters)
// use wprintf instead of printf (when printing special characters)
// and lastly make sure to set the stdout mode to u16 before using wprintf, and txt for printf (it might crash otherwise)

#define settxt _setmode(_fileno(stdout), _O_TEXT)
#define setu16 _setmode(_fileno(stdout), _O_U16TEXT)
#define sleep(x) Sleep(1 * (x))
int applex, appley , score = 0;
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void showscore() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(0, 0);
    SetConsoleTextAttribute(h, 7);
    wprintf(L"Score: %d", score);
}
void Apple(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    applex = rand() % (WIDTH - 2) + 1;
    appley = rand() % (HEIGHT - 2) + 1;
    while (map[appley][applex] != 0) {
        applex = rand() % (WIDTH - 2) + 1;
        appley = rand() % (HEIGHT - 2) + 1;
    }
    map[appley][applex] = 3;
    gotoxy(applex, appley);
    SetConsoleTextAttribute(h, 12);
    wprintf(L"●");
    SetConsoleTextAttribute(h, 2);
    }


void runsnake(){
    int x = 0, y = 0 , counter = 0 , flag = 0 , apllex = 0 , appley =0;
    char dir = 'd';
    int snakeX[100];
    int snakeY[100];
    int snakeLength = 3;
    _setmode(_fileno(stdout), _O_U16TEXT);
    snakeX[0] = 5; snakeY[0] = 5; //head
    snakeX[1] = 4; snakeY[1] = 5; //body
    snakeX[2] = 3; snakeY[2] = 5; //tail
    
    gotoxy(snakeX[0], snakeY[0]);
    wprintf(L"▲");
    for (int i = 0; i < snakeLength; ++i) {
        gotoxy(snakeX[i], snakeY[i]);
        wprintf(L"■");
    }
    while (1) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 'w' || c == 's' || c == 'a' || c == 'd')
                dir = c;
        }

        int prevx = snakeX[0];
        int prevy = snakeY[0];
        if (dir == 'w')
            snakeY[0]--;
        if (dir == 's')
            snakeY[0]++;
        if (dir == 'd')
            snakeX[0]++;
        if (dir == 'a')
            snakeX[0]--;


        for (int i = 1; i < snakeLength; ++i) {
            map[snakeY[i]][snakeX[i]] = 2;
        }


        if (map[snakeY[0]][snakeX[0]] == 1 || map[snakeY[0]][snakeX[0]] == 2) {
            for (int i = 1; i < snakeLength; ++i) {
                gotoxy(snakeX[i], snakeY[i]);
                wprintf(L" ");
            }
            gotoxy(15, 10);
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 12);
            wprintf(L"game over");
            page = PAGE_SCORE;
            break;
        }

        if (counter == 10) {
            Apple();
        }
        if (map[snakeY[0]][snakeX[0]] == 3) {
            flag = 1;
            ++score;
            showscore();
            gotoxy(snakeX[0], snakeY[0]);
            wprintf(L" ");
            map[appley][applex] = 0;
            Apple();
        }
        
            gotoxy(snakeX[snakeLength - 1], snakeY[snakeLength - 1]);
            wprintf(L" ");
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 0;
     

            if (flag == 1) {
                ++snakeLength;
            }

            for (int i = 1; i < snakeLength; ++i) {
                int tempX = snakeX[i];
                int tempY = snakeY[i];
                snakeX[i] = prevx;
                snakeY[i] = prevy;
                prevx = tempX;
                prevy = tempY;
            }
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            gotoxy(snakeX[0], snakeY[0]);
            SetConsoleTextAttribute(h, 2);
            wprintf(L"▲");
            for (int i = 1; i < snakeLength; ++i) {
                gotoxy(snakeX[i], snakeY[i]);
                SetConsoleTextAttribute(h, 10);
                wprintf(L"■");
            }

            sleep(200);
            ++counter;
            flag = 0;

        }
    }
