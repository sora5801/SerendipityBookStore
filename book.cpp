#include "book.h"



book::book(std::string isbn, std::string tt, std::string aut,
   std::string pub, std::string date, int qty, double cost, double price)
{
   ISBN = isbn;
   title = tt;
   author = aut;
   publisher = pub;
   dateAdded = date;
   qtyonHand = qty;
   wholesaleCost = cost;
   retailPrice = price;
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
   publisher = str;
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

bool book::operator==(const book &b)
{
   if (this->ISBN == b.ISBN && this->title == b.title)
      return true;
   else return false;
}

bool book::operator!=(const book &b)
{
   if (this->ISBN != b.ISBN || this->title != b.title)
      return true;
   else return false;
}

book book::operator=(const book &b)
{
   ISBN = b.ISBN;
   title = b.title;
   author = b.author;
   publisher = b.publisher;
   dateAdded = b.dateAdded;
   qtyonHand = b.qtyonHand;
   wholesaleCost = b.wholesaleCost;
   retailPrice = b.retailPrice;
   next = b.next;
   return *this;
}

void book::swapData(book& b)
{
   book temp = *this;
   ISBN = b.ISBN;
   title = b.title;
   author = b.author;
   publisher = b.publisher;
   dateAdded = b.dateAdded;
   qtyonHand = b.qtyonHand;
   wholesaleCost = b.wholesaleCost;
   retailPrice = b.retailPrice;

   b.ISBN = temp.ISBN;
   b.title = temp.title;
   b.author = temp.author;
   b.publisher = temp.publisher;
   b.dateAdded = temp.dateAdded;
   b.qtyonHand = temp.qtyonHand;
   b.wholesaleCost = temp.wholesaleCost;
   b.retailPrice = temp.retailPrice;
}

int book::compareByQty(const book& b)
{
   return this->qtyonHand - b.qtyonHand;
}

double book::compareByCost(const book& b)
{
   return this->wholesaleCost - b.wholesaleCost;
}

int book::compareByAge(const book& b)
{
   if (this->dateAdded == b.dateAdded) return 0;
   if (stoi(this->dateAdded.substr(6, 4)) != stoi(b.dateAdded.substr(6, 4)))
      return stoi(b.dateAdded.substr(6, 4)) - stoi(this->dateAdded.substr(6, 4));
   else if (stoi(this->dateAdded) != stoi(b.dateAdded))
      return stoi(b.dateAdded) - stoi(this->dateAdded);
   else
      return stoi(b.dateAdded.substr(3, 2)) - stoi(this->dateAdded.substr(3, 2));
}

std::ostream& operator<<(std::ostream& out, const book& b)
{
   out << b.ISBN << std::endl;
   out << b.title << std::endl;
   out << b.author << std::endl;
   out << b.publisher << std::endl;
   out << b.dateAdded << std::endl;
   out << b.qtyonHand << std::endl;
   out << b.wholesaleCost << std::endl;
   out << b.retailPrice;
   return out;
}

void displayBook(const book &b)
{
   std::cout << "ISBN: " << b.ISBN << std::endl;
   std::cout << "Title: " << b.title << std::endl;
   std::cout << "Author: " << b.author << std::endl;
   std::cout << "Publisher: " << b.publisher << std::endl;
   std::cout << "Date Added: " << b.dateAdded << std::endl;
   std::cout << "Qty on Hand: " << b.qtyonHand << std::endl;
   std::cout << "Wholesale Cost: " << b.wholesaleCost << std::endl;
   std::cout << "Retail Price: " << b.retailPrice << std::endl;
}

book::~book()
{
}