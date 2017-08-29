/*
 Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
 Purpose: Compute taxes on a property based on if it is a residential or commercial property
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
 Test Cases:
   Case 1:
      Input: The following test case is to ensure that a file that is not able to be opened
         prints out the error message
         openmytestfile
      Output:
         Prints that the openmytestfile can't be opened
   Case 2:
      Input: The following test case is to make sure that properties written in Test.txt
         incorrectly are not added to the vector of pointers
         These were the only changed properties in Test.txt:
            No 345678 Residential yes Banana-Onion-Road
            Commercial yes 77299351 no zero 12-Spirit-Way
      Output:
         Everything is printed correctly except for the two inputs changed since they
            were not added to the vector of pointers from having the incorrect data types
            typed into them
   Case 3:
      Input: The following test case is to make sure that more than just the 8 given properties
         can be added to the vector of pointers and that the tax report is writen to the correct
         file
         These were the added properties:
            Residential no 9876543 yes 1-Million-Drive
            Commercial no 9102345678 yes 35.2 1-Infinite-Loop
            Residential yes 200000 no 808-Bob-Street
            Commercial yes 45678943 yes 25.1 76-Galaxy-Lane
            Commercial no 12345 no 0 1230-Warehouse-Road
            Commercial yes 12355665 no 0 11-Hobbit-Circle
         myOutputFile
      Expected Output:
         1-Million-Drive Taxes Due - 59259.26
         1-Infinite-Loop Taxes Due - 58983199.99
         808-Bob-Street Taxes Due - 1800.00
         76-Galaxy-Lane Taxes Due - 410562.34
         1230-Warehouse-Road Taxes Due - 123.45
         11-Hobbit-Circle Taxes Due - 148267.98
      Ouput:
         Prints out all of the properties including the new ones added
         All of the expected output was correct
         Makes a file called myOutputFile and has the correct Tax Report in it
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

#include "Commercial.h"
#include "Residential.h"
#include "Property.h"

void ReadFromFile(ifstream& inputFile, vector<Property*>& myProperties) {
	istringstream propertyInput;
	string inputLine;
	string propertyType;
	string availableToRent;
	double valueOfProperty = 0.0;
	string propertyAddress;
	double taxDiscountRate = 0.0;
	string taxDiscount;
	string occupationalStatus;

	while (getline(inputFile, inputLine)) {
		propertyInput.clear();
		propertyInput.str(inputLine);

		propertyInput >> propertyType;
		if (propertyType == "Residential") {
			if (propertyInput >> availableToRent >> valueOfProperty >> occupationalStatus >> propertyAddress) {
				Property* residentialProperty = new Residential(availableToRent, valueOfProperty, 
					propertyAddress, occupationalStatus);
				myProperties.push_back(residentialProperty);
			}
		}
		else {
			if (propertyInput >> availableToRent >> valueOfProperty >> taxDiscount >> taxDiscountRate >> propertyAddress) {
				Property* commercialProperty = new Commercial(availableToRent, valueOfProperty, 
					propertyAddress, taxDiscountRate, taxDiscount);
				myProperties.push_back(commercialProperty);
			}
		}
	}

}

void PrintProperties(const vector<Property*>& myProperties) {
	cout << "All properties:" << endl;
	for (int i = 0; i < myProperties.size(); ++i) {
		cout << myProperties.at(i)->ToString() << endl;
	}
}

string GenerateTaxReport(const vector<Property*> myProperties) {
	ostringstream toString;

	toString << "TAX REPORT:" << endl;
	for (int i = 0; i < myProperties.size(); ++i) {
		toString << myProperties.at(i)->TaxesDueString() << endl;
	}
	return toString.str();
}

string SortedTaxVersion(vector<Property*> myProperties) {
	Property* tempPtr = 0;
	string sortedString;
	
	for (int i = 0; i < myProperties.size() - 1; ++i) {
		for (int j = 0; j < myProperties.size() - 1; ++j) {
			if (myProperties.at(j)->TaxesDue() > myProperties.at(j + 1)->TaxesDue()) {
				tempPtr = myProperties.at(j);
				myProperties.at(j) = myProperties.at(j + 1);
				myProperties.at(j + 1) = tempPtr;
			}
		}
	}

	sortedString = GenerateTaxReport(myProperties);

	return sortedString;
}

void CleanUpPointers(vector<Property*>& myProperties) {
	const int STARTING_INDEX = 0;

	while (myProperties.size() != 0) {
		delete myProperties.at(STARTING_INDEX);
		myProperties.erase(myProperties.begin());
	}
}

int main() {
	ifstream inputFile;
	ofstream outputFile;
	string taxReport;
	string fileLocation;
	vector<Property*> myProperties;

	cout << "starting..." << endl;
	cout << "Where should I read the data from: ";
	getline(cin, fileLocation);
	cout << endl;
	inputFile.open(fileLocation.c_str());
	if (!inputFile.is_open()) {
		cout << "Could not open file " << fileLocation << "." << endl;
	}
	else {
		ReadFromFile(inputFile, myProperties);
		inputFile.close();

		PrintProperties(myProperties);

		taxReport = GenerateTaxReport(myProperties);
		cout << taxReport;

		cout << "Where should I write the report (just press return to skip):" << endl;
		getline(cin, fileLocation);
		outputFile.open(fileLocation.c_str());
		if (!outputFile.is_open() && fileLocation != "") {
			cout << "Could not open file " << fileLocation << "." << endl;
		}
		else {
			outputFile << taxReport;
			outputFile.close();
		}

		taxReport = SortedTaxVersion(myProperties);
		cout << "SORTED VERSION:" << endl;
		cout << taxReport;

		CleanUpPointers(myProperties);
	}
	cout << endl;

	return 0;
}