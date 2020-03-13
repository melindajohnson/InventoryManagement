/*
 Store.cpp
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The Store class contains a Store Respository
 It reads the input files and sets data into the store using the following methods
 The process data file that does the following
 1.Fill inventory - reads the inventory file and creates a hashtable of Item trees containing Items
 2.Fill cutsomer date - reads the customer file and creates a hashtable of Customers and a tree of the same Cutsomers
 3.Process Transaction - reads the command file and creates the executes necessary command
 ---------------------------------------------------------------------------
 */
#include "Store.h"
/**
 //-------------------------- Default constructor for class Store  ------------------------------------//
 Create a new Store Object
 */
Store::Store(){
   myStore = nullptr;
}

/**
 //-------------------------- Destructor for class Store  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Store:: ~Store(){
   delete myStore;
}

/**
 //-------------------------- processDataFiles ------------------------------------//
 Preconditions: A store object is created
 Postconditions: The myStore is filled with data
 */
void Store::processDataFiles(std::ifstream &inventoryFile, std::ifstream &customerFile, std::ifstream &commandfile){
   //create a new StoreRepository
   myStore = new StoreRepository();
   FillInventory(inventoryFile);
   FillCustomerData(customerFile);
   ProcessTransactions(commandfile);
}

/**
 //-------------------------- FillInventory ------------------------------------//
 Preconditions: A store object is created
 Postconditions: The inventory tree is filled with items in the store
 */
void Store::FillInventory(std::ifstream &inventoryFile){
   while(inventoryFile.peek() != EOF){
      std::string type;
      std::string stringCount;
      std::string description;
      getline(inventoryFile, type, ',');           //get type of item
      inventoryFile.get();                         //discard space
      getline(inventoryFile, stringCount, ',');    //get count
      inventoryFile.get();                         //discard space
      getline(inventoryFile, description, '\n');   //get rest of info
      //based on the item type,a dummy item object is created
      Item *itemPtr = myStore->itemFactory.make_Item(type);
      if(itemPtr!= nullptr){
         //Set the item with data from the input file
         itemPtr->setData(stringCount, description);
         myStore->itemtree.insert(itemPtr);
      }
      
   }
}

/**
 //-------------------------- FillCustomerData ------------------------------------//
 Preconditions: A store object is created
 Postconditions: The customerData hashtable is filled with customer information
 */
void Store::FillCustomerData(std::ifstream &customerFile){
      //read customer id and customer name file until eof
   while(customerFile.peek() != EOF){
      std::string id;
      std::string name;
      getline(customerFile, id, ',');          //get customer id
      customerFile.get();                      //discard space
      getline(customerFile, name, '\n');       //get customer name
      //Create a new Customer Repository and insert it in both customer hash and customer tree
      CustomerRepository *c1 = new CustomerRepository(name);
      myStore->customerHash->insert(id, c1);
      myStore->customerTree.insert(c1);
   }
}

/**
 //-------------------------- ProcessTransactions------------------------------------//
 Preconditions: A store object is created and inventorytree and customerData is filled with data
 Postconditions: The rootPtr of the Searchtree is initialized to a nullptr
 */
void Store::ProcessTransactions(std::ifstream &commandfile){
   std::string input;         //input line from file
   std::string commandCode;   //code of command
   std::string commandString; //rest of the description of the command
   CommandFactory  commandFactory;
   Command* commandPtr = NULL;
   while(commandfile.peek() != EOF){  //read command file until eof
      getline(commandfile, input);
      commandCode = input.at(0);
      if(input.size() > 1){
         commandString = input.substr(3, input.size());
      }
      //based on the commandCode,a dummy command object is created
      commandPtr = commandFactory.make_Command(commandCode);
      //the command is then executed
      if(commandPtr!= nullptr){
         commandPtr->execute(commandString, myStore);
         delete commandPtr;
      } else {
         std::cout << "Invalid Code!!" << std::endl;
      }
   }

}
