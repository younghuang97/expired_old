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
#include <set>
#include "Item.h"

using namespace std;

/*
 * Deterministically sorts Items by date bought, and if the dates are
 * the same, then it is ordered alphabetically
 */
struct classcomp
{
	bool operator() (Item* const& lhs, Item* const& rhs) const
	{
		int value = lhs->getDateBought().compare(rhs->getDateBought());
		if (value < 0) return true;
		else if (value == 0)
		{
			int nameCmp = lhs->getName().compare(rhs->getName());
			if (nameCmp < 0) return true;
			else return false;
		}
		else return false;
	}
};

class Fridge
{
private:
	map<string, unordered_map<string, Item*>> myFridge;  //ordered by dateExpired
	multiset<Item*, classcomp> purchasedSet;  //ordered by dateBought
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
	 * Prints 'amount' number items in order of expiration date
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
