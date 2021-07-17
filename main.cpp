#include <iostream>
#include "Subject.h"
#include "ShoppingList.h"
#include "Observer.h"
#include "User.h"
#include <string>
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
                Item i(itemName,quantity);
                items.insert(make_pair(itemName,i));
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
                if(itrl==shoppingLists.end()||itri==items.end())
                    cout<<"No list/item with this name :("<<endl;
                else
                {
                    itrl->second.addItem(&(itri->second));
                }
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
                if(itrl==shoppingLists.end()||itri==items.end())
                    cout<<"No list/item with this name :("<<endl;
                else
                {
                    itrl->second.removeItem(itemName);
                }
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
                if(itrl==shoppingLists.end()||itri==items.end())
                    cout<<"No list/item with this name :("<<endl;
                else
                {
                    itrl->second.setBought(itemName);
                }
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
                if(itrl==shoppingLists.end()||itru==users.end())
                    cout<<"No user/list with this name :("<<endl;
                else
                {
                    itru->second.addShoppingList(&(itrl->second));
                }
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
                if(itrl==shoppingLists.end()||itru==users.end())
                    cout<<"No user/list with this name :("<<endl;
                else
                {
                    itru->second.removeShoppingList(listName);
                }
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
        for(auto &itl: itr.second.myLists)
        {
            cout<<endl;
            itl.second->print();
        }
    }


    return 0;
}
