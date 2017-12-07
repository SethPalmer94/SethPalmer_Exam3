// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"
#include <iostream>


HousePrice::HousePrice(int ID, int Number, const string & Street, const string & City, const string & State, int PostalCode, double Price) : id(ID),number(Number),
street(Street),city(City),state(State),postalCode(PostalCode),price(Price)
{
}
HousePrice::HousePrice()
{

}

HousePrice::~HousePrice()
{
}




double HousePrice::getPrice() const
{
	return price;

}

const string & HousePrice::getState() const
{
	return state ;
	// TODO: insert return statement here
}

 ostream & operator<<(ostream & os, const HousePrice & price)
{
	 os << "id: " << price.id << " number: " << price.number << " postalCode: " << price.postalCode << " street: " << price.street << " city: " << price.city <<
		 " state: " << price.state << " Price: " << price.price << endl;
	return os;
}

