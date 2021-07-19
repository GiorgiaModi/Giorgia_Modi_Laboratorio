//
// Created by Giorg on 16/07/2021.
//


#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListSuite:  public::testing::Test{

protected:
protected:

    void SetUp() override {
        s.addItem(frutta);
        s.addItem(verdura);
        s.addItem(pane);
    }


    ShoppingList s{"casa"};
    Item frutta{"frutta",1};
    Item verdura{"verdura",1};
    Item pane{"pane",5};
    User user;
};



TEST_F(ShoppingListSuite, TestParametrizeConstructor) {
    ShoppingList sl("Animali");
    ASSERT_EQ(sl.getShoppingListName(),"Animali");
}


TEST_F(ShoppingListSuite, TestAddItem) {
    Item carne("carne",4);
    s.addItem(carne);
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,4);    //item nella lista

    ASSERT_EQ(s.notBought(),11); //oggetti da comprare in totale

    Item carne2("carne",2);    //provo ad aggiungere un oggetto con lo stesso nome(deve cambiare solo il numero tot di oggetti)
    s.addItem(carne2);
    size=s.getShoppingList().size();
    ASSERT_EQ(size,4);
    ASSERT_EQ(s.notBought(),13);
}



TEST_F(ShoppingListSuite, TestRemoveItem) {
    s.removeItem("frutta");
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,2);
    ASSERT_EQ(s.notBought(),6);
}


TEST_F(ShoppingListSuite, TestSetBought) {
    s.setBought("frutta");
    ASSERT_EQ(s.notBought(),6);
}


TEST_F(ShoppingListSuite,TestSubject)
{
    s.subscribe(&user);
    ASSERT_EQ(1,s.getObservers().size());

    s.unsubscribe(&user);
    ASSERT_EQ(0,s.getObservers().size());
}


TEST_F(ShoppingListSuite, TestNotBought) {
    ASSERT_EQ(7,s.notBought());
}


TEST_F(ShoppingListSuite, GettersAndSetters)
{
    s.setShoppingListName("lavoro");
    ASSERT_EQ("lavoro",s.getShoppingListName());
}



