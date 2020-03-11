
#include "ComicBook.h"
/**
 //-------------------------- Default constructor  for class ComicBook  ------------------------------------//
 Create and new ComicBook Object by calling Item constructor
 */
ComicBook::ComicBook():Item(){
   publisher =" ";
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
   return (name == c.name && grade ==c.grade && year ==c.year && publisher == c.publisher);
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
   return !(name == c.name && grade == c.grade && year ==c.year && publisher == c.publisher);
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
   if(publisher < c.publisher) return true;
   else if(publisher == c.publisher){
      if (name < c.name) return true;
      else if(name == c.name){
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
   if(publisher > c.publisher) return true;
   else if(publisher == c.publisher){
      if (name > c.name) return true;
      else if(name == c.name){
         if(year > c.year) return true;
         else if(year == c.year){
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
Item* ComicBook::create() const {
   return new ComicBook;
   
}


/**
 //-------------------------- Method to set data  ------------------------------------//
 sets the data members of an  Item Object with the parameters provided
 */
void ComicBook::setData(std::string stringCount, std::string description){
   inventoryCount = atoi(stringCount.c_str());
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
   publisher = tokens[3];

}
/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string ComicBook::toString() const {
   return  Item::toString() + ", " + publisher;
}


/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string ComicBook::toStringWithoutCount()const{
   return Item::toStringWithoutCount() + ", " + publisher;;
}

/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Preconditions: A comparable object is created and its data is set
 Postconditions: Outputs the Comparable objects
 */
std::ostream& operator<<(std::ostream& out, const ComicBook& obj1) {
   out << obj1.toString();
   return out;
}
