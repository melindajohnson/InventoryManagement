/*
 Coin.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 Coin class:
 The coin class inherits from the Class Item and overloads its virtual methods
 There are no additional data members
 */

#include "Coin.h"
/**
 //-------------------------- Default constructor  for class Coin  ------------------------------------//
 Create and new Coin Object by calling Item constructor
 */
Coin::Coin():Item(){
   
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
   if(Item::operator==(right)){
   const Coin &c = static_cast<const Coin &>(right);
   return (name == c.name && grade ==c.grade && year ==c.year);
   } else {
      return false;
   }
}

/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool Coin::operator!=(const Comparable& right)const{
   if(Item::operator==(right)){
   const Coin &c = static_cast<const Coin &>(right);
   return !(name ==c.name && grade ==c.grade && year ==c.year);
   } else {
      return false;
   }
}


/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool Coin::operator<(const Comparable& right)const{
   bool result = false;
   if(Item::operator==(right)){
   const Coin &c = static_cast<const Coin &>(right);
   if(name < c.name) result = true;
   else if(name == c.name){
      if (grade < c.grade) result = true;
      else if(grade == c.grade){
         if(year < c.year) result = true;
      }
   }
   return result;
   }
   else {
      return Item::operator<(right);
   }
}


/**
 //-------------------------- Overloaded greater than operator >  ------------------------------------//
 Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
 @return boolean true is left is larger than right
 */
bool Coin::operator>(const Comparable& right)const{
   bool result = false;
   if(Item::operator==(right)){
      const Coin &c = static_cast<const Coin &>(right);
      if(name > c.name) result = true;
      else if(name == c.name){
         if (grade > c.grade) result = true;
         else if(grade == c.grade){
            if(year > c.year) result = true;
         }
      }
      return result;
   }
   else {
      return Item::operator>(right);
   }
}

/**
 -------------------------- Method to set data  ------------------------------------//
 sets the data members of an  Item Object with the parameters provided
 */
void Coin::setData(std::string stringCount, std::string description){
   inventoryCount = atoi(stringCount.c_str());
   std::string tokens[3];
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
   grade = tokens[1];;
   name = tokens[2];
   type = "Coin";
}
/**
 //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
 Create and new Item Object with the description provided
 */
Item* Coin::create() const {
   return new Coin;
}

/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string Coin::toString() const {
   
   return Item::toString();
}


/**
 *  Output a textual representation of this instance to a string
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string Coin::toStringWithoutCount()const{
   return Item::toStringWithoutCount();
}

/**
 *  Output a textual representation of this instance to the output stream
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a output stream and returned
 *  @return A textual representation of this instance is appended to output stream
 */
std::ostream& operator<<(std::ostream& out, const Coin& obj1) {
   out << obj1.toString();
   return out;
}
