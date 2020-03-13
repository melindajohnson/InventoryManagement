
/*
 StoreRepository.cpp
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The StoreRepository class contains
 a binary search trees to holds CustomerRepository
 a hashtable for items called the tree hash which contains a hashtable of pointers to Item trees which inturn have item pointers in them
 a hashtable for CustomerRepository called the cutsomerTree
 a Item factory to create Items whenever desired
 ---------------------------------------------------------------------------
 */

#include "StoreRepository.h"
/**
 //-------------------------- Default constructor for class StoreRepository  ------------------------------------//
 Create a new StoreRepository Object
 */
StoreRepository::StoreRepository(){
}


/**
 //-------------------------- Destructor for class StoreRepository  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
StoreRepository::~StoreRepository(){
   delete customerHash;
}
