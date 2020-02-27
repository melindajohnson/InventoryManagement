
/*
 CustomerTransactions.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 CustomerTransactions class:
 The CustomerTransactions class inherits from the Class Comparable and implements its pure virtual methods
 Data members include;
   --A struct transactions which contains
      --A code of type char;
      --A pointer to an Item object
   --A pointer to an Customer object
   --A vector called transactionList thats contains transactions
 The Class allows for comparison of 2 items based on their customer object
 Assumptions:
 -- The class has a default constructor, destructor and an assignment operator
 */
#pragma once
#include <stdio.h>
#include <vector>
#include "Comparable.h"
#include "Customer.h"
#include "Item.h"
class CustomerTransactions : public Comparable {
private:
   struct Transaction{
      char code;  //code would S for sell and B for Buy
      Item* ptr;
   };
   
   Customer* c;
   std::vector<Transaction> transactionList;
   
public:
   /**
    //-------------------------- Default constructor  for class CustomerTransactions  ------------------------------------//
    Create and new CustomerTransactions Object
    */
   CustomerTransactions();
   
   /**
    //-------------------------- Parametric constructor  for class CustomerTransactions  ------------------------------------//
    Create and new Item Object with
    */
   CustomerTransactions(Customer* c, std::string itemDescription);
   
   /**
    //-------------------------- Destructor  for class CustomerTransactions  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~CustomerTransactions();
   /**
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean true if the left and right object are the same
    @return boolean true if same or false if not
    */
    bool operator==(const Comparable& right) const;
    //check if both objects are the same
   /**
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Determines if two Item are equal based on  data members
    Preconditions: two item objects this and right
    Postconditions:  boolean false if the left and right object are the same
    @return boolean true if different or false if not
    */
    bool operator!=(const Comparable& right)const;
   //negates ==operator
   /**
    //-------------------------- Overloaded lesser than operator <------------------------------------//
    Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
    @return boolean true is left is smaller than right
    */
    bool operator<(const Comparable& right)const;
   //checks if this customer objects is lesser than rights customer object
   /**
    //-------------------------- Overloaded greater than operator >  ------------------------------------//
    Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
    Preconditions: two item objects this and right
    Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
    @return boolean true is left is larger than right
    */
    bool operator>(const Comparable& right)const;
   //negates the <operator
};
 
