#define _CRT_SECURE_NO_WARNINGS
#include "ThemainMenu.h" 
/* Pseudocode for the program:
Creates an Inventory object called list.
Create a ThemainMenu object called main.
Calls the ThemainMenu function inputInventory and passes list to it.
   Opens the .txt file of the Inventory
   Declares variables for isbn, title, author, publisher, date, qty, cost, and price.
   Declares a book object bk.
   While the file has not reached the end,
      getline the isbn
      getline the title
      getline the author
      getline the publisher
      getline the date
      store the quantity, cost, and price
      Call the book function setBook to set a book
      Calls the Inventory function addBook to add a book to the inventory.
   Closes the file
Calls the ThemainMenu function outputInventory and passes list to it.
   Opens the .txt file of the Inventory
   Declares a book pointer arr to be set to the returnHead() pointer function
   While arr is still pointing
      if dereferenced arr calls getnextptr function
         write to the file the dereferenced arr
      else
         write to the file the dereference add
      set arr to be arr that calls the getnextptr function.
   Closes the file.
Calls the ThemainMenu function mainMenu and passes list to it.
Give the user four option.
If the user selects 1, call the cashierMenu function
   Declares string item, int n, char date, option, and double subtotal, tax, and total
   Declare a book pointer *bk;
   Display the start of the menu
   Ask user to Enter a book title or ISBN
   Ask user for the number of copies
   If user enters a title
      Set the pointer to be the list object that calls the Inventory function searchbyISBN
   Else
      Set the pointer to be the list object that calls the Inventory function searchByTitle
   If bk
      If there is more book on than the number of copies in the inventory
         Display "Purchase complete	'
         Remove the number of books from the inventory
         Calculate the subtotal
      Else
         Display "Not enough books"
      Else
         Display "There's not enough books"
      Ask users if you want to buy more item
   Set tax to be subtotals times Tax rate
   Set total to be the subtotal + tax
   Output the subtotal, tax, and total
   Prompt user to return to the main menu or quite the program
   If the user inputs R
      return to the mainmenu
   Else
      exit the program
If the user selects 2, call the InventoryMenu function
   Displays the Inventory DataBase Module
   Declares int option, string item, book *bk, book b, and string data.
   Gives user 5 options.
      If the user presses 1, looks up information of a book
      Prompts user to enter the book title or ISBN
         If the item is a number
            Call the search by ISBN function
         Else
            Call the search by title function
      If the book is in the inventory
         Displays the book
      Else
         Display "Haven't seen this book"
   If the user presses 2, then add new book
      Prompt user for ISBN
      if the ISBN is already in the inventory
         display "The book is already in the inventory"
         Give the user the option to edit the book or return to the inventory
         If the user wants to edit
            editBook
         else if user does not want to edit
            return the main menu
      else
            display "You entered the wrong option."
      Ask for Title
      Ask for the Author
      Ask for the Publisher
      Ask for the date Added
      Ask for the quantity on hand
      Ask for the wholesale cost
      Ask for the retail price
      display "Add book complete".
   If the user presses 3, then edit the book
      Prompt user to enter the title or ISBN of a book
      if the item is a number
         call the search by ISBN function
      else
         call the search by title function
      if the book is in the inventory
      call the editbook function
         Prompt user 9 options
         if the user inputs 1
            Ask for new ISBN
         if the user inputs 2
            Ask for new Title
         if the user inputs 3
            Ask for new Author
         if the user inputs 4
            Ask for new Publisher
         if the user inputs 5
            Ask for new date added
         if the user inputs 6
            Ask for new Quantity on hand
         if the user inputs 7
            Ask for new Wholesale Cost
         if the user inputs 8
            Ask for new Retail Price
         If the user inputs 9
            returns to the inventory menu
      else
         display "Haven't seen this book"
      If the user presses 4, then delete a book
         Prompt user to enter the title of ISBN of a book
         if the item is a number
            call the search by ISBN function
         else
            call the search by title function
       if the book is in the inventory
            call the Inventory function removeBook to remove the book
            display "Delete complete!"
       else
            display "Haven't seen this book in the inventory.'
If the user presses 5, return to the main menu.
If the user selects 3, call the reportMenu function
Displays the Report Module
   Gives the user 7 options
      If the user inputs 1
         call the displaylist function by passing the list object to the function
      If the user inputs 2
         call the getWholesaleValue function
               Sums up the entire wholesale cost of the inventory
      If the user inputs 3
         call the getRetailValue function
               Sums up the entire retail value cost of the inventory
      If the user inputs 4
         call the sortByQty function
         Finds the largest quantity first
         Places that at the start of the node
         Repeats until sorted.
      If the user inputs 5
         call the sortByCost function
         Finds the largest wholesale cost first
         Places that at the start of the node
         Repeats until sorted.
      If the user inputs 6
         call the sortByAge function
         Finds the oldest book first
         Places that at the start of the node
         Repeats until sorted.
      If the user inputs 7
         return to main menu
*/
int main()
{
   Inventory list;
   ThemainMenu main;
   main.inputInventory(list);
   main.outputInventory(list);
   main.mainMenu(list);
   system("pause");
   return 0;
}
