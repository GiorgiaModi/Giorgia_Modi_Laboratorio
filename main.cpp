#include <iostream>
#include "Subject.h"
#include "ShoppingList.h"
#include "Observer.h"
#include "User.h"
#include <string>
using namespace std;




int main() {


    ShoppingList casa ("Casa");
    ShoppingList cibo("Cibo");
    ShoppingList bevande ("Bevande");

    Item cartaigienica("cartaigienica",2);
    Item fazzoletti("fazzoletti");
    Item zampironi("zampironi",5);
    Item zampironi2("zampironi",2);

    Item frutta("frutta");
    Item verdura("verdura");
    Item merendine("merendine",10);
    Item prosciutto("prosciutto");

    Item acqua("acqua",5);
    Item fanta("fanta",3);
    Item redbull ("redbull",4);
    Item coca ("coca");



    casa.addItem(&cartaigienica);
    casa.addItem(&fazzoletti);
    casa.addItem(&zampironi);
    casa.addItem(&zampironi2);

    casa.print();
    cout<<endl;

    cibo.addItem(&frutta);
    cibo.addItem(&verdura);
    cibo.addItem(&merendine);
    cibo.addItem(&prosciutto);

    cibo.print();
    cout<<endl;

    bevande.addItem(&acqua);
    bevande.addItem(&fanta);
    bevande.addItem(&redbull);
    bevande.addItem(&coca);

    bevande.print();
    cout<<endl;
/*
    casa.removeItem("zampiron");
    casa.print();
    cout<<endl;

    casa.removeItem("zampironi");
    casa.print();
    cout<<endl;

    bevande.setBought("coca");
    bevande.print();
    cout<<endl;

    casa.setBought("zampironi");
    casa.print();
    cout<<endl;
*/

    map<string,ShoppingList*> giorgia;
    giorgia.insert(make_pair("Casa",&casa));
    giorgia.insert(make_pair("Bevande",&bevande));
    giorgia.insert(make_pair("Cibo",&cibo));

    User Giorgia(giorgia);

    casa.removeItem("zampironi");

    Item pane("pane",6);
    cibo.addItem(&pane);


    return 0;
    /*
    Giorgia.addShoppingList(&cibo);
    Giorgia.addShoppingList(&bevande);
    */


}
