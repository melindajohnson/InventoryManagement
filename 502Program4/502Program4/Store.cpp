
#include "Store.h"

void Store::processDataFiles(Hashtable customerData){
   FillInventory();
   FillCustomerData(customerData);
   ProcessTransactions(customerData);
}
void Store::FillInventory(){
      //create a factory hashtable
   Hashtable FactoryHashtable;
      //create dummy points to derived class
   Coin *dummyCoin = new Coin();
   ComicBook *dummycomic = new ComicBook();
   SportsCard *dummySportsCard = new SportsCard();
      //insert data in factory hashtable
   FactoryHashtable.insert("M", dummyCoin);
   FactoryHashtable.insert("C", dummycomic);
   FactoryHashtable.insert("S", dummySportsCard);
      //read inventory file until eof
   for(;;){
         //Code is the code obtained from file such as M, C or S and description is the name, year, grade and other details of that item
         //if code doesnt exist in the hashtable skip over to the next line in file
      std::string description ;
      Item *ptr1 = dynamic_cast<Item*>(FactoryHashtable.getValue("Code"));
      Item *ptr = ptr1->create(description);
         //insert this itemPtr to the BST inventoryTree
      inventoryTree.insert(ptr);
   }
}
void Store::FillCustomerData(Hashtable customerData){
      //read customerdata file until eof
   for(;;){
         //read customer id and customer name
         //in case of error in input skip over to the next line in file
      std::string customerID = " read customer id from file ";
      Customer *c1 = new Customer(); //read customer name and create new Customer Object
      customerData.insert(customerID, c1);
   }
}
void Store::ProcessTransactions(Hashtable customerData){
      //read command file until eof
   for(;;){
         
      char input=' '; //read command code
      switch(input)
      {
         case 'S':
               //read customer id and find out customer name in the customerData hashtable
               //increase inventory of the particular object by 1
               //transactionTree.insert(customerTransaction);
            break;
         case 'B':
               //read customer id and find out customer name in the customerData hashtable
               //reduce inventory of the particular object by 1
               //add customerTransaction in TransactionTree
            break;
         case 'C':
               //read customer id and find out customer name in the customerData hashtable
               //Search for Customer in TransactionTree and output transactions
            break;
         case 'D':
               //Inorder traversal of the InventoryTree outputs the entire inventory of the store
            break;
         case 'H':
               //Inorder traversal of the TransactionTree outputs the entire history of transactions that took place in the store along with the customer details
            break;
         default:
            std::cout << "Invalid Code." << std::endl;
      }
   }
}


