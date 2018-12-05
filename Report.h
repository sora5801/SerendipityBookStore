#pragma once
#include "book.h"
#include "Inventory.h"

class Report: public Inventory, public book //Display inheritance
{
private:
   book * head;
   book *tail;
public:
   virtual double getWholesaleValue();
   virtual double getRetailValue();
   virtual void sortByQty(); //Displays polymorphism
   virtual void sortByCost();
   virtual void sortByAge();
   friend void displayList(const Report&);
}; 

