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

#include <map>
#include <unordered_set>
#include "Item.h"

class Fridge
{
	map<string, unordered_set<Item>> myFridge;  // 1st param is date exp; 2nd param is set of items

	/*
	 * Adds an item to it's respective array of items, and if the array
	 * doesn't exist, create one and add to the map. Goes through database
	 * to find the date the item expires.
	 */
	void add(string item, int dayBought);

	/*
	 * Adds an item to it's respective array of items, and if the array
	 * doesn't exist, create one and add to the map. Uses user-provided
	 * date for date expired.
	 */
	void add(string item, int dayBought, int dayExp);

	/*
	 * Deletes an item from the fridge
	 */
	void remove(Item item);

	/*
	 * Prints entire fridge and the kitchen sink in order of expiration date
	 */
	void printContents();

	/*
	 * Prints 'amount' number items based on nearest expiration date
	 */
	void printContents(int amount);

	/*
	 * Prints 'amount' number of items based on when the item was purchased
	 */
	void printRecent(int amount);

	/*
	 * Returns the # of expected days until the food expires
	 */
	int calcExp(string item);
};



#endif /* FRIDGE_H_ */
