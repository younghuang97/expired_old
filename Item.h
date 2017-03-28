/*
 * Item.h
 *
 *  Created on: Mar 21, 2017
 *      Author: thele
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class Item
{
private:
	const string name;
	const int dateBought;
	const int dateExpired;
	bool operator<(const Item& item) const;
public:
	// Constructors
	Item(string name, int dateBought) :
		name(name), dateBought(dateBought), dateExpired(0) {}
	Item(string name, int dateBought, int dateExpired) :
		name(name), dateBought(dateBought), dateExpired(dateExpired) {}
	// Accessors
	const string& getName() const { return name; };
	const int& getDateBought() const { return dateBought; };
	const int& getDateExpired() const { return dateExpired; };
};

#endif /* ITEM_H_ */
