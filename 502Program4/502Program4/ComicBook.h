
/*
 ComicBook.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 ComicBook class:
 The ComicBook class inherits from the Class Item and overloads its virtual methods
 There is one additional data members a title of type string
 The Class allows for comparison of 2 items based on their data members in a particular order.
 */
#pragma once
#include <stdio.h>
#include "Item.h"
class ComicBook : public Item{
private:
   std::string publisher;
public:
   /**
    //-------------------------- Default constructor  for class ComicBook  ------------------------------------//
    Create and new ComicBook Object by calling Item constructor
    */
   ComicBook();
   
   /**
    //-------------------------- Destructor  for class ComicBook  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~ComicBook();
   
   /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
   bool operator==(const Comparable& right) const override; ;
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
    //-------------------------- Parametric constructor  for class ComicBook  ------------------------------------//
    Create and new Item Object with the description provided
    */
   virtual Item* create() const override;;
   
   /**
    -------------------------- Method to set data  ------------------------------------//
    sets the data members of an  Item Object with the parameters provided
    */
   void setData(std::string stringCount, std::string description) override;
   
   /**
    *  Output a textual representation of this instance to a string
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to a string and returned
    *  @return A textual representation of this instance is appended to a string
    */
   virtual std::string toString()const override;
   
   /**
    *  Output a textual representation of this instance to a string
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to a string and returned
    *  @return A textual representation of this instance is appended to a string
    */
   virtual std::string toStringWithoutCount()const override;
   
   /**
    *  Output a textual representation of this instance to the output stream
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to a output stream and returned
    *  @return A textual representation of this instance is appended to output stream
    */
    friend std::ostream& operator<<(std::ostream& out, const ComicBook& obj1) ;
};
