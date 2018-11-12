#pragma once
//#define __BOOK_H__

#include <string>

class book
{
private:
   std::string ISBN;
   std::string title;
   std::string author;
   std::string publisher;
   std::string dateAdded;
   int qtyonHand;
   double wholesaleCost;
   double retailPrice;
   book *next; //dynamically allocate next
public:
   //Constructors
   book();

   //Accessors
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

   //mutators
   std::string getISBN();
   std::string gettitle();
   std::string getauthor();
   std::string getpublisher();
   std::string getdateAdded();
   int getqtyonHand();
   double getwholesaleCost();
   double getretailPrice();
   book* getnextptr();

   //Bool functions
   bool operator==(book&);
   bool operator!=(book&);
   book operator=(book&);

   //Destructor
   ~book();
};