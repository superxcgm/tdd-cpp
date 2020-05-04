//
// Created by Yujia Li on 2020/5/4.
//
#include "gtest/gtest.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

class ARetweetCollection: public Test {
public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
    ASSERT_EQ(collection.size(), 0);
}

class ARetweetCollectionWithOneTweet: public Test {
public:
    RetweetCollection collection;
    void SetUp() override {
        collection.add(Tweet());
    }
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmptyAfterTweetAdded) {
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOneAfterTweetAdded) {
    ASSERT_EQ(collection.size(), 1);
}

TEST_F(ARetweetCollection, IgnoresDuplicateTweetAdded) {
    Tweet tweet("msg", "@user");
    Tweet duplicate(tweet);
    collection.add(tweet);

    collection.add(duplicate);

    ASSERT_EQ(collection.size(), 1);
}