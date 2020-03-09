/*
 Comparable.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 Comparable class:
   The comparable class is an abstract class with pure virtual methods that help in comparison between comaprable objects.
 */
#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

class Comparable
{

public:
   
   /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Comparable objects are equal
    Preconditions: data and right.data are two characters belonging to two comparable objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
   virtual bool operator==(const Comparable& right) const = 0;
   
   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Comparable obejcts are not equal 
    Preconditions: data and right.data are two characters belonging to two comparable objects this and right
    Postconditions:boolean true if the left and right object are different
    @return boolean false if same or true if not
    */
   virtual bool operator!=(const Comparable& right)const= 0;
   
   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the Comparable object on the left hand side is lesser than the Comparable object on right hand side
    Preconditions:data and right.data are two characters belonging to two comparable objects this and right
    Postconditions: boolean true if the left hand side data is lesser than the char on right hand side
    @return boolean true is left is smaller than right
    */
   virtual bool operator<(const Comparable& right)const= 0;
   
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the Comparable object on the left hand side is greater than the Comparable object on right hand side
    Preconditions: data and right.data are two characters belonging to two comparable objects this and right
    Postconditions: boolean true if the right hand side data is lesser than the char on left hand side
    @return boolean true is right.data is smaller than data
    */
   virtual bool operator>(const Comparable& right)const= 0;
   
   /**
    //-------------------------- Destructor  for class Comaparable  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~Comparable();
   
};
