/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: Compute taxes on a property based on if it is a residential or commercial property
 Purpose of File:
   To define the public member functions found in the Residential header file, and call
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

#include "Residential.h"

Residential::Residential() : Property() {
	this->occupationStatus = "none";
	this->taxRateNonOccupiedRental = 0.0;
	this->taxRateOccupiedRental = 0.0;
}

Residential::Residential(string rentalStatus, double valueOfProperty, string propertyAddress, 
		string occupationStatus) : Property(rentalStatus, valueOfProperty, propertyAddress) {
   
	const double NONOCCUPIED_RATE = 0.009;
   const double OCCUPIED_RATE = 0.006;
   
   if (occupationStatus == "yes") {
		this->occupationStatus = "Occupied";
	}
	else {
		this->occupationStatus = "NOT occupied";
	}
	this->taxRateNonOccupiedRental = NONOCCUPIED_RATE;
	this->taxRateOccupiedRental = OCCUPIED_RATE;
}

string Residential::ToString() const {
	ostringstream toString;
   
	toString << Property::ToString();
	toString << "A Residential Property. " << this->occupationStatus << ".";
	
   return toString.str();
}

double Residential::TaxesDue() {
	double taxesDueForProperty = 0.0;
   
	if (this->occupationStatus == "Occupied") {
		taxesDueForProperty = GetValueOfProperty() * this->taxRateOccupiedRental;
	}
	else {
		taxesDueForProperty = GetValueOfProperty() * this->taxRateNonOccupiedRental;
	}
	return taxesDueForProperty;
}

string Residential::TaxesDueString() {
	const int SET_PRECISION = 2;
   const int SET_WIDTH = 15;
	ostringstream toString;
   
	toString << Property::TaxesDueString();
	toString << "  Taxes due on this property are:" << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << TaxesDue();
	
   return toString.str();
}