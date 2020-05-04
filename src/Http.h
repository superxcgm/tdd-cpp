//
// Created by Yujia Li on 2020/5/4.
//

#ifndef TDD_CPP_HTTP_H
#define TDD_CPP_HTTP_H

#include <string>

class Http {
public:
    virtual ~Http() {};

    virtual void initialize() = 0;

    virtual std::string get(const std::string &url) const = 0;
};

#endif //TDD_CPP_HTTP_H
