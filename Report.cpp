#include "Report.h"

void displayList(const Report &list)
{
   book *temp = list.head;
   while (temp)
   {
      displayBook(*temp);
      std::cout << std::endl;
      temp = temp->getnextptr();
   }
}





void Report::sortByQty()
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

void Report::sortByCost()
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

void Report::sortByAge()
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

double Report::getWholesaleValue()
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


double Report::getRetailValue()
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