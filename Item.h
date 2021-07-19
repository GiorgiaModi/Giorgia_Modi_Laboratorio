//
// Created by Giorg on 19/07/2021.
//

#ifndef ESAME_LABORATORIO_ITEM_H
#define ESAME_LABORATORIO_ITEM_H

#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class Item {
public:
    Item(string s, int q=1):  itemName(std::move(s)){
        if(q>=0)
            itemQuantity=q;
        else
            throw out_of_range("Item quantity entered is not positive");
    }

    const string &getItemName() const {
        return itemName;
    }

    void setItemName(const string &itemName) {
        Item::itemName = itemName;
    }

    int getItemQuantity() const {
        return itemQuantity;
    }

    void setItemQuantity(int itemQuantity) {
        if(itemQuantity>=0)
            Item::itemQuantity = itemQuantity;
        else
            throw std::out_of_range("Item quantity entered is not positive");
    }

    bool isBought() const {
        return bought;
    }

    void setBought(bool bought) {
        Item::bought = bought;
    }

private:
    string itemName;
    int itemQuantity;
    bool bought;
};


#endif //ESAME_LABORATORIO_ITEM_H
