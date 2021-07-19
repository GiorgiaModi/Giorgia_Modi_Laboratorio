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

#include <iostream>
using namespace std;


class ShoppingList: public Subject {
public:

    ShoppingList(const string &shoppingListName) : shoppingListName(shoppingListName) {}

    virtual ~ShoppingList(){}

    virtual void subscribe(Observer* o) override;

    virtual void unsubscribe(Observer* o) override;

    virtual void notify() override;

    void addItem(Item* item);

    void removeItem(const string& name);

    void setBought(const string& name);

    int notBought();

    void printNotBought();

    void print();

    const string &getShoppingListName() const;

    void setShoppingListName(const string &shoppingListName);

    list<Observer*> observers;

    map<string,Item*> shoppingList;

private:

    string shoppingListName;

};


#endif //ESAME_LABORATORIO_SHOPPINGLIST_H
