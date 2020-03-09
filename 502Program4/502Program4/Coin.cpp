
#include "Coin.h"

Coin::Coin():Item(){
   
}

/**
 //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
 Create and new Item Object with deafault value where name = "n, year = y; grade = g
 */
Coin::Coin(std::string n, int y, std::string g, int i):Item(i, n, y, g){
   
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
   return (name == c.name && grade ==c.grade && year ==c.year);
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
//   if(Item::operator<(right)){
//   }
   const Coin &c = static_cast<const Coin &>(right);
   if(name < c.name) return true;
   else if(name == c.name){
      if (grade < c.grade) return true;
      else if(grade == c.grade){
         if(year < c.year) return true;
         else if(year == c.year) return false;
      }
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
   const Coin &c = static_cast<const Coin &>(right);
   if(name > c.name) return true;
   else if(name == c.name){
      if (grade > c.grade) return true;
      else if(grade == c.grade){
         if(year > c.year) return true;
         else if(year == c.year) return false;
      }
   }
   return false;
}

/**
 //--------------------------Overloaded input operator <<  ------------------------------------//
 Preconditions: A Node is created in the SearchTree
 Postconditions: Read in a char from an istream.
 */
std::istream& operator>>(std::istream& in, Item& obj1) {
   
   in.get(obj1.data);
   return in;
}
///**
// //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
// Create and new Item Object with the description provided
// */
//Coin* Coin::create(std::string description){
//   //split description into data members and set them in new coin
//   Coin *c = new Coin;
//   return c;
//}
