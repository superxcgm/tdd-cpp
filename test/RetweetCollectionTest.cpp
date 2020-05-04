//
// Created by Yujia Li on 2020/5/4.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

class ARetweetCollection : public Test {
public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
    ASSERT_EQ(collection.size(), 0);
}

class ARetweetCollectionWithOneTweet : public Test {
public:
    RetweetCollection collection;
    std::shared_ptr<Tweet> tweet;

protected:
    void SetUp() override {
        tweet = std::shared_ptr<Tweet>(new Tweet("msg", "@user"));
        collection.add(*tweet);
    }
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmptyAfterTweetAdded) {
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOneAfterTweetAdded) {
    ASSERT_EQ(collection.size(), 1);
    EXPECT_THAT(1, Eq(1)); // hamcrest style
}

TEST_F(ARetweetCollectionWithOneTweet, IgnoresDuplicateTweetAdded) {
    Tweet duplicate(*tweet);

    collection.add(duplicate);

    ASSERT_EQ(collection.size(), 1);
}