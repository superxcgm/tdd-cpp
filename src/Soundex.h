//
// Created by Yujia Li on 2020/5/3.
//

#ifndef TDD_CPP_SOUNDEX_H
#define TDD_CPP_SOUNDEX_H

class Soundex {

public:

    std::string encode(const std::string &word) const {
        return zeroPad(head(word) + encodedDigits(word));
    }

private:
    std::string encodedDigits(const std::string &word) const {
        if (word.length() > 1) return encodedDigit(word[1]);
        return "";
    }

    std::string head(const std::string &word) const {
        return word.substr(0, 1);
    }

    std::string encodedDigit(char letter) const {
        if (letter == 'c') {
            return "2";
        }
        return "1";
    }

    static const size_t MaxCodeLength{4};

    std::string zeroPad(const std::string &word) const {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }
};

#endif //TDD_CPP_SOUNDEX_H
