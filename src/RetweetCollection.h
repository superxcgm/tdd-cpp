//
// Created by Yujia Li on 2020/5/4.
//

#ifndef TDD_CPP_RETWEETCOLLECTION_H
#define TDD_CPP_RETWEETCOLLECTION_H


#include <vector>
#include "Tweet.h"

class RetweetCollection {
public:
    RetweetCollection() : size_(0) {}

    bool isEmpty() const {
        return size() == 0;
    }

    unsigned int size() const {
        return size_;
    }

    void add(const Tweet &tweet) {
        if (std::find(collection.begin(), collection.end(), tweet) != collection.end()) {
            return;
        }
        collection.push_back(tweet);
        size_++;
    }

private:
    unsigned int size_;
    std::vector<Tweet> collection;
};


#endif //TDD_CPP_RETWEETCOLLECTION_H
