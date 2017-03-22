/*
 * Fridge.h
 *
 *  Created on: Mar 21, 2017
 *      Author: thele
 */

/*
 *  Date format for storage: year/month/day
 *  Organize by value of date
 *  How to access info?
 *
 *  Handle GUI at the end
 */

#ifndef FRIDGE_H_
#define FRIDGE_H_

#include <unordered_map>
#include <set>
#include "Item.h"

class Fridge
{
	unordered_map<string, set<Item>> myFridge;
};

#endif /* FRIDGE_H_ */
