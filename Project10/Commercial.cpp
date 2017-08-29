/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: Compute taxes on a property based on if it is a residential or commercial property
 Purpose of File:
   To define the public member functions found in the Commercial header file, and call
      the parent public member functions from Property when needed
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

#include "Commercial.h"

Commercial::Commercial() : Property() {
	this->taxDiscountPercentageRate = 0.0;
	this->discountStatus = "none";
	this->taxRateNonRental = 0.0;
	this->taxRateRental = 0.0;
}

Commercial::Commercial(string rentalStatus, double valueOfProperty, string propertyAddress, 
		double taxDiscountPercentageRate, string discountStatus) : Property(rentalStatus, valueOfProperty, propertyAddress) {
   
	const double NONRENTAL_RATE = 0.01;
   const double RENTAL_RATE = 0.012;
   
   if (discountStatus == "yes") {
		this->discountStatus = "In a discount zone with discount of:";
	}
	else {
		this->discountStatus = "NOT in a discount zone";
	}
	this->taxDiscountPercentageRate = taxDiscountPercentageRate;
	this->taxRateNonRental = NONRENTAL_RATE;
	this->taxRateRental = RENTAL_RATE;
}

string Commercial::ToString() const {
	const int SET_PRECISION = 2;
   const int SET_WIDTH = 15;
	ostringstream toString;
   
	toString << Property::ToString();
	toString << "A Commercial Property. " << this->discountStatus;
	if (this->discountStatus == "In a discount zone with discount of:") {
		toString << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << this->taxDiscountPercentageRate << "%.";
	}
	else {
		toString << ".";
	}
	return toString.str();
}

double Commercial::TaxesDue() {
	double taxesDueForProperty = 0.0;

	if (GetAvailableToRent() == "Rental") {
		taxesDueForProperty = (this->taxRateRental * GetValueOfProperty());
		if (this->discountStatus == "In a discount zone with discount of:") {
			taxesDueForProperty -= ((this->taxRateRental * GetValueOfProperty()) * (this->taxDiscountPercentageRate / 100.0));
		}
	}
	else {
		taxesDueForProperty = (this->taxRateNonRental * GetValueOfProperty());
		if (this->discountStatus == "In a discount zone with discount of:") {
			taxesDueForProperty -= ((this->taxRateNonRental * GetValueOfProperty()) * (this->taxDiscountPercentageRate / 100.0));
		}
	}
	return taxesDueForProperty;
}

string Commercial::TaxesDueString() {
	const int SET_PRECISION = 2;
   const int SET_WIDTH = 15;
	ostringstream toString;
   
	toString << Property::TaxesDueString();
	toString << "  Taxes due on this property are:" << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << TaxesDue();
   
	return toString.str();
}