//
// Created by Giorg on 19/07/2021.
//



#include "gtest/gtest.h"
#include"../Item.h"


TEST(ItemSuite,TestConstructor)
{
    Item i("pane",6);
    ASSERT_EQ(i.getItemQuantity(),6);
    ASSERT_EQ(i.getItemName(),"pane");

    ASSERT_THROW(Item i2("pane",-2) ,out_of_range);
}


TEST(ItemSuite, TestSetItemquantity) {
    Item i("pane",3);
    ASSERT_THROW(i.setItemQuantity(-2),out_of_range);
}
