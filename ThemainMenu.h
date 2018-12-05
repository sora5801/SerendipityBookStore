#pragma once
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <string>
#include "Inventory.h"
#include "book.h"


class ThemainMenu 
{
public:
  
    void inputInventory(Inventory&);
   void outputInventory(Inventory&);
   void mainMenu(Inventory&);
   void cashierMenu(Inventory&);
   void inventoryMenu(Inventory&);
   void editBook(book&);
   void reportMenu(Inventory&);
   bool is_number(const std::string&);

};
