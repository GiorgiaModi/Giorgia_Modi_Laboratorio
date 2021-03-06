//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_SHOPPINGLIST_H
#define ESAME_LABORATORIO_SHOPPINGLIST_H


#include "Observer.h"
#include "Subject.h"
#include "Item.h"
#include <map>
#include <list>
#include <string>
#include <utility>
#include <exception>
#include <stdexcept>
#include <memory>

#include <iostream>
using namespace std;


class ShoppingList: public Subject {
public:

    ShoppingList(const string &shoppingListName) : shoppingListName(shoppingListName) {}

    virtual ~ShoppingList()=default;

    virtual void subscribe(Observer* o) override;

    virtual void unsubscribe(Observer* o) override;

    virtual void notify() override;

    void addItem(const Item& item);

    void removeItem(const string& name);

    void setBought(const string& name);

    int notBought();

    void printNotBought();

    const string &getShoppingListName() const;

    void setShoppingListName(const string &shoppingListName);

    const map<string, shared_ptr<Item>> &getShoppingList() const;

    const list<Observer *> &getObservers() const;

    const map <string,int> &getCategories() const;

private:

    list<Observer*> observers;
    map<string, shared_ptr<Item>> shoppingList;
    map<string, int> categories;
    string shoppingListName;

};


#endif //ESAME_LABORATORIO_SHOPPINGLIST_H
