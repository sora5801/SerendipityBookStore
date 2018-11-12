#pragma once

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
   void addBook(book);
   void removeBook(book*);
   book* searchByISBN(std::string);
   book* searchByTitle(std::string);
   void purchaseBook(book*);
   ~Inventory();
};
