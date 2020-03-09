
#include "SportsCard.h"
/**
 //-------------------------- Default constructor  for class SportsCard  ------------------------------------//
 Create and new ComicBook Object by calling Item constructor
 */
SportsCard::SportsCard():Item(){
   manufacturer = " ";
}

/**
 //-------------------------- Parametric constructor  for class SportsCard  ------------------------------------//
 Create and new Item Object with deafault value where name = "n, year = y; grade = g, inventory = i
 */
SportsCard::SportsCard(int i, std::string n, int y, std::string g,std::string m ):Item(i, n, y, g){
   manufacturer = m;
}

/**
 //-------------------------- Destructor  for class SportsCard  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
SportsCard:: ~SportsCard(){
   
}
/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */


bool SportsCard::operator==(const Comparable& right) const{
   const SportsCard &c = static_cast<const SportsCard &>(right);
   return (name == c.name && grade ==c.grade && year ==c.year && manufacturer == c.manufacturer);
}
  
/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool SportsCard::operator!=(const Comparable& right)const{
   const SportsCard &c = static_cast<const SportsCard &>(right);
   return !(name == c.name && grade ==c.grade && year ==c.year && manufacturer == c.manufacturer);
}

  
/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool SportsCard::operator<(const Comparable& right)const{
   const SportsCard &c = static_cast<const SportsCard &>(right);
   if(name < c.name) return true;
   else if(name == c.name){
      if (year < c.year) return true;
      else if(year == c.year){
         if(manufacturer < c.manufacturer) return true;
         else if(manufacturer == c.manufacturer){
            if(grade < c.grade) return true;
            else if(grade == c.grade) return false;
         }
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
bool SportsCard::operator>(const Comparable& right)const{
   const SportsCard &c = static_cast<const SportsCard &>(right);
   if(name > c.name) return true;
   else if(name == c.name){
      if (year > c.year) return true;
      else if(year == c.year){
         if(manufacturer > c.manufacturer) return true;
         else if(manufacturer == c.manufacturer){
            if(grade > c.grade) return true;
            else if(grade == c.grade) return false;
         }
      }
   }
   return false;
}

///**
// //-------------------------- Parametric constructor  for class SportsCard  ------------------------------------//
// Create and new Item Object with the description provided
// */
//SportsCard* SportsCard::create(std::string description){
//      //split description into data members and set them in new coin
//   SportsCard *c = new SportsCard;
//   return c;
//}
