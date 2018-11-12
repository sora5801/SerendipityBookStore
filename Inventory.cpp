#include "Inventory.h"

Inventory::Inventory()
{
   head = nullptr;
   tail = nullptr;
   count = 0;
}

void Inventory::addBook(book bk)
{
   book * temp = new book;
   *temp = bk;
   if (!head)
   {
      head = temp;
      head->setnextptr(nullptr);
      tail = head;
   }
   else
   {
      tail->setnextptr(temp);
      tail = temp;
      tail->setnextptr(nullptr);
   }
   count++;
}

void Inventory::removeBook(book* bk)
{
   book *temp = head;
   if (*head == *bk)
   {
      if (tail == head)
         tail = nullptr;
      head = head->getnextptr();
      temp->setnextptr(nullptr);
      delete temp;
      count--;
   }
   else
   {
      while (*(temp->getnextptr()) != *bk && temp != nullptr)
      {
         temp = temp->getnextptr();
      }
      if (temp->getnextptr() == tail)
      {
         tail = temp;
         tail->setnextptr(nullptr);
      }
      else
         temp->setnextptr(temp->getnextptr()->getnextptr());
      count--;
   }


}

book* Inventory::searchByISBN(std::string isbn)
{
   book *temp = head;
   while (temp)
   {
      if (temp->getISBN() == isbn)
         return temp;
      temp = temp->getnextptr();
   }
   return nullptr;
}

book* Inventory::searchByTitle(std::string name)
{
   book *temp = head;
   while (temp)
   {
      if (temp->gettitle() == name)
         return temp;
      temp = temp->getnextptr();
   }
   return nullptr;
}

void Inventory::purchaseBook(book* bk)
{
   if (bk->getqtyonHand() > 0)
   {
      bk->setqtyonHand(bk->getqtyonHand() - 1);
   }
   else
   {
      removeBook(bk);
   }
}

Inventory::~Inventory()
{
   book * temp = head;
   while (head)
   {
      head = head->getnextptr();
      delete temp;
      temp = head;
   }
}