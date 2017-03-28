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
#include <unordered_map>
#include "Item.h"

using namespace std;

class Fridge
{
private:
	map<string, unordered_map<string, Item>> myFridge;  // 1st param is date exp; 2nd param is set of items
public:
	/*
	 * Adds an item to a set that denotes the expired date of the item
	 * If no set exists for the date, then a new set is created.
	 */
	void add(Item item);

	/*
	 * Deletes an item from the Fridge
	 */
	void remove(Item item);

	/*
	 * Prints date in a prettier format
	 */
	void printDate(string date);

	/*
	 * Prints entire Fridge and the kitchen sink in order of expiration date
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
	int calcExp(string item_name);
};

#endif /* FRIDGE_H_ */
