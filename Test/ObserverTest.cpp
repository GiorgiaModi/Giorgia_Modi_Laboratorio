//
// Created by Giorg on 17/07/2021.
//


#include "gtest/gtest.h"
#include "../Observer.h"
#include "../ShoppingList.h"


class ObserverTest : public testing::Test, public Observer {
public:
    void update(const string& listName) override {
        updated = true;
    }

    bool isUpdated() const {
        return updated;
    }

protected:

    void SetUp() override {

        s.setShoppingListName("Casa");
        s.subscribe(this);
        carta.itemName="carta";
        carta.itemQuantity=3;

    }

    void TearDown() override {
        s.unsubscribe(this);
    }

    bool updated = false;
    ShoppingList s;
    Item carta;

};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    s.addItem(&carta);
    ASSERT_TRUE(isUpdated());
}


