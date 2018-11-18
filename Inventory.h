#pragma once
#include "book.h"
class Inventory
{
private:
   book * head;
   book *tail;
   int count;
public:
   Inventory();
   int getCount();
   void addBook(book);
   void removeBook(book*);
   book* searchByISBN(std::string);
   book* searchByTitle(std::string);
   double getWholesaleValue();
   double getRetailValue();
   void sortByQty();
   void sortByCost();
   void sortByAge(); 
   book* returnHead();
   friend void displayList(const Inventory&);
   friend class Report;
   friend class book;
   ~Inventory();
};
