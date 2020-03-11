
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
 
