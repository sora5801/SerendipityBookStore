#pragma once

//#ifndef __BOOK_H__
//#define __BOOK_H__

#include <string>
#include <iostream>

class book
{
protected:
   std::string ISBN;
   std::string title;
   std::string author;
   std::string publisher;
   std::string dateAdded;
   int qtyonHand;
   double wholesaleCost;
   double retailPrice;
   book *next;
public:
   book(std::string isbn = "", std::string tt = "", std::string aut = "",
      std::string pub = "", std::string date = "", int qty = 0, double cost = 0, double price = 0);

   void setISBN(std::string);
   void settitle(std::string);
   void setauthor(std::string);
   void setpublisher(std::string);
   void setdateAdded(std::string);
   void setqtyonHand(int);
   void setwholesaleCost(double);
   void setretailPrice(double);
   void setnextptr(book*);
   void setBook(std::string, std::string, std::string, std::string, std::string, int, double, double, book*);

   std::string getISBN();
   std::string gettitle();
   std::string getauthor();
   std::string getpublisher();
   std::string getdateAdded();
   int getqtyonHand();
   double getwholesaleCost();
   double getretailPrice();
   book* getnextptr();

   bool operator==(const book&);
   bool operator!=(const book&);
   book operator=(const book&);

   void swapData(book&);

   int compareByQty(const book&);
   double compareByCost(const book&);
   int compareByAge(const book&);

   friend std::ostream& operator<<(std::ostream&, const book&);
   friend void displayBook(const book&);
   friend class Inventory;
   friend class Report;
   ~book();
};