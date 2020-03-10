
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
   std::string year;
   std::string  grade;
   
   
public:
   /**
    //-------------------------- Default constructor  for class Item  ------------------------------------//
    Create and new Item Object with deafault value where name = " ", year = 0; grade = 0
    */
   Item();
   
   /**
    //-------------------------- Destructor  for class Item  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~Item();
   /**
    //-------------------------- Parametric constructor  for class item  ------------------------------------//
    Create and new Item Object with the description provided
    */
   virtual Item* create() const = 0;
   
   /**
    //-------------------------- Method to set data  ------------------------------------//
    sets the data members of an  Item Object with the parameters provided
    */
  virtual void setData(std::string stringCount, std::string description);
   
   
   /**
    
    */
   virtual std::string toString()const override;
};
