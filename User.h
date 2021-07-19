//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_USER_H
#define ESAME_LABORATORIO_USER_H

#include "ShoppingList.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <memory>

using namespace std;

class User : public Observer {
public:

    virtual ~User() {
        for (auto &itr:myLists)
            itr.second->unsubscribe(this);
    }

    void addShoppingList(ShoppingList& shoppingList);

    virtual void update(const string &listName) override;

    void removeShoppingList(const string &name);

    const map<string, shared_ptr<ShoppingList >> &getMyLists() const;

private:
    map<string, shared_ptr<ShoppingList>> myLists; //le liste sono i subject; un User può avere più subject

};


#endif //ESAME_LABORATORIO_USER_H
