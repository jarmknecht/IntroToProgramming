/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: To create an online shopping cart program and to learn how to use Classes to do so
 Purpose of File:
   To define the public member function found in the ItemToPurchase header file
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

#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemPrice = 0;
   itemQuantity = 0;
   itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string nameOfItem, string descriptionOfItem, int priceOfItem, int quantityOfItem) {
   itemName = nameOfItem;
   itemPrice = priceOfItem;
   itemQuantity = quantityOfItem;
   itemDescription = descriptionOfItem;
}

void ItemToPurchase::SetName(string nameOfItem) {
   itemName = nameOfItem;
}

void ItemToPurchase::SetPrice(int priceOfItem) {
   itemPrice = priceOfItem;
}

void ItemToPurchase::SetQuantity(int quantityOfItem) {
   itemQuantity = quantityOfItem;
}

string ItemToPurchase::GetName() const {
   return itemName;
}

int ItemToPurchase::GetPrice() const {
   return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
   return itemQuantity;
}

void ItemToPurchase::SetDescription(string descriptionOfItem) {
   itemDescription = descriptionOfItem;
   return;
}

string ItemToPurchase::GetDescription() const {
   return itemDescription;
}

void ItemToPurchase::PrintItemCost() const {
   
   int totalItemPrice = 0;
   totalItemPrice = GetQuantity() * GetPrice();
   
   cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() <<
   " = $" << totalItemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() const {
   cout << GetName() << ": " << GetDescription() << endl;
}
