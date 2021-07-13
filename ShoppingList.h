//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_SHOPPINGLIST_H
#define ESAME_LABORATORIO_SHOPPINGLIST_H

#include "main.cpp"
#include "Observer.h"
#include "Subject.h"
#include <map>
#include <list>
#include <string>
using namespace std;

class ShoppingList: public Subject {
public:

    virtual ~ShoppingList()=default;

    virtual void subscribe(Observer* o) override;

    virtual void unsubscribe(Observer* o) override;

    virtual void notify() override;

    void addItem(Item* item);

    bool removeItem(const string& name);

    void setBought(const string& name);

    void toDo();

    const map<string, Item *> &getShoppingList() const;

    const string &getShoppingListName() const;

    void setShoppingListName(const string &shoppingListName);

private:

    list<Observer*> observers;
    string shoppingListName;
    map<string,Item*> shoppingList;
};


#endif //ESAME_LABORATORIO_SHOPPINGLIST_H
