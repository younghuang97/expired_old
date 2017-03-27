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
	string name;
	int dateBought;
	int dateExpired;
	Item(string name, int dateBought) :
		name(name), dateBought(dateBought), dateExpired(0) {}
	Item(string name, int dateBought, int dateExpired) :
		name(name), dateBought(dateBought), dateExpired(dateExpired) {}

	/*
	 * Overloaded so a set of items can be obtained by name
	 */
	//bool operator<(const Item& item);
};

#endif /* ITEM_H_ */
