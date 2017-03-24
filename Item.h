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
	int dateBought;
	int dateExpired;
	string name;
	Item(string name) : dateBought(0), dateExpired(0), name(name) {}
};

#endif /* ITEM_H_ */
