#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"



Inventory::Inventory()
{
   head = nullptr;
   tail = nullptr;
   count = 0;
}

int Inventory::getCount()
{
   return count;
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
   if (bk)
   {
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

double Inventory::getWholesaleValue()
{
   book *temp = head;
   double total = 0;
   while (temp)
   {
      total += temp->getwholesaleCost() * temp->getqtyonHand();
      temp = temp->getnextptr();
   }
   return total;
}


double Inventory::getRetailValue()
{
   book *temp = head;
   double total = 0;
   while (temp)
   {
      total += temp->getretailPrice() * temp->getqtyonHand();
      temp = temp->getnextptr();
   }
   return total;
}

void Inventory::sortByQty()
{
   for (book* i = head; i != nullptr && i->getnextptr() != nullptr; i = i->getnextptr())
   {
      book *max;
      max = i;
      for (book *j = i->getnextptr(); j != nullptr; j = j->getnextptr())
      {
         if (j->compareByQty(*max) > 0)
            max = j;
      }
      if (max != i)
         i->swapData(*max);
   }
}

void Inventory::sortByCost()
{
   for (book* i = head; i != nullptr && i->getnextptr() != nullptr; i = i->getnextptr())
   {
      book *max;
      max = i;
      for (book *j = i->getnextptr(); j != nullptr; j = j->getnextptr())
      {
         if (j->compareByCost(*max) > 0)
            max = j;
      }
      if (max != i)
         i->swapData(*max);
   }
}

void Inventory::sortByAge()
{
   for (book* i = head; i != nullptr && i->getnextptr() != nullptr; i = i->getnextptr())
   {
      book *max;
      max = i;
      for (book *j = i->getnextptr(); j != nullptr; j = j->getnextptr())
      {
         if (j->compareByAge(*max) > 0)
            max = j;
      }
      if (max != i)
         i->swapData(*max);
   }
}

book* Inventory::returnHead()
{
   return head;
}

void displayList(const Inventory &list)
{
   book *temp = list.head;
   while (temp)
   {
      displayBook(*temp);
      std::cout << std::endl;
      temp = temp->getnextptr();
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