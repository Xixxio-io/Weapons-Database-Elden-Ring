#ifndef HELPER_H
#define HELPER_H

void getInfo(char* category, int countWeapon[]);
void clearScreen();
char* choose_Category(char* category);
void clearInputBuffer();
int ifExist(char* name, list L);

#endif