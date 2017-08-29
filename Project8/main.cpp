/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: To create an online shopping cart program and to learn how to use Classes to do so
 Inputs:
   A single letter for menu choice
   Name of item to add to cart as well as:
      Item description, Item price, and Item quantity
   Name of item to delete from cart
   Name of item to update quantity and the new quantity
   Name of shopper and the current date
 Outputs:
   Prints shoper name and date, number of items, item names, quantity and price, and total price of all items in cart
      If nothing in cart says shopping cart is empty
   Prints shopper name and date, item name and description of all items in cart
   Outputs menu choices and prompts user for their choice
   Prompts user to add an item, description, price and quantity of item to the cart
   Prompts user to enter name of item to remove
      If not in cart says its not in there and nothing is removed
   Prompts user to enter name and change quantity of item
      If not in cart says its not in there and nothing updated
   Prompts user to enter name and date and prints them out
 Test Cases:
   Case 1:
      Input: The following input tests to see if an appropriate message is displayed for the user input typed:
         Walter White, November 1, 2016, o, d, Methylamine, c, Methylamine, 2, f, x, q
      Output: The output was correct in testing to see if the cart was empty, if nothing was deleted if not found,
         and nothing was modified if not found. Also, tested to see if menu prompt choice
         is printed over again till a correct option is chosen.
   Case 2:
      Input: Walter White, November 1, 2016, a, Methylamine, 10 gal of chemical precursor, 500, 10, a,
         Plastic Barrel, 25 gal barrel, 45, 10, d, Plastic Barrel, i, q
      Expected Output: Will prompt to enter item name, item description, item price, and item quantity for
         both Methylamine and Plastic Barrel. Will ask for the name of the item to remove and will remove it.
         Prints out only the description for Methylamine.
      All outputs were as expected
   Case 3:
      Input: Walter White, November 1, 2016, a, Methylamine, 10 gal of chemical precursor, 500, 10, a,
         Plastic Barrel, 25 gal barrel, 45, 10, a, Hydrofluoric acid, 1 gal acidic solution, 35, 20, c, Hydrofluoric acid,
         10, o, q
      Expected Output: Prompt for item info as above for each item. Asks for which item to change quantity of.
         Should print out Hydrofluoric acid as a quantity of 10 and not 20. Price of 10 Methylamine should be 5,000.
         Price of 10 Plastic Barrels should be 450. Price of 10 Hydrofluoric acid should be
         350 not 700 since quantity was changed. Total should be 5,800 with 30 items in cart.
      All outputs were as expected
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart customersItems) {
   
   char const QUIT_OPTION = 'q';
   char const ADD_OPTION = 'a';
   char const REMOVE_OPTION = 'd';
   char const CHANGE_QUANTITY_OPTION = 'c';
   char const OUTPUT_DESCRIPTIONS_OPTION = 'i';
   char const OUTPUT_CART_OPTION = 'o';
   char menuChoice = '?';
   bool stopMenuFunction = false;
   string addItemName;
   string addItemDescription;
   string deleteItemName;
   string updateItemQuantity;
   int addItemPrice = 0;
   int addItemQuantity = 0;
   int changedQuantityItem = 0;
   ItemToPurchase addItem;
   
   while (!stopMenuFunction) {
      cout << "MENU" << endl;
      cout << ADD_OPTION << " - Add item to cart" << endl;
      cout << REMOVE_OPTION << " - Remove item from cart" << endl;
      cout << CHANGE_QUANTITY_OPTION << " - Change item quantity" << endl;
      cout << OUTPUT_DESCRIPTIONS_OPTION << " - Output items\' descriptions" << endl;
      cout << OUTPUT_CART_OPTION << " - Output shopping cart" << endl;
      cout << QUIT_OPTION << " - Quit" << endl;
      do {
         cout << "Choose an option: ";
         cin >> menuChoice;
      } while (menuChoice != QUIT_OPTION && menuChoice != ADD_OPTION && menuChoice != REMOVE_OPTION
               && menuChoice != CHANGE_QUANTITY_OPTION && menuChoice != OUTPUT_DESCRIPTIONS_OPTION &&
               menuChoice != OUTPUT_CART_OPTION);
      cout << endl;
      
      if (menuChoice == OUTPUT_CART_OPTION) {
         cout << "OUTPUT SHOPPING CART" << endl;
         customersItems.PrintTotal();
      }
      else if (menuChoice == OUTPUT_DESCRIPTIONS_OPTION) {
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         customersItems.PrintDescription();
      }
      else if (menuChoice == ADD_OPTION) {
         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name: ";
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         getline(cin, addItemName);
         addItem.SetName(addItemName);
         cout << endl;
         cout << "Enter the item description: ";
         getline(cin, addItemDescription);
         addItem.SetDescription(addItemDescription);
         cout << endl;
         cout << "Enter the item price: ";
         cin >> addItemPrice;
         addItem.SetPrice(addItemPrice);
         cout << endl;
         cout << "Enter the item quantity: ";
         cin >> addItemQuantity;
         addItem.SetQuantity(addItemQuantity);
         cout << endl;
         customersItems.AddItem(addItem);
      }
      else if (menuChoice == REMOVE_OPTION) {
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove: ";
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         getline(cin, deleteItemName);
         cout << endl;
         customersItems.RemoveItem(deleteItemName);
      }
      else if (menuChoice == CHANGE_QUANTITY_OPTION) {
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name: ";
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         getline(cin, updateItemQuantity);
         cout << endl;
         cout << "Enter the new quantity: ";
         cin >> changedQuantityItem;
         cout << endl;
         customersItems.UpdateQuantity(updateItemQuantity, changedQuantityItem);
      }
      else if (menuChoice == QUIT_OPTION) {
         stopMenuFunction = true;
      }
   }
}

int main() {
   
   string shoperName;
   string dateToday;
   ShoppingCart customerAndDate;
   
   cout << "Enter Customer's Name: ";
   getline(cin, shoperName);
   cout << endl;
   cout << "Enter Today's Date: ";
   getline(cin, dateToday);
   cout << endl;
   customerAndDate = ShoppingCart(shoperName, dateToday);
   
   cout << "Customer Name: " << customerAndDate.GetCustomerName() << endl;
   cout << "Today's Date: " << customerAndDate.GetDate() << endl << endl;
   
   PrintMenu(customerAndDate);
   
   return 0;
}
