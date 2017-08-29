/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: To create an online shopping cart program and to learn how to use Classes to do so
 Purpose of File:
   To declare the class ItemToPurchase with its public member functions and private data members
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
*/

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
   public:
      ItemToPurchase();
      ItemToPurchase(string nameOfItem, string descriptionOfItem, int priceOfItem, int quantityOfItem);
      void SetName(string nameOfItem);
      string GetName() const;
      void SetPrice(int priceOfItem);
      int GetPrice() const;
      void SetQuantity(int quantityOfItem);
      int GetQuantity() const;
      void SetDescription(string descriptionOfItem);
      string GetDescription() const;
      void PrintItemCost() const;
      void PrintItemDescription() const;
   private:
      string itemName;
      int itemPrice;
      int itemQuantity;
      string itemDescription;
};

#endif
