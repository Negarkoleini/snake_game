#ifndef MENU_H
#define MENU_H

#define PAGE_LOGIN       0
#define PAGE_SELECTMAP   1
#define PAGE_MAPMENU     2
#define PAGE_GAME        3
#define PAGE_SCORE       4

extern int page;
extern int selectedMap;
extern char currentUser[50];

void runMenu();

#endif