//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_SHOPPINGLIST_H
#define ESAME_LABORATORIO_SHOPPINGLIST_H


#include "Observer.h"
#include "Subject.h"
#include <map>
#include <list>
#include <string>
#include <utility>

#include <iostream>
using namespace std;

struct Item{
public:
    Item(string s, int q=1):  itemName(std::move(s)){
        if(q>=0)
            itemQuantity=q;
        else
            throw std::out_of_range("the quantity entered is not positive");
    }

    string itemName;
    int itemQuantity;
    bool bought;
};


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
