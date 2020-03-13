/*
 Comparable.cpp
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 Comparable class:
 The comparable class is an abstract class with pure virtual methods that help in comparison between comaprable objects.
 */
#include "Comparable.h"

/**
 //-------------------------- Destructor  for class Comaparable  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Comparable:: ~Comparable(){
   
}
/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Preconditions: A comparable object is created and its data is set
 Postconditions: Outputs the Comparable objects
 */
std::ostream& operator<<(std::ostream& out, const Comparable& obj1){
   out << obj1.toString();
   return out;
}
 
