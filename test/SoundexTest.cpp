//
// Created by Yujia Li on 2020/5/3.
//
#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexEncoding: public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
    EXPECT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    EXPECT_EQ(soundex.encode("I"), "I000");
}