#include <iostream>
#include "Subject.h"
#include "ShoppingList.h"
#include "Observer.h"
#include "User.h"
#include <string>
#include <stdexcept>
using namespace std;


int main() {

    cout<< "Welcome! Thanks to this program you will be able to memorize your shopping lists in a simple way"<<endl;
    cout<<endl<<endl<<endl;

    bool create=true;
    int result;
    map <string, ShoppingList> shoppingLists;
    map <string, Item> items;
    map <string,User> users;


    cout<<"         Create the shopping lists: "<<endl<<endl;


    while(create)
    {
        cout<<endl;
        cout<<"Enter 1 if you want to create a new shopping list, 2 if you want to move on"<<endl;
        cin>>result;

        switch (result) {
            case 1 : {
                string shoppingListName;
                cout<< "Insert shopping list name: "<<endl;
                cin>>shoppingListName;
                ShoppingList s(shoppingListName);
                shoppingLists.insert(make_pair(shoppingListName,s));
                break;
            }

            case 2 : {
                create=false;
                break;
            }
        }
    }

    cout<<endl;
    cout<<"         Create the items: "<<endl<<endl;

    create=true;
    while(create)
    {
        cout<<endl;
        cout<<"Enter 1 if you want to create a new item, 2 if you want to move on"<<endl;
        cin>>result;

        switch (result) {
            case 1 : {
                string itemName;
                int quantity=1;
                cout<<"Insert item name and quantity: "<<endl;
                cin>>itemName;
                cin>>quantity;
                try{
                    Item i(itemName,quantity);
                    items.insert(make_pair(itemName,i));
                }catch(std::out_of_range& e){
                    cerr<<e.what()<<endl;}
                break;
            }

            case 2 : {
                create=false;
                break;
            }
        }
    }

    cout<<endl;
    cout<<"         Create the users: "<<endl<<endl;

    create=true;
    while(create)
    {
        cout<<endl;
        cout<<"Enter 1 if you want to create a new user, 2 if you want to move on"<<endl;
        cin>>result;

        switch (result) {
            case 1 : {
                string userName;
                cout<<"Insert User name: "<<endl;
                cin>>userName;
                User u;
                users.insert(make_pair(userName,u));
                break;
            }

            case 2 : {
                create=false;
                break;
            }
        }
    }

    cout<<endl<<endl;
    cout<<"Now it's time to perform operations on created users / lists / objects"<<endl;
    cout<<"From the  moment of adding lists to  a user's list of lists, any changes to the lists will be notified to the user."<<endl<<endl;

    bool operations=true;
    while(operations)
    {
        cout<<endl;
        cout<<"Operations:"<<endl<<"1) add item to list "<<endl<<"2) remove item from list (insert list name and item name)"<<endl;
        cout<<"3) mark an item as bought "<<endl<<"4) add shopping list to a user's shopping lists"<<endl<< "5) remove shopping list from a user's shopping lists"<<endl;
        cout<<"6) no more operations"<<endl;
        cin>>result;
        cout<<endl;
        switch (result) {
            case 1 :{
                string listName;
                string itemName;
                cout<<"Insert list name and item name"<<endl;
                cin>>listName;
                cin>>itemName;
                auto itrl=shoppingLists.find(listName);
                auto itri=items.find(itemName);

                try {
                    if(itrl==shoppingLists.end()||itri==items.end())
                            throw std::invalid_argument("Invalid list/item name");
                    else
                    {
                            itrl->second.addItem(&(itri->second));
                    }
                }catch(std::invalid_argument& e){
                    cout<<e.what()<<endl;}
                break;
            }

            case 2: {
                string itemName;
                string listName;
                cout<<"Insert list name and item name"<<endl;
                cin>>listName;
                cin>>itemName;
                auto itrl=shoppingLists.find(listName);
                auto itri=items.find(itemName);
                try {
                    if (itrl == shoppingLists.end() || itri == items.end())
                        throw std::invalid_argument("Invalid list/item name");
                    else
                        itrl->second.removeItem(itemName);

                }catch(std::invalid_argument& e){
                        cerr<<e.what()<<endl;}
                break;
            }

            case 3: {
                string itemName;
                string listName;
                cout<<"Insert list name and item name"<<endl;
                cin>>listName;
                cin>>itemName;
                auto itrl=shoppingLists.find(listName);
                auto itri=items.find(itemName);
                try {
                    if (itrl == shoppingLists.end() || itri == items.end())
                        throw std::invalid_argument("Invalid list/item name");
                    else
                        itrl->second.setBought(itemName);

                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;
            }

            case 4: {
                string userName;
                string listName;
                cout<<"Insert list name and user name"<<endl;
                cin>>listName;
                cin>>userName;
                auto itrl=shoppingLists.find(listName);
                auto itru=users.find(userName);
                try {
                    if(itrl==shoppingLists.end()||itru==users.end())
                        throw std::invalid_argument("Invalid list/user name");
                    else
                    {
                        itru->second.addShoppingList(&(itrl->second));
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;
            }

            case 5: {
                string userName;
                string listName;
                cout<<"Insert list name and user name"<<endl;
                cin>>listName;
                cin>>userName;
                auto itrl=shoppingLists.find(listName);
                auto itru=users.find(userName);
                try {
                    if(itrl==shoppingLists.end()||itru==users.end())
                        throw std::invalid_argument("Invalid list/user name");
                    else
                    {
                        itru->second.removeShoppingList(listName);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;
            }

            case 6: {
                operations=false;
                break;
            }
        }
    }

    cout<<"Let's see your users/lists/ items"<<endl;
    for(auto&itr: users)
    {
        cout<<endl;
        cout<<"     User name:  "<< itr.first<<endl;
        for(auto &itl: itr.second.getMyLists())
        {
            cout<<endl;
            itl.second->print();
        }
    }


    return 0;
}
