
/*
 ComicBook.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 ComicBook class:
 The ComicBook class inherits from the Class Item and overloads its virtual methods
 There is one additional data members a title of type string
 The Class allows for comparison of 2 items based on their data members in a particular order.
 Assumptions:
 -- The class has a default constructor, destructor and an assignment operator
 */
#pragma once
#include <stdio.h>
#include "Item.h"
class ComicBook : public Item{
private:
   std::string title;
public:
   /**
    //-------------------------- Default constructor  for class ComicBook  ------------------------------------//
    Create and new ComicBook Object by calling Item constructor
    */
   ComicBook();
   
   /**
    //-------------------------- Parametric constructor  for class ComicBook  ------------------------------------//
    Create and new Item Object with deafault value where name = "n, year = y; grade = g, inventory = i
    */
   ComicBook(int i, std::string n, int y, std::string g,std::string t);
   
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
   bool operator==(const Comparable& right) const;
   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean false if the left and right object are the same
    @return boolean true if different or false if not
    */
   bool operator!=(const Comparable& right)const;

   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
    @return boolean true is left is smaller than right
    */
   bool operator<(const Comparable& right)const;
   
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
    @return boolean true is left is larger than right
    */
   bool operator>(const Comparable& right)const;
   
//   /**
//    //-------------------------- Parametric constructor  for class ComicBook  ------------------------------------//
//    Create and new Item Object with the description provided
//    */
//   ComicBook* create(std::string description);
//   
};
