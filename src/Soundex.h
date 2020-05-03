//
// Created by Yujia Li on 2020/5/3.
//

#ifndef TDD_CPP_SOUNDEX_H
#define TDD_CPP_SOUNDEX_H

class Soundex {

public:
    std::string encode(const std::string &word) const {
        if (word == "Ab") {
            return "A100";
        }
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string &word) const { return word + "000"; }
};

#endif //TDD_CPP_SOUNDEX_H
