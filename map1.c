#include "map1.h"
#include <wchar.h>
#include <windows.h>
#include <io.h> 
#include <fcntl.h>
#include <stdio.h> 
#define setu16 _setmode(_fileno(stdout), _O_U16TEXT)
int map[HEIGHT][WIDTH];

void Map1() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (i == 0 || j == WIDTH - 1 || j == 0 || i == HEIGHT - 1 || i == HEIGHT - 2 || i == 1)
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
}
void drawMap1() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (map[i][j] == 1) {
			   _setmode(_fileno(stdout), _O_U16TEXT);
			   wprintf(L"\u2588");
			}
			else {
			wprintf(L" ");
		    }
		}
		wprintf(L"\n");
	}
}