
/*
 SportsCard.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 SportsCard class:
 The ComicBook class inherits from the Class Item and overloads its virtual methods
 There is one additional data members a manufacturer of type string
 The Class allows for comparison of 2 items based on their data members in a particular order.
 Assumptions:
 -- The class has a default constructor, destructor and an assignment operator
 */
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
   
   bool operator==(const Comparable& right) const override;;

   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean false if the left and right object are the same
    @return boolean true if different or false if not
    */
   bool operator!=(const Comparable& right)const override;;

   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
    @return boolean true is left is smaller than right
    */
   bool operator<(const Comparable& right)const override;;
     
   
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
    @return boolean true is left is larger than right
    */
   bool operator>(const Comparable& right)const override;;

   
   /**
    //-------------------------- Parametric constructor  for class SportsCard  ------------------------------------//
    Create and new Item Object with the description provided
    */
   virtual Item* create() const override; ;
   
   /**
    -------------------------- Method to set data  ------------------------------------//
    sets the data members of an  Item Object with the parameters provided
    */
   
   void setData(std::string stringCount, std::string description) override;
   
   /**
    *  Initialize an instance of this class from an input stream.
    *  Expected format is: {quantity},{year},{grade},{player},{manufacturer}
    *  e.g. "9, 1989, Near Mint, Ken Griffey Jr., Upper Deck"
    *  @param in An input stream to read `Card` data from.
    *  @param card A reference to a `Card` to initialize.
    *  @return The input stream that was passed in.
    */
   friend std::istream& operator>>(std::istream& in, SportsCard& card);
   
   /**
    *  Output a textual representation of this instance to the output stream.
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to
    *   output stream.
    *  @param out An output stream to append to.
    *  @param card A card instance to append to the output stream.
    *  @return The output stream that was passed in
    */
   friend std::ostream& operator<<(std::ostream& out, const SportsCard& card);
   
   /**
    
    */
   virtual std::string toString()const override;
};
