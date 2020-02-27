#pragma once
#include <stdio.h>
#include <string>
#include "HashValueType.h"

class Customer: public HashValueType{
private:
   std::string customerName;
};
