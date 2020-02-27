
/*
 Coin.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 Coin class:
 The coin class inherits from the Class Item and overloads its virtual methods
 There are no additional data members
 The Class allows for comparison of 2 items based on their data members in a particular order.
 Assumptions:
 -- The class has a default constructor, destructor and an assignment operator
 */
#pragma once
#include <stdio.h>
#include "Item.h"
class Coin : public Item{
   
public:
   /**
    //-------------------------- Default constructor  for class Coin  ------------------------------------//
    Create and new Coin Object by calling Item constructor
    */
   Coin();
   
   /**
    //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
    Create and new Item Object with deafault value where name = "n, year = y; grade = g, inventory = i
    */
   Coin(std::string n, int y, std::string g, int i);
   
   /**
    //-------------------------- Destructor  for class Coin  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~Coin();
   
    /**
    //-------------------------- Parametric constructor  for class Coin  ------------------------------------//
    Create and new Item Object with the description provided
    */
   Coin* create(std::string description);
      
    /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
    bool operator==(const Comparable& right) const;
      // call itemClass operator== to make sure the two objects are Coins
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
      // call itemClass operator< and if that returns true then start comparing the data members and return bool based on "Coins are sorted first by type, then by year, then by grade"
   
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
