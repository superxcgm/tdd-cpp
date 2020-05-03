//
// Created by Yujia Li on 2020/5/3.
//

#ifndef TDD_CPP_SOUNDEX_H
#define TDD_CPP_SOUNDEX_H

class Soundex {

public:
    std::string encode(const std::string &word) const {
        auto encoded = word.substr(0, 1);
        if (word.length() > 1)
            encoded += "1";
        return zeroPad(encoded);
    }

private:
    std::string zeroPad(const std::string &word) const {
        auto zerosNeeded = 4 - word.length();
        return word + std::string(zerosNeeded, '0');
    }
};

#endif //TDD_CPP_SOUNDEX_H
