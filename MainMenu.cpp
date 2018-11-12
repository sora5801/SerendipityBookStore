#include <iostream>
#include <iomanip>

using namespace std;

void menu();
int main()
{
   menu();
}

void menu()

{

   cout << "\n****************************************" << endl;

   cout << "\t Serendipity Booksellers" << endl;

   cout << "******************************************" << endl;

   cout << "\t MAIN MENU " << endl;

   cout << "\t ---------- " << endl;

   cout << "\t 1.Cashier Module" << endl;

   cout << "\t 2.Inventory Database Module" << endl;

   cout << "\t 3.Report Module" << endl;

   cout << "\t 4.Exit" << endl;

}

void cashier()

{

   cout << "\n****************************************" << endl;

   cout << "\t Serendipity Booksellers" << endl;

   cout << "******************************************" << endl;

   cout << "\n\t Cashier Module is selected" << endl;

   cout << "\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

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

void invmenu() //Inventory Database function

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
