/*
 * Fridge.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: thele
 */

#include "Fridge.h"

void Fridge::add(string item)
{
	auto itemSet = myFridge.find(item);

	// add the element to the set if found
	if (itemSet != myFridge.end())
	{
		Item theItem = new Item(item);
		itemSet->second.insert(theItem);
	}  // otherwise create a set and insert the item
	else
	{
		set<Item> bundle;
		Item theItem = new Item(item);
		bundle.insert(theItem);
		myFridge.insert(make_pair(item, bundle));
	}
}

void calcExp(string item)
{
	// search through database
	// set field of item to date found
}



