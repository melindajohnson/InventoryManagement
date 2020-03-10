#include "ItemFactory.h"


int ItemFactory::hash(char ch) const{
   return ch-'A';
   
}

ItemFactory::ItemFactory() {
//   itemFactory[12] = new AObject;
//   objFactory[1] = new BObject;
//   objFactory[2] = new CObject;
//   objFactory[3] = new DObject;
//   objFactory[4] = new EObject;
//   for (int i = 5; i < 10; i++) objFactory[i] = NULL;
}

 ItemFactory:: ~ItemFactory() {
   for (int i = 0; i < 5; i++) {
      delete itemFactory[i];
      itemFactory[i] = NULL;
   }
}

Item* ItemFactory::make_Item(char ch) const {
   int subscript = hash(ch);             // would do error checking
   return itemFactory[subscript]->create();
}
