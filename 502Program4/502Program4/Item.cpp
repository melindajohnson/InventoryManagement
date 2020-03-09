
#include "Item.h"
/**
 //-------------------------- Default constructor  for class Item  ------------------------------------//
 Create and new Item Object with deafault value where name = " ", year = 0; grade = 0
 */
Item::Item(){
   inventory = 0;
   name = " ";
   year = 0;
   grade= " ";
}

/**
 //-------------------------- Parametric constructor  for class Item  ------------------------------------//
 Create and new Item Object with deafault value where name = n, year = y; grade = g
 */
Item::Item(int i, std::string n, int y, std::string g){
   inventory = i;
   name = n;
   year = y;
   grade= g;
}

/**
 //-------------------------- Destructor  for class Item  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Item:: ~Item(){
   
}

/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */
bool Item::operator==(const Comparable& right) const{
    const Item &item = static_cast<const Item &>(right);
  return (name == item.name && grade ==item.grade && year ==item.year);
}

/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool Item::operator!=(const Comparable& right)const{
   const Item &item = static_cast<const Item &>(right);
 return !(name == item.name && grade == item.grade && year == item.year);
}

/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool Item::operator<(const Comparable& right)const{
   const Item &item = static_cast<const Item &>(right);
   if(name < item.name) return true;
   else if(name == item.name){
      if (grade < item.grade) return true;
      else if(grade == item.grade){
         if(year < item.year) return true;
         else if(year == item.year) return false;
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
bool Item::operator>(const Comparable& right)const{
   const Item &item = static_cast<const Item &>(right);
   if(name > item.name) return true;
   else if(name == item.name){
      if (grade > item.grade) return true;
      else if(grade == item.grade){
         if(year > item.year) return true;
         else if(year == item.year) return false;
      }
   }
   return false;
}


/**
 -------------------------- Parametric constructor  for class item  ------------------------------------//
 Create and new Item Object with the description provided
 */
//Item* Item::create(char itemCode){
////      if (itemCode == 'M')
////         return new Coin;
////      else if (itemCode == 'C')
////         return new ComicBook;
////      else if (itemCode == 'S')
////         return new SportsCard;
//}
//
