/*
 * test.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: thele
 */

#include "Fridge.h"

int main(int argc, char** argv)
{
	Fridge* fridge = new Fridge();

	Item* item1 = new Item("Carrot", 2017273, 2017303);
	fridge->add(*item1);

	//fridge->printContents();

	return 0;
}
