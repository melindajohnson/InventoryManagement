/*
 Customer.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 --The Customer class contains one private data member customer name;
 --This class is extensibe and could include further details of a customer in the future
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include <string>
#include "HashValueType.h"

class Customer: public HashValueType{
private:
   std::string customerName;
};
