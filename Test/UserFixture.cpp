//
// Created by Giorg on 17/07/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class UserSuite : public ::testing::Test {

protected:
protected:

    virtual void SetUp() {
        u.addShoppingList(&s1);
    }

    ShoppingList s1{"Casa"};
    ShoppingList s2{"Lavoro"};
    User u;

};


TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(&s2);

    ASSERT_EQ(2,u.getMyLists().size());
}



TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("Casa");

    ASSERT_EQ(0,u.getMyLists().size());
}
