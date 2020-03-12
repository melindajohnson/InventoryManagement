

#pragma once
#include <stdio.h>
#include "Comparable.h"
#include "HashValueType.h"

class Command: public HashValueType {
protected:
   Comparable* itemPtr;
public:
   /**
    //-------------------------- Default constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   Command();
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create and new Command Object with the description provided
    */
   virtual Command* create() const = 0;
};
