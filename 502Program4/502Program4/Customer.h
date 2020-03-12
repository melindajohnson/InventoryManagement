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
#include <vector>
#include "HashValueType.h"
#include "Comparable.h"
#include "Item.h"
#include "TransactionItem.h"
#include "Command.h"

class Customer: public HashValueType, public Comparable {
private:
   
   std::string customerName;
   //std::vector<TransactionItem*> transactionList ;
   std::vector<Command*> transactionList ;
   
   
public:
   
   Customer(std::string name);
   
   /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
   bool operator==(const Comparable& right) const override;
   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean false if the left and right object are the same
    @return boolean true if different or false if not
    */
   bool operator!=(const Comparable& right)const override;
   
   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
    @return boolean true is left is smaller than right
    */
   bool operator<(const Comparable& right)const override;
   
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
    @return boolean true is left is larger than right
    */
   bool operator>(const Comparable& right)const override;
   
   std::string toString()const override;
   
   void addTransactions(Command* transactionItem);
   
   /*
    //--------------------------Overloaded output operator <<  ------------------------------------//
    
    */
   friend std::ostream& operator<<(std::ostream& out, const Customer& c) ;
};
