
#include "ComicBook.h"
/**
 //-------------------------- Default constructor  for class ComicBook  ------------------------------------//
 Create and new ComicBook Object by calling Item constructor
 */
ComicBook::ComicBook():Item(){
   title =" ";
}

/**
 //-------------------------- Parametric constructor  for class ComicBook  ------------------------------------//
 Create and new Item Object with deafault value where name = "n, year = y; grade = g, inventory = i
 */
ComicBook::ComicBook(int i, std::string n, int y, std::string g,std::string t):Item(i, n, y, g){
    title = t;
}

/**
 //-------------------------- Destructor  for class ComicBook  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
ComicBook:: ~ComicBook(){
   
}

/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */
bool ComicBook::operator==(const Comparable& right) const{
   const ComicBook &c = static_cast<const ComicBook &>(right);
   return (name == c.name && grade ==c.grade && year ==c.year && title == c.title);
}
  
/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool ComicBook::operator!=(const Comparable& right)const{
   const ComicBook &c = static_cast<const ComicBook &>(right);
   return !(name == c.name && grade == c.grade && year ==c.year && title == c.title);
}
   
/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool ComicBook::operator<(const Comparable& right)const{
   const ComicBook &c = static_cast<const ComicBook &>(right);
   if(name < c.name) return true;
   else if(name == c.name){
      if (title < c.title) return true;
      else if(title == c.title){
         if(year < c.year) return true;
         else if(year == c.year){
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
bool ComicBook::operator>(const Comparable& right)const{
   const ComicBook &c = static_cast<const ComicBook &>(right);
   if(name < c.name) return true;
   else if(name == c.name){
      if (title < c.title) return true;
      else if(title == c.title){
         if(year < c.year) return true;
         else if(year == c.year){
            if(grade < c.grade) return true;
            else if(grade == c.grade) return false;
         }
      }
   }
   return false;
}

///**
// //-------------------------- Parametric constructor  for class ComicBook  ------------------------------------//
// Create and new Item Object with the description provided
// */
//ComicBook* ComicBook::create(std::string description){
//      //split description into data members and set them in new coin
//   ComicBook *c = new ComicBook;
//   return c;
//}
