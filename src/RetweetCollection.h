//
// Created by Yujia Li on 2020/5/4.
//

#ifndef TDD_CPP_RETWEETCOLLECTION_H
#define TDD_CPP_RETWEETCOLLECTION_H


#include "Tweet.h"

class RetweetCollection {
public:
    RetweetCollection() : size_(0) {}
    bool isEmpty() const {
        return size() == 0;
    }

    int size() const {
        return size_;
    }

    void add(const Tweet &tweet) {
        size_ = 1;
    }

private:
    unsigned int size_;
};


#endif //TDD_CPP_RETWEETCOLLECTION_H
