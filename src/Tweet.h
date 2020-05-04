//
// Created by Yujia Li on 2020/5/4.
//

#ifndef TDD_CPP_TWEET_H
#define TDD_CPP_TWEET_H


#include <string>

class Tweet {

public:
    Tweet() = default;

    Tweet(const std::string &message, const std::string &user) {
        message_ = message;
        user_ = user;
    }

    bool operator==(const Tweet &rhs) const {
        return message_ == rhs.message_ &&
               user_ == rhs.user_;
    }

    bool operator!=(const Tweet &rhs) const {
        return !(rhs == *this);
    }

private:
    std::string message_;
    std::string user_;
};


#endif //TDD_CPP_TWEET_H
