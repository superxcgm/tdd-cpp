//
// Created by Yujia Li on 2020/5/4.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Adder {
public:
    static int sum(int a, int b) {
        return a + b;
    }
};

struct SumCase {
    int a, b, expected;

    SumCase(int a, int b, int expected) : a(a), b(b), expected(expected) {}
};

class AnAdder: public testing::TestWithParam<SumCase> {
};

TEST_P(AnAdder, GeneratesLotsOfSumsFromTwoNumbers) {
    SumCase input = GetParam();
    ASSERT_THAT(Adder::sum(input.a, input.b), testing::Eq(input.expected));
}

SumCase sums[] = {
        SumCase(1, 1, 2),
        SumCase(1, 2, 3),
        SumCase(2, 2, 4)
};
INSTANTIATE_TEST_CASE_P(BulkTest, AnAdder, testing::ValuesIn(sums));