// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>

using namespace std;
using namespace io;

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
	CSVReader<7> rCSV(fileIn);
	rCSV.read_header(ignore_no_column, "id", "number", "street", "city", "state", "postalCode", "price");
	int id =0 , number=0, PostalCode=0;
	double price=0.0;
	int count = 0;
	string street, state, city;
	while (rCSV.read_row(id, number, street, city, state, PostalCode, price))
	{	
       hp.push_back(HousePrice(id,number,street,city,state,PostalCode,price));
	}
	for (auto i = hp.begin(); i != hp.end(); i++)
	{
		cout << *i;		
	}	
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    // Sort by Price
     sort(hp.begin(), hp.end(), [](const HousePrice& lhs, const HousePrice& rhs){ return lhs.getPrice() < rhs.getPrice(); });
	 cout <<"most expensive house " <<  hp.back();
	 cout << "cheapest house " << hp.front();

}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{

    // Sort by State
     
	int l = 1,j =0;
	int count = 1;
	map<string, int> amount;
     sort(hp.begin(), hp.end(), [](const HousePrice& lhs, const HousePrice& rhs){ return lhs.getState() < rhs.getState(); });
	 cout << endl;
	 for (auto i = hp.begin(); i != hp.end(); i++)
	 {
		 if (i != hp.end() - 1)
		 {
			 if (hp.at(l).getState() == hp.at(l - 1).getState())
			 {
				 count++;
			 }
			 else if (hp.at(l).getState() != hp.at(l - 1).getState())
			 {

				 cout << hp.at(l-1).getState() << ": " << count << " ";
				 j++;
				 if (j == 10)
				 {
					 cout << endl;
					 j = 0;
				 }
				 //amount[hp.at(l).getState()] = count;
				 count = 1;
				 //cout << hp.at(l).getState() << endl;
			 }
		 }
		 else {
			 cout << hp.at(l - 1).getState() << ": " << count << " ";
		 }
		 l++;
	 }
	 count = 0;
	
}
