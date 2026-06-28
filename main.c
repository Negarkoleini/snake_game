#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include "map1.h"
#include "map2.h"
#include "snake.h"
#include "menu.h"

int page = PAGE_LOGIN;
int selectedMap = 1;
char currentUser[50];

void drawMap1();
void drawMap2();
void runsnake();

int main() {
	page = PAGE_LOGIN;
	while (1) {
		runMenu();
	}
	
	return 0;
}