
#include "TransactionItem.h"
/**
 //-------------------------- Default constructor  for class TransactionItem  ------------------------------------//
 Create and new TransactionItem Object
 */
TransactionItem::TransactionItem(){
   
}

/**
 //-------------------------- Parametric constructor  for class TransactionItem  ------------------------------------//
 Create and new Item Object with
 */
TransactionItem::TransactionItem(std::string type, Item* ptr1){
   code = type;
   ptr = ptr1;
}
/**
 //-------------------------- Destructor  for class TransactionItem  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
TransactionItem:: ~TransactionItem(){
   
}
