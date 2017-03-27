/*
 * Fridge.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: thele
 */

#include "Fridge.h"
#include <iostream>

using namespace std;

void Fridge::add(string item, int dayBought)
{

	Item theItem;
	unordered_set<Item> itemSet;

	//TODO:
	// first obtain expiration date of item
	// then find set with expiration date
	string dayExpStr;
	auto foundSet = myFridge.find(dayExpStr);

	// add the element to the set if found
	if (foundSet != myFridge.end())
	{
		int dayExp = calcExp(item);
		theItem = new Item(item, dayBought, dayExp);
		itemSet = foundSet->second;
		itemSet.insert(theItem);
	}  // otherwise create a set and insert the item
	else
	{
		theItem = new Item(item, dayBought);
		itemSet.insert(theItem);
		myFridge.insert(make_pair(dayExpStr, itemSet));
	}
}

void Fridge::add(string item, int dayBought, int dayExp)
{
	Item theItem;
	unordered_set<Item> itemSet;

	string dayExpStr = to_string(dayExp);
	auto foundSet = myFridge.find(dayExpStr);

	// add the element to the set if found
	if (foundSet != myFridge.end())
	{
		int dayExp = calcExp(item);
		theItem = new Item(item, dayBought, dayExp);
		itemSet = foundSet->second;
		itemSet.insert(theItem);
	}  // otherwise create a set and insert the item
	else
	{
		theItem = new Item(item, dayBought);
		itemSet.insert(theItem);
		myFridge.insert(make_pair(dayExpStr, itemSet));
	}
}

void Fridge::remove(Item item)
{
	string dateExp = to_string(item.dateExpired);
	auto foundSet = myFridge.find(dateExp);
	unordered_set<Item> itemSet = foundSet->second;
	itemSet.erase(item);
}

void Fridge::printContents()
{
	// every set
	for(auto it = myFridge.begin(); it != myFridge.end(); ++it)
	{
		auto itemSet = it->second;
		// every item in each set
		for (auto it2 = itemSet.begin(); it2 != itemSet.end(); ++it2)
		{
			Item item = *it2;
			cout << "Item: " << item.name << ", Date Bought: ";
			cout << item.dateBought << ", Date Expires: ";
			cout << item.dateExpired << endl;
		}
	}
}

void Fridge::printContents(int amount)
{
	int counter = 0;
	// every set
	for(auto it = myFridge.begin(); it != myFridge.end(); ++it)
	{
		auto itemSet = it->second;
		// every item in each set
		for (auto it2 = itemSet.begin(); it2 != itemSet.end(); ++it2)
		{
			if (counter >= amount) return; // stop when amount is reached
			Item item = *it2;
			cout << "Item: " << item.name << ", Date Bought: ";
			cout << item.dateBought << ", Date Expires: ";
			cout << item.dateExpired << endl;
			counter++;
		}
	}
}
//TODO:, print by date of purchase
void Fridge::printRecent(int amount)
{

}
//TODO:
int Fridge::calcExp(string item)
{
	// get today's date and add # of days stored in database field
	// search through database
	// set field of item to date found
	return 0;
}



