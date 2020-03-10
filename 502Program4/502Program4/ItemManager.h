
#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "ItemFactory.h"
#include "BinarySearchTree.h"
class ItemManager {
private:
   ItemFactory objFactory;
   
public:
   ItemManager();
   
   void buildItemsByFactory(std::ifstream &inventoryFile);
   
   void displayItems() ;
   
   void destroyItems() ;
   
};
