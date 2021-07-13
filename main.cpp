#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include <string>
using namespace std;

struct Item{

    Item(string s, int q=0):  itemName(s),itemQuantity(q){}
    string itemName;
    int itemQuantity;
    bool bought {false};
};


int main() {

    Item cartaigienica("cartaigienica");

}
