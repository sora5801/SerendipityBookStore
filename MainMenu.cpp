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
