//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_USER_H
#define ESAME_LABORATORIO_USER_H

#include "ShoppingList.h"
#include "Observer.h"

class User: public Observer{
public:

    User(){
        for(auto&itr:myLists)
            itr.second->subscribe(this);
    }

    virtual ~User()
    {
        for(auto&itr:myLists)
            itr.second->unsubscribe(this);
    }

    virtual void update(const string& listName) override;

    void addShoppingList(ShoppingList* shoppingList);

    bool removeShoppingList(const string& name);

private:

    map<string,ShoppingList*> myLists; //le liste sono i subject; un User può avere più subject
};


#endif //ESAME_LABORATORIO_USER_H
