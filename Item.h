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
	const string dateBought;
	const string dateExpired;
	bool operator<(const Item& item) const;
public:
	// Constructors
	Item(string name, string dateBought) :
		name(name), dateBought(dateBought), dateExpired(0) {}
	Item(string name, string dateBought, string dateExpired) :
		name(name), dateBought(dateBought), dateExpired(dateExpired) {}
	// Accessors
	const string& getName() const { return name; };
	const string& getDateBought() const { return dateBought; };
	const string& getDateExpired() const { return dateExpired; };
};

#endif /* ITEM_H_ */
