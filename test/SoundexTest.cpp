//
// Created by Yujia Li on 2020/5/3.
//
#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexEncoding : public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
    EXPECT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    EXPECT_EQ(soundex.encode("I"), "I000");
}

TEST_F(SoundexEncoding, ReplaceFuYinWithDigit) {
    EXPECT_EQ(soundex.encode("Ax"), "A200");
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics) {
    EXPECT_EQ(soundex.encode("A#"), "A000");
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
    EXPECT_EQ(soundex.encode("Acdl"), "A234");
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
    EXPECT_EQ(soundex.encode("Dcdlb").length(), 4);
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters) {
    EXPECT_EQ(soundex.encode("Baeiouhycdl"), "B234");
}