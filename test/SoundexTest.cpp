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
    EXPECT_EQ(soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
    EXPECT_EQ(soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
    EXPECT_EQ(soundex.encode("abcd").substr(0, 1), "A");
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants) {
    EXPECT_EQ(soundex.encode("BCDL"), soundex.encode("Bcdl"));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWith2ndLetterDuplicate1st) {
    EXPECT_EQ(soundex.encode("Bbcd"), "B230");
}

TEST_F(SoundexEncoding, DoesNotCombineDuplicateEncodingsSeparatedByVowel) {
    EXPECT_EQ(soundex.encode("Jbob"), "J110");
}