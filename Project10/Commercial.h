/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: Compute taxes on a property based on if it is a residential or commercial property
 Purpose of File:
   To declare the child class of Property named Commercial with its public member functions and private data members
 Inputs:
   Inputs come from a data file that contains lines with:
      Property type = Residential or Commercial
      Rental Status = yes or no
      Property Value
      For a Residential Type
         Contains occupied status = yes or no
      For a Commercial Type
         Contains tax discount status = yes or no
         Contains discount rate
      Property Address
 Outputs:
   Asks where data should be read from
      If unable to read file prints that it could not be opened
   Prints all properties information based on if it is residential or commercial
   Prints tax report for all properties
   Asks where tax report should be written to
      If unable to write to file prints that it could not be opened
   Prints a sorted tax report on taxes due from low to high
*/

#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Property.h"

class Commercial : public Property {
   public:
      Commercial();
      Commercial(string rentalStatus, double valueOfProperty, string propertyAddress, 
			double taxDiscountPercentageRate, string discountStatus);
      virtual string ToString() const;
      virtual string TaxesDueString();
      virtual double TaxesDue();
   private:
      double taxDiscountPercentageRate;
      string discountStatus;
      double taxRateRental;
      double taxRateNonRental;
};
#endif