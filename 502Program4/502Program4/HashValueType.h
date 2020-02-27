/*
 HashValueType.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 --The HashValueType class is an abstract class
 --Item class and Customer class inherit from HashValueType class 
 ---------------------------------------------------------------------------
 */

#pragma once
#include <stdio.h>
class HashValueType{
public:
   /**
    //-------------------------- Default construtcor ------------------------------------//
    Preconditions: None
    Postconditions: A HashValueType object is created
    */
   HashValueType();
   /**
    //-------------------------- Destructor  for class Hashtable  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~HashValueType();
};

