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
	unordered_map<string, Item*> itemMap;   // current set we are looking at

	string strDayExp = item.getDateExpired();
	auto foundSet = myFridge.find(strDayExp);
	string itemName = item.getName();

	// add the element to the set if found
	if (foundSet != myFridge.end())
	{
		int dayExp = calcExp(itemName);
		itemMap = foundSet->second;
		itemMap.insert(make_pair(itemName, &item));
	}
	else // otherwise create a set and insert the item
	{
		itemMap.insert(make_pair(itemName, &item));
		myFridge.insert(make_pair(strDayExp, itemMap));
	}
	purchasedSet.insert(&item);
}

void Fridge::remove(Item item)
{
	string dateExp = item.getDateExpired();
	auto foundSet = myFridge.find(dateExp);
	auto itemMap = foundSet->second;
	itemMap.erase(item.getName());
}

void Fridge::printDate(string date)
{
	string day;
	string month;
	string year;

	day = date.substr(6, 2);
	month = date.substr(4, 2);
	year = date.substr(0, 4);

	cout << month << "/" << day << "/" << year;
}

void Fridge::printContents(int amount)
{
	int counter = 0;
	// iterates through sets
	for(auto it = myFridge.begin(); it != myFridge.end(); ++it)
	{
		auto itemMap = it->second;
		// iterates through items in each set
		for (auto it2 = itemMap.begin(); it2 != itemMap.end(); ++it2)
		{
			if (counter >= amount) return; // stop when amount is reached
			counter++;

			Item* item = it2->second;
			cout << "Item: " << item->getName() << "; Date Bought: ";
			printDate(item->getDateBought());
			cout << "; Date Expires: ";
			printDate(item->getDateExpired());
			cout << endl;
		}
	}
}

void Fridge::printRecent(int amount)
{
	int counter = 0;
	// iterates through items
	for(auto it = purchasedSet.begin(); it != purchasedSet.end(); ++it)
	{
		Item* item= *it;

		if (counter >= amount) return; // stop when amount is reached
		counter++;

		cout << "Item: " << item->getName() << "; Date Bought: ";
		printDate(item->getDateBought());
		cout << "; Date Expires: ";
		printDate(item->getDateExpired());
		cout << endl;
	}
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
