//
// Created by Giorg on 13/07/2021.
//

#include "ShoppingList.h"

void ShoppingList::addItem(Item *item) {

    auto itr = shoppingList.find(item->itemName);
    if (itr == shoppingList.end()) //l'oggetto non è ancora presente
        shoppingList.insert(make_pair(item->itemName, item));
    else
        itr->second->itemQuantity += item->itemQuantity;

    notify();
}


void ShoppingList::removeItem(const string &name) {
    auto itr = shoppingList.find(name);
    if (itr == shoppingList.end()) {
        cout << "There isn't any " << name << "  in the list :(" << endl;
    } else {
        shoppingList.erase(name);
        itr->second->itemQuantity = 0;
        notify();
    }
}


const map<string, Item *> &ShoppingList::getShoppingList() const {
    return shoppingList;
}


const string &ShoppingList::getShoppingListName() const {
    return shoppingListName;
}


void ShoppingList::setShoppingListName(const string &shoppingListName) {
    ShoppingList::shoppingListName = shoppingListName;
}


void ShoppingList::setBought(const string &name) {
    auto itr = shoppingList.find(name);

    if (itr != shoppingList.end()) {
        bool isBought = itr->second->bought;
        if (isBought == true)
            itr->second->bought = false;
        else
            itr->second->bought = true;

        notify();
    } else
        cout << "There isn't any " << name << "  in the list :(" << endl;
}


void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}


void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}


void ShoppingList::notify() {
    for (auto &itr:observers)
        itr->update(shoppingListName);
}


void ShoppingList::printNotBought() {

    int result = 0;
    cout << "Oggetti da acquistare: ";
    cout << endl;
    for (auto itr: shoppingList) {
        if (itr.second->bought == false) {
            result += itr.second->itemQuantity;   //conto gli oggetti da acquistare;
            cout << itr.second->itemName;
            cout << "      " << itr.second->itemQuantity << endl;
        }
    }
    cout << endl;
    cout << "Numero totale oggetti da acquistare: " << result << endl;
    cout << endl;
}


void ShoppingList::print() {
    cout << "Nome lista:  " << shoppingListName << endl;

    for (auto &itr: shoppingList) {
        cout << itr.first << "     " << itr.second->itemQuantity;
        if (itr.second->bought)
            cout << "       Bought" << endl;
        else
            cout << "       Not bought" << endl;
    }

}

