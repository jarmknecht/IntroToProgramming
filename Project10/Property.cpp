/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: Compute taxes on a property based on if it is a residential or commercial property
 Purpose of File:
   To define the public member functions found in the Property header file
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

#include "Property.h"

Property::Property() {
	this->rentalStatus = "none";
	this->valueOfProperty = 0.0;
	this->propertyAddress = "none";
}

Property::Property(string rentalStatus, double valueOfProperty, string propertyAddress) {
	if (rentalStatus == "yes") {
		this->rentalStatus = "Rental";
	}
	else {
		this->rentalStatus = "NOT rental";
	}
	this->valueOfProperty = valueOfProperty;
	this->propertyAddress = propertyAddress;
}

double Property::GetValueOfProperty() const {
	return this->valueOfProperty;
}

string Property::GetAvailableToRent() const {
	return this->rentalStatus;
}

string Property::ToString() const {
	const int SET_PRECISION = 2;
   const int SET_WIDTH = 15;
	ostringstream toString;
   
	toString << "Address: " << this->propertyAddress << ". ";
	toString << this->rentalStatus << ". ";
	toString << "Estimated value:" << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << this->valueOfProperty << ". ";
	
   return toString.str();
}

string Property::TaxesDueString() {
	const int SET_PRECISION = 2;
   const int SET_WIDTH = 15;
	ostringstream toString;
   
	toString << "** Taxes due for the property at: " << this->propertyAddress << endl;
	toString << "  This property has an estimated value of:" << setw(SET_WIDTH) << fixed << 
		setprecision(SET_PRECISION) << this->valueOfProperty << endl;
	
   return toString.str();
}