
#include "SportsCard.h"
/**
 //-------------------------- Default constructor  for class SportsCard  ------------------------------------//
 Create and new ComicBook Object by calling Item constructor
 */
SportsCard::SportsCard():Item(){
   manufacturer = " ";
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

/**
 //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
 Create and new Item Object with the description provided
 */
Item* SportsCard::create() const {
   return new SportsCard();
   
}

/**
 -------------------------- Method to set data  ------------------------------------//
 sets the data members of an  Item Object with the parameters provided
 */
void SportsCard::setData(std::string stringCount, std::string description){
   inventory = atoi(stringCount.c_str());
   std::string tokens[4];
   int i = 0;
   std::stringstream  data(description);
   std::string line;
   while(std::getline(data,line,','))
   {
      tokens[i] = line;
      i++;
      data.get();
   }
   year = tokens[0];
   grade = tokens[1];
   name = tokens[2];
   manufacturer = tokens[3];
   
}

/**
 *  Initialize an instance of this class from an input stream.
 *  Expected format is: {quantity},{year},{grade},{player},{manufacturer}
 *  e.g. "9, 1989, Near Mint, Ken Griffey Jr., Upper Deck"
 *  @param in An input stream to read `Card` data from.
 *  @param card A reference to a `Card` to initialize.
 *  @return The input stream that was passed in.
 */
std::istream& operator>>(std::istream& in, SportsCard& card){
   return in;
}
/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to
 *   output stream.
 *  @param out An output stream to append to.
 *  @param card A card instance to append to the output stream.
 *  @return The output stream that was passed in
 */
std::ostream& operator<<(std::ostream& out, const SportsCard& card){
   return out;
}
std::string SportsCard::toString() const {
   
   return  Item::toString() + ", " + manufacturer;
}
