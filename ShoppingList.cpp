//
// Created by Giorg on 13/07/2021.
//

#include "ShoppingList.h"

void ShoppingList::addItem(Item &item) {

    auto itr = shoppingList.find(item.getItemName());
    if (itr == shoppingList.end()) //l'oggetto non è ancora presente
    {
        auto itemPtr= make_shared<Item>(item);
        shoppingList.insert(make_pair(item.getItemName(), itemPtr));
    }
    else
    {
        int result= itr->second->getItemQuantity() + item.getItemQuantity();
        itr->second->setItemQuantity(result);
    }

    string itemCat=item.getCategory();   //serve in seguito per andare a stampare gli oggetti in base alla categoria
    bool flag=false;
    for(auto&it: categories)
    {
        if(it==itemCat)
        {
            flag=true;
            break;
        }
    }
    if(flag==false)
        categories.push_back(itemCat);

    notify();
}


void ShoppingList::removeItem(const string &name) {
    auto itr = shoppingList.find(name);
    if (itr == shoppingList.end()) {
        throw std::invalid_argument("Invalid item name");
    } else {
        shoppingList.erase(name);
        itr->second->setItemQuantity(0);
        notify();
    }
}


const string &ShoppingList::getShoppingListName() const {
    return shoppingListName;
}



void ShoppingList::setBought(const string &name) {
    auto itr = shoppingList.find(name);

    if (itr != shoppingList.end()) {
        bool isBought = itr->second->isBought();
        if (isBought)
            itr->second->setBought(false);
        else
            itr->second->setBought(true);

        notify();
    } else
        throw std::invalid_argument("Invalid item name");
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
    for (auto &itr: shoppingList) {
        if (!itr.second->isBought()) {
            result += itr.second->getItemQuantity();   //conto gli oggetti da acquistare;
            cout << itr.second->getItemName();
            cout << "      " << itr.second->getItemQuantity() << endl;
        }
    }
    cout << endl;
    cout << "Numero totale oggetti da acquistare: " << result << endl;
    cout << endl;
}


void ShoppingList::print() {
    cout << "Nome lista:  " << shoppingListName << endl<<endl;

    string cat;
    bool first;
    for (auto &itr: categories) {
       cat=itr;
       first=true;
       for(auto &s: shoppingList)
       {
           if(s.second->getCategory()==cat)
           {
               if(first)
               {
                   cout<<"Categoria:  "<<cat<<endl;
                   first=false;
               }

               cout << s.first << "     " << s.second->getItemQuantity();
               if (s.second->isBought()==true)
                   cout << "       Bought" << endl;
               else
                   cout << "       Not bought" << endl;


           }
       }
    }

}


void ShoppingList::setShoppingListName(const string &shoppingListName) {
    ShoppingList::shoppingListName = shoppingListName;
}

int ShoppingList::notBought() {
    int result=0;
    for (auto &itr: shoppingList) {
        if (!itr.second->isBought()) {
            result += itr.second->getItemQuantity();   //conto gli oggetti da acquistare;
        }
    }
    return result;
}


const map<string, shared_ptr<Item>> &ShoppingList::getShoppingList() const {
    return shoppingList;
}

const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}


