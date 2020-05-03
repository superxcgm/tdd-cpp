//
// Created by Yujia Li on 2020/5/3.
//
#include "gtest/gtest.h"

class Soundex {

public:
    std::string encode(const std::string &word) const {
        return "A";
    }
};

TEST(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
    Soundex soundex;

    auto encoded = soundex.encode("A");

    EXPECT_EQ(encoded, "A");
}