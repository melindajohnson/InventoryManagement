
/*
 Store.cpp
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The Store class contains two binary search trees -> one for the inventry and the other to holds Customer transactions.
 The Store class also contains a hashtable for inventory control which helps in easy addition or removal of inventory for items in the store.
 Assumptions:
 -- The inventoryfile has correct formatting, but the data could be invalid.
 -- The customerfile has correct formatting, but the data could be invalid(duplicates)
 -- The commandFile has correct formatting, but the data could be invalid i.e not available or error codes
 
 ErroHandling:
 -- In the inventoryfile in case of invalid code, the line is skipped and file reading continues
 -- In the customerfile in case of invalid code, the line is skipped and file reading continues
 -- In the commandFile in case of invalid code, error messages are printed for incorrect data and then file reading continues
 ---------------------------------------------------------------------------
 */
#include "Store.h"

Store::Store(){
   std::cout << "out";
}
void Store::processDataFiles(ifstream &inventoryFile, ifstream &customerFile, ifstream &commandfile){
   FillInventory(inventoryFile);
   FillCustomerData(customerFile);
   ProcessTransactions(commandfile);
}
void Store::FillInventory(ifstream &inventoryFile){
   while(inventoryFile.peek() != EOF){
         //if (inventoryFile.eof()) break;
      std::string type;
      std::string stringCount;
      std::string description;
      getline(inventoryFile, type, ',');          //get type of inventory
      inventoryFile.get();          //discard space
      getline(inventoryFile, stringCount, ',');    //get count
      inventoryFile.get();          //discard space
      getline(inventoryFile, description, '\n');    //get rest of info
      Item *ptr = itemManager.buildItemsByFactory(type);
      if(ptr!= nullptr){
         ptr->setData(stringCount, description);
            // int key = code - 'A';
            //create new tree for new code and then insert item else just insert item
         if(treeHash->containsKey(type)){
            BinarySearchTree *tree = dynamic_cast<BinarySearchTree*>(treeHash->getValue(type));
            tree->insert(ptr);
         }else{
            BinarySearchTree *tree = new BinarySearchTree;
            treeHash->insert(type, tree);
            tree->insert(ptr);
         }
      }
      
   }
}
void Store::FillCustomerData(ifstream &customerFile){
      //read customer id and customer name file until eof
   while(customerFile.peek() != EOF){
      std::string id;
      std::string name;
      getline(customerFile, id, ',');          //get customer id
      customerFile.get();                      //discard space
      getline(customerFile, name, '\n');       //get customer name
      Customer *c1 = new Customer(name);
      customerHash->insert(id, c1);
      customerTree.insert(c1);
      
   }
      // display(*customerData);
   
}
void Store::ProcessTransactions(ifstream &commandfile){
   std::string input;       //command code
   std::string id;          //customer Id
   std::string itemCode;    //item code
   std::string description; //command code
                            //read command file until eof
                            //S, 001, S, 1989, Near Mint, Ken Griffey Jr., Upper Deck
   while(commandfile.peek() != EOF){
      getline(commandfile, input, ',');        //get command code
      commandfile.get();                      //discard space
      getline(commandfile, id, ',');          //get customer id
      commandfile.get();                      //discard space
      getline(commandfile, itemCode, ',');          //get customer id
      commandfile.get();                      //discard space
      getline(commandfile, description,'\n');          //get customer id
      commandfile.get();                      //discard space
      
      switch(input.at(0))
      {
         case 'S':{
            
            //read customer id and find out customer name in the customerData hashtable
            Customer *c1 = dynamic_cast<Customer*>(customerHash->getValue(id));
            BinarySearchTree *tree = dynamic_cast<BinarySearchTree*>(treeHash->getValue(itemCode));
            Item *ptr = itemManager.buildItemsByFactory(itemCode);
            if(ptr!= nullptr){
               ptr->setData(" ", description);
            }
            Item *item = dynamic_cast<Item*>(tree->retrieve(*ptr));
            //increase inventory of the particular object by 1
            item->increaseInventory();
            TransactionItem *t1 = new TransactionItem(input, item);
            c1->addTransactions(t1);
            break;
         }
         case 'B':{
               //read customer id and find out customer name in the customerData hashtable
            Customer *c1 = dynamic_cast<Customer*>(customerHash->getValue(id));
            BinarySearchTree *tree = dynamic_cast<BinarySearchTree*>(treeHash->getValue(itemCode));
            Item *ptr = itemManager.buildItemsByFactory(itemCode);
            if(ptr!= nullptr){
               ptr->setData(" ", description);
            }
            Item *item = dynamic_cast<Item*>(tree->retrieve(*ptr));
               //increase inventory of the particular object by 1
            item->decreaseInventory();
            TransactionItem *t1 = new TransactionItem(input, item);
            c1->addTransactions(t1);
            break;
         }
         case 'C':{
            Customer *c1 = dynamic_cast<Customer*>(customerHash->getValue(id));
            c1->toString();
            break;
         }
         case 'D':{
               //Inorder traversal of the InventoryTree outputs the entire inventory of the store
            display(*treeHash);
            break;
         }
         case 'H':{
               //Inorder traversal of the TransactionTree outputs the entire history of transactions that took place in the store along with the customer details
            break;
         }
         default:{
            std::cout << "Invalid Code." << std::endl;
         }
      }
   }
}

void Store::display(Hashtable& h1){
   std::cout << endl;
   std::vector<HashValueType*> itemsContent = h1.getContents();
   for (auto it = begin (itemsContent); it != end (itemsContent); ++it) {
      BinarySearchTree *item = dynamic_cast<BinarySearchTree*>(*it);
      if(item != nullptr){
         std::cout << *item;
      }
   }
}
