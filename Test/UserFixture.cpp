//
// Created by Giorg on 17/07/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class UserSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        s1.setShoppingListName("Casa");
        s2.setShoppingListName("Lavoro");
        u.addShoppingList(&s1);
    }

    ShoppingList s1;
    ShoppingList s2;
    User u;

};


TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(&s2);

    ASSERT_EQ(2,u.myLists.size());
}



TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("Casa");

    ASSERT_EQ(0,u.myLists.size());
}
