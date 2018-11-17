#include <time.h>
#include <iomanip>
#include <fstream>
#include "Inventory.h"

using namespace std;

#define TAX_RATE 0.1

void inputInventory(Inventory&);
void outputInventory(Inventory&);
void mainMenu(Inventory&);
void cashierMenu(Inventory&);
void inventoryMenu(Inventory&);
void editBook(book&);
void reportMenu(Inventory&);
bool is_number(const string&);

int main()
{
   Inventory list;
   inputInventory(list);
   mainMenu(list);
   outputInventory(list);
   system("pause");
   return 0;
}

void inputInventory(Inventory &list)
{
   ifstream inFile;
   inFile.open("Inventory.txt");
   if (!inFile.fail())
   {
      string isbn, title, author, publisher, date;
      int qty;
      double cost, price;
      book bk;
      while (!inFile.eof())
      {
         getline(inFile, isbn);
         getline(inFile, title);
         getline(inFile, author);
         getline(inFile, publisher);
         getline(inFile, date);
         inFile >> qty >> cost >> price;
         inFile.ignore();
         bk.setBook(isbn, title, author, publisher, date, qty, cost, price, nullptr);
         list.addBook(bk);
      }
      cout << "Read Inventory Database File Complete!" << endl << endl;
   }
   inFile.close();
}

void outputInventory(Inventory &list)
{
   ofstream outFile;
   outFile.open("Inventory.txt");
   if (!outFile.fail())
   {
      book * arr = list.returnHead();
      while (arr)
      {
         if (arr->getnextptr())
            outFile << *arr << endl;
         else
            outFile << *arr;
         arr = arr->getnextptr();
      }
   }
   outFile.close();
}

void mainMenu(Inventory& list)
{
   int option;
   cout << "****************************************" << endl;
   cout << "\t Serendipity Booksellers" << endl;
   cout << "****************************************" << endl;
   cout << "\t MAIN MENU " << endl;
   cout << "\t --------- " << endl;

   cout << "1. Cashier Module" << endl
      << "2. Inventory Database Module" << endl
      << "3. Report Module" << endl
      << "4. Quit the program" << endl
      << "Enter your option: ";
   cin >> option;
   switch (option)
   {
   case 1:
      cashierMenu(list);
      break;
   case 2:
      inventoryMenu(list);
      break;
   case 3:
      reportMenu(list);
      break;
   case 4:
      cout << "Thank you for using the program!" << endl;
      break;
   default:
      cout << "You entered wrong option! Please try again!" << endl;
      mainMenu(list);
      break;
   }

}

void cashierMenu(Inventory &list)
{
   string item;
   int n;
   char date[9], option = 'Y';
   double subtotal = 0, tax, total;
   _strdate_s(date);
   book *bk;
   cout << "\n****************************************" << endl;
   cout << "\t Serendipity Booksellers" << endl;
   cout << "\t Date: " << date << endl;
   cout << "******************************************" << endl;
   cout << "\n\t Cashier Module is selected" << endl;
   cout << "\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << left << setw(5) << "Qty"
      << setw(10) << "ISBN"
      << setw(30) << "Title"
      << setw(8) << "Price"
      << setw(10) << "Total" << endl;
   cout << "-----------------------------------------------------------------------------" << endl;

   while (option == 'Y' || option == 'y')
   {
      cout << "Enter book title or ISBN: ";
      cin.ignore();
      getline(cin, item);
      cout << "Enter number of copies: ";
      cin >> n;
      if (is_number(item))
         bk = list.searchByISBN(item);
      else
         bk = list.searchByTitle(item);
      if (bk)
      {
         if (bk->getqtyonHand() > n)
         {
            cout << "Purchase complete!" << endl;
            bk->setqtyonHand(bk->getqtyonHand() - n);
            subtotal += n * bk->getretailPrice();
            cout << fixed;
            cout << left << setw(5) << n
               << setw(10) << bk->getISBN()
               << setw(30) << bk->gettitle()
               << right << setw(8) << setprecision(2) << bk->getretailPrice()
               << setw(10) << n * bk->getretailPrice() << endl;
         }
         else
            cout << "Not enough books in the inventory! Please try again!" << endl;
      }
      else
         cout << "This item is not in the inventory! Please try again!" << endl;
      cout << "Press Y to buy more item or N to finish and get bill: ";
      cin >> option;
   }
   tax = subtotal * TAX_RATE;
   total = subtotal + tax;
   cout << left << setw(30) << " " << setw(11) << "Subtotal: " << setw(8) << right << setprecision(2) << subtotal << endl;
   cout << left << setw(30) << " " << setw(11) << "Tax: " << setw(8) << right << setprecision(2) << tax << endl;
   cout << left << setw(30) << " " << setw(11) << "Total: " << setw(8) << right << setprecision(2) << total << endl;
   cout << "Enter R to return to main menu or Q to quit the program: ";
   cin >> option;
   if (option == 'R')
      mainMenu(list);
   else
      cout << "Thank you for using the program!" << endl;
}

void inventoryMenu(Inventory &list)
{
   int option;
   string item;
   book *bk;
   book b;
   string data;
   cout << "\n****************************************" << endl;
   cout << "\t Serendipity Booksellers" << endl;
   cout << "******************************************" << endl;
   cout << "\t Inventory Database Module" << endl;
   cout << "\t =========================" << endl;


   cout << "1. Look up infomation of a book" << endl;
   cout << "2. Add a new book to inventory" << endl;
   cout << "3. Edit a book in inventory" << endl;
   cout << "4. Delete a book in inventory" << endl;
   cout << "5. Return the main menu" << endl;
   cout << "Enter your option: ";
   cin >> option;
   cout << endl;
   switch (option)
   {
   case 1:
      cout << "Enter book title or ISBN: ";
      cin.ignore();
      getline(cin, item);
      if (is_number(item))
         bk = list.searchByISBN(item);
      else
         bk = list.searchByTitle(item);
      cout << endl;
      if (bk)
         displayBook(*bk);
      else
         cout << "Haven't seen this book in the inventory!" << endl << endl;
      break;
   case 2:
      int qty;
      double price;
      cout << "Enter book's information" << endl;
      cout << "ISBN: ";
      cin.ignore();
      getline(cin, data);
      if (bk = list.searchByISBN(data))
      {
         char check = '0';
         cout << "The book with ISBN " << data << " is already in the inventory!" << endl;
         while (check == '0')
         {
            cout << "Enter E if you want to edit the book or R to go back Inventory menu: ";
            cin >> check;
            if (check == 'Y' || check == 'y')
               editBook(*bk);
            else if (check == 'R' || check == 'r')
            {
               inventoryMenu(list);
               return;
            }
            else
            {
               cout << "You entered wrong option!" << endl;
               check = '0';
            }
         }
      }
      b.setISBN(data);
      cout << "Title: ";
      getline(cin, data);
      b.settitle(data);
      cout << "Author: ";
      getline(cin, data);
      b.setauthor(data);
      cout << "Publisher: ";
      getline(cin, data);
      b.setpublisher(data);
      cout << "Date Added (mm/dd/yyyy): ";
      getline(cin, data);
      b.setdateAdded(data);
      cout << "Quantity-on-hand: ";
      cin >> qty;
      b.setqtyonHand(qty);
      cout << "Wholesale Cost: ";
      cin >> price;
      b.setwholesaleCost(price);
      cout << "Retail Price: ";
      cin >> price;
      b.setretailPrice(price);
      list.addBook(b);
      cout << endl << "Add book complete!" << endl;
      break;
   case 3:
      cout << "Enter book title or ISBN: ";
      cin.ignore();
      getline(cin, item);
      if (is_number(item))
         bk = list.searchByISBN(item);
      else
         bk = list.searchByTitle(item);
      cout << endl;
      if (bk)
         editBook(*bk);
      else
         cout << "Haven't seen this book in the inventory!" << endl << endl;
      break;
   case 4:
      cout << "Enter book title or ISBN: ";
      cin.ignore();
      getline(cin, item);
      if (is_number(item))
         bk = list.searchByISBN(item);
      else
         bk = list.searchByTitle(item);
      cout << endl;
      if (bk)
      {
         list.removeBook(bk);
         cout << "Delete complete!" << endl;
      }
      else
         cout << "Haven't seen this book in the inventory!" << endl << endl;
      break;
   case 5:
      mainMenu(list);
      return;
   default:
      cout << "You entered wrong option! Please try again!" << endl << endl;
      inventoryMenu(list);
      break;
   }
   system("pause");
   cout << endl;
   inventoryMenu(list);
}

void editBook(book& b)
{
   int opt, qty;
   char option;
   double price;
   string data;

   cout << "Which one do you want to edit?" << endl
      << "1. ISBN" << endl
      << "2. Title" << endl
      << "3. Author" << endl
      << "4. Publisher" << endl
      << "5. Date Added" << endl
      << "6. Quantity-on-hand" << endl
      << "7. Wholesale Cost" << endl
      << "8. Retail Price" << endl
      << "9. Return to the Inventory Menu"
      << "Enter your option: ";
   cin >> opt;
   switch (opt)
   {
   case 1:
      cout << "Enter new ISBN: ";
      cin.ignore();
      getline(cin, data);
      b.setISBN(data);
      break;
   case 2:
      cout << "Enter new Title: ";
      cin.ignore();
      getline(cin, data);
      b.settitle(data);
      break;
   case 3:
      cout << "Enter new Author: ";
      cin.ignore();
      getline(cin, data);
      b.setauthor(data);
      break;
   case 4:
      cout << "Enter new Publisher: ";
      cin.ignore();
      getline(cin, data);
      b.setpublisher(data);
      break;
   case 5:
      cout << "Enter new Date Added (mm/dd/yyyy): ";
      cin.ignore();
      getline(cin, data);
      b.setdateAdded(data);
      break;
   case 6:
      cout << "Enter new Quantity-on-hand: ";
      cin >> qty;
      b.setqtyonHand(qty);
      break;
   case 7:
      cout << "Enter new Wholesale Cost: ";
      cin >> price;
      b.setwholesaleCost(price);
      break;
   case 8:
      cout << "Enter new Retail Price: ";
      cin >> price;
      b.setretailPrice(price);
      break;
   case 9:
      return;
   default:
      cout << "You entered wrong option! Please try again!" << endl;
      break;
   }
   cout << "Do you want to edit more?" << endl
      << "Enter Y if you want or N to return Inventory Menu: ";
   cin >> option;
   if (option == 'Y' || option == 'y')
      editBook(b);
}


void reportMenu(Inventory &list)
{
   int opt;
   cout << "\n***************************************" << endl;
   cout << "\t Serendipity Booksellers" << endl;
   cout << "***************************************" << endl;
   cout << "\t Reports Module" << endl;
   cout << "\t ==============" << endl;

   cout << "1. Inventory Listing" << endl
      << "2. Inventory Wholesale Value" << endl
      << "3. Inventory Retail Value" << endl
      << "4. Listing by Quantity" << endl
      << "5. Listing by Cost" << endl
      << "6. Listing by Age" << endl
      << "7. Return to the Main Menu" << endl;
   cout << "Enter your option: ";
   cin >> opt;
   cout << endl;
   switch (opt)
   {
   case 1:
      displayList(list);
      break;
   case 2:
      cout << "Inventory Wholesale Value: " << list.getWholesaleValue() << endl;
      break;
   case 3:
      cout << "Inventory Retail Value: " << list.getRetailValue() << endl;
      break;
   case 4:
      list.sortByQty();
      cout << "Complete sorted from high to low qty!" << endl;
      break;
   case 5:
      list.sortByCost();
      cout << "Complete sorted from high to low cost!" << endl;
      break;
   case 6:
      list.sortByAge();
      cout << "Complete sorted from high to low age!" << endl;
      break;
   case 7:
      mainMenu(list);
      return;
   default:
      break;
   }
   system("pause");
   cout << endl;
   reportMenu(list);
}

bool is_number(const string &s) {
   bool check = true;
   if (!s.empty())
   {
      for (size_t i = 0; i < s.length(); i++)
      {
         if (!isdigit(s[i]))
            check = false;
      }
   }
   return check;
}
/*
void cashier()

{

   cout << "\n****************************************" << endl;

   cout << "\t Serendipity Booksellers" << endl;

   cout << "******************************************" << endl;

   cout << "\n\t Cashier Module is selected" << endl;

   cout << "\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

   cout<<"\n\n Thank you for shopping at Serendipity!!! Have a nice day\n\n"<<endl;

}

void setbookdetails()

{

   int i = size;

   cout << "Enter book info for book " << i << endl;

   cout << "Enter title of the book" << endl;

   cin >> title[i];

   cout << "Enter ISBN: " << endl;

   cin >> isbn[i];

   cout << "Enter the author name" << endl;

   cin >> author[i];

   cout << "Enter the publisher name" << endl;

   cin >> publisher[i];

   cout << "Enter the date in MM-DD-YYYY format" << endl;

   cin >> date[i];

   cout << "Enter the quantity on hand" << endl;

   cin >> qty[i];

   cout << "Enter the whole sale price of each book" << endl;

   cin >> wholesale[i];

   cout << "Enter the retail price of the book" << endl;

   cin >> retail[i];

   cout << endl;

}

void editmenu()

{

   cout << "\t Edit menu fields are" << endl;

   cout << "===============================" << endl;

   cout << "\t 1.Title" << endl;

   cout << "\t 2.ISBN" << endl;

   cout << "\t 3.Author" << endl;

   cout << "\t 4.Publisher" << endl;

   cout << "\t 5.Date added" << endl;

   cout << "\t 6.Quantity on hand" << endl;

   cout << "\t 7.Wholesale cost of the book" << endl;

   cout << "\t 8.Retail price of the book" << endl;

   cout << "\t 9.Exit from edit menu" << endl;

   cout << endl;

}

void invmenu() 
{

   int ch;

   do

   {

      cout << "\n****************************************" << endl;

      cout << "\t Serendipity Booksellers" << endl;

      cout << "******************************************" << endl;

      cout << "\t Inventory Database Module" << endl;

      cout << "\t ==========================" << endl;

      cout << "\t 1.AddBook Function" << endl;

      cout << "\t 2.LookupBook Function" << endl;

      cout << "\t 3.EditBook Function" << endl;

      cout << "\t 4.DeleteBook Function" << endl;

      cout << "\t 5.Return to main menu" << endl;

      cout << endl;

      cout << "Enter ur choice" << endl;
   }

   void reports()

   {

   int ch;

   cout << endl;

   do

   {

   cout << "***************************************" << endl;

   cout << "\t Serendipity Booksellers" << endl;

   cout << "***************************************" << endl;

   cout << "\t Reports Module" << endl;

   cout << "\t ================" << endl;

   cout << "\t 1.Inventory Listing" << endl;

   cout << "\t 2.Inventory WholeSale value" << endl;

   cout << "\t 3.Inventory Retail Value" << endl;

   cout << "\t 4.Listing by Quantity" << endl;

   cout << "\t 5.Listing by Cost" << endl;

   cout << "\t 6.Listing by Age" << endl;

   cout << "\t 7.Return to the main menu" << endl;

   cout << "Enter ur choice" << endl;
   }

*/