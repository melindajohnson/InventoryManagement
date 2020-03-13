/*
 ItemFactory.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 ItemFactory class: is a Factory class that has a
 Hashatable itemHash
 a make_Item method to make a dummy item object based on the code from the inventory file
 a buildItemsByFactory method to make a dummy item object
 ---------------------------------------------------------------------------
 */

#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include "Item.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"
#include "Hashtable.h"
const static int numberOfItems = 26;

class ItemFactory
{
private:
   // A hashtable of item codes as key and Dummy item objects as values
   Hashtable *itemsHash = new Hashtable(numberOfItems);

public:
   /**
    //-------------------------- Default constructor for class ItemFactory  ------------------------------------//
    Create a new ItemFactory Object
    */
   ItemFactory();
   /**
    //-------------------------- Destructor for class ItemFactory  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~ItemFactory();
   /**
    //-------------------------- make_Item method for class ItemFactory  ------------------------------------//
    Make a dummy item object based on the code from the inevtory file
    */
   Item* make_Item(std::string code) const;
};
