/*
 * Fridge.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: thele
 */

#include "Fridge.h"
#include <iostream>

using namespace std;

void Fridge::add(Item item)
{
	unordered_map<string, Item> itemMap;   // current set we are looking at

	string strDayExp = to_string(item.getDateExpired());
	auto foundSet = myFridge.find(strDayExp);
	string itemName = item.getName();

	// add the element to the set if found
	if (foundSet != myFridge.end())
	{
		int dayExp = calcExp(itemName);
		itemMap = foundSet->second;
		itemMap.insert(make_pair(itemName, item));
	}
	else // otherwise create a set and insert the item
	{
		itemMap.insert(make_pair(itemName, item));
		myFridge.insert(make_pair(strDayExp, itemMap));
	}
}

void Fridge::remove(Item item)
{
	string dateExp = to_string(item.getDateExpired());
	auto foundSet = myFridge.find(dateExp);
	auto itemMap = foundSet->second;
	itemMap.erase(item.getName());
}

void Fridge::printContents()
{
	// every set
	for(auto it = myFridge.begin(); it != myFridge.end(); ++it)
	{
		auto itemMap = it->second;
		// every item in each set
		for (auto it2 = itemMap.begin(); it2 != itemMap.end(); ++it2)
		{
			Item item = it2->second;
			cout << "Item: " << item.getName() << "; Date Bought: ";
			cout << item.getDateBought() << "; Date Expires: ";
			cout << item.getDateExpired() << endl;
		}
	}
}

void Fridge::printContents(int amount)
{
	int counter = 0;
	// every set
	for(auto it = myFridge.begin(); it != myFridge.end(); ++it)
	{
		auto itemMap = it->second;
		// every item in each set
		for (auto it2 = itemMap.begin(); it2 != itemMap.end(); ++it2)
		{
			if (counter >= amount) return; // stop when amount is reached
			Item item = it2->second;
			cout << "Item: " << item.getName() << "; Date Bought: ";
			cout << item.getDateBought() << "; Date Expires: ";
			cout << item.getDateExpired() << endl;
			counter++;
		}
	}
}
//TODO:, print by date of purchase(this gonna be slow)
void Fridge::printRecent(int amount)
{

}

//TODO:
int Fridge::calcExp(string item_name)
{
	int dateExp = 0;
	// get today's date and add # of days stored in database field
	// search through database
	// set field of item to date found
	return dateExp;
}
