
#include "Item.h"
/**
 //-------------------------- Default constructor  for class Item  ------------------------------------//
 Create and new Item Object with deafault value where name = " ", year = 0; grade = 0
 */
Item::Item(){
   inventory = 0;
   name = " ";
   year = " ";
   grade= " ";
}


/**
 //-------------------------- Destructor  for class Item  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Item:: ~Item(){
   
}

/**
 //-------------------------- Method to set data  ------------------------------------//
 sets the data members of an  Item Object with the parameters provided
 */
void Item::setData(std::string stringCount, std::string description){
   //
}
