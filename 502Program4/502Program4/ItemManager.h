
#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "ItemFactory.h"
#include "Hashtable.h"
#include "BinarySearchTree.h"
class ItemManager {
private:
   ItemFactory objFactory;
   
public:
   ItemManager();
   
   Item* buildItemsByFactory(std::string type);
   
   void displayItems() ;
   
   void destroyItems() ;
   
};
