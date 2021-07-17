//
// Created by Giorg on 13/07/2021.
//

#include "User.h"

void User::addShoppingList(ShoppingList *shoppingList) {
    myLists.insert(make_pair(shoppingList->getShoppingListName(), shoppingList));
    shoppingList->subscribe(this);
}


void User::removeShoppingList(const string &name) {
    auto itr = myLists.find(name);
    if (itr == myLists.end()) {
        cout << "There isn't any " << name << "  in MyLists :(" << endl;
    } else {
        myLists.erase(name);
    }
    itr->second->unsubscribe(this);
}


void User::update(const string &listName) {

    auto itr = myLists.find(listName);
    cout << "Lista ' " << listName << " ' aggiornata: " << endl;
    cout << endl;
    itr->second->printNotBought();


}
