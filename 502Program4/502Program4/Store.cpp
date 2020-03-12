
#include "Store.h"
Store::Store(){
   
}
void Store::processDataFiles(std::ifstream &inventoryFile, std::ifstream &customerFile, std::ifstream &commandfile){
   myStore = new StoreRepository();
   FillInventory(inventoryFile);
   FillCustomerData(customerFile);
   ProcessTransactions(commandfile);
}

void Store::FillInventory(std::ifstream &inventoryFile){
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
   
      Item *itemPtr = myStore->itemFactory.buildItemsByFactory(type);
      if(itemPtr!= nullptr){
         itemPtr->setData(stringCount, description);
            // int key = code - 'A';
            //create new tree for new code and then insert item else just insert item
         if(myStore->treeHash->containsKey(type)){
            BinarySearchTree *tree = dynamic_cast<BinarySearchTree*>(myStore->treeHash->getValue(type));
            tree->insert(itemPtr);
         }else{
            BinarySearchTree *tree = new BinarySearchTree;
            myStore->treeHash->insert(type, tree);
            tree->insert(itemPtr);
         }
      }
      
   }
}

void Store::FillCustomerData(std::ifstream &customerFile){
      //read customer id and customer name file until eof
   while(customerFile.peek() != EOF){
      std::string id;
      std::string name;
      getline(customerFile, id, ',');          //get customer id
      customerFile.get();                      //discard space
      getline(customerFile, name, '\n');       //get customer name
      CustomerRepository *c1 = new CustomerRepository(name);
      myStore->customerHash->insert(id, c1);
      myStore->customerTree.insert(c1);
      
   }
}
void Store::ProcessTransactions(std::ifstream &commandfile){
   std::string input;       //command code
   std::string commandCode;
   std::string commandString;
   CommandFactory  commandFactory;
   while(commandfile.peek() != EOF){  //read command file until eof
      getline(commandfile, input);        //
      commandCode = input.at(0);
      if(input.size() > 1){
         commandString = input.substr(3, input.size());
      }
      
      Command *commandPtr = commandFactory.buildCommandsByFactory(commandCode);
      if(commandPtr!= nullptr){
         commandPtr->execute(commandString, myStore);
      } else {
         std::cout << "Invalid Code!!" << std::endl;
      }
   }
}
