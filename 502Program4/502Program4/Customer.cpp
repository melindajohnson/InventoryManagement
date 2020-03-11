
#include "Customer.h"
Customer::Customer(std::string name){
   customerName = name;
}
/**
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean true if the left and right object are the same
 @return boolean true if same or false if not
 */
bool Customer::operator==(const Comparable& right) const{
   const Customer &c = static_cast<const Customer &>(right);
   return (customerName == c.customerName);
}

/**
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Determines if two Item are equal based on  data members
 Preconditions: two item objects this and right
 Postconditions:  boolean false if the left and right object are the same
 @return boolean true if different or false if not
 */
bool Customer::operator!=(const Comparable& right)const{
   const Customer &c = static_cast<const Customer &>(right);
   return !(customerName == c.customerName);
}


/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the item object on the left hand side is smaller than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is smaller than the data on the right hand side
 @return boolean true is left is smaller than right
 */
bool Customer::operator<(const Comparable& right)const{
    
   const Customer &c = static_cast<const Customer &>(right);
   return (customerName < c.customerName);
}

/**
 //-------------------------- Overloaded greater than operator >  ------------------------------------//
 Determines if the item object on the left hand side is larger than the Item object on right hand side based on name of the item
 Preconditions: two item objects this and right
 Postconditions: boolean true if the left hand side data is larger than the data on the right hand side
 @return boolean true is left is larger than right
 */
bool Customer::operator>(const Comparable& right)const{
   const Customer &c = static_cast<const Customer &>(right);
     return (customerName > c.customerName);
}


std::string Customer::toString()const{
   std::string contents;
   contents = customerName + "\n";
   for (auto it = begin (transactionList); it != end (transactionList); ++it) {
      contents = contents + (*it)->toString() + "\n";
   }
   return contents;
}

void Customer::addTransactions(TransactionItem* transactionItem){
   transactionList.push_back(transactionItem);
}


/*
 //--------------------------Overloaded output operator <<  ------------------------------------//

 */
std::ostream& operator<<(std::ostream& out, const Customer& c) {
   out << c.customerName << std::endl;
  // out << "Transactions List " << std::endl;
   for (auto it = begin (c.transactionList); it != end (c.transactionList); ++it) {
      out << *(*it);
   }
   return out;
   
}
