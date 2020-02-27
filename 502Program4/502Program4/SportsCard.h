#pragma once
#include <stdio.h>
#include "Item.h"
class SportsCard : public Item{
private:
   std::string manufacturer;
public:
   /**
    //-------------------------- Default constructor  for class SportsCard  ------------------------------------//
    Create and new ComicBook Object by calling Item constructor
    */
   SportsCard();
   
   /**
    //-------------------------- Parametric constructor  for class SportsCard  ------------------------------------//
    Create and new Item Object with deafault value where name = "n, year = y; grade = g, inventory = i
    */
   SportsCard(std::string n, int y, std::string g,std::string m, int i );
   
   /**
    //-------------------------- Destructor  for class SportsCard  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~SportsCard();
   /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
   /**
    //-------------------------- Parametric constructor  for class SportsCard  ------------------------------------//
    Create and new Item Object with the description provided
    */
   SportsCard* create(std::string description);
   
   bool operator==(const Comparable& right) const;
      // call itemClass operator== to make sure the two objects are SportsCard
   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean false if the left and right object are the same
    @return boolean true if different or false if not
    */
   bool operator!=(const Comparable& right)const;
      //negate operator==
   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
    @return boolean true is left is smaller than right
    */
   bool operator<(const Comparable& right)const;
      // call itemClass operator< and if that returns true then start comparing the data members and return bool based on "Sports cards are sorted by player, then by year, then by manufacturer, then by grade"
   
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
    @return boolean true is left is larger than right
    */
   bool operator>(const Comparable& right)const;
      //negate operator<
};
