
/*
 Item.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 Item class:
   The item class inherits from the Class Comparable and implements its pure virtual methods
   The item class also inherits from the Class HashValueType
   Data members include;
   inventory, name, year and grade whose access specifiers are protected so that derived class could inherit them
   The Class allows for comparison of 2 item objects based on the name 
 Assumptions:
 -- The class has a default constructor, destructor and an assignment operator
 */
#pragma once
#include <stdio.h>
#include "Comparable.h"
#include "HashValueType.h"

class Item : public Comparable, public HashValueType {
protected:
   
   int inventory;
   std::string name;
   int year;
   std::string  grade;
   
   
public:
   /**
    //-------------------------- Default constructor  for class Item  ------------------------------------//
    Create and new Item Object with deafault value where name = " ", year = 0; grade = 0
    */
   Item();
   
   /**
    //-------------------------- Parametric constructor  for class Item  ------------------------------------//
    Create and new Item Object with deafault value where name = n, year = y; grade = g
    */
   Item(std::string n, int y, std::string g,int i);
   
   /**
    //-------------------------- Destructor  for class Item  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~Item();
   /**
    //-------------------------- Parametric constructor  for class item  ------------------------------------//
    Create and new Item Object with the description provided
    */
   virtual Item* create(std::string description);
   
   /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
   virtual bool operator==(const Comparable& right) const;
   
   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Item are equal based on  data members 
    Preconditions: two item objects this and right
    Postconditions:  boolean false if the left and right object are the same
    @return boolean true if different or false if not
    */
   virtual bool operator!=(const Comparable& right)const;
   
   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
    @return boolean true is left is smaller than right
    */
   virtual bool operator<(const Comparable& right)const;
   
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
    @return boolean true is left is larger than right
    */
   virtual bool operator>(const Comparable& right)const;
   
};
