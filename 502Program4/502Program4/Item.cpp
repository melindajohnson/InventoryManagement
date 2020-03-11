
#include "Item.h"
/**
 //-------------------------- Default constructor  for class Item  ------------------------------------//
 Create and new Item Object with deafault value where name = " ", year = 0; grade = 0
 */
Item::Item(){
   inventoryCount = 0;
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
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string Item::toString()const{
   std::string in= std::to_string(inventoryCount);
   return in + ", " + year + ", " + grade + ", " + name;
   
}

/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string Item::toStringWithoutCount()const{
   return year + ", " + grade + ", " + name;
}

/**
 //-------------------------- Method to increase inventory  ------------------------------------//
 increments the inventory of an  Item Object by 1
 */
void Item::increaseInventory(){
   inventoryCount++;
}

/**
 //-------------------------- Method to decrease inventory  ------------------------------------//
 decrements the inventory of an  Item Object by 1
 */
void Item::decreaseInventory(){
   inventoryCount--;
}

/**
 //-------------------------- Method to set data  ------------------------------------//
 sets the data members of an  Item Object with the parameters provided
 */
void Item::setData(std::string stringCount, std::string description){
   
}


/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Preconditions: A comparable object is created and its data is set
 Postconditions: Outputs the Comparable objects
 */
std::ostream& operator<<(std::ostream& out, const Item& obj1) {
   out << obj1.toString();
   return out;
}
