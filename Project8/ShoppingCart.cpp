/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: To create an online shopping cart program and to learn how to use Classes to do so
 Purpose of File:
   To define the public member functions in the class ShoppingCart and to use those functions in calling
      public member functions in the class ItemToPurchase. Thus, having a class within a class.
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
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
   this -> customerName = customerName;
   this -> currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() const {
   return customerName;
}

string ShoppingCart::GetDate() const {
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase addItem) {
   cartItems.push_back(addItem);
}

void ShoppingCart::RemoveItem(string itemInCart) {
   
   ItemToPurchase cartItem;
   bool itemFound = false;
   
   for (int i = 0; i < cartItems.size(); ++i) {
      cartItem = cartItems.at(i);
      if (cartItem.GetName() == itemInCart) {
         cartItems.erase(cartItems.begin() + i);
         itemFound = true;
      }
   }
   if (!itemFound) {
      cout << "Item not found in cart. Nothing removed." << endl;
   }
   cout << endl;
}

void ShoppingCart::UpdateQuantity(string itemName, int newQuantity) {
   
   ItemToPurchase itemInCart;
   bool itemFound = false;
   
   for (int i = 0; i < cartItems.size(); ++i) {
      itemInCart = cartItems.at(i);
      if (itemInCart.GetName() == itemName) {
         itemInCart.SetQuantity(newQuantity);
         itemFound = true;
         cartItems.at(i) = itemInCart;
      }
   }
   if (!itemFound) {
      cout << "Item not found in cart. Nothing modified." << endl;
   }
}

int ShoppingCart::GetNumItemsInCart() const {
   
   int countItems = 0;
   ItemToPurchase itemInCart;
   
   for (int i = 0; i < cartItems.size(); ++i) {
      itemInCart = cartItems.at(i);
      countItems = countItems + itemInCart.GetQuantity();
   }
   return countItems;
}

int ShoppingCart::GetCostOfCart() const {
   
   int totalCost = 0;
   ItemToPurchase itemInCart;
   
   for (int i = 0; i < cartItems.size(); ++i) {
      itemInCart = cartItems.at(i);
      totalCost = totalCost + (itemInCart.GetPrice() * itemInCart.GetQuantity());
   }
   return totalCost;
}

void ShoppingCart::PrintTotal() const {
   
   ItemToPurchase itemInCart;
   
   cout << GetCustomerName() << "\'s Shopping Cart - " << GetDate() << endl;
   cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
   for (int i = 0; i < cartItems.size(); ++i) {
      itemInCart = cartItems.at(i);
      itemInCart.PrintItemCost();
   }
   if (cartItems.size() == 0) {
      cout << "SHOPPING CART IS EMPTY" << endl << endl;
   }
   cout << "Total: $" << GetCostOfCart() << endl << endl;
}

void ShoppingCart::PrintDescription() const {
   
   ItemToPurchase itemInCart;
   
   cout << GetCustomerName() << "\'s Shopping Cart - " << GetDate() << endl;
   cout << "Item Descriptions" << endl << endl;
   for (int i = 0; i < cartItems.size(); ++ i) {
      itemInCart = cartItems.at(i);
      itemInCart.PrintItemDescription();
      cout << endl;
   }
   cout << endl;
}
