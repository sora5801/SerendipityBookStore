#pragma once
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <string>
#include "Inventory.h"
#include "book.h"


class ThemainMenu : private book, private Inventory
{
private:
  // Inventory list;
  // book Book;
public:
   //Default Constructor
  // ThemainMenu();
  // ThemainMenu(Inventory&);
    void inputInventory(Inventory&);
   void outputInventory(Inventory&);
   void mainMenu(Inventory&);
   void cashierMenu(Inventory&);
   void inventoryMenu(Inventory&);
   void editBook(book&);
   void reportMenu(Inventory&);
   bool is_number(const std::string&);
   //Destructor;
  // ~ThemainMenu();

};
