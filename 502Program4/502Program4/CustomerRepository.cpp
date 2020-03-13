/*
 CustomerRepository.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 --The CustomerRepository class contains the private data member customer name and a vector of TransactionEntry
 --This class is extensibe and could include further details of a customer in the future
 ---------------------------------------------------------------------------
 */
#include "CustomerRepository.h"


/**
 //-------------------------- Default constructor  for class CustomerRepository  ------------------------------------//
 Create and new CustomerRepository Object with parameter name
 */
CustomerRepository::CustomerRepository(std::string name){
   customerName = name;
}


/**
 //-------------------------- Destructor  for class CustomerRepository  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
CustomerRepository:: ~CustomerRepository(){
   transactionList.clear();
}

/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */
bool CustomerRepository::operator==(const Comparable& right) const{
   const CustomerRepository &c = static_cast<const CustomerRepository &>(right);
   return (customerName == c.customerName);
}

/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool CustomerRepository::operator!=(const Comparable& right)const{
   const CustomerRepository &c = static_cast<const CustomerRepository &>(right);
   return !(customerName == c.customerName);
}


/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool CustomerRepository::operator<(const Comparable& right)const{
   
   const CustomerRepository &c = static_cast<const CustomerRepository &>(right);
   return (customerName < c.customerName);
}

/**
 //-------------------------- Overloaded greater than operator >  ------------------------------------//
 Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
 @return boolean true is left is larger than right
 */
bool CustomerRepository::operator>(const Comparable& right)const{
   const CustomerRepository &c = static_cast<const CustomerRepository &>(right);
   return (customerName > c.customerName);
}

/**
 Adds new TransactionEntry to the TransactionList vector
 */
void CustomerRepository::addTransactions(TransactionEntry* transactionItem){
   transactionList.push_back(transactionItem);
}

/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::string CustomerRepository::toString()const{
   std::string contents;
   contents = "Customer name: " +customerName + "\n";
   if(transactionList.empty()){
      contents = contents + "No Transactions \n";
      return contents;
   }
   for (auto it = begin (transactionList); it != end (transactionList); ++it) {
      contents = contents + (*it)->toString();
   }
   return contents;
}

/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a output stream. and returned
 *  @return A textual representation of this instance is appended to a output stream.
 */
std::ostream& operator<<(std::ostream& out, const CustomerRepository& c) {
   out << c.toString();
   return out;
   
}
