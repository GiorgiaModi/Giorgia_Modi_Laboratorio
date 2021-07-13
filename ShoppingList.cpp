//
// Created by Giorg on 13/07/2021.
//

#include "ShoppingList.h"

void ShoppingList::addItem(Item* item) {

    auto itr=shoppingList.find(item->itemName);
    if(itr==shoppingList.end()) //l'oggetto non è ancora presente
    {
        shoppingList.insert(make_pair(item->itemName,item));
        item->itemQuantity++;
    }
    else
        itr->second->itemQuantity++;

    notify();
}


bool ShoppingList::removeItem(const string &name) {
    auto itr=shoppingList.find(name);
    if(itr==shoppingList.end())
    {
        cout<<"There isn't any "<< name<< "  in the list :("<<endl;
        return false;
    }
    else {
        shoppingList.erase(name);
        notify();
        return true;
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


void ShoppingList::setBought(const string& name) {
    auto itr=shoppingList.find(name);

    if(itr!= shoppingList.end())
    {
        bool bought= itr->second->bought;
        if(bought)
            bought=false;    //segno l'oggetto come da comprare
        else
            bought=true;    //segno l'oggetto come comprato

        notify();
    }
    else
        cout<<"There isn't any "<< name<< "  in the list :("<<endl;
}


void ShoppingList::subscribe(Observer* o)
{
    observers.push_back(o);
}


void ShoppingList::unsubscribe(Observer* o)
{
    observers.remove(o);
}


void ShoppingList::notify()
{
    for(auto &itr:observers)
        itr->update(shoppingListName);
}


void ShoppingList::toDo() {

    int result=0;
    cout<<"Oggetti da acquistare nella lista "<<shoppingListName<< ":  "<<endl;
    cout<<endl;
    for(auto&itr: shoppingList)
    {
        if(itr.second->bought) {
            result += itr.second->itemQuantity;   //conto gli oggetti da acquistare;
            cout << itr.second->itemName << endl;
        }
    }
    cout<<endl;
    cout<<"Numero oggetti da acquistare: "<<result<<endl;
}

