
/*
 Item.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 Item class:
 The item class inherits from the Class Comparable and implements its pure virtual methods
 The item class also inherits from the Class HashValueType
 Data members include;
 inventory, name, year and grade whose access specifiers are protected so that derived class could inherit them
 The Item Class allows for comparison of 2 item objects based on the name
 It also has
 a create method to create dummy command objects
 a setData method to set the protected fields
 a toString method
 */
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
 *  Output a textual representation of this instance as a string without the inventory
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string without the inventory
 */
std::string Item::toStringWithoutCount()const{
   return year + ", " + grade + ", " + name;
}

/**
 //-------------------------- Method to increase inventory  ------------------------------------//
 Increments the inventory of an  Item Object by 1
 */
void Item::increaseInventory(){
   inventoryCount++;
}

/**
 //-------------------------- Method to decrease inventory  ------------------------------------//
 Decrements the inventory of an  Item Object by 1
 @returns a bool true if inventorycount was decreased or false if not
 */
bool Item::decreaseInventory(){
   if(inventoryCount > 0){
      inventoryCount--;
      return true;
   }
   return false;
}

/**
 //-------------------------- Method to set data  ------------------------------------//
 Sets the data members of an  Item Object with the parameters provided
 */
void Item::setData(std::string stringCount, std::string description){
   
}

/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a output stream
 */
std::ostream& operator<<(std::ostream& out, const Item& obj1) {
   out << obj1.toString();
   return out;
   }
/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */
bool Item::operator==(const Comparable& right) const {
    const Item &c = static_cast<const Item &>(right);
   return(type == c.type);
}
/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool Item::operator!=(const Comparable& right)const {
   const Item &c = static_cast<const Item &>(right);
   return !(type == c.type);
}

/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool Item::operator<(const Comparable& right)const {
   const Item &c = static_cast<const Item &>(right);
   return(type < c.type);
}

/**
 //-------------------------- Overloaded greater than operator >  ------------------------------------//
 Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
 @return boolean true is left is larger than right
 */
bool Item::operator>(const Comparable& right)const {
   const Item &c = static_cast<const Item &>(right);
   return(type > c.type);
}

void Item::setType(std::string t){
   type = t;
}
