#define _CRT_SECURE_NO_WARNINGS
#include "ThemainMenu.h" 

int main()
{
   Inventory list;
   ThemainMenu main;
   main.inputInventory(list);
   main.outputInventory(list);
   main.mainMenu(list);
   system("pause");
   return 0;
}
