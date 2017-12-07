// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#ifndef HW8_HOUSEPRICE_H
#define HW8_HOUSEPRICE_H

#include <iostream>
#include <string>
using namespace std;

/*!
 * Class HousePrice
 */
class HousePrice
{
private:
	int id, number;
	string street, city, state;
	int postalCode;
	double price;
public:
	HousePrice();
	~HousePrice();
	HousePrice(int ID, int Number, const string &Street, const string &City, const string &State, int PostalCode, double Price );
	double getPrice() const;
	const string& getState() const;

	friend ostream & operator<<(ostream&os, const HousePrice &price);
};


#endif //HW8_HOUSEPRICE_H
