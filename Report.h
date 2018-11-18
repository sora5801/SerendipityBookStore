#pragma once
#include "book.h"
#include "Inventory.h"

class Report:public Inventory
{
private:
   book * head;
   book *tail;
public:
   virtual double getWholesaleValue();
   virtual double getRetailValue();
   virtual void sortByQty();
   virtual void sortByCost();
   virtual void sortByAge();
   friend void displayList(const Report&);
   friend class Inventory;
   friend class book;
}; 

