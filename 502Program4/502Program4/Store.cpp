
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
   std::string commandCode;          //customer Id
   std::string id;          //customer Id
   std::string itemCode;    //item code
   std::string description; //command code
                           
                            //S, 001, S, 1989, Near Mint, Ken Griffey Jr., Upper Deck
   while(commandfile.peek() != EOF){  //read command file until eof
      getline(commandfile, input);        //get line by line from command file
      std::string tokens[7];
      int i = 0;
      std::stringstream  data(input);
      std::string line;
      while(std::getline(data,line,','))
      {
         tokens[i] = line;
         i++;
         data.get();
      }
      commandCode = tokens[0];
      id = tokens[1];;
      itemCode = tokens[2];
      description = tokens[3] + ", " + tokens[4]+ ", " + tokens[5] + ", "+ tokens[6];
      
      switch(commandCode.at(0))
      {
         case 'S':{
            //read customer id and find out customer name in the customerData hashtable
            Customer *c1 = dynamic_cast<Customer*>(customerHash->getValue(id));
            if(c1!= nullptr){
            BinarySearchTree *itemTree = dynamic_cast<BinarySearchTree*>(treeHash->getValue(itemCode));
            Item *ptr = itemManager.buildItemsByFactory(itemCode);
            if(ptr!= nullptr){
               ptr->setData(" ", description);
            }
            Item *item = dynamic_cast<Item*>(itemTree->retrieve(*ptr));
            //increase inventory of the particular object by 1
            item->increaseInventory();
            TransactionItem *t1 = new TransactionItem("Sell", item);
            c1->addTransactions(t1);
            }
            break;
         }
         case 'B':{
               //read customer id and find out customer name in the customerData hashtable
            Customer *c1 = dynamic_cast<Customer*>(customerHash->getValue(id));
            if(c1!= nullptr){
            BinarySearchTree *itemTree = dynamic_cast<BinarySearchTree*>(treeHash->getValue(itemCode));
            Item *ptr = itemManager.buildItemsByFactory(itemCode);
            if(ptr!= nullptr){
               ptr->setData(" ", description);
            }
            Item *item = dynamic_cast<Item*>(itemTree->retrieve(*ptr));
               //increase inventory of the particular object by 1
            item->decreaseInventory();
            TransactionItem *t1 = new TransactionItem("Buy", item);
            c1->addTransactions(t1);
            }
            break;
         }
         case 'C':{
            Customer *c1 = dynamic_cast<Customer*>(customerHash->getValue("001"));
            if(c1!= nullptr){
            std::cout << *c1 ;
            }
            break;
         }
         case 'D':{
               //Inorder traversal of the InventoryTree outputs the entire inventory of the store
            displayInventory(*treeHash);
            break;
         }
         case 'H':{
               //Inorder traversal of the TransactionTree outputs the entire history of transactions that took place in the store along with the customer details
            std::cout << customerTree;
            break;
         }
         default:{
            std::cout << "Invalid Code." << std::endl;
         }
      }
   }
}

void Store::displayInventory(Hashtable& h1){
   std::cout << endl;
   std::vector<HashValueType*> itemsContent = h1.getContents();
   for (auto it = begin (itemsContent); it != end (itemsContent); ++it) {
      BinarySearchTree *item = dynamic_cast<BinarySearchTree*>(*it);
      if(item != nullptr){
         std::cout << *item;
      }
   }
}

void Store::displayAllCustomer(Hashtable& h1){
   
}
