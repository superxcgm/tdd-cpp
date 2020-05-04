//
// Created by Yujia Li on 2020/5/4.
//

#include "gtest/gtest.h"
#include "Tweet.h"


TEST(ATweet, RequiresUserToStartWithAtSign) {
    std::string invalidUser("notStartingWith@");

    //    ASSERT_ANY_THROW(Tweet tweet("msg", invalidUser));
    ASSERT_THROW(Tweet tweet("msg", invalidUser), InvalidUserException);
}
