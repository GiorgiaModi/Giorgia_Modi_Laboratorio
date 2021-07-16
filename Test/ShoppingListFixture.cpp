//
// Created by Giorg on 16/07/2021.
//


#include "gtest/gtest.h"
#include "../ShoppingList.h"

class ShoppingListSuite:  public::testing::Test{

protected:
    void SetUp() override {
        s.setShoppingListName("casa");
        frutta.itemName="frutta";
        frutta.itemQuantity=1;
        verdura.itemName="verdura";
        verdura.itemQuantity=1;
        pane.itemName="pane";
        pane.itemQuantity=5;
        s.addItem(&frutta);
        s.addItem(&verdura);
        s.addItem(&pane);
    }

    ShoppingList s;
    Item frutta;
    Item verdura;
    Item pane;
};



TEST_F(ShoppingListSuite, TestDefaultConstructor) {
    ShoppingList sl;
    ASSERT_EQ(sl.getShoppingListName(),"");
}


TEST_F(ShoppingListSuite, TestParametrizeConstructor) {
    ShoppingList sl("Animali");
    ASSERT_EQ(sl.getShoppingListName(),"Animali");
}


TEST_F(ShoppingListSuite, TestAddItem) {
    Item carne("carne",4);
    s.addItem(&carne);
    ASSERT_EQ(s.notBought(),11);
}



TEST_F(ShoppingListSuite, TestRemoveItem) {
    s.removeItem("frutta");
    ASSERT_EQ(s.notBought(),6);
}


TEST_F(ShoppingListSuite, TestSetBought) {
    s.setBought("frutta");
    ASSERT_EQ(s.notBought(),6);
}





