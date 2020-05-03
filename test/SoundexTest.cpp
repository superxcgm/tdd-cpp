//
// Created by Yujia Li on 2020/5/3.
//
#include "gtest/gtest.h"

class Soundex {

public:
    std::string encode(const std::string &word) const {
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string &word) const { return word + "000"; }
};

class SoundexEncoding: public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
    auto encoded = soundex.encode("A");

    EXPECT_EQ(encoded, "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    auto encoded = soundex.encode("I");

    EXPECT_EQ(encoded, "I000");
}