
#include "Coin.h"

Coin::Coin():Item(){
   
}

/**
 //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
 Create and new Item Object with deafault value where name = "n, year = y; grade = g
 */
Coin::Coin(std::string n, int y, std::string g, int i):Item(n, y, g, i){
   
}

/**
 //-------------------------- Destructor  for class Coin  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Coin:: ~Coin(){
   
}
/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */
bool Coin::operator==(const Comparable& right) const{
   const Coin &c = static_cast<const Coin &>(right);
   return (name ==c.name && grade ==c.grade && year ==c.year);
}

/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool Coin::operator!=(const Comparable& right)const{
   const Coin &c = static_cast<const Coin &>(right);
   return !(name ==c.name && grade ==c.grade && year ==c.year);
}


/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool Coin::operator<(const Comparable& right)const{
   if(Item::operator<(right)){
   }
   return false;
}

/**
 //-------------------------- Overloaded greater than operator >  ------------------------------------//
 Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
 @return boolean true is left is larger than right
 */
bool Coin::operator>(const Comparable& right)const{
   if(Item::operator<(right)){
   }
   return false;
}
