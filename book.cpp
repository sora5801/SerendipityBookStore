#include "book.h"



book::book()
{
   /*ISBN = nullptr;
   title = nullptr;
   author = nullptr;
   publisher = nullptr;
   dateAdded = nullptr;
   */
   qtyonHand = 0;
   wholesaleCost = 0;
   retailPrice = 0;
   next = nullptr;
}

void book::setISBN(std::string str)
{
   ISBN = str;
}

void book::settitle(std::string str)
{
   title = str;
}

void book::setauthor(std::string str)
{
   author = str;
}

void book::setpublisher(std::string str)
{
   publisher;
}

void book::setdateAdded(std::string str)
{
   dateAdded = str;
}

void book::setqtyonHand(int x)
{
   this->qtyonHand = x;
}

void book::setwholesaleCost(double x)
{
   wholesaleCost = x;
}

void book::setretailPrice(double x)
{
   retailPrice = x;
}

void book::setnextptr(book* ptr)
{
   next = ptr;
}

void book::setBook(std::string isbn, std::string ttl, std::string aut, std::string pub,
   std::string date, int qty = 0, double cost = 0, double price = 0, book* nx = nullptr)
{
   this->ISBN = isbn;
   this->title = ttl;
   this->author = aut;
   this->publisher = pub;
   this->dateAdded = date;
   this->qtyonHand = qty;
   this->wholesaleCost = cost;
   this->retailPrice = price;
   this->next = nx;
}

std::string book::getISBN()
{
   return ISBN;
}

std::string book::gettitle()
{
   return title;
}

std::string book::getauthor()
{
   return author;
}

std::string book::getpublisher()
{
   return publisher;
}

std::string book::getdateAdded()
{
   return dateAdded;
}

int book::getqtyonHand()
{
   return qtyonHand;
}

double book::getwholesaleCost()
{
   return wholesaleCost;
}

double book::getretailPrice()
{
   return retailPrice;
}

book* book::getnextptr()
{
   return next;
}

bool book::operator==(book &b)
{
   if (this->getISBN() == b.getISBN() && this->gettitle() == b.gettitle())
      return true;
   else return false;
}

bool book::operator!=(book &b)
{
   if (this->getISBN() != b.getISBN() || this->gettitle() != b.gettitle())
      return true;
   else return false;
}

book book::operator=(book &b)
{
   ISBN = b.getISBN();
   title = b.gettitle();
   author = b.getauthor();
   publisher = b.getpublisher();
   dateAdded = b.getdateAdded();
   qtyonHand = b.getqtyonHand();
   wholesaleCost = b.getwholesaleCost();
   retailPrice = b.getretailPrice();
   next = b.getnextptr();
   return *this;
}

book::~book()
{
}
